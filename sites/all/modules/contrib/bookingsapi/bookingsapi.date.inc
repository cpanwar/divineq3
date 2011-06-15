<?php

/**
 * A booking that has not been changed.
 */
define('BOOKINGSAPI_DATE_UNCHANGED', TRUE);

/**
 * A booking that exists in the old record but not in the new record anymore.
 * It has been removed
 */
define('BOOKINGSAPI_DATE_REMOVED', -1);
/**
 * A booking that exists in both records but with differing times.
 */
define('BOOKINGSAPI_DATE_MOVED', 0);
/**
 * A booking that exists in the new record but not in the old.
 * It has been added to the booking.
 */
define('BOOKINGSAPI_DATE_ADDED', 1);

/**
 * Calculates differences between two record-dates.
 *
 * This method is not interested in the length-difference but in differing times.
 * A return will tell you that e.g. the starting time has moved 5minutes, but
 * not whether the total length has changed.
 *
 * @return array
 *  array( array( 'start' => diff or datetime, 
                  'end'   => diff or datetime,
                  'change'=> REMOVED, MOVED, ADDED
                ),
                ..
         )
 */
function bookingsapi_date_diff( $oldRecord, $newRecord ) {
  $unchanged = array();
  $result = array();
  $keylist = array('start', 'end', 'rrule', 'rrule_until');

  $allTrue = TRUE;

  foreach ( $keylist as $key ) {
    $allTrue &= $unchanged[$key] = $oldRecord[$key] == $newRecord[$key];
  }

  if ( $allTrue ) {
    return $allTrue;
  }

  $intervalsNew = array();
  $intervalsOld = array();
  $exceptionsNew = array();
  $execeptionsOld = array();

  bookingsapi_parse_rrule($newRecord,$exceptionsNew, $intervalsNew);
  bookingsapi_parse_rrule($oldRecord,$exceptionsOld, $intervalsOld);

  $cNew = count($intervalsNew);
  $cOld = count($intervalsOld);

  $res = array();

  if ( $cNew == 1 && $cOld == 1 || $cNew == $cOld && $unchanged['rrule'] ) {
    for ( $i=0; $i<$cNew; $i++ ) {
      $changeStart = date_difference($intervalsNew[$i][0], $intervalsOld[$i][0], 'seconds', DATE_DATETIME);
      $changeEnd   = date_difference($intervalsNew[$i][1], $intervalsOld[$i][1], 'seconds', DATE_DATETIME);      

      foreach ( $intervalsNew as $rec ) {
        if ( $changeStart != 0 || $changeEnd != 0 ) {
          $res[] = array( 'start'=>$changeStart, 'end'=>$changeEnd, 'change'=>BOOKINGSAPI_DATE_MOVED);
        } else {
          $res[] = array( 'start'=>$changeStart, 'end'=>$changeEnd, 'change'=>BOOKINGSAPI_DATE_UNCHANGED);
        }
      }
      return $res;
    }
  } else {
    // Mist. Tut nicht -> Mehrdimensionaler Array
    $removed = array_diff( $intervalsNew, $intervalsOld );
    $added   = array_diff( $intervalsOld, $intervalsNew );
    foreach ( $removed as $rem ) {
      $res[] = array( 'start' => $rem[0], 'end' => $rem[1], 'change'=>BOOKINGSAPI_DATE_REMOVED);
    }
    foreach ( $added as $add ) {
      $res[] = array( 'start' => $add[0], 'end' => $add[1], 'change'=>BOOKINGSAPI_DATE_ADDED);
    }
    return $res;
  }
}
