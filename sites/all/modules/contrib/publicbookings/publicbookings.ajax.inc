<?php
/**
 * @file
 * Public Bookings AJAX conflict-checking functions.
 */

module_load_include('module', 'publicbookings');

/**
 * List resources or resource information.
 * 
 * <p>If no parameter is given returns a list of resources as JSON-Array</p>
 * <p>One parameter resource_id may be given as url-parameter by adding /[value] 
 * or via POST, it may be one of:<ul>
 * <li><b>BOOLEAN</b> Whether only active resources should be returned.</li>
 * <li><b>INTEGER</b> ID of the resource to show additional information for.</li>
 * <li><b>STRING</b> If the string 'tree' is given a tree of resources is returned.</li>
 * </ul></p>
 * <p>Alternatively you may give the int-parameter <b>parent_id</b> which
 * will show all *childs of this resource (via GET)</p>
 * <p>For a single resource this will show:<ul>
 * <li><b>nid</b> ID of this resource</li>
 * <li><b>language</b> Content-language of this resource</li>
 * <li><b>title</b> Name of the resource</li>
 * <li><b>bookable</b> Whether this resource is bookable or deactivated.</li>
 * <li><b>location</b> Location of this resource.</li>
 * <li><b>body</b> Description of this resource.</li>
 * </ul>For a list of resources this will give an array containing 
 * numeric keys (resource-ids) and the resource titles.</p>
 * <p>Access to this is possible via BASE_PATH/publicbookings/ajax/resource/list</p>
 */
function publicbookings_ajax_resource_list( $resourceID = NULL ) {
  if ( is_null($resourceID) && array_key_exists('resource_id', $_POST) && 
      ( is_bool($_POST['resource_id']) || is_numeric($_POST['resource_id']) )) {
    $resourceID = (int) $_POST['resource_id'];
  }
  if ( is_numeric($_GET['parent_id']) ) {
    $res = bookingsapi_resource_get_nchilds((int) $_GET['parent_id']);
    $res[] = (int) $_GET['parent_id'];
    drupal_json(bookingsapi_resource_entitle($res));
    return;
  }
  if ( is_null($resourceID) || is_bool($resourceID) || $resourceID == 0 ) {
    if ( $_GET['restaurant_id'] == 'tree' ) {
      module_load_include('forms.inc','bookingsapi');
      $arr = array('tree'=>TRUE);
      $arr = bookingsapi_resource_select_process($arr,NULL);
      unset($arr['#options'][0]);
      drupal_json($arr['#options']);
      return;
    }
    $list = bookingsapi_resource_minimal_list( $resourceID === TRUE || $resourceID == 'TRUE' );
    drupal_json($list);
    return;
  } else {
    $res = bookingsapi_resource_load($resourceID);
    $ret = array();
    $ret['nid']       = $res->nid;
    $ret['language']  = $res->language;
    $ret['title']     = $res->title;
    $ret['bookable']  = $res->status;
    $ret['location']  = $res->field_ba_location[0]['value'];
    $ret['body']      = $res->body;

    $config = array('type'=>'ajax','limit'=>1,'element'=>$res);
    bookingsapi_extend('bookingsapi_resource','list',$ret,$config);

    drupal_json( $ret );
  }
}

/**
 * Check for conflicts, reading from $_POST and returning via drupal_json.
 *
 * <p>Needs at least the parameters, all given via POST:<ul>
 * <li><b>resource_id</b> (integer, defining the ID of the resource controlled)</li>
 * <li><b>start</b> (UNIXTIME or DATE_ARRAY, defining the starttime)</li>
 * <li><b>end</b> (UNIXTIME or DATE_ARRAY, defining the endtime)</li></ul>
 * The integer parameter <b>record_id</b> may be given to check whether an update
 * of an existing booking is possible.</p>
 * <p>This will return an JSON-Array containing two or three keys:<ul>
 * <li><b>count_certain_conflicts</b> (Integer) Number of certain conflicts found.</li>
 * <li><b>count_potential_conflicts</b> (Integer) Number of potential conflicts found.</li>
 * <li><b>html_all_conflicts</b> (HTML) If Public Bookings is configured accordingly, this key will contain HTML to display the conflicting bookings.</li>
 * </ul></p>
 * <p>To check repeating bookings the following parameters can be used, an
 * asterisk (*) denotes needed parameters. For explanation please have a look at the date_repeat module.<ul>
 * <li>UNTIL['datetime'] - DATE_ARRAY of the enddate</li>
 * <li>INTERVAL*</li>
 * <li>FREQ*</li>
 * <li>BYMONTH*</li>
 * <li>BYMONTHDAY*</li>
 * <li>BYDAY*</li>
 * <li>EXCEPTIONS - array</li>
 * </ul></p>
 * <p>Access to this is possible via BASE_PATH/publicbookings/ajax/availability</p>
 */
function publicbookings_ajax_availability($noPrint = FALSE ) {
  if ( ! is_numeric($_POST['resource_id']) ) {
    drupal_json(t('Error, invalid data, need resource_id'));
    return;
  }
  $params['resource_id'] = (int) $_POST['resource_id'];
  if ( array_key_exists('record_id', $_POST) && is_numeric($_POST['record_id']) ) {
    $params['record_id']   = (int) $_POST['record_id'];
  }

  if (is_array($_POST['start']) && is_array($_POST['end'])) {
    foreach ($_POST['start'] as &$v) {
      $v = (int) $v;
    }
    foreach ($_POST['end'] as &$v) {
      $v = (int) $v;
    }
  } else if ( ! is_numeric($_POST['start']) || ! is_numeric($_POST['end']) ) {
    // invalid start or end - quit
    drupal_json(t('Error, invalid data. Need start and end.'));
    return;
  }

  if ( is_array($_POST['start']) ) {
    $params['start']      = date_convert($_POST['start'], DATE_ARRAY, DATE_DATETIME);
  } else {
    $params['start']      = date_convert($_POST['start'], DATE_UNIX, DATE_DATETIME);
  }
  if ( is_array($_POST['end']) ) {
    $params['end']      = date_convert($_POST['end'], DATE_ARRAY, DATE_DATETIME);
  } else {
    $params['end']      = date_convert($_POST['end'], DATE_UNIX, DATE_DATETIME);
  }

  $params['UNTIL']      = $_POST['UNTIL'];
  $params['INTERVAL']   = $_POST['INTERVAL'];
  $params['FREQ']       = $_POST['FREQ'];
  $params['BYMONTH']    = $_POST['BYMONTH'];
  $params['BYMONTHDAY'] = $_POST['BYMONTHDAY'];
  $params['BYDAY']      = $_POST['BYDAY'];

  if ( is_array($_POST['EXCEPTIONS']) ) {
    foreach( $_POST['EXCEPTIONS'] as $key => $value ) {
      if ( is_int($key) ) {
        $params[$key] = $value;
      }
    }
  }

  if ( is_array($params['UNTIL']) ) {
    $until = $params['UNTIL']['datetime'];
    //  $exdate0 = $_POST[0]['datetime'];
    if (empty($until['year']) || empty($until['month']) || empty($until['day'])) {
      // invalid RRULE because there's no valid UNTIL
    } else {
      include_once('./'. drupal_get_path('module', 'date_repeat') .'/date_repeat_form.inc');
      include_once('./'. drupal_get_path('module', 'date_api') .'/date_api_ical.inc');

      // date_repeat_rrule_validate runs this before building RRULE, so we do this too.
      //    $processed = date_repeat_merge($params, $params['UNTIL']);
      $params['UNTIL']['datetime'] = date_convert($params['UNTIL']['datetime'], DATE_ARRAY, DATE_DATETIME);
      $params[0]['datetime'] = date_convert($params[0]['datetime'], DATE_ARRAY, DATE_DATETIME);

      // if first EXDATE is invalid, unset the entire EXDATE array to prevent errors
      if ($params[0]['datetime'] == '0000-00-00 00:00:00') {
        unset($params[0]);
      }

      $params['rrule']       = date_api_ical_build_rrule( $params );
      $params['rrule_until'] = bookingsapi_rrule_until_as_dt($params['rrule']);
    }
  } else {
    $params['rrule'] = '';
    $params['rrule_until'] = '';
  }

  publicbookings_conflict_check($params);
  $res =  array( 
                 'count_certain_conflicts'   => $params['count_certain_conflicts'],
                 'count_potential_conflicts' => $params['count_potential_conflicts'],
                 'html_all_conflicts'        => $params['html_all_conflicts'],
               );

  if ( !$noPrint ) {
    drupal_json($res);
    return;
  } else {
    $res['params'] = $params;
    return $res;
  }
}

/**
 * Save a booking (new or update), reading from $_POST and returning via drupal_json.
 *
 * <p>The first step of this method is calling publicbookings_ajax_availability.
 * If a conflict is found, the errors from publicbookings_ajax_availability are 
 * returned. Please see above method for information regarding the booking
 * time and date.</p>
 * <p>If an existing booking should be changed, provide record_id and the matching
 * passphrase.</p>
 * <p>Additional client-information (* marks needed parameters):<ul>
 * <li><b>name*</b> Name of the event.</li>
 * <li><b>description</b> Description of the event.</li>
 * <li><b>first_name</b> First name of the client.</li>
 * <li><b>last_name*</b> Last name of the client.</li>
 * <li><b>email*</b> Email-address of the client.</li>
 * <li><b>comments</b> Comments to the client.</li>
 * <li><b>record_id</b> ID of the record (for changes).</li>
 * <li><b>passphrase</b> Passphrase of the record (for changes).</li>
 * </ul></p>
 * <p>Access to this is possible via BASE_PATH/publicbookings/ajax/booking/save</p>
 * @see publicbookings_ajax_availability
 */
function publicbookings_ajax_booking_save() {
  $checkRes = publicbookings_ajax_availability(TRUE);
  $params = $checkRes['params'];
  unset($checkRes['params']);

  // Conflicts? Cancel booking.
  if ( $checkRes['count_certain_conflicts'] > 0 ) {
    drupal_json($checkRes);
    return;
  }

  if ( $params['record_id'] ) {
    $passphrase = (string) $_POST['passphrase'];
    if ( is_null($passphrase) || strlen($passphrase) == 0 || 
      ! publicbookings_confirm_passphrase_correct($params['record_id'], $passphrase) ) {
        drupal_json("Error: Invalid passphrase given.");
        return;
    }
  }

  // $params already contains all date-related information
  // we need to add client-information.

  if ( is_string($_POST['name']) ) {
    $params['name'] = $_POST['name'];
  } else {
    drupal_json("Error: Need an event name.");
    return;
  }

  foreach ( array('description', 'first_name', 'last_name', 'phone', 'email', 'comments') as $key ) {
    if ( is_string($_POST[$key]) ) {
      $params[$key] = $_POST[$key];
    }
  }

  if ( ! (isset($params['last_name']) && isset($params['email'])) ) {
    drupal_json("Error: Need customer name and email.");
    return;
  }

  $ret = publicbookings_booking_save($params);

  if ( $ret[0] ) {
    drupal_json("Success");
  } else if ( $ret[1] == BOOKINGSAPI_TIME_CONFLICT ) {
    drupal_json("Conflicting booking found.");
  } else {
    drupal_json("Booking not possible");
  }
}

/**
 * Read a booking (identified via passphrase), reading from $_GET and returning via drupal_json.
 *
 * <p>Parameters (* marks needed parameters)<ul>
 * <li><b>passphrase*</b> Passphrase of the booking as presented in the confirmation e-mail</li>
 * <li><b>full</b> If set the full record is returned, otherwise only the record id</li>
 * </ul></p>
 * <p>Access to this is possible via BASE_PATH/publicbookings/ajax/booking/read</p>
 * @see publicbookings_ajax_availability
 */
function publicbookings_ajax_readbooking() {
  if ( is_string($_GET['passphrase']) ) {
    $passphrase = (string) $_GET['passphrase'];
  } else {
    drupal_json(t('Error: Need a passphrase'));
    return;
  }
  if ( array_key_exists('full', $_GET) ) {
    $full = TRUE;
  } else {
    $full = FALSE;
  }
  drupal_json(publicbookings_from_passphrase($passphrase, $full));
}


/**
 * Create or change an availability or unavailability.
 *
 * <p>Parameters are read from $_POST and output is given via drupal_json.<br>
 * <p>Needs at least the parameters, all given via POST:<ul>
 * <li><b>resource_id</b> (integer, defining the ID of the resource controlled)</li>
 * <li><b>start</b> (UNIXTIME, DATETIME or DATE_ARRAY, defining the starttime)</li>
 * <li><b>end</b> (UNIXTIME, DATETIME or DATE_ARRAY, defining the endtime)</li>
 * <li><b>type</b> May be one of <b>2</b> - UNavailable or <b>3</b> Available</li>
 * <li><b>name</b> The name of this (un)availability</li>
 * </ul>
 * The integer parameter <b>record_id</b> may be given to check whether an update
 * of an existing record is possible.</p>
 * <p>This will return an JSON-Array containing a boolean (wether the record could be saved) and a save-type.</p>
 * <p>To check repeating bookings the following parameters can be used, an
 * asterisk (*) denotes needed parameters. For explanation please have a look at the date_repeat module.<ul>
 * <li>UNTIL['datetime'] - DATE_ARRAY of the enddate</li>
 * <li>INTERVAL*</li>
 * <li>FREQ*</li>
 * <li>BYMONTH*</li>
 * <li>BYMONTHDAY*</li>
 * <li>BYDAY*</li>
 * <li>EXCEPTIONS - array</li>
 * <li>description</li>
 * </ul></p>
 * <p>Access to this is possible via BASE_PATH/publicbookings/ajax/resource_availability</p>
 * @see bookingsapi_availability_save
 */
function publicbookings_ajax_resource_availability($noPrint = FALSE ) {
  $params = array();

  if ( is_numeric($_REQUEST['type']) ) {
    $_REQUEST['type'] = (int) $_REQUEST['type'];
  }
  if ( in_array($_REQUEST['type'], array_keys(bookingsapi_record_types())) && $_REQUEST['type'] != BOOKINGSAPI_BOOKING ) {
    $params['type'] = $_REQUEST['type'];
  } else {
    if ( $noPrint ) {
      return FALSE;
    } else {
      drupal_json(array(FALSE,t('Error, invalid type. Need 2 or 3.')));
      return;
    }
  }

  if (is_array($_POST['start']) ) {
    foreach ($_POST['start'] as &$v) {
      $v = (int) $v;
    }
  }
  if ( is_array($_POST['end'])) {
    foreach ($_POST['end'] as &$v) {
      $v = (int) $v;
    }
  }
  
  if ( is_array($_POST['start']) ) {
    $params['start']      = date_convert($_POST['start'], DATE_ARRAY, DATE_DATETIME);
  } else if ( is_numeric($_POST['start']) ) {
    $params['start']      = date_convert((int)$_POST['start'], DATE_UNIX, DATE_DATETIME);
  } else if ( is_string($_POST['start']) && preg_match(DATE_REGEX_LOOSE, $_POST['start']) ) {
    $params['start'] = $_POST['start'];
  } else {
    if ( $noPrint ) {
      return FALSE;
    } else {
      drupal_json(array(FALSE,t('Error, invalid data. Need start.')));
      return;
    }
  }

  if ( is_array($_POST['end']) ) {
    $params['end']      = date_convert($_POST['end'], DATE_ARRAY, DATE_DATETIME);
  } else if ( is_numeric($_POST['end']) ) {
    $params['end']      = date_convert((int)$_POST['end'], DATE_UNIX, DATE_DATETIME);
  } else if ( is_string($_POST['end']) && preg_match(DATE_REGEX_LOOSE, $_POST['end']) ) {
    $params['end'] = $_POST['end'];
  } else {
    if ( $noPrint ) {
      return FALSE;
    } else {
      drupal_json(array(FALSE,t('Error, invalid data. Need end.')));
      return;
    }
  }
  
  $params['name'] = trim(htmlspecialchars((string)$_POST['name']));
  if ( strlen($params['name']) <= 0 || ! is_string($params['name']) ) {
    drupal_json(array(FALSE,t('Error, invalid data. Need name.')));
    return;
  }

  $params['UNTIL']      = $_POST['UNTIL'];
  $params['INTERVAL']   = $_POST['INTERVAL'];
  $params['FREQ']       = $_POST['FREQ'];
  $params['BYMONTH']    = $_POST['BYMONTH'];
  $params['BYMONTHDAY'] = $_POST['BYMONTHDAY'];
  $params['BYDAY']      = $_POST['BYDAY'];

  if ( is_array($_POST['EXCEPTIONS']) ) {
    foreach( $_POST['EXCEPTIONS'] as $key => $value ) {
      if ( is_int($key) ) {
        $params[$key] = $value;
      }
    }
  }

  if ( is_numeric($_POST['record_id']) ) {
    $params['record_id'] = (int) $_POST['record_id'];
    $params['status'] = (int) $_POST['status'];
    if ( is_numeric($_POST['instance_id']) ) {
      $params['instance_id'] = (int) $_POST['instance_id'];
    }
  }

  if ( is_array($_POST['rrule_until']) ) {
    $params['rrule_until']      = date_convert($_POST['rrule_until'], DATE_ARRAY, DATE_DATETIME);
  } else if ( is_numeric($_POST['rrule_until']) ) {
    $params['rrule_until']      = date_convert((int)$_POST['rrule_until'], DATE_UNIX, DATE_DATETIME);
  } else if ( is_string($_POST['rrule_until']) && preg_match(DATE_REGEX_LOOSE, $_POST['rrule_until']) ) {
    $params['rrule_until'] = $_POST['rrule_until'];
  }

  if ( ! defined($params['rrule_until']) ) {
    if ( is_array($params['UNTIL']) ) {
      $until = $params['UNTIL']['datetime'];
      //  $exdate0 = $_POST[0]['datetime'];
      if (empty($until['year']) || empty($until['month']) || empty($until['day'])) {
        // invalid RRULE because there's no valid UNTIL
      } else {
        include_once('./'. drupal_get_path('module', 'date_repeat') .'/date_repeat_form.inc');
        include_once('./'. drupal_get_path('module', 'date_api') .'/date_api_ical.inc');

        // date_repeat_rrule_validate runs this before building RRULE, so we do this too.
        //    $processed = date_repeat_merge($params, $params['UNTIL']);
        $params['rrule_until'] = date_convert($params['UNTIL']['datetime'], DATE_ARRAY, DATE_DATETIME);
      }
    }
  }

  if ( array_key_exists('rrule_until',$params) ) {
    if ( is_string($_POST['rrule']) ) {
      $vals = explode(',',$_POST['rrule']);
      foreach ( $vals as $v ) {
        $values = explode('=',$v);
        if ( $values[0] == 'FREQ' ) {
          $params['FREQ'] = $values[1];
        } else if ( $values[0] == 'INTERVAL' ) {
          $params['INTERVAL'] = (int) $values[1];
        }
      }
    }
    $params['UNTIL']['datetime'] = $params['rrule_until'];
    foreach ( array_keys($_POST) as $key ) {
      if ( is_numeric($key) ) {
        $key = (int) $key;
        $params[$key]['datetime'] = date_convert($_POST[$key]['datetime'], DATE_ARRAY, DATE_DATETIME);

        // if first EXDATE is invalid, unset the entire EXDATE array to prevent errors
        if ($params[$key]['datetime'] == '0000-00-00 00:00:00') {
          unset($params[$key]);
        }
      }
    }

    require_once(drupal_get_path('module','date')."/../date_api_ical.inc");

    $params['rrule']       = date_api_ical_build_rrule( $params );
    $params['rrule_until'] = bookingsapi_rrule_until_as_dt($params['rrule']);
  }

  $params['description'] = trim(htmlspecialchars((string)$_POST['description']));
  $params['subtype'] = trim(htmlspecialchars((string)$_POST['subtype']));

  if ( ! is_numeric($_POST['resource_id']) ) {
    if ( $noPrint ) {
      return FALSE;
    } else {
      drupal_json(array(FALSE,t('Error, invalid data. Need resource_id.')));
      return;
    }
  } else {
    $params['resource_id'] =& $resId;
    $resId = (int) $_POST['resource_id'];
    $resource = bookingsapi_resource_load($resId);
    if ( $resource === FALSE ) {
      if ( $noPrint ) {
        return FALSE;
      } else {
        drupal_json(array(FALSE,t('Error, invalid resource_id.')));
        return;
      }
    } 
    if ( isset($params['record_id']) ) {
      $oldRecord = bookingsapi_record_load($params['record_id']);
      if ( $resId != $oldRecord['resource_id'] ) {
        if ( $noPrint ) {
          return FALSE;
        } else {
          drupal_json(array(FALSE,t('Error, invalid resource_id.')));
          return;
        }
      }
    }
  }

  // Now $params should contain a complete list of parameters for this availability...

  $res = bookingsapi_record_save($params);
 
  if ( $noPrint ) {
    $params['result'] = $res;
    return $params;
  } else {
    drupal_json($res);
  }
}

