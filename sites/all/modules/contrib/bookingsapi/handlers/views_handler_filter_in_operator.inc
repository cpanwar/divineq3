<?php


/**
 * Filter by resource ID.
 *
 */
class views_handler_filter_bookings_resource_id extends views_handler_filter_in_operator {
  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }

    $this->value_options = array();
    $resources = bookingsapi_resource_minimal_list();
    foreach ( $resources as $id => $name ) {
      $this->value_options[$id] = $name;
    }
  }
}

/**
 * Filter by record ID.
 *
 */
class views_handler_filter_bookings_record_id extends views_handler_filter_in_operator {
  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }

    $this->value_options = array();
    $records = bookingsapi_record_minimal_list();
    foreach ( $records as $id => $name ) {
      $this->value_options[$id] = $name;
    }
  }
}

/**
 * Filter by type (booking type + availability types).
 *
 */
class views_handler_filter_bookings_record_types extends views_handler_filter_in_operator {
  function construct() {
    parent::construct();
    $this->definition['numeric'] = TRUE;
  }

  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }
    $this->value_options = array();
    $types = bookingsapi_record_types();
    foreach($types as $k => $v) {
      $this->value_options[$k] = $v;
    }
  }
}

class views_handler_filter_bookings_record_statuses extends views_handler_filter_in_operator {
  function construct() {
    parent::construct();
    $this->definition['numeric'] = TRUE;
  }

  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }
    $this->value_options = array();
    $status = bookingsapi_record_status();
    foreach($status as $k => $v) {
      $this->value_options[$k] = $v;
    }
  }
}

/**
 * Filter by availability type.
 *
 */
class views_handler_filter_bookings_availability_types extends views_handler_filter_bookings_record_types {
  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }
    $this->value_options = array();
    $types = bookingsapi_availability_types();
    foreach($type as $k => $v) {
      $this->value_options[$k] = $v;
    }
  }
}
