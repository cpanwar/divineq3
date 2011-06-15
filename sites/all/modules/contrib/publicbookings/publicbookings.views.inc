<?php
/**
 * @file
 * Expose Public Bookings information to Views.
 */

/**
 * Implementation of hook_views_data().
 */
function publicbookings_views_data() {
  $data['publicbookings_clients']['table']['group']  = t('Booking client');

  $data['publicbookings_clients']['table']['base'] = array(
    'field' => 'client_id',
    'title' => t('Booking client'),
    'help' => t("Booking requests made on the public request pages have client information."),
  );

  $data['publicbookings_clients']['table']['join'] = array(
    'bookings_records' => array(
      'left_field' => 'record_id',
      'field' => 'record_id',
    ),
    'bookings_schedules' => array(
      'left_field' => 'record_id',
      'field' => 'record_id',
    ),
  );

  $data['publicbookings_clients']['title'] = array(
    'title' => t('Salutation'),
    'help'  => t('title of the client / Salutation'),
    'field' => array(
      'handler' => 'views_handler_field_publicbookings_title',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['publicbookings_clients']['first_name'] = array(
    'title' => t('First name'),
    'help' => t('The first name of the client.'),
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

  $data['publicbookings_clients']['last_name'] = array(
    'title' => t('Last name'),
    'help' => t('The last name of the client.'),
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

  $data['publicbookings_clients']['phone'] = array(
    'title' => t('Phone'),
    'help' => t('The phone number of the client.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
  );

  $data['publicbookings_clients']['email'] = array(
    'title' => t('Email'),
    'help' => t('The email address of the client.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
  );

  $data['publicbookings_clients']['comments'] = array(
    'title' => t('Comments'),
    'help' => t('Comments by the client.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
  );

  $data['publicbookings_clients']['uid'] = array(
    'title' => t('User'),
    'help' => t('If the client was logged in, this is the user ID.'),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
    ),
  );

  $data['publicbookings_clients']['created'] = array(
    'title' => t('Created date'),
    'help' => t('Created date.'),
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

  $data['publicbookings_clients']['changed'] = array(
    'title' => t('Modified date'),
    'help' => t('Last modified.'),
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


  $data['bookings_records']['edit_booking'] = array(
    'field' => array(
      'title' => t('Edit booking link'),
      'help' => t('Provide a simple link to edit the booking.'),
      'handler' => 'views_handler_field_publicbookings_booking_link_edit',
    ),
  );

  $data['bookings_records']['delete_booking'] = array(
    'field' => array(
      'title' => t('Delete booking link'),
      'help' => t('Provide a simple link to delete the booking.'),
      'handler' => 'views_handler_field_publicbookings_booking_link_delete',
    ),
  );

  $data['bookings_records']['edit_availability'] = array(
    'field' => array(
      'title' => t('Edit availability link'),
      'help' => t('Provide a simple link to edit the availability.'),
      'handler' => 'views_handler_field_publicbookings_availability_link_edit',
    ),
  );

  $data['bookings_records']['delete_availability'] = array(
    'field' => array(
      'title' => t('Delete booking link'),
      'help' => t('Provide a simple link to delete the availability.'),
      'handler' => 'views_handler_field_publicbookings_availability_link_delete',
    ),
  );

  $data['bookings_resources']['edit_resource'] = array(
    'field' => array(
      'title' => t('Edit resource link'),
      'help' => t('Provide a simple link to edit the resource.'),
      'handler' => 'views_handler_field_publicbookings_resource_link_edit',
    ),
  );

  $data['bookings_resources']['delete_resource'] = array(
    'field' => array(
      'title' => t('Delete resource link'),
      'help' => t('Provide a simple link to delete the resource.'),
      'handler' => 'views_handler_field_publicbookings_resource_link_delete',
    ),
  );

  $data['bookings_resources']['list_availability'] = array(
    'field' => array(
      'title' => t('List availability link'),
      'help' => t('Provide a simple link to list the resource\s availabilities.'),
      'handler' => 'views_handler_field_publicbookings_resource_link_availability',
    ),
  );


  $data['bookings_records']['edit_booking'] = array(
    'field' => array(
      'title' => t('Edit booking link'),
      'help' => t('Provide a simple link to edit the booking.'),
      'handler' => 'views_handler_field_publicbookings_booking_link_edit',
    ),
  );

  $data['bookings_records']['delete_booking'] = array(
    'field' => array(
      'title' => t('Delete booking link'),
      'help' => t('Provide a simple link to delete the booking.'),
      'handler' => 'views_handler_field_publicbookings_booking_link_delete',
    ),
  );

  $data['bookings_records']['edit_availability'] = array(
    'field' => array(
      'title' => t('Edit availability link'),
      'help' => t('Provide a simple link to edit the availability.'),
      'handler' => 'views_handler_field_publicbookings_availability_link_edit',
    ),
  );

  $data['bookings_records']['delete_availability'] = array(
    'field' => array(
      'title' => t('Delete booking link'),
      'help' => t('Provide a simple link to delete the availability.'),
      'handler' => 'views_handler_field_publicbookings_availability_link_delete',
    ),
  );

  $data['bookings_resources']['edit_resource'] = array(
    'field' => array(
      'title' => t('Edit resource link'),
      'help' => t('Provide a simple link to edit the resource.'),
      'handler' => 'views_handler_field_publicbookings_resource_link_edit',
    ),
  );

  $data['bookings_resources']['delete_resource'] = array(
    'field' => array(
      'title' => t('Delete resource link'),
      'help' => t('Provide a simple link to delete the resource.'),
      'handler' => 'views_handler_field_publicbookings_resource_link_delete',
    ),
  );

  return $data;
}

