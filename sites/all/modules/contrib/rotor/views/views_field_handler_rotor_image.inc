<?php

/**
 * @file
 * This include file implements views functionality on behalf of the
 * rotor.module.
 */

/**
 * A handler to provide proper displays for rotor item images.
 */
class views_field_handler_rotor_image extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['imagecache_preset'] = array('default' => '');
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
      if (module_exists('imagecache')) {
      $presets[0] = t('None');
      $presets += rotor_get_imagecache_presets();
      $form['imagecache_preset'] = array(
        '#type' => 'select',
        '#title' => t('Imagecache preset'),
        '#default_value' => $this->options['imagecache_preset'],
        '#options' => $presets,
        '#description' => t('Select the imagecache preset to use with the images.'),
      );
    }
  }
  
  function render($values) {
    $node = node_load($values->nid);
    return theme('rotor_image', $node, $this->options['imagecache_preset']);
  }
}
