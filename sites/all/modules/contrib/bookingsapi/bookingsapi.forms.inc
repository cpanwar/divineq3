<?php
/**
 * @file
 * Generic forms, validation, and form elements.
 *
 * Basic forms and components to create bookings, availabilities, and resources.
 */

function _bookingsapi_elements() {
  $type['bookingsapi_resource_select'] = array(
    '#input' => TRUE,
    '#process' => array('bookingsapi_resource_select_process'),
    '#element_validate' => array('bookingsapi_resource_select_validate'),
    '#bookingsapi_empty' => FALSE,
    '#bookingsapi_showall' => FALSE,
//    '#bookingsapi_where' => FALSE,
  );
  return $type;
}

/**
 * A very simple dropdown list for picking one resource.
 *
 * @param array $element
 * @param array $form_state
 * @return array
 */
function bookingsapi_resource_select_process($element, $form_state) {
  $res_list = bookingsapi_resource_list(0, 'ORDER BY nid asc');
  
  $available_resources = array();
  $available_resources[0] = '- ' . t('Pick a resource.');

  foreach ( $res_list as $resource ) {
    if ( $element['#bookingsapi_showall'] || $resource->status = 1 ) {
      $row = $resource->title;
      if (!empty($resource->field_ba_location[0]['value'])) {
        $row .= ' - ' . $resource->field_ba_location[0]['value'];
      }
      if ( variable_get('bookingsapi_resource_tree',false) || $element['tree'] ) {
        if ( $resource->field_ba_parent[0]['nid'] ) {
          _bookingsapi_resultform_insert_elem($available_resources, $row, $resource, $res_list[$resource->field_ba_parent[0]['nid']]);
        } else {
          $available_resources[$resource->nid][$resource->nid] = $row;
          $resource->pointer =& $available_resources[$resource->nid]; 
          $resource->level = "";
        }
      } else {
        $available_resources[$resource->nid] = $row;
      }
    }
  }

  if (empty($available_resources)) {
    $element['#empty'] = TRUE;
    $available_resources[0] = t('No resources available.');
  }

  $element['#tree'] = FALSE;
  $element['#title'] = t('Resource');
  $element['#type'] = 'select';
  if ( variable_get('bookingsapi_resource_tree',false) ) {
    $element['#options'] = _bookingsapi_resultform_build_result($available_resources, $res_list);
  } else {
    $element['#options'] = $available_resources;
  }

  return $element;
}

function _bookingsapi_resultform_insert_elem(&$resources, $row, $curr, $parent ) {
  $curr->level = "|--".$parent->level;
  $parent->pointer[$curr->nid][$curr->nid] = $row;
  $curr->pointer =& $parent->pointer[$curr->nid];
}

function _bookingsapi_resultform_build_result($resources, $list) {
  $result = array();
  foreach ( $resources as $key=>$res ) {
    if ( is_array($res) ) {
      $result = array_merge($result, _bookingsapi_resultform_build_result($res,$list));
    } else {
      $result[$key] = $list[$key]->level . $res;
    }
  }
  return $result;
}

function bookingsapi_resource_select_validate($element, &$form_state) {
  if($element['#required'] && $element['#value']==0) {
    $error_field = implode('][', $element['#parents']);
    if($element['#empty']) {
      form_set_error($error_field, t(''));
    } else {
      form_set_error($error_field, t('A resource must be chosen.'));
    }
  }
}

/**
 * Basic booking form. Implementing modules can call this function to get a ready-made
 * form for basic booking fields.
 *
 * @param array $booking
 *  representing a booking, to fill in default values.
 * @return array
 *  for Form API
 * @see bookingsapi_record_validate()
 */
function bookingsapi_booking_form($booking, &$form_state=array()) {
  $sql = "SELECT nid FROM {node} WHERE type = '".BOOKINGSAPI_RESOURCE_TYPE."'";
  $q = db_query($sql);
  if ( ! ($q && db_fetch_array($q)) ) {
    drupal_set_message(t('Cannot book a resource - no resources found'),'error');
    return array();
  }
  
  // TODO: granularity for hours and days instead of just minutes
  $granularity = variable_get('bookingsapi_time_granularity', 10);

  if ( isset($form_state['values']) ) {
    $booking = $form_state['values'] + $booking;
  }

  $form = array();
  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Booking record'),
  );
  $form['basic']['resource_id'] = array(
    '#type' => 'bookingsapi_resource_select',
    '#default_value' => $booking['resource_id'],
    '#required' => TRUE,
  );
  $form['basic']['record_id'] = array(
    '#type' => 'hidden', // 'hidden' instead of 'value' to let AJAX pick up the hidden form field
    '#value' => $booking['record_id'],
  );
  $form['basic']['type'] = array(
    '#type' => 'value',
    '#value' => 1,
  );
  $form['basic']['values'] = array(
    '#type'  => 'value',
    '#value' => $booking,
  );
  $form['basic']['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#description' => t('Such as the event name.'),
    '#default_value' => $booking['name'],
    '#required' => TRUE,
  );
  $form['basic']['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#description' => t('Any information about this booking, for future reference.'),
    '#default_value' => $booking['description'],
  );
  $form['basic']['start'] = array(
    '#title' => t('Start'),
    '#type' => 'date_select',
    '#date_label_position' => 'within',
    '#date_year_range' => variable_get('bookingsapi_year_range','0:+1'),
    '#date_increment' => $granularity,
    '#default_value' => $booking['start'],
    '#required' => TRUE,
  );
  $form['basic']['end'] = array(
    '#title' => t('End'),
    '#type' => 'date_select',
    '#date_label_position' => 'within',
    '#date_year_range' => variable_get('bookingsapi_year_range','0:+1'),
    '#date_increment' => $granularity,
    '#default_value' => $booking['end'],
    '#required' => TRUE,
  );
  $form['basic']['rrule'] = array(
    '#type' => 'date_repeat_rrule',
    '#default_value' => $booking['rrule'],
    '#repeat_collapsed' => TRUE
  );
  
  $form['basic']['priority'] = array(
    '#title' => t('Priority'),
    '#description' => t('Higher priority bookings may override lower ones.'),
    '#type' => 'select',
    '#options' => bookingsapi_booking_priorities(),
    '#default_value' => isset($booking['priority']) ? $booking['priority'] : 0,
    '#weight' => 5,
  );
  $status = 1;
  if ( isset($booking['status']) ) {
    $status = bookingsapi_numeric_record_status($booking['status']);
  }
  $form['basic']['status'] = array(
    '#title' => t('Status'),
    '#type' => 'radios',
    '#options' => bookingsapi_record_status(),
    '#default_value' => $status,
    '#description' => t('Finalized bookings cannot have time conflicts with each other.'),
    '#weight' => 5,
  );
  if(!empty($booking['record_id'])) {
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#weight' => 8,
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 7,
  );
  $form['#validate'] = array('bookingsapi_record_validate');
  return $form;
}

/**
 * Basic availability form. Implementing modules can call this function to get a ready-made
 * form for basic availability fields. Variant of bookingsapi_booking_form.
 *
 * @param array $avail
 *  representing an availability record, to fill in default values.
 * @return array
 *  for Form API
 * @see bookingsapi_booking_form()
 * @see bookingsapi_record_validate()
 */
function bookingsapi_availability_form($avail) {
  $form = bookingsapi_booking_form($avail);
  $form['basic']['status'] = array(
    '#type' => 'value',
    '#value' => BOOKINGSAPI_STATUS_FINALIZED, // finalized, as otherwise conflict check ignores it
  );
  $form['basic']['#title'] = t('Availability restriction');
  $form['basic']['resource']['#description'] = t('Pick a resource to define availability information for.');
  $form['basic']['name']['#description'] = t('Such as \'Regular building hours\'.');
  $form['basic']['description']['#description'] = t('Any information about this availability restriction.');
  unset($form['basic']['priority']); // perhaps not needed, for now
  //$form['basic']['priority']['#description'] = t('Higher priority restrictions override lower ones.');
  if ( isset($avail['type']) ) {
    $avail_code = bookingsapi_numeric_record_types($avail['type']);
  }
  else {
    $avail_code = BOOKINGSAPI_UNAVAILABLE;
  }
  $form['basic']['type'] = array(
    '#title' => t('Availability status'),
    '#type' => 'radios',
    '#options' => array(BOOKINGSAPI_UNAVAILABLE=>'Unavailable', BOOKINGSAPI_AVAILABLE=>'Available'),
    '#description' => t('The availability status of the resource during the specified time frame.'),
    '#weight' => 2,
    '#default_value' => $avail_code,
    '#required' => TRUE,
  );
//  $form['basic']['flexibility'] = array(
//    '#title' => t('Flexibility'),
//    '#type' => 'radios',
//    '#options' => array(0=>'Rigid',1=>'Flexible'),
//    '#default_value' => 0,
//    '#description' => t('Flexible restrictions are informational only, while rigid restrictions are enforced.'),
//    '#required' => TRUE,
//  );
  if(!empty($avail)) {
    unset($form['cancel']);
  }
  $form['#validate'][] = 'bookingsapi_availability_validate';
  return $form;
}

/**
 * Translate integers representing priority levels to human-readable priority level names.
 *
 * @return array
 *  [k,v] pairs representing each priority level.
 */
function bookingsapi_booking_priorities() {
  $priorities = array( 1=>'High', 0=>'Normal', -1=>'Low' );
  bookingsapi_extend($prefix.'priorities', null, $priorities);
  return $priorities;
}


/**
 * Default, sane validation checks for both bookings and availabilities.
 *
 * @param array $form
 * @param array $form_state
 */
function bookingsapi_record_validate($form, &$form_state) {
  // empty the RRULE if it doesn't do anything
  if(strpos($form_state['values']['rrule'], 'FREQ=NONE')) {
    $form_state['values']['rrule'] = '';
  }
  
  $values = $form_state['values'];
  // make sure the start date is before the end date
  $unix_start = date_convert($values['start'], DATE_DATETIME, DATE_UNIX);
  $unix_end = date_convert($values['end'], DATE_DATETIME, DATE_UNIX);
  if (($unix_end - $unix_start) < 0)
    form_set_error('end', t('The end date and time must come after the start date and time.'));

  // TODO: if UNTIL is set, check to make sure UNTIL comes after end date
}

/**
 * Convert the type value to an int ready for saving.
 *
 * @param array $form
 * @param array $form_state
 */
function bookingsapi_availability_validate($form, &$form_state) {
  $form_state['values']['type'] = (int) $form_state['values']['type'] ;//+ (int) $form['values']['flexibility'];
}

/**
 * Basic resource form. Implementing modules can call this function to get a ready-made
 * form for basic resource fields.
 *
 * @param object $resource
 *  to optionally fill in the form
 * @return array
 *  for Form API
 */
function bookingsapi_resource_form($resource) {
  $form = array();
  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bookable resource')
  );
  $form['basic']['resource_id'] = array(
    '#type' => 'value',
    '#value' => isset($resource->nid) ? $resource->nid : NULL,
  );
  $form['basic']['name'] = array(
    '#title' => t('Resource name'),
    '#type' => 'textfield',
    '#description' => t('Such as \'Room 312\' or \'Computer #31\'.'),
    '#default_value' => isset($resource->title) ? $resource->title : '',
  );
  $form['basic']['location'] = array(
    '#title' => t('Resource location'),
    '#type' => 'textfield',
    '#description' => t('Such as \'3rd floor\' or \'Lab X350\'.'),
    '#default_value' => isset($resource->field_ba_location[0]['value']) ? $resource->field_ba_location[0]['value'] : '',
  );
  $form['basic']['description'] = array(
    '#title' => t('Resource description'),
    '#type' => 'textarea',
    '#description' => t('Any other information that describes the bookable resource.'),
    '#default_value' => isset($resource->body) ? $resource->body : '',
  );
  $form['basic']['parent'] = array(
    '#type' => 'bookingsapi_resource_select',
    '#title' => t('Parent resource'),
    '#description' => t('If this resource has a parent, it will inherit all bookings and availabilities of the parent.'),
    '#default_value' => isset($resource->field_ba_parent[0]['value']) ? $resource->field_ba_parent[0]['value'] : '',
  );
  $form['basic']['default_availability'] = array(
    '#title' => t('Default availability'),
    '#type' => 'radios',
    '#options' => bookingsapi_availability_types(),
    '#description' => t('If no availability information is defined for a given time, the resource falls back onto this setting.'),
    '#default_value' =>
       isset($resource->field_ba_defaultavailability[0]['value']) ? bookingsapi_numeric_record_types($resource->field_ba_defaultavailability[0]['value']) : BOOKINGSAPI_AVAILABLE,
  );
  $form['basic']['disabled'] = array(
    '#title' => t('Disable new bookings from being made'),
    '#type' => 'checkbox',
    '#description' => t('Existing bookings will be preserved.'),
    '#default_value' => isset($resource->status) ? $resource->status != 1 : FALSE,
  );
  if(!empty($resource)) {
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#weight' => 8,
    );
  }
  $form['#validate'] = array('bookingsapi_resource_validate');
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );
  return $form;
}

/**
 * Default, sane validation checks for resources.
 *
 * @param array $form
 * @param array $form_state
 */
function bookingsapi_resource_validate($form, &$form_state) {
  $values = $form_state['values'];
  // anything?
}

function bookingsapi_availability_types() {
  $types = bookingsapi_record_types();
  unset($types[BOOKINGSAPI_BOOKING]);
  return $types;
}

