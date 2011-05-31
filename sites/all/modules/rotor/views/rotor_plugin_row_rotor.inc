<?php

/**
 * @file
 * GMap style plugin.
 */

/**
 * Style plugin to render a map.
 *
 * @ingroup views_style_plugins
 */
class rotor_plugin_row_rotor extends views_plugin_row {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['imagecache_preset'] = array(
      'default' => '',
    );
    return $options;
  }

  function render($row) {
    $output = theme($this->theme_functions(), $this->view, $this->options, $row);
    return trim($output);
  }

  /**
   * Render the given style.
   */
  /**
   * Render the given style.
   */
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
}
