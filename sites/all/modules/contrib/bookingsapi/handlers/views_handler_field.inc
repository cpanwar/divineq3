<?php

/*
class views_handler_field_bookings_resource_disabled extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['disabled'] = 'disabled';
  }

  function query() { // what is this?
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    parent::render($values);
    $disabled = (bool) $values->{$this->aliases['disabled']};
    return $disabled ? t('Yes') : t('No');
  }
}
*/

class views_handler_field_bookings_record_types extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }

  function render($values) {
    parent::render($values);
    $type = $values->{$this->aliases['type']};
    $types = bookingsapi_record_types();
    $type = bookingsapi_numeric_record_types($type);
    return $types[$type];
  }
}

/*
class views_handler_field_bookings_default_availability extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['default_availability'] = 'default_availability';
  }

  function render($values) {
    parent::render($values);
    $type = $values->{$this->aliases['default_availability']};
    $types = bookingsapi_record_types();
    $type = bookingsapi_numeric_record_types($type);
    return $types[$type];
  
  }
}
*/

/**
 * Display the rrule column in human-readable format.
 *
 */
class views_handler_field_bookings_rrule extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['rrule'] = 'rrule';
    $this->additional_fields['start'] = 'start';
  }

  function render($values) {
    parent::render($values);
    $rrule = $values->{$this->aliases['rrule']};
    $start = $values->{$this->aliases['start']};
    return date_repeat_rrule_description($rrule);
  }
}

class views_handler_field_bookings_record_statuses extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['status'] = 'status';
  }

  function render($values) {
    parent::render($values);
    $status = $values->{$this->aliases['status']};
    $statA  = bookingsapi_record_status();
    $status = bookingsapi_numeric_record_status($status);
    return $statA[$status];
  }
}
