<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function all_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-authentication-menu
  $menus['menu-authentication-menu'] = array(
    'menu_name' => 'menu-authentication-menu',
    'title' => 'Authentication menu',
    'description' => 'Login, Register links on the header',
  );
  // Exported menu: menu-footer-menu-1
  $menus['menu-footer-menu-1'] = array(
    'menu_name' => 'menu-footer-menu-1',
    'title' => 'Footer contact us links',
    'description' => 'Footer menu for contact, feedback and other purposes',
  );
  // Exported menu: menu-footer-menu-2
  $menus['menu-footer-menu-2'] = array(
    'menu_name' => 'menu-footer-menu-2',
    'title' => 'Footer privacy links',
    'description' => 'Footer menu for privacy, terms and other',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Authentication menu');
  t('Footer contact us links');
  t('Footer menu for contact, feedback and other purposes');
  t('Footer menu for privacy, terms and other');
  t('Footer privacy links');
  t('Login, Register links on the header');


  return $menus;
}
