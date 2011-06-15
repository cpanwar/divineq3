<?php
/**
 * @file
 * Administrative forms and callbacks.
 *
 */

/**
 * Bookings overview page.
 */
function publicbookings_overview_page() {
  include_once('publicbookings.views_default.inc');
  $text = '<h3>'.t('Awaiting approval').'</h3>';
  // views_embed_view('viewname','display-id',$arg1, $arg2)
  // here arg1 is the STATUS and arg2 is the "end time" (defaulting to "next year")
  $text .= views_embed_view('publicbookings_view_schedules_ad','default', BOOKINGSAPI_STATUS_PENDING,NULL);
  $text .= '<h3>'.t('Finalized').'</h3>';
  $text .= views_embed_view('publicbookings_view_schedules_ad','default', BOOKINGSAPI_STATUS_FINALIZED,NULL);
  if ( variable_get('publicbookings_show_unconfirmed',true) ) {
    $text .= '<h3>'.t('Unconfirmed:').'</h3>';
    $text .= views_embed_view('publicbookings_view_schedules_ad','default', BOOKINGSAPI_STATUS_UNCONFIRMED,NULL);
  }
  return $text;
}

function publicbookings_booking_list($where = '', $element = 0) {
  include_once('publicbookings.views_default.inc');
  return views_embed_view('publicbookings_view_schedules','default', NULL,NULL);
//  $view = publicbookings_view_schedules();
//  return $view->render();
}

/**
 * Bookings add page.
 */
function publicbookings_booking_add() {
  return drupal_get_form('publicbookings_booking_add_form');
}

/**
 * Bookings edit page.
 *
 * @param array $booking
 */
function publicbookings_booking_edit($booking) {
  return drupal_get_form('publicbookings_booking_edit_form', $booking);
}

/**
 * Bookings form.
 *
 * @param array $form_state
 * @param array $booking
 * @return array
 */
function publicbookings_booking_form(&$form_state, $booking = array()) {
  include_once('./'. drupal_get_path('module', 'bookingsapi') .'/bookingsapi.forms.inc');
  $form = bookingsapi_booking_form($booking);
  if (empty($booking['start']) && empty($booking['end'])) {
    $default_date = date_format(date_now(), DATE_DATETIME);
    $form['basic']['start']['#default_value'] = $default_date;
    $form['basic']['end']['#default_value'] = $default_date;
  }

  if ($booking['resource_id'] > 0) {
    // if a resource ID is given, don't let the user change it
    $form['basic']['resource_id']['#value'] = $booking['resource_id'];
    $form['basic']['resource_id']['#disabled'] = TRUE;
  }

  drupal_add_js(drupal_get_path('module', 'publicbookings') . '/js/booking.js');
  // AJAX availability checker
  $form['basic']['ajax_display'] = array(
    '#value' => '<div id="ajax-availability">&nbsp;</div><div id="ajax-display">&nbsp;</div>',
  );

  $client = publicbookings_client_load_from_record_id($booking['record_id']);
  // If client information exists, disable all the fields except the comment box, and preserve all the values.
  if ($client) {
    include_once('./'. drupal_get_path('module', 'publicbookings') .'/publicbookings.public.inc');
    $clientform = publicbookings_clientinfo_form($client);
    $clientform['client']['#title'] = t('Client details');
    $clientform['client']['first_name']['#disabled'] = TRUE;
    $clientform['client']['first_name']['#value'] = $clientform['client']['first_name']['#default_value'];
    $clientform['client']['last_name']['#disabled'] = TRUE;
    $clientform['client']['last_name']['#value'] = $clientform['client']['last_name']['#default_value'];
    $clientform['client']['phone']['#disabled'] = TRUE;
    $clientform['client']['phone']['#value'] = $clientform['client']['phone']['#default_value'];
    $clientform['client']['email']['#disabled'] = TRUE;
    $clientform['client']['email']['#value'] = $clientform['client']['email']['#default_value'];
    $form = array_merge($form, $clientform);
    $form['basic']['status']['#description'] .= '<br />' . t('This booking was made by a public client.
      Changing the status will dispatch a notification email to the client.');
  }


  $form['#base'] = 'publicbookings_booking_form';
  $form['#submit'] = array('publicbookings_booking_form_submit');
  $form['#validate'][] = 'publicbookings_booking_form_validate';
  return $form;
}

/**
 * Bookings form validation. Checks for scheduling conflicts, and that the RRULE has an UNTIL.
 *
 * @param array $form
 * @param array $form_state
 */
function publicbookings_booking_form_validate($form, &$form_state) {
  // If we're deleting, conflicts and validity don't matter.
  if ($form_state['values']['op'] == t('Delete')) return;
  
  if ( $form_state['values']['INTERVAL'] != 0 ) {
    $form_state['values']['rrule_until'] = $form_state['values']['UNTIL']['datetime'];
    if (empty($form_state['values']['rrule_until'])) {
      form_set_error('rrule', t('Recurrences must have an end date.'));
    }
    else {
      $form_state['values']['rrule'] = date_api_ical_build_rrule($form_state['values']);
    }
  }
  publicbookings_conflict_check($form_state['values']);
  if ($form_state['values']['count_certain_conflicts'] > 0) {
    form_set_error('basic', $form_state['values']['html_certain_conflicts']);
  }
}

function publicbookings_booking_form_submit($form, &$form_state) {
  // If we're deleting, redirect to the deletion page immediately.
  if ($form_state['values']['op'] == t('Delete')) {
    $form_state['redirect'] = array('admin/content/publicbookings/booking/'.$form_state['values']['record_id'].'/delete');
    return;
  }

  $save_result = publicbookings_booking_save($form_state['values']);
  $t_args = array('%name' => $form_state['values']['name']);
  // no message for BOOKINGSAPI_TIME_CONFLICT, as we should have prevented it before we got here
  if ( $save_result[0] ) {
    switch ($save_result[1] ) {
      case SAVED_NEW:
        $op = 'created'; break;
      case SAVED_UPDATED:
        $op = 'updated'; break;
      default:
        $op = 'failed';
    }
  } else {
    $op = 'failed';
  }
  drupal_set_message(t("The booking %name has been $op.", $t_args));
  $form_state['redirect'] = 'admin/content/publicbookings/booking/list';
}

function publicbookings_resource_overview() {
  return publicbookings_resource_list();
}

/**
 * Resource listing page.
 */
function publicbookings_resource_list() {
  include_once('publicbookings.views_default.inc');
  return views_embed_view('publicbookings_view_resources_ad','default', NULL, NULL);
//  $view = publicbookings_view_resources_admin();
//  return $view->render();
}

/**
 * Booking delete confirmation page.
 * @param array $booking
 */
function publicbookings_booking_delete($booking) {
  return drupal_get_form('publicbookings_booking_delete_confirm', $booking);
}

/**
 * Booking delete confirmation form.
 */
function publicbookings_booking_delete_confirm(&$form_state, $booking) {
  $form['#item'] = $booking;
  $desc = t('%name, and all of its instances, will be deleted.', array('%name'=>$booking['name']));
  return confirm_form($form, t('Are you sure you want to delete this booking?'),
    'admin/content/publicbookings',$desc,t('Delete'));
}

/**
 * Booking delete.
 */
function publicbookings_booking_delete_confirm_submit($form, &$form_state) {
  bookingsapi_record_delete($form['#item']);
  $t_args = array('%name' => $form['#item']['name']);
  drupal_set_message(t('The booking %name has been deleted.', $t_args));
  $form_state['redirect'] = 'admin/content/publicbookings';
}

/**
 * Resource adding page.
 */
function publicbookings_resource_add() {
  return drupal_get_form('publicbookings_resource_add_form');
}

/**
 * Resource editing page.
 */
function publicbookings_resource_edit($resource) {
  return drupal_get_form('publicbookings_resource_edit_form', $resource);
}

/**
 * Resource delete confirmation page.
 * @param array $resource
 */
function publicbookings_resource_delete($resource) {
  return drupal_get_form('publicbookings_resource_delete_confirm', $resource);
}

/**
 * Resource delete confirmation form.
 */
function publicbookings_resource_delete_confirm(&$form_state, $resource) {
  $form['#item'] = $resource;
  $desc = t('All booking and availability records associated with %name will also be deleted.', array('%name'=>$resource['name']));
  return confirm_form($form, t('Are you sure you want to delete this resource?'),
    'admin/content/publicbookings/resource',$desc,t('Delete'));
}

/**
 * Resource delete.
 */
function publicbookings_resource_delete_confirm_submit($form, &$form_state) {
  bookingsapi_resource_delete($form['#item']);
  $t_args = array('%name' => $form['#item']['name']);
  drupal_set_message(t('The bookable resource %name has been deleted.', $t_args));
  $form_state['redirect'] = 'admin/content/publicbookings/resource';
}

/**
 * Resources form.
 */
function publicbookings_resource_form(&$form_state, $resource = array()) {
  include_once('./'. drupal_get_path('module', 'bookingsapi') .'/bookingsapi.forms.inc');
  $form = bookingsapi_resource_form($resource);
  $form_state['resource'] = $resource;
  if (!empty($resource)) $form['delete']['#submit'] = array('publicbookings_resource_delete');
  $form['#submit'] = array('publicbookings_resource_form_submit');
  $form['#validate'] = array('publicbookings_resource_form_validate');
  return $form;
}

/**
 * Resource form validation.
 */
function publicbookings_resource_form_validate($form, &$form_state) {

}

/**
 * Resource form submit.
 */
function publicbookings_resource_form_submit($form, &$form_state) {
  $val = $form_state['values'];
  $save_result = bookingsapi_resource_save($val);
  $t_args = array('%name' => $form_state['values']['name']);
  switch($save_result) {
    case SAVED_NEW:
      $op = 'created'; break;
    case SAVED_UPDATED:
      $op = 'updated'; break;
    default:
      $op = 'failed';
  }
  drupal_set_message(t("The bookable resource %name has been $op.", $t_args));
  if($op=='failed') return false;
  $form_state['redirect'] = 'admin/content/publicbookings/resource';
}


/**
 * Availability list page.
 */
function publicbookings_availability_list($resource) {
  include_once('./'. drupal_get_path('module', 'bookingsapi') .'/bookingsapi.forms.inc');
  $avail_code = bookingsapi_numeric_record_types($resource->field_ba_defaultavailability[0]['value']);
  $text .= '<h2>'.$resource->title.'</h2>';
  $avail = bookingsapi_availability_types();
  $text .= '<strong>'.t('Default availability:').'</strong> ' . $avail[$avail_code];

  include_once('publicbookings.views_default.inc');
  $text .= views_embed_view('publicbookings_view_avail_ad','default', $resource->nid, NULL);
//  $view = publicbookings_view_availability_admin();
//  $text .= $view->preview(NULL, array($resource->nid)); // first argument is the resource ID
  return $text;
}

/**
 * Availability add page.
 */
function publicbookings_availability_add($resource) {
  include_once('./'. drupal_get_path('module', 'bookingsapi') .'/bookingsapi.forms.inc');
  $fakeavail = array('resource_id'=>$resource->nid);
  return drupal_get_form('publicbookings_availability_add_form', $fakeavail);
}

function publicbookings_availability_edit($avail) {
  return drupal_get_form('publicbookings_availability_edit_form', $avail);
}

/**
 * Availability delete confirmation page.
 * @param array availability
 */
function publicbookings_availability_delete($avail) {
  return drupal_get_form('publicbookings_availability_delete_confirm', $avail);
}

/**
 * Availability delete confirmation form.
 */
function publicbookings_availability_delete_confirm(&$form_state, $avail) {
  $form['#item'] = $avail;
  $desc = t('%name, and all of its instances, will be deleted.', array('%name'=>$avail['name']));
  return confirm_form($form, t('Are you sure you want to delete this availability?'),
    'admin/content/publicbookings',$desc,t('Delete'));
}

/**
 * Availability delete.
 */
function publicbookings_availability_delete_confirm_submit($form, &$form_state) {
  bookingsapi_availability_delete($form['#item']);
  $t_args = array('%name' => $form['#item']['name']);
  drupal_set_message(t('The availability %name has been deleted.', $t_args));
  $form_state['redirect'] = 'admin/content/publicbookings';
}

function publicbookings_availability_form(&$form_state, $avail = array()) {
  include_once('./'. drupal_get_path('module', 'bookingsapi') .'/bookingsapi.forms.inc');
  $form = bookingsapi_availability_form($avail);
  if (empty($avail['start']) && empty($avail['end'])) {
    $default_date = date_format(date_now(), DATE_DATETIME);
    $form['basic']['start']['#default_value'] = $default_date;
    $form['basic']['end']['#default_value'] = $default_date;
  }
  if ($avail['resource_id'] > 0) {
    // if a resource ID is given, don't let the user change it
    $form['basic']['resource_id']['#value'] = $avail['resource_id'];
    $form['basic']['resource_id']['#disabled'] = TRUE;
    $res = bookingsapi_resource_load($avail['resource_id']);
    if (! $res->status) {
      // disabled resources don't appear in the dropdown menu be default
      // so if disabled, make the menu show all
      $form['basic']['resource_id']['#bookingsapi_showall'] = TRUE;
    }
  }
  $form['#base'] = 'publicbookings_availability_form';
  $form['#submit'][] = 'publicbookings_availability_form_submit';
  $form['#validate'][] = 'publicbookings_availability_form_validate';
  return $form;
}

// temporarily identical to booking equivalent
function publicbookings_availability_form_validate($form, &$form_state) {
  // If we're deleting, conflicts and validity don't matter.
  if ($form_state['values']['op'] == t('Delete')) return;
  if ( $form_state['values']['INTERVAL'] != 0 ) {
    $form_state['values']['rrule_until'] = $form_state['values']['UNTIL']['datetime'];
    if (empty($form_state['values']['rrule_until'])) {
      form_set_error('UNTIL', t('Recurrences must have an end date.'));
    } 
    else {
      $form_state['values']['rrule'] = date_api_ical_build_rrule($form_state['values'], "%d.%m.%y");
    }
  }
  /*
  if ($form_state['values']['type'] == BOOKINGSAPI_UNAVAILABLE ) {
    $conflicts = array();
    $conflicted = bookingsapi_conflict_check($form_state['values'], FALSE, $conflicts, 10); 
    if ($conflicted) {
      // TODO: create theme function
      // get resource name
      $errormsg = '<strong>'.t('Conflicts found').'</strong>'.
          '<p>'.t('The following conflicts with your unavailability:').'</p><ul>';
      foreach ($conflicts as $c) {
        $errormsg .= '<li>'.publicbookings_types_translate($c['type']).': '.$c['name'].', from '.$c['start'].' to '.$c['end'].'</li>';
      }
      $errormsg .= '</ul>';
      form_set_error('basic', $errormsg);
    }
  }
  */
}

// temporarily identical to booking equivalent
function publicbookings_availability_form_submit($form, &$form_state) {
  //publicbookings_availability_form_validate($form, $form_state);

  // If we're deleting, redirect to the deletion page immediately.
  if ($form_state['values']['op'] == t('Delete')) {
    $form_state['redirect'] = array('admin/content/publicbookings/availability/'.$form_state['values']['record_id'].'/delete');
    return;
  }

  $save_result = bookingsapi_availability_save($form_state['values']);
  $t_args = array('%name' => $form_state['values']['name']);
  // no message for BOOKINGSAPI_TIME_CONFLICT, as we should have prevented it before we got here
  switch ($save_result) {
    case SAVED_NEW:
      $op = 'created'; break;
    case SAVED_UPDATED:
      $op = 'updated'; break;
    default:
      $op = 'failed';
  }
  drupal_set_message(t("The availability %name has been $op.", $t_args));
  $form_state['redirect'] = 'admin/content/publicbookings/resource/'.$form_state['values']['resource_id'].'/availability';
}

/**
 * Settings page.
 */
function publicbookings_settings() {
  return drupal_get_form('publicbookings_settings_form');
}

/**
 * Settings form.
 */
function publicbookings_settings_form() {
  $form = array();
  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Basic settings'),
  );
  $form['basic']['publicbookings_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable the public bookings form'),
    '#default_value' => variable_get('publicbookings_enabled', 0),
    '#description' => t('If unchecked, all public request functionality will be disabled.
      The administrative interface will not be affected.'),
  );

  $form['basic']['bookingsapi_time_granularity'] = array(
    '#type' => 'textfield',
    '#title' => t('Time granularity'),
    '#default_value' => variable_get('bookingsapi_time_granularity', 10),
    '#description' => t('The increments for datetime selectors, in minutes.'),
  );

  $form['basic']['bookingsapi_year_range'] = array(
    '#type' => 'textfield',
    '#title' => t('Range of years'),
    '#default_value' => variable_get('bookingsapi_year_range', '0:+1'),
    '#description' => t('The maximal range of years to be displayed for new bookings. Use the format 0:+[number of years from now]. 0:+1 will be this year and the next one.'),
  );
  
  $form['basic']['bookingsapi_resource_tree'] = array(
    '#type' => 'checkbox',
    '#title' => t('Resources are shown as hierarchical tree in the select-field'),
    '#default_value' => variable_get('bookingsapi_resource_tree', false),
  );

  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['advanced']['bookingsapi_using_sql_ts_triggers'] = array(
    '#type' => 'checkbox',
    '#title' => t('Tables have triggers defined for updating the \'created\' and \'modified\' timestamps.'),
    '#default_value' => variable_get('bookingsapi_using_sql_ts_triggers', 0),
    '#description' => t('If checked, the updating of these fields will be delegated entirely to the MySQL triggers.'),
  );

  $form['advanced']['publicbookings_sendmail'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Whether to require email-verification for new (public) bookings - Highly Recommanded.'),
    '#default_value' => variable_get('publicbookings_sendmail',true),
    '#description' => t('If checked, each new public booking requires, that the corresponding mailadress is verified by following a link send in a confirmation email. It is recommanded to leave this checked in order to verify, that mailadresses are correct and bookings serious.'),
  );
  
  $form['advanced']['publicbookings_show_unconfirmed'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Whether to show unconfirmed bookings on the administration page - Recommanded.'),
    '#default_value' => variable_get('publicbookings_show_unconfirmed',true),
    '#description' => t('If checked, the administration page at ').l('admin/content/publicbookings','admin/content/publicbookings').t(' will show bookings with unconfirmed email-adresses. Highly recommanded if unconfirmed bookings conflict with new bookings!'),
  );
  
  $form['advanced']['bookingsapi_potential_conflicts'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Whether potential conflicts (not-strictly unavailable resource, pending booking) conflict with new bookings - NOT Recommanded.'),
    '#default_value' => variable_get('bookingsapi_potential_conflicts',FALSE),
    '#description' => t('If checked, potential conflicts are regarded as conflicts. Potential conflicts are every booking on a unavailable resource (normally limited to strictly unavailable) or conflicts with pending bookings.'),
  );
  
  $form['advanced']['bookingsapi_unconfirmed_conflicts'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Whether unconfirmed bookings conflict with new bookings - NOT Recommanded.'),
    '#default_value' => variable_get('bookingsapi_unconfirmed_conflicts',FALSE),
    '#description' => t('If checked, unconfirmed bookings conflict with new Bookings. Please regard that this allows spammers to disallow your booking system by adding unconfirmed bookings in masses. Use only in controlled internal areas!'),
  );
  
  $form['advanced']['publicbookings_finalized_after_confirm'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Whether confirmed bookings are set to finalized (approved) without an administrator rechecking them - NOT Recommanded.'),
    '#default_value' => variable_get('publicbookings_finalized_after_confirm',FALSE),
    '#description' => t('If checked, new bookings are automatically set to finalized ("approved by an administrator") as soon as they are confirmed. Use only in controlled internal areas if you trust your users to not misuse resources.'),
  );

  $form['advanced']['publicbookings_ajax_display_conflicts'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Display conflicting bookings via AJAX'),
    '#default_value' => variable_get('publicbookings_ajax_display_conflicts',FALSE),
    '#description' => t('If checked, a list of conflicting bookings is returned via AJAX conflict checks.'),
  );
  $form['advanced']['bookingsapi_time_before_booking'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimal time before each booking (min)'),
    '#description' => t('Min. time between the time the booking is made and the start of the booked time'),
    '#default_value' => variable_get('bookingsapi_time_before_booking', 0),
  );

  $form['mail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content of client-mails'),
    '#description' => t('Contains settings for the content of Emails, send to clients. A couple of 
    parameters can be used:
    <ul><li>%passphrase: Contains the passphrase of this booking</li>
    <li>%url: Contains an URL where the client can view and edit the booking</li>
    <li>%name: Contains the name of the booking</li>
    <li>%resource_name: Contains the name of the resource booked</li>
    <li>%start: Contains the start date and time</li>
    <li>%end: Contains the end date and time</li>
    <li>%prefix: Contains the subject-prefix</li>
    <li>%postfix: Contains the subject-postfix</li>
    <li>%header: Contains the body header</li>
    <li>%footer: Contains the body footer</li></ul>'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['all'] = array(
    '#type' => 'fieldset',
    '#title' => 'Content of every client-mail',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['all']['_publicbookings_all_body_header'] = array(
    '#type'  => 'textarea',
    '#title' => t('Email Header'),
    '#description' => t('Header that will be printed with %header and in front of each mail-body.'),
    '#default_value' => variable_get('publicbookings_all_body_header',''),
  );
  $form['mail']['all']['_publicbookings_all_body_footer'] = array(
    '#type'  => 'textarea',
    '#title' => t('Email Footer'),
    '#description' => t('Footer that will be printed with %footer and after each mail-body.'),
    '#default_value' => variable_get('publicbookings_all_body_footer',''),
  );
  $form['mail']['all']['_publicbookings_all_subject_prefix'] = array(
    '#type'  => 'textfield',
    '#title' => t('Email subject prefix'),
    '#description' => t('Prefix that will be printed with %prefix and in front of each subject.'),
    '#default_value' => variable_get('publicbookings_all_subject_prefix',''),
  );
  $form['mail']['all']['_publicbookings_all_subject_postfix'] = array(
    '#type'  => 'textfield',
    '#title' => t('Email subject postfix'),
    '#description' => t('Postfix that will be printed with %postfix and after each subject.'),
    '#default_value' => variable_get('publicbookings_all_subject_postfix',''),
  );


  $form['mail']['confirm'] = array(
    '#type' => 'fieldset',
    '#title' => 'Content of confirmation requests',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['confirm']['_publicbookings_request_confirm_subject'] = array(
    '#type'  => 'textfield',
    '#title' => t('Subject of requests for confirmation'),
    '#default_value' => variable_get('publicbookings_request_confirm_subject',''),
  );
  $form['mail']['confirm']['_publicbookings_request_confirm_body'] = array(
    '#type'  => 'textarea',
    '#title' => t('Body of requests for confirmation'),
    '#default_value' => variable_get('publicbookings_request_confirm_body',''),
  );

  $form['mail']['pending'] = array(
    '#type' => 'fieldset',
    '#title' => 'Booking request now pending review',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['pending']['_publicbookings_request_pending_subject'] = array(
    '#type'  => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('publicbookings_request_pending_subject',''),
  );
  $form['mail']['pending']['_publicbookings_request_pending_body'] = array(
    '#type'  => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('publicbookings_request_pending_body',''),
  );

  $form['mail']['finalized'] = array(
    '#type' => 'fieldset',
    '#title' => 'Booking request finalized',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['finalized']['_publicbookings_request_finalized_subject'] = array(
    '#type'  => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('publicbookings_request_finalized_subject',''),
  );
  $form['mail']['finalized']['_publicbookings_request_finalized_body'] = array(
    '#type'  => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('publicbookings_request_finalized_body',''),
  );

  $form['mail']['denied'] = array(
    '#type' => 'fieldset',
    '#title' => 'Booking request denied',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['denied']['_publicbookings_request_denied_subject'] = array(
    '#type'  => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('publicbookings_request_denied_subject',''),
  );
  $form['mail']['denied']['_publicbookings_request_denied_body'] = array(
    '#type'  => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('publicbookings_request_denied_body',''),
  );

  $form['mail']['updated'] = array(
    '#type' => 'fieldset',
    '#title' => 'Booking request updated',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['updated']['_publicbookings_request_updated_subject'] = array(
    '#type'  => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('publicbookings_request_updated_subject',''),
  );
  $form['mail']['updated']['_publicbookings_request_updated_body'] = array(
    '#type'  => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('publicbookings_request_updated_body',''),
  );

  $form['mail']['cancelled'] = array(
    '#type' => 'fieldset',
    '#title' => 'Booking request now cancelled',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['cancelled']['_publicbookings_request_cancelled_subject'] = array(
    '#type'  => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('publicbookings_request_cancelled_subject',''),
  );
  $form['mail']['cancelled']['_publicbookings_request_cancelled_body'] = array(
    '#type'  => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('publicbookings_request_cancelled_body',''),
  );

  $form['mail']['reset'] = array(
    '#type' => 'fieldset',
    '#title' => 'Reset mail content',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mail']['reset']['publicbookings_mail_reset'] = array(
    '#type' => 'checkbox',
    '#title' => 'Reset every mail to its default',
    '#default_value' => FALSE,
  );

  $form['notify'] = array(
    '#type' => 'fieldset',
    '#title' => t('Notification settings'),
  );

  $form['notify']['publicbookings_notify'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Notify administrator of new bookings.'),
    '#default_value' => variable_get('publicbookings_notify',false),
    '#description' => t('If checked, the administrator will get a copy of each email send to a customer (e.g. confirmation mails)'),
  );
  $form['notify']['publicbookings_notify_address'] = array(
    '#type'  => 'textfield',
    '#title' => t('Address that will recieve notifications.'),
    '#default_value' => variable_get('publicbookings_notify_address',variable_get('site_mail','')),
  );

  $form['#validate'][] = 'publicbookings_settings_validate';

  $form['#submit'][] = 'publicbookings_settings_submit';
  
  return system_settings_form($form);
}

/**
 * Settings form validation.
 */
function publicbookings_settings_validate($form, &$form_state) {
  $errors = publicbookings_validate_settings($form_state['values']);
  if ( count($errors) > 0 ){
    foreach( $errors as $field => $error ) {
      form_set_error($field, $error);
    }
  }
}

/**
 * Checks a set of values wether they are valid settings.
 * @param array $values Values to be checked (equal to $form_state['values'])
 * @returns array Returns a set or errors or an empty error ($field_title => $error)
 */
function publicbookings_validate_settings($values) {
  $errors = array();
  $variables = bookingsapi_variables();

  foreach ( $variables as $n => $stats ) {
    if ( $n == 'publicbookings_mail_reset' ) {
      continue;
    }
    if ( ! array_key_exists($n, $values) ) {
      if ( array_key_exists('_'.$n,$values) ) {
        $name = '_'.$n;
      } else {
        continue;
      }
    } else {
      $name = $n;
    }
    $v = $values[$name];
    switch ($stats['type'] ) {
      case 'bool':
        if ( is_bool($v) || $v == 0 || $v == 1 || strtolower($v) == 'true' || strtolower($v) == 'false' ) {
          break;
        } else {
          $errors[$name] = t('Must be a valid boolean (0,1,true,false)');
          break;
        }
      case 'int':
        if ( ! is_numeric($v) ) {
          $errors[$name] = t('Must be a valid integer.');
        }
        break;
      case 'string':
        if ( ! is_string($v) ) {
          $errors[$name] = t('Must be a valid string.');
        }
        break;
      default:
        watchdog('Public Bookings','Invalid type '.$stats['type'].' in '.$n);
    }
  }
  if (isset($values['publicbookings_notify_address']) && !valid_email_address($values['publicbookings_notify_address'])) {
    $errors['publicbookings_notify_address'] = t('Must be a valid email address.');
  }

  return $errors;
}

function publicbookings_submit_settings($values) {
  $variables = bookingsapi_variables();
  $errors = array();
  $config = array('variables'=>&$variables, 'errors'=>&$errors);
  bookingsapi_extend('publicbookings_config', 'pre_save', $values, $config);

  foreach ( $variables as $n => $stats ) {
    if ( $n == 'publicbookings_mail_reset' ) {
      continue;
    }
    if ( ! array_key_exists($n, $values) ) {
      if ( array_key_exists('_'.$n,$values) ) {
        $name = '_'.$n;
      } else {
        continue;
      }
    } else {
      $name = $n;
    }
    switch ($stats['type'] ) {
      case 'bool':
        $values[$name] = (bool) $values[$name];
        variable_set($n, $values[$name]);
        break;
      case 'int':
        if ( is_numeric($values[$name]) ) {
          $values[$name] = (int) $values[$name];
          variable_set($n, $values[$name]);
        } else {
          $errors[$n] = t('Must be a valid integer.');
        }
        break;
      case 'string':
        $values[$name] = strtr($values[$name],"\r\n","\n");
        $values[$name] = strtr($values[$name],"\n<br>","\n");
        $values[$name] = strtr($values[$name],"<br>\n","\n");
        $values[$name] = strtr($values[$name],"<br>","\n");
        $values[$name] = strtr($values[$name],"\n","\n<br>");
        variable_set($n, $values[$name]);
        break;
      default:
        watchdog('Public Bookings','Invalid type '.$stats['type'].' in '.$n);
    }
  }

  if ($values['publicbookings_mail_reset'] || $values['op'] == t('reset') ) {
    if ( $values['op'] == 'reset' ) {
      variable_del('publicbookings_enabled');
      variable_del('bookingsapi_time_granularity');
      variable_del('bookingsapi_using_sql_ts_triggers');
      variable_del('bookingsapi_year_range');
      variable_del('publicbookings_sendmail');
      variable_del('publicbookings_notify');
      variable_del('publicbookings_notify_address');
      variable_del('bookingsapi_potential_conflicts');
      variable_del('bookingsapi_unconfirmed_conflicts');
      variable_del('publicbookings_show_unconfirmed');
      variable_del('publicbookings_finalized_after_confirm');
    }
    require_once('publicbookings.install');
    publicbookings_variable_init();
  }
  bookingsapi_extend('publicbookings_config', 'post_save', $values, $config);

  return $errors;
}

/**
 * Settings form submit.
 */
function publicbookings_settings_submit($form, &$form_state) {
  publicbookings_submit_settings($form_state['values']);
}


function publicbookings_test_ajax() {
  return drupal_get_form('publicbookings_test_ajax_form');
  // AJAX availability checker
}

function publicbookings_test_ajax_form(&$form_state, $booking = array()) {
  $form = array();
  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Booking record'),
  );
  $form['basic']['resource_id'] = array(
    '#type' => 'bookingsapi_resource_select',
    '#default_value' => 0,
  );
  drupal_add_js(drupal_get_path('module', 'publicbookings') . '/js/resource.js');
  $form['basic']['ajax_display'] = array(
    '#value' => '<div id="ajax-display">&nbsp;</div>',
  );

  return $form;
}



  /*
  variable_set('bookingsapi_time_before_booking', (int) $values['bookingsapi_time_before_booking']);
  variable_set('bookingsapi_time_granularity', (int) $values['bookingsapi_time_granularity']);

  variable_set('publicbookings_enabled', (bool) $values['publicbookings_enabled']);
  variable_set('bookingsapi_using_sql_ts_triggers', (bool) $values['bookingsapi_using_sql_ts_triggers']);
  variable_set('publicbookings_sendmail', (bool) $values['publicbookings_sendmail']);
  variable_set('publicbookings_notify', (bool) $values['publicbookings_notify']);
  variable_set('publicbookings_notify_address', (bool) $values['publicbookings_notify_address']);
  variable_set('publicbookings_show_unconfirmed', (bool) $values['publicbookings_show_unconfirmed']);
  variable_set('bookingsapi_unconfirmed_conflicts', (bool) $values['bookingsapi_unconfirmed_conflicts']);
  variable_set('bookingsapi_potential_conflicts', (bool) $values['bookingsapi_potential_conflicts']);
  variable_set('publicbookings_finalized_after_confirm', (bool) $values['publicbookings_finalized_after_confirm']);
  variable_set('publicbookings_ajax_display_conflicts', (bool) $values['publicbookings_ajax_display_conflicts']);
  */
  /*
  else {
    variable_set('publicbookings_all_subject_prefix', $values['_publicbookings_all_subject_prefix']);
    variable_set('publicbookings_all_subject_postfix', $values['_publicbookings_all_subject_postfix']);
    variable_set('publicbookings_all_body_header', $values['_publicbookings_all_body_header']);
    variable_set('publicbookings_all_body_footer', $values['_publicbookings_all_body_footer']);
    variable_set('publicbookings_request_confirm_subject', $values['_publicbookings_request_confirm_subject']);
    variable_set('publicbookings_request_confirm_body', $values['_publicbookings_request_confirm_body']);
    variable_set('publicbookings_request_pending_subject', $values['_publicbookings_request_pending_subject']);
    variable_set('publicbookings_request_pending_body', $values['_publicbookings_request_pending_body']);
    variable_set('publicbookings_request_finalized_subject', $values['_publicbookings_request_finalized_subject']);
    variable_set('publicbookings_request_finalized_body', $values['_publicbookings_request_finalized_body']);
    variable_set('publicbookings_request_denied_subject', $values['_publicbookings_request_denied_subject']);
    variable_set('publicbookings_request_denied_body', $values['_publicbookings_request_denied_body']);
    variable_set('publicbookings_request_updated_subject', $values['_publicbookings_request_updated_subject']);
    variable_set('publicbookings_request_updated_body', $values['_publicbookings_request_updated_body']);
    variable_set('publicbookings_request_cancelled_subject', $values['_publicbookings_request_cancelled_subject']);
    variable_set('publicbookings_request_cancelled_body', $values['_publicbookings_request_cancelled_body']);
  }
  */
