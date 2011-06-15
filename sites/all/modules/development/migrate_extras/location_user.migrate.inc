<?php
// $Id: location_user.migrate.inc,v 1.1.2.1 2010/05/29 21:55:21 textplease Exp $

/**
 * @file
 * Integrates location_user module (part of location) with the migrate module
 * 
 */

//reuses function from location module.
require_once('location.migrate.inc');

/**
 * Implementation of hook_migrate_types().
 */
function location_user_migrate_types() {
    $types = array('location_user' => t('User Location'));
  return $types;
}

/**
 * Implementation of hook_migrate_fields().
 */
function location_user_migrate_fields_location_user($type) { 
  $fields = location_migrate_fields_location('location');
  
  //make some adjustments - replace nid with uid.
  unset($fields['nid']);
  $fields['uid'] = t('User ID');
  
  return $fields;
}

/**
 * Implementation of hook_migrate_prepare().
 */
function location_user_migrate_prepare_location_user(&$uloc, $tblinfo, $row) {
  return location_migrate_prepare_location($uloc, $tblinfo, $row);
}
 

/**
 * Implementation of hook_migrate_import().
 */
function location_user_migrate_import_location_user($tblinfo, $row) {
  return location_migrate_import_location($tblinfo, $row);
}

/**
 * Implementation of hook_migrate_complete().
 */
function location_user_migrate_complete_location_user(&$uloc, $tblinfo, $row) {
  return location_migrate_complete_location($uloc, $tblinfo, $row);
}

function location_user_migrate_delete_location_user($lid) {
  
  /* BIG problems, and some hacky solutions: see similar function in 
   * location.migrate.inc for details on assuptions being made here.
   * This does the same things but for uid instead of nid.
   */
   
  $result = db_query('SELECT nid, uid, genid FROM {location_instance} WHERE lid = %d AND uid <> 0 ORDER BY uid DESC', $lid);
  if($location_instance = db_fetch_array($result)) {
    //at least one node matches this location
    db_query('DELETE FROM {location_instance} WHERE lid = %d and uid = %d', array($lid, $location_instance['uid']));
  }
  
  //check to see if ths is the last instance, and if it is, remove the location.
  $count = db_result(db_query('SELECT COUNT(*) FROM {location_instance} WHERE lid = %d', $lid));
  if ($count !== FALSE && $count == 0) {
    $location = array('lid' => $lid);
    location_invoke_locationapi($location, 'delete');
    db_query('DELETE FROM {location} WHERE lid = %d', $location['lid']);
  }
}
