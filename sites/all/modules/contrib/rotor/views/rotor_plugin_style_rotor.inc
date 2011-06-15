<?php

/**
 * @file
 * Rotor style plugin.
 */

/**
 * Style plugin to render a map.
 *
 * @ingroup views_style_plugins
 */
class rotor_plugin_style_rotor extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['width'] = array(
      'default' => '0',
    );
    $options['height'] = array(
      'default' => '0',
    );
    $options['seconds'] = array(
      'default' => '5',
    );
    $options['speed'] = array(
      'default' => '1',
    );
    $options['effect'] = array(
      'default' => 'fade',
    );
    $options['pause'] = array(
      'default' => '0',
    );
    $options['tabs']['show_tabs'] = array(
      'default' => TRUE,
    );
    $options['tabs']['group_tabs'] = array(
      'default' => ROTOR_GROUP_TABS,
    );
    $options['tabs']['position'] = array(
      'default' => ROTOR_TAB_POSITION_TOP,
    );
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['width'] = array(
      '#type' => 'textfield',
      '#title' => t('Width'),
      '#default_value' => $this->options['width'],
      '#description' => t("Width of the Rotor items in pixels. eg. '200' (set to 0 for no restriction)."),
      '#required' => TRUE,
    );
    $form['height'] = array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#default_value' => $this->options['height'],
      '#description' => t("Height of the Rotor items in pixels. eg. '200' (set to 0 for no restriction)."),
      '#required' => TRUE,
    );
    $form['seconds'] = array(
      '#type' => 'textfield',
      '#title' => t('Time'),
      '#default_value' => $this->options['seconds'],
      '#rows' => 1,
      '#size' => 2,
      '#description' => t('The time in seconds that will be shown every Rotor item before change to the next one.'),
      '#required' => TRUE,
    );
   $form['speed'] = array(
      '#type' => 'textfield',
      '#title' => t('Speed'),
      '#default_value' => $this->options['speed'],
      '#rows' => 1,
      '#size' => 2,
      '#description' => t('The time in seconds of the transition effect between each Rotor item (set to 0 for no transition).'),
      '#required' => TRUE,
    );
    $form['effect'] = array(
      '#type' => 'select',
      '#title' => t('Effect'),
      '#default_value' => $this->options['effect'],
      '#options'        => _rotor_get_effects(),
      '#description' => t('The effect to use when changing to the next Rotor item.'),
      '#required' => TRUE,
    );
    $form['pause'] = array(
      '#type' => 'checkbox',
      '#title' => t('Pause on hover'),
      '#default_value' => $this->options['pause'],
      '#description' => t('Enables/Disables pause on hover.'),
    );
    $form['tabs'] = array(
      '#type' => 'fieldset',
      '#title' => t('Tabs'),
    );
    $form['tabs']['show_tabs'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable tabs'),
      '#default_value' => $this->options['tabs']['show_tabs'],
      '#description' => t('Shows/Hide the item tabs in the block.'),
    );
    $form['tabs']['group_tabs'] = array(
      '#type' => 'radios',
      '#title' => t('Group tabs'),
      '#options' => array(ROTOR_GROUP_TABS => t('Group tabs'), ROTOR_DONT_GROUP_TABS => t("Each tab with its own item")),
      '#description' => t("If tabs are grouped, all Rotor item tabs will be displayed together (all at once). Clicking on a tab will take force the rotor to rotate to the tabs content. otherwise each tab will be displayed with its own content only and will not be clickable."),
    );
    $form['tabs']['position'] = array(
      '#type' => 'select',
      '#title' => t('Tab position'),
      '#default_value' => $this->options['tabs']['position'],
      '#options' => array(ROTOR_TAB_POSITION_TOP => t("Above"), ROTOR_TAB_POSITION_BOTTOM => t("Below")),
      '#description' => t("Where the tabs should be positioned."),
    );
  }
}