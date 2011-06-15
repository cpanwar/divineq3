<?php
// $id$

class tellafriend_node_handler_field_tellafriend_node_send_ecard_link extends views_handler_field {
  function construct() {
     parent::construct();
     $this->additional_fields['nid'] = 'nid';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_node'] = array('default' => TRUE);
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
    $ecard_link_text = 'Send this e-card';
    $output =  '<div class="tellafriend_node-send-ecard-link">' . $this->render_link($ecard_link_text, $values) . '</div>';
    return $output;
  }
}
