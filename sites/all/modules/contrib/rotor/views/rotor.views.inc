<?php

/**
 * @file
 * Rotor views integration.
 */

/**
 * Implementation of hook_views_plugins
 */
function rotor_views_plugins() {
  $path = drupal_get_path('module', 'rotor');
  $views_path = drupal_get_path('module', 'views');
  require_once "./$path/theme/theme.inc";
  return array(
    'module' => 'rotor',
    'style' => array(
      'rotor' => array(
        'title' => t('Rotor'),
        'help' => t('Displays nodes as a rotoating banner.'),
        'handler' => 'rotor_plugin_style_rotor',
        'path' => "$path/views",
        'theme' => 'rotor_view_rotor',
        'theme file' => 'theme.inc',
        'theme path' => "$path/theme",
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
    'row' => array(
      'unformatted' => array(
        'title' => t('Rotor'),
        'help' => t('(Displays a Rotor Item ready to be used in a Rotor block'),
        'handler' => 'rotor_plugin_row_rotor',
        'path' => "$path/views",
        'theme' => 'rotor_row_rotor',
        'theme file' => 'theme.inc',
        'theme path' => "$path/theme",
        'uses fields' => FALSE,
        'uses options' => module_exists('imagecache'),
        'type' => 'normal',
      ),
    )
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function rotor_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'rotor') .'/views',
    ),
    'handlers' => array(
      'views_field_handler_rotor_image' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 *
 * Exposes all fields to the views system.
 */
function rotor_views_data() {
  $data = array();

  $data['rotor_item']['table']['group']  = t('Content');

  $data['rotor_item']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'files' => array(
      'left_field' => 'fid',
      'field' => 'fid',
    ),
  );

  $data['rotor_item']['rotor_item_image'] = array(
    'title' => t('Rotor Item image'),
    'real field' => 'nid',
    'help' => t('Add a Rotor Item image as a field to this view.'),
    'field' => array(
      'handler' => 'views_field_handler_rotor_image',
      'click sortable' => FALSE,
    ),
  );
  $data['rotor_item']['rotor_item_url'] = array(
    'title' => t('Rotor Item link'),
    'real field' => 'url',
    'help' => t('Add a Rotor Item link as a field to this view.'),
    'field' => array(
      'handler' => 'views_handler_field_url',
      'click sortable' => FALSE,
    ),
  );

  return $data;
}