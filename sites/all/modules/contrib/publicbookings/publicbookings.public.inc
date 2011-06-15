<?php
/**
 * @file
 * Public Bookings - Public interface
 */

function publicbookings_clientinfo_form($values, &$form_state=array()) {
  $form = array();
  if ( isset($form_state['values']) ) {
    $values = $form_state['values'] + $values;
  }
  $form['client'] = array(
    '#title' => t('Your details'),
    '#type' => 'fieldset',
  );
  $form['client']['client_id'] = array(
    '#type' => 'value',
    '#value' => $values['client_id'],
  );
  $form['client']['title'] = array(
    '#title' => t('Title'),
    '#type'  => 'select',
    '#options' => publicbookings_title(),
    '#default_value' => 0,
  );
  $form['client']['first_name'] = array(
    '#title' => t('First name'),
    '#type' => 'textfield',
    '#default_value' => $values['first_name'],
    '#required' => TRUE,
  );
  $form['client']['last_name'] = array(
    '#title' => t('Last name'),
    '#type' => 'textfield',
    '#default_value' => $values['last_name'],
  );
  $form['client']['phone'] = array(
    '#title' => t('Phone number'),
    '#type' => 'textfield',
    '#description' => t('20 digits.'),
    '#default_value' => $values['phone'],
  );
  $form['client']['email'] = array(
    '#title' => t('Email address'),
    '#type' => 'textfield',
    '#description' => t('Your booking will be confirmed by email.'),
    '#default_value' => $values['email'],
    '#required' => TRUE,
  );
  $form['client']['comments'] = array(
    '#title' => t('Special instructions or comments'),
    '#type' => 'textarea',
    '#description' => t('If this booking has any special requirements, specify them here.'),
    '#default_value' => $values['comments'],
  );
  if(isset($values['created'])) {
    $form['client']['created'] = array(
      '#type' => 'item',
      '#title' => t('Created'),
      '#value' => $values['created'],
    );
    $form['client']['changed'] = array(
      '#type' => 'item',
      '#title' => t('changed'),
      '#value' => $values['changed'],
    );
  }
  $form['client']['#validate'] = array('publicbookings_clientinfo_form_validate');

  return $form;
}

function publicbookings_clientinfo_form_validate($form, &$form_state) {
  // remove all non-digits
  $form_state['values']['phone'] = preg_replace('/\D/','',$form_state['values']['phone']);
  if ( strlen($form_state['values']['phone']) > 20 ) {
    form_set_error('client', 'Phonenumber may not be longer then 20 characters.');
  }
  if ( ! is_numeric($form_state['values']['title']) || is_array(publicbookings_title($form_state['values']['title'])) ) {
    form_set_error('title', 'Please select one of the given salutations');
  }
}

function publicbookings_passphrase_form() {
  $form = array();
  $form['client'] = array(
    '#title' => t('Update request'),
    '#type' => 'fieldset',
  );
  $form['client']['passphrase'] = array(
    '#title' => t('Passphrase'),
    '#type' => 'textfield',
    '#description' => t('Your booking request\'s passphrase is found in your initial confirmation email.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Proceed'),
  );
  $form['#validate'] = array('publicbookings_passphrase_validate');
  $form['#submit'] = array('publicbookings_passphrase_submit');
  return $form;
}

function publicbookings_request_form(&$form_state, $values) {
  include_once('./'. drupal_get_path('module', 'bookingsapi') .'/bookingsapi.forms.inc');
  $form = array_merge(bookingsapi_booking_form($values), publicbookings_clientinfo_form($values));
  $form['basic']['#title'] = t('Booking request');
  // until email confirmation, the status is UNCONFIRMED. afterwards, it becomes PENDING.
  // unless publicbookings_finalized_after_confirm is set, the its unconfirmed or finalized
  $form['basic']['status'] = array(
    '#type' => 'value',
    '#value' => array_key_exists('status',$values) 
                && $values['status'] != BOOKINGSAPI_STATUS_UNCONFIRMED 
                ? variable_get('publicbookings_finalized_after_confirm',false) ?
                    BOOKINGSAPI_STATUS_FINALIZED :
                    BOOKINGSAPI_STATUS_PENDING 
                : BOOKINGSAPI_STATUS_UNCONFIRMED,
  );
  if (empty($values['start']) && empty($values['end'])) {
    $default_date = date_format(date_now(), DATE_DATETIME);
    $form['basic']['start']['#default_value'] = $default_date;
    $form['basic']['end']['#default_value'] = $default_date;
  }

  // repeat functionality is probably unnecessary for public use
  unset($form['basic']['rrule']);

  if (!empty($values)) {
    // clients don't have option to delete
    unset($form['delete']);

    // for consistency, do not allow the changing of the requested resource, or the client email
    if (isset($values['resource_id']) ) {
      $form['basic']['resource_id']['#disabled'] = TRUE;
      $form['basic']['resource_id']['#value'] = $form['basic']['resource_id']['#default_value'];
    }
    if (isset($values['record_id']) ) {
      $form['client']['email']['#disabled'] = TRUE;
      $form['client']['email']['#value'] = $form['client']['email']['#default_value'];
    }
 } 

  // implement later
  unset($form['basic']['priority']);

  // AJAX availability checker
  drupal_add_js(drupal_get_path('module', 'publicbookings') . '/ajax.js');
  $form['basic']['ajax_display'] = array(
    '#value' => '<div id="ajax-availability">Enable JavaScript.</div>',
  );
/*
  $form['basic']['check'] = array(
    '#title' => t('Availability check'),
    '#type' => 'fieldset',
  );
  $form['basic']['check']['button'] = array(
      '#type' => 'button',
      '#value'=> t('Check avail'),
      '#ahah'  => array(
        'path'    => 'publicbookings/ajax/availability',
        'wrapper' => 'avail-wrapper',
        'progress'=> array('type' => 'bar', 'message' => t('Checking..')),
      ),
    );

  $form['basic']['check']['ajax_display'] = array(
    '#prefix' => '<br><div id="avail-wrapper">',
    '#suffix' => '</div>',
    '#value'  => '&nbsp;',
    );
 */

  $form['#validate'][] = 'publicbookings_request_form_validate';
  $form['#submit'] = array('publicbookings_request_form_submit');

  $form['submit'] = array(
    '#type' => 'submit',
    '#weight' => 8,
  );
  if(empty($values['record_id'])) {
    $form['submit']['#value'] = t('Submit request');
  } else {
    $form['submit']['#value'] = t('Update request');
    $form['cancel'] = array(
      '#type' => 'submit',
      '#validate' => array('publicbookings_request_form_cancel'),
      '#weight' => 9,
      '#value' => t('Cancel request'),
    );
  }
  return $form;
}

function publicbookings_request_form_cancel($form, &$form_state) {
  $form_state['values']['status'] = BOOKINGSAPI_STATUS_CANCELLED;
  publicbookings_request_form_validate($form, $form_state);
}

function publicbookings_request_form_validate($form, &$form_state) {
  $form_state['values']['phone'] = preg_replace('/\D/','',$form_state['values']['phone']);
  if ( ! $form_state['#submitted'] ) {
    return;
  }
  if ( strlen($form_state['values']['phone']) > 20 ) {
    form_set_error('client', 'Phonenumber may not be longer then 20 characters.');
  }
  publicbookings_conflict_check($form_state['values']);
  if ($form_state['values']['count_all_conflicts'] > 0 && 
        ( variable_get('bookingsapi_unconfirmed_conflicts',false) || variable_get('bookingsapi_pending_conflicts',false)) ) {
    form_set_error('basic', $form_state['values']['html_all_conflicts']);
  } else if ($form_state['values']['count_certain_conflicts'] > 0) {
    form_set_error('basic', $form_state['values']['html_certain_conflicts']);
  }
}

function publicbookings_request_form_submit($form, &$form_state) {
  $save_result = publicbookings_booking_save($form_state['values']);
  $t_args = array('%name' => $form_state['values']['name']);
  $blurb = '';
  // no message for BOOKINGSAPI_TIME_CONFLICT, as we should have prevented it before we got here
  $type = 'status';
  if ( ! $save_result[0] ) {
    $blurb .= '<p>'.t('A conflict occured while saving your request. Please try again in a few minutes').'</p>';
    $type = 'error';
  } else {
    switch ($save_result[1]) {
      case SAVED_NEW:
        $op = t('submitted');
        if (variable_get('publicbookings_sendmail',true)) {
          $blurb .= '<p>'.t('A confirmation link has been sent to your email address.
              Check your email and visit the link to proceed.').'</p>';
        }
        else {
          $blurb .= '<p>'.t('Your booking has been submitted. A confirmation has been sent to your email address.').'</p>';
        }
        break;
      case SAVED_UPDATED:
        $op = t('updated');
        sess_write('publicbookings_authed_req_id', NULL);
        break;
    }
    $blurb = '<p>'.t("Your booking request %name has been ", $t_args).$op.'.</p>' . $blurb;
  }
  $form_state['redirect'] = 'publicbookings/overview';
  drupal_set_message($blurb,$type);
}

function publicbookings_public_overview_page() {
  include_once('publicbookings.views_default.inc');

  $text = '<h3>'.t('Currently occupied').'</h3>';
  $view = publicbookings_view_currently_happening();
  $text .= $view->render();

  $text .= '<h3>'.t('Upcoming').'</h3>';
  $view = publicbookings_view_upcoming();
  $text .= $view->render();

  return $text;
}

function publicbookings_public_request_add($id = NULL) {
  if (variable_get('publicbookings_enabled', 0) == 0) {
    return publicbookings_public_disabled_message();
  }
  if ( $id == NULL ) {
    return drupal_get_form('publicbookings_request_form', array());
  } else {
    return drupal_get_form('publicbookings_request_form', array('resource_id'=>$id));
  }
}

function publicbookings_public_passphrase() {
  if (variable_get('publicbookings_enabled', 0) == 0) {
    return publicbookings_public_disabled_message();
  }

  $blurb = '<p>'.t('To update or cancel your booking request, enter the unique passphrase associated with your booking.').'</p>'.
           '<p>'.t('If you have lost your passphrase, or if your booking status has already been set to finalized, contact
           an administrator to make changes.').'</p>';
  return $blurb . drupal_get_form('publicbookings_passphrase_form');
}

function publicbookings_passphrase_validate($form, &$form_state) {
  $sql = "SELECT * FROM {publicbookings_clients} WHERE passphrase='%s'";
  $q = db_query($sql, $form_state['values']['passphrase']);
  $client = db_fetch_array($q);
  if ($client == FALSE) {
    form_set_error('passphrase', t('Invalid passphrase.'));
  } else {
    $form_state['client'] = $client;
  }
}

function publicbookings_confirm($passphrase) {
  if (variable_get('publicbookings_enabled', 0) == 0) {
    return publicbookings_public_disabled_message();
  }


// This is actually a quite annoying function
// This SQL-statement is most likely the most performant method to get the complete Resource-Set
// But then: Confirms are rare and using API-calls (like bookingsapi_resource_load or publicbookings_record_load) would
// be much easier to maintain.
//
// TODO: REWRITE

  $sql = "SELECT record_id, email, passphrase FROM {publicbookings_clients} WHERE passphrase = '%s'";
  $q = db_query($sql, $passphrase);
  $client = db_fetch_array($q);
  if ($client == FALSE) {
    return '<p>'.t('Invalid passphrase. Verify the link in your confirmation email.').'</p>';
  } else {
    $record   = bookingsapi_record_load($client['record_id']);
    $resource = bookingsapi_resource_load($record['resource_id']);

  // record_id, email and passphrase are already set
    $client['resourceName'] = $resource->title;
    $client['start'] = $record['start'];
    $client['end'] = $record['end'];
    $client['eventName'] = $record['name'];
    $client['resource_id'] = $record['resource_id'];

    $values = array(
      'name'=>$client['eventName'],
      'resource_name'=>$client['resourceName'],
      'start'=>$client['start'],
      'end'=>$client['end'],
      'passphrase'=>$passphrase,
    );

    $msg = "";
    if ( variable_get('publicbookings_finalized_after_confirm',false) ) {
      // Add conflict checking
      $conflicts = bookingsapi_conflict_check($client);
      if ( in_array($conflicts, bookingsapi_booking_conflicting_status()) ) {
        $msg = t('Conflicts with your booking exist, your booking will be set to PENDING');
      } else {
        bookingsapi_record_status_change($client, BOOKINGSAPI_STATUS_FINALIZED);
        _publicbookings_send_mail('request_finalized', $client['email'], $values);
        return '<p>'.t('Your email has been verified. Your booking request is now finalized.
            You will be informed of any status changes by email').'</p>';
      }
    } 
    
    bookingsapi_record_status_change($client, BOOKINGSAPI_STATUS_PENDING);
    _publicbookings_send_mail('request_pending', $client['email'], $values);
    return '<p>'.t('Your email has been verified. Your booking request is now pending review by a booking manager.
        You will be informed of any status changes by email').'</p><p>'.$msg.'</p>';
  }
}

function publicbookings_passphrase_submit($form, &$form_state) {
  session_save_session(TRUE);
  sess_write('publicbookings_authed_req_id', $form_state['client']['client_id']);
  $form_state['redirect'] = 'publicbookings/request/'.$form_state['client']['client_id'].'/update';
}

function publicbookings_public_request_update($client) {
  if(sess_read('publicbookings_authed_req_id') != $client['client_id']) {
    return drupal_access_denied();
  }
  $booking = bookingsapi_booking_load($client['record_id']);
  $values = array_merge($booking, $client);
  return drupal_get_form('publicbookings_request_form', $values);
}

function publicbookings_public_schedules() {
  include_once('publicbookings.views_default.inc');
  $view = publicbookings_view_schedules();
  return $view->render();
}

function publicbookings_public_resources() {
  include_once('publicbookings.views_default.inc');
  $view = publicbookings_view_resources();
  return $view->render();
}

function publicbookings_public_disabled_message() {
  $blurb = t('The public booking system is currently disabled. Try again later.');
  $blurb = '<p>'.$blurb.'</p>';
  return $blurb;
}
