<?php
// $Id: postmark.drupal.inc,v 1.2 2011/01/10 15:04:42 luketsimmons Exp $

/**
 * @file
 * Implements postmark support on behalf of Drupal core.
 */
define('POSTMARKAPP_API_KEY', variable_get('postmark_api_key', ''));

if (module_load_include('php', 'postmark', 'includes/Postmark')) {
  drupal_set_message('You must include the Postmark PHP5 library to use this module. See README.txt for more details.', 'error');
}

/**
 * Send out an e-mail.
 *
 * @param $message
 *   Message array structure.
 */
function postmark_send($message) {
  static $mail;

  if (!isset($mail)) {
    $mail = new Mail_Postmark();
  }

  // Parse 'From' e-mail address.
  $address = postmark_parse_address($message['from']);

  $mail->from($address[0]['mail']);
  if ($address[0]['name'] != '') {
    $mail->fromName($address[0]['name']);
  }
  unset($message['headers']['From']);

  // Set up our debugging mode vars
  $debug_mode = variable_get('postmark_debug_mode', 0);
  $debug_email = variable_get('postmark_debug_email', '');
  if (!$debug_mode) {
    // Set recipients.
    foreach (postmark_parse_address($message['to']) as $id => $address) {
      // For the first email set as initial 'To'
      if ($id == 0) {
        $mail->to($address['mail'], $address['name']);
      }
      // Otherwise we must add to the array
      else {
        $mail->addTo($address['mail'], $address['name']);
      }    
    }
  }
  else {
    // Reroute to debug e-mail address.
    if ($debug_email != '') {
      drupal_set_message(t('Debugging email used @email', array('@email' => $debug_email)), 'warning');
      $mail->to($debug_email);
    }
  }

  $mail->subject($message['subject']);
  // Check the header content type to see if email is plain text
  // if not we send as HTML
  if (strpos($message['headers']['Content-Type'], 'text/plain') !== FALSE) {
    $mail->messagePlain($message['body']);
  }
  else {
    $mail->messageHtml($message['body']);
  }

  // If debug mode is on, output the message
  if ($debug_mode) {
    drupal_set_message('Message array: <pre>'. print_r($message, TRUE) .'</pre>', 'warning');    
  }

  // If the debug option of not sending a credit, i.e.
  // for testing, is switched on just return TRUE,
  // otherwise send the email via Postmark
  if (variable_get('postmark_debug_no_send', 0)) {
    drupal_set_message('Email successfully tested, no email has been sent (no credits used)', 'warning');
    return TRUE;
  }
  else {
    try {
      if (!($result = $mail->send())) {
        watchdog('postmark', "Mail sending error: $mail->ErrorInfo", NULL, WATCHDOG_ERROR);
      }
    }
    catch (Exception $e) {
      watchdog('postmark', 'Exception message: '. $e->getMessage(), NULL, WATCHDOG_ERROR);
      drupal_set_message('Mail sending error: '. $e->getMessage(), 'error');
      // If debugging is on let's put the whole exception into watchdog
      // to enable closer inspection
      if ($debug_mode) {
        watchdog('postmark', 'Exception caught: <pre>'. print_r($e, TRUE) .'</pre>', NULL, WATCHDOG_ERROR);
      }
    }
  }
  return $result;
}
