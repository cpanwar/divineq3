<?php

/**
 * Implementation of hook_strongarm().
 */
function base_system_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = '1';

  $export['clean_url'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_expanded';
  $strongarm->value = array(
    0 => 'primary-links',
  );

  $export['menu_expanded'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_footer';
  $strongarm->value = 'Copyright © 2010 Divine Wellness Pvt.Ltd., All rights reserved.';

  $export['site_footer'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'Divine wellness';

  $export['site_name'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_divine';
  $strongarm->value = array(
    'block' => array(
      'search-0' => array(
        'grid16-width' => 'grid16-6',
        'fusion-alignment' => 'fusion-right',
        'fusion-content-alignment' => 'fusion-right-content',
      ),
      'menu-menu-authentication-menu' => array(
        'grid16-width' => 'grid16-3',
        'fusion-alignment' => 'fusion-right',
        'fusion-content-alignment' => 'fusion-center-content',
        'fusion-general-styles' => array(
          'fusion-bold-links' => 'fusion-bold-links',
        ),
        'fusion-menu' => 'fusion-inline-menu',
      ),
      'menu-primary-links' => array(),
      'menu-menu-footer-menu-1' => array(
        'grid16-width' => 'grid16-16',
        'fusion-alignment' => 'fusion-center',
        'fusion-content-alignment' => 'fusion-center-content',
        'fusion-general-styles' => array(
          'fusion-bold-links' => 'fusion-bold-links',
        ),
        'fusion-menu' => 'fusion-inline-menu',
      ),
      'menu-menu-footer-menu-2' => array(
        'grid16-width' => 'grid16-16',
        'fusion-alignment' => 'fusion-center',
        'fusion-content-alignment' => 'fusion-center-content',
        'fusion-menu' => 'fusion-inline-menu',
      ),
    ),
  );

  $export['skinr_divine'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_divine_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_search' => 0,
    'toggle_favicon' => 1,
    'toggle_primary_links' => 1,
    'toggle_secondary_links' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'theme_grid' => 'grid16-960',
    'fluid_grid_width' => 'fluid-100',
    'sidebar_layout' => 'sidebars-split',
    'sidebar_first_width' => '3',
    'sidebar_last_width' => '5',
    'theme_font' => 'font-family-lucida',
    'theme_font_size' => 'font-size-13',
    'primary_menu_dropdown' => 1,
    'breadcrumb_display' => 1,
    'search_snippet' => 1,
    'search_info_type' => 1,
    'search_info_user' => 1,
    'search_info_date' => 1,
    'search_info_comment' => 1,
    'search_info_upload' => 1,
    'user_notverified_display' => 1,
    'block_config_link' => 1,
    'grid_mask' => 1,
    'rebuild_registry' => 0,
    'fix_css_limit' => 0,
  );

  $export['theme_divine_settings'] = $strongarm;
  return $export;
}
