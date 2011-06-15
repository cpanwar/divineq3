<?php

class views_handler_field_publicbookings_record_link extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['record_id'] = 'record_id';
  }

  function query() { // what is this?
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    parent::render($values);
  }
}

class views_handler_field_publicbookings_resource_link extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['resource_id'] = 'resource_id';
  }

  function query() { // what is this?
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    parent::render($values);
  }
}

class views_handler_field_publicbookings_booking_link_edit extends views_handler_field_publicbookings_record_link {
  function render($values) {
    parent::render($values);
    $record_id = $values->{$this->aliases['record_id']};
    return l(t('edit'), "admin/content/publicbookings/booking/$record_id/edit");
  }
}

class views_handler_field_publicbookings_booking_link_delete extends views_handler_field_publicbookings_record_link {
  function render($values) {
    parent::render($values);
    $record_id = $values->{$this->aliases['record_id']};
    return l(t('delete'), "admin/content/publicbookings/booking/$record_id/delete");
  }
}

class views_handler_field_publicbookings_availability_link_edit extends views_handler_field_publicbookings_record_link {
  function render($values) {
    parent::render($values);
    $record_id = $values->{$this->aliases['record_id']};
    return l(t('edit'), "admin/content/publicbookings/availability/$record_id/edit");
  }
}

class views_handler_field_publicbookings_availability_link_delete extends views_handler_field_publicbookings_record_link {
  function render($values) {
    parent::render($values);
    $record_id = $values->{$this->aliases['record_id']};
    return l(t('delete'), "admin/content/publicbookings/availability/$record_id/delete");
  }
}



class views_handler_field_publicbookings_resource_link_edit extends views_handler_field_publicbookings_resource_link {
  function render($values) {
    parent::render($values);
    $resource_id = $values->{$this->aliases['resource_id']};
    return l(t('edit'), "admin/content/publicbookings/resource/$resource_id/edit");
  }
}

class views_handler_field_publicbookings_resource_link_delete extends views_handler_field_publicbookings_resource_link {
  function render($values) {
    parent::render($values);
    $resource_id = $values->{$this->aliases['resource_id']};
    return l(t('delete'), "admin/content/publicbookings/resource/$resource_id/delete");
  }
}
class views_handler_field_publicbookings_resource_link_availability extends views_handler_field_publicbookings_resource_link {
  function render($values) {
    parent::render($values);
    $resource_id = $values->{$this->aliases['resource_id']};
    return l(t('availability'), "admin/content/publicbookings/resource/$resource_id/availability/list");
  }
}

class views_handler_field_publicbookings_title extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['title'] = 'title';
  }

  function render($values) {
    parent::render($values);
    return publicbookings_title($values->{$this->aliases['title']});
  }
}
