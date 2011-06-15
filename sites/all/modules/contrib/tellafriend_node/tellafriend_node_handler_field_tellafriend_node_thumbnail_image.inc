<?php
// $id$

class tellafriend_node_handler_field_tellafriend_node_thumbnail_image extends views_handler_field {
  function construct() {
     parent::construct();
     $this->additional_fields['nid'] = 'nid';
     $this->additional_fields['tellafriend_node_ecard_thumbnail_image'] = 'tellafriend_node_ecard_thumbnail_image';
  }
 
  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_node'] = array('default' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_node'] = array(
      '#title' => t('Link this field to its node'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_node']),
    );
  }

  function render_link($data, $values) {
    if (!empty($this->options['link_to_node'])) {
      return l($data, "node/" . $values->{$this->aliases['nid']}, array('html' => TRUE));
    }
    else {
      return $data;
    }
  }

  function render($values) {
    $image = '<img src="/' . $values->tellafriend_node_data_tellafriend_node_ecard_thumbnail_image . '" alt="" class="tellafriend_node-ecard-thumbnail-image" />';
    $output =  $this->render_link($image, $values);
    return $output;
  }
}
