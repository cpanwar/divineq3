<?php
/**
 * @file
 * Expose booking information to Views.
 */

/**
 * Implementation of hook_views_data().
 */
function bookingsapi_views_data() {

  // The flexible date argument.
  $data['bookings_records']['date_argument'] = array(
    'group' => t('Date'),
    'title' => t('Date'),
    'help' => t('Filter any Views date field by a date argument, using any common ISO date/period format (i.e. YYYY, YYYY-MM, YYYY-MM-DD, YYYY-W99, YYYY-MM-DD--P3M, P90D, etc).'),
    'argument' => array(
      'handler' => 'date_api_argument_handler',
      'empty name field' => t('Undated'),
//      'base' => 'bookings_records',
    ),
  );
  // The flexible date filter.
  $data['bookings_records']['date_filter'] = array(
    'group' => t('Date'),
    'title' => t('Date'),
    'help' => t('Filter any Views date field.'),
    'filter' => array(
      'handler' => 'date_api_filter_handler',
      'empty name field' => t('Undated'),
    ),
  );

  $data['bookings_records']['table']['group']  = t('Bookings record');

  $data['bookings_records']['table']['base'] = array(
    'field' => 'record_id',
    'title' => t('Booking record'),
    'help' => t("Booking records can either be actual bookings, or availability information."),
  );

  $data['node']['table']['join'] = array(
    'bookings_records' => array(
      'field' => 'nid',
      'left_field' => 'resource_id',
//      'type' => 'INNER',
    ),
    'bookings_schedules' => array(
      'field' => 'nid',
      'left_field' => 'resource_id',
//      'type' => 'INNER',
    ),
  );

  $data['bookings_records']['table']['join'] = array(
    'bookings_schedules' => array(
      'left_field' => 'record_id',
      'field' => 'record_id',
      'type' => 'INNER',
    ),
    'node' => array(
      'table'      => 'node',
      'left_field' => 'nid',
      'field' => 'resource_id',
//      'type' => 'INNER',
    ),
  );

  $data['bookings_records']['record_id'] = array(
    'title' => t('Record ID'),
    'help' => t('The record ID.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'record_id', // the field to display in the summary.
      'numeric' => TRUE,
    ),
    // Information for accepting a nid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['bookings_records']['resource_id'] = array(
    'title' => t('Resource'),
    'help' => t('The resource the record is referring.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Resource'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'resource_id', // the field to display in the summary.
      'numeric' => TRUE,
    ),
  );

  $data['bookings_records']['start'] = array(
    'title' => t('First start date'),
    'help' => t('The date and time the record starts.'),
    'field' => array(
      'handler' => 'views_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_datetime',
    ),
    /*
    'argument' => array(
      'handler'     => 'date_api_argument_handler',
      'name field'  => 'start',
      'empty name field' => t('Undated'),
      'base' => 'bookings_records',
    ),
    */
  );

  $data['bookings_records']['end'] = array(
    'title' => t('First end date'), // The item it appears as on the UI,
    'help' => t('The date and time the record ends.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_datetime',
    ),
  );

  $data['bookings_records']['rrule'] = array(
    'title' => t('Repeat rule'),
    'help' => t('A description of the RRULE.'),
    'field' => array(
      'handler' => 'views_handler_field_bookings_rrule',
      'click sortable' => FALSE,
    ),
  );

  // created field
  $data['bookings_records']['created'] = array(
    'title' => t('Created date'), // The item it appears as on the UI,
    'help' => t('The date the record was created.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // changed field
  $data['bookings_records']['changed'] = array(
    'title' => t('Updated date'), // The item it appears as on the UI,
    'help' => t('The date the record was last updated.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['bookings_records']['name'] = array(
    'title' => t('Name'),
    'help' => t('The name of the record.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['bookings_records']['description'] = array(
    'title' => t('Description'),
    'help' => t('The description of the record.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
  );

  $data['bookings_records']['type'] = array(
    'title' => t('Type'),
    'help' => t('The record type.'),
    'field' => array(
      'handler' => 'views_handler_field_bookings_record_types',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bookings_record_types',
    ),
   'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'type', // the field to display in the summary.
      'numeric' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['bookings_records']['status'] = array(
    'title' => t('Status'),
    'help' => t('The record status.'),
    'field' => array(
      'handler' => 'views_handler_field_bookings_record_statuses',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bookings_record_statuses',
    ),
   'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'status', // the field to display in the summary.
      'numeric' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['bookings_schedules']['table']['group']  = t('Bookings instance');

  $data['bookings_schedules']['table']['base'] = array(
    'field' => 'instance_id',
    'title' => t('Bookable record instance'),
    'help' => t('Recurrence instances of every record.'),
  );

  $data['bookings_schedules']['table']['join'] = array(
    'bookings_records' => array(
      'left_field' => 'record_id',
      'field' => 'record_id',
    ),
    'node' => array(
      'table'      => 'node',
      'left_field' => 'nid',
      'field' => 'resource_id',
//      'type' => 'INNER',
    ),
  );

  $data['bookings_schedules']['resource_id'] = array(
    'title' => t('Resource'),
    'help' => t('The resource the record is referring.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Resource'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bookings_resource_id',
    ),
  );

  $data['bookings_schedules']['record_id'] = array(
    'title' => t('Record'),
    'help' => t('The parent record that this is an instance of.'),
    'relationship' => array(
      'base' => 'bookings_records',
      'field' => 'record_id',
      'handler' => 'views_handler_relationship',
      'label' => t('Record'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bookings_record_id',
    ),
  );

  $data['bookings_schedules']['type'] = array(
    'title' => t('Type'),
    'help' => t('The occurence type.'),
    'field' => array(
      'handler' => 'views_handler_field_bookings_record_types',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bookings_record_types',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['bookings_schedules']['start'] = array(
    'title' => t('Start date'),
    'help' => t('The date and time the record instance starts.'),
    'field' => array(
      'handler' => 'views_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_datetime',
    ),
  );

  $data['bookings_schedules']['end'] = array(
    'title' => t('End date'), // The item it appears as on the UI,
    'help' => t('The date and time the record instance ends.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_datetime',
    ),
  );

  $data['bookings_schedules']['status'] = array(
    'title' => t('Status'),
    'help' => t('The occurence status.'),
    'field' => array(
      'handler' => 'views_handler_field_bookings_record_statuses',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bookings_record_statuses',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

/*
  $data['bookings_resources']['table']['group']  = t('Bookings resource');

  $data['bookings_resources']['table']['base'] = array(
    'field' => 'resource_id',
    'title' => t('Bookable resource'),
    'help' => t('Can be booked through Bookings API.'),
  );

  $data['bookings_resources']['table']['join'] = array(
    'bookings_schedules' => array(
      'left_field' => 'resource_id',
      'field' => 'resource_id',
    ),
    'bookings_records' => array(
      'left_field' => 'resource_id',
      'field' => 'resource_id',
    ),
  );

  $data['bookings_resources']['name'] = array(
    'title' => t('Name'),
    'help' => t('The name of the resource.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['bookings_resources']['location'] = array(
    'title' => t('Location'),
    'help' => t('The location of the resource.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['bookings_resources']['description'] = array(
    'title' => t('Description'),
    'help' => t('The description of the resource.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
  );

  $data['bookings_resources']['default_availability'] = array(
    'title' => t('Default availability'),
    'help' => t('The default availability of the resource.'),
    'field' => array(
      'handler' => 'views_handler_field_bookings_default_availability',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bookings_availability_types',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['bookings_resources']['disabled'] = array(
    'title' => t('Disabled'),
    'help' => t('Whether the resource is disabled or not.'),
    'field' => array(
      'handler' => 'views_handler_field_bookings_resource_disabled',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_bookings_resource_disabled',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
*/

  return $data;
}

function bookingsapi_date_api_fields($field) {
  $values = array(
    'sql_type'       => DATE_DATETIME,
    'tz_handling'    => 'site',
    'timezone_field' => '',
    'offset_field'   => '',
    'related fields' => array(),
    'granularity'    => array('year','month','day','hour','minute','second'),
  );
  switch ( $field) {
    case 'bookings_records.start':
    case 'bookings_records.end':
    case 'bookings_schedules.start':
    case 'bookings_schedules.end':
      return $values;
  };
}
