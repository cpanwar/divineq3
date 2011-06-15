<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function block_settings_default_fe_block_settings() {
  $export = array();

  // divine
  $theme = array();

  $theme['block-newspaper_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
    'machine_name' => 'newspaper_feature',
  );

  $theme['block-wellness_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'wellness_feature',
  );

  $theme['block-livesession_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'livesession_feature',
  );

  $theme['block-meetguru_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'meetguru_feature',
  );

  $theme['block-liveconsultation_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'liveconsultation_feature',
  );

  $theme['block-corporatewellness_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'corporatewellness_feature',
  );

  $theme['block-explore_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'EXPLORE OUR PROGRAMS',
    'cache' => '-1',
    'machine_name' => 'explore_feature',
  );

  $theme['block-askanexpert_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
admin/*
instructor',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'askanexpert_feature',
  );

  $theme['block-recentpost_static'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'recentpost_static',
  );

  $theme['block-userprofile_fav_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Favourites',
    'cache' => '-1',
    'machine_name' => 'userprofile_fav_feature',
  );

  $theme['block-userprofile_community_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Community',
    'cache' => '-1',
    'machine_name' => 'userprofile_community_feature',
  );

  $theme['block-howitworks_static'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => 'How it Works',
    'cache' => '-1',
    'machine_name' => 'howitworks_static',
  );

  $theme['block-mypackage_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Packages',
    'cache' => '-1',
    'machine_name' => 'mypackage_feature',
  );

  $theme['block-bookedclass_feature'] = array(
    'module' => 'block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'Booked Schedules',
    'cache' => '-1',
    'machine_name' => 'bookedclass_feature',
  );

  $theme['blog-0'] = array(
    'module' => 'blog',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-45',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-0'] = array(
    'module' => 'comment',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-18',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-0'] = array(
    'module' => 'faq',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-26',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-1'] = array(
    'module' => 'faq',
    'delta' => '1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-22',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-2'] = array(
    'module' => 'faq',
    'delta' => '2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-24',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['fivestar-0'] = array(
    'module' => 'fivestar',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-12',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-0'] = array(
    'module' => 'forum',
    'delta' => '0',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-60',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'community',
    'title' => 'Message Board',
    'cache' => '1',
  );

  $theme['forum-1'] = array(
    'module' => 'forum',
    'delta' => '1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-19',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['homebox-custom'] = array(
    'module' => 'homebox',
    'delta' => 'custom',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-25',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['logintoboggan-0'] = array(
    'module' => 'logintoboggan',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-devel'] = array(
    'module' => 'menu',
    'delta' => 'devel',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-20',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-features'] = array(
    'module' => 'menu',
    'delta' => 'features',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-47',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-authentication-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-authentication-menu',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-61',
    'region' => 'header',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['menu-menu-community'] = array(
    'module' => 'menu',
    'delta' => 'menu-community',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-customerservice'] = array(
    'module' => 'menu',
    'delta' => 'menu-customerservice',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footer-navigation'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer-navigation',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-31',
    'region' => 'footer',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['menu-menu-footermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-footermenu',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu1'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu2'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-join-divine-wellness'] = array(
    'module' => 'menu',
    'delta' => 'menu-join-divine-wellness',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-myaccount'] = array(
    'module' => 'menu',
    'delta' => 'menu-myaccount',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-59',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-resource'] = array(
    'module' => 'menu',
    'delta' => 'menu-resource',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-usermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-usermenu',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-60',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-44',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-secondary-links'] = array(
    'module' => 'menu',
    'delta' => 'secondary-links',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-42',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['nice_menus-1'] = array(
    'module' => 'nice_menus',
    'delta' => '1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['node-0'] = array(
    'module' => 'node',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-29',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['poll-0'] = array(
    'module' => 'poll',
    'delta' => '0',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-51',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>
node/*/edit
admin',
    'title' => 'Polls',
    'cache' => '1',
  );

  $theme['print-0'] = array(
    'module' => 'print',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-10',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['print-1'] = array(
    'module' => 'print',
    'delta' => '1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-11',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '8',
  );

  $theme['profile-0'] = array(
    'module' => 'profile',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-53',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '5',
  );

  $theme['question-0'] = array(
    'module' => 'question',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-28',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['question-1'] = array(
    'module' => 'question',
    'delta' => '1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-23',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['quicktabs-1'] = array(
    'module' => 'quicktabs',
    'delta' => '1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-57',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
node/*/edit
admin',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-10'] = array(
    'module' => 'quicktabs',
    'delta' => '10',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-54',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-11'] = array(
    'module' => 'quicktabs',
    'delta' => '11',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-12'] = array(
    'module' => 'quicktabs',
    'delta' => '12',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-2'] = array(
    'module' => 'quicktabs',
    'delta' => '2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-61',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['quicktabs-3'] = array(
    'module' => 'quicktabs',
    'delta' => '3',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-55',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-4'] = array(
    'module' => 'quicktabs',
    'delta' => '4',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-49',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['quicktabs-5'] = array(
    'module' => 'quicktabs',
    'delta' => '5',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-31',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['quicktabs-6'] = array(
    'module' => 'quicktabs',
    'delta' => '6',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-58',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3762',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-8'] = array(
    'module' => 'quicktabs',
    'delta' => '8',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-50',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'video/*',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['quicktabs-9'] = array(
    'module' => 'quicktabs',
    'delta' => '9',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-56',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['search-0'] = array(
    'module' => 'search',
    'delta' => '0',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-62',
    'region' => 'header',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['sharethis-sharethis'] = array(
    'module' => 'sharethis',
    'delta' => 'sharethis',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-21',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['site_map-0'] = array(
    'module' => 'site_map',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '3',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['statistics-0'] = array(
    'module' => 'statistics',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-35',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['system-0'] = array(
    'module' => 'system',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-58',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['uc_cart-0'] = array(
    'module' => 'uc_cart',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-41',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['uc_catalog-0'] = array(
    'module' => 'uc_catalog',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-51',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['uc_coupon-0'] = array(
    'module' => 'uc_coupon',
    'delta' => '0',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-27',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-0'] = array(
    'module' => 'user',
    'delta' => '0',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-62',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['user-1'] = array(
    'module' => 'user',
    'delta' => '1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-49',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['user-2'] = array(
    'module' => 'user',
    'delta' => '2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '7',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-3'] = array(
    'module' => 'user',
    'delta' => '3',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '8',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views--exp-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => '-exp-ask_an_expert-block_3',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-56',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'question',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-Category_related_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'Category_related_video-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-49',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-aea2bcc4980651448a7febf07d7c6729'] = array(
    'module' => 'views',
    'delta' => 'aea2bcc4980651448a7febf07d7c6729',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-4',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'articles-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-56',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'node/*/edit',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['views-articles-block_2'] = array(
    'module' => 'views',
    'delta' => 'articles-block_2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-54',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Related Articles',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_1'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-62',
    'region' => 'content_new',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>
community',
    'title' => 'Ask An Expert',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_2'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-6',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_3',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-55',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'question',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['views-block_all-block_1'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-54',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_2'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_2',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-52',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_3'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_3',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-53',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_4'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_4',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-51',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-40',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_2'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '5',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'My Blog',
    'cache' => '-1',
  );

  $theme['views-current_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'current_video-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-17',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-dashboard_forum-block_1'] = array(
    'module' => 'views',
    'delta' => 'dashboard_forum-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-5',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-events_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'events_view-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-38',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-f673a5c15fdb840a8081477f9413598e'] = array(
    'module' => 'views',
    'delta' => 'f673a5c15fdb840a8081477f9413598e',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '1',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-faq_list-block_1'] = array(
    'module' => 'views',
    'delta' => 'faq_list-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-63',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'resource_lib',
    'title' => 'FAQ',
    'cache' => '-1',
  );

  $theme['views-fav_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_articles-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-62',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_kidzone-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_kidzone-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '2',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-favourite_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'favourite_articles-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-37',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-featured_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'featured_videos-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-3',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_1'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-15',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_2'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-43',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'community',
    'title' => 'MESSAGE BOARD',
    'cache' => '-1',
  );

  $theme['views-glossery-block_1'] = array(
    'module' => 'views',
    'delta' => 'glossery-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-62',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'resource_lib',
    'title' => 'Glossery',
    'cache' => '-1',
  );

  $theme['views-health_az-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_az-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-53',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
node/*/edit
admin',
    'title' => 'Health A-Z',
    'cache' => '-1',
  );

  $theme['views-health_news-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-39',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_2'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_2',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-50',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'Health News',
    'cache' => '-1',
  );

  $theme['views-health_qna-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-32',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna_extra-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-2',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-30',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip_extra-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-1',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-36',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles_extra-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_1'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-59',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_2'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_2',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-58',
    'region' => 'sidebar_last',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => 'Knowledge Base',
    'cache' => '-1',
  );

  $theme['views-most_viewed_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'most_viewed_articles-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-33',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-nodequeue_1-block'] = array(
    'module' => 'views',
    'delta' => 'nodequeue_1-block',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-50',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'yoga_sequence',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-poll_questions-block_2'] = array(
    'module' => 'views',
    'delta' => 'poll_questions-block_2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '6',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-16',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_2'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_2',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '4',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_recepies-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-59',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Recepies',
    'cache' => '-1',
  );

  $theme['views-related_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_videos-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-14',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-rotor-block_1'] = array(
    'module' => 'views',
    'delta' => 'rotor-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-smartqueue_users_user_1-block_1'] = array(
    'module' => 'views',
    'delta' => 'smartqueue_users_user_1-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-13',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-testimonies-block_1'] = array(
    'module' => 'views',
    'delta' => 'testimonies-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-61',
    'region' => 'content_new',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'Our customer say..',
    'cache' => '-1',
  );

  $theme['views-user_profile_info-block_1'] = array(
    'module' => 'views',
    'delta' => 'user_profile_info-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-video_related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'video_related_recepies-block_1',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-34',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'videos-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-61',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'resource_lib',
    'title' => 'Videos',
    'cache' => '-1',
  );

  $theme['views-videos-block_3'] = array(
    'module' => 'views',
    'delta' => 'videos-block_3',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-57',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
node/*/edit',
    'title' => 'Watch associated videos',
    'cache' => '-1',
  );

  $theme['views-videos-block_4'] = array(
    'module' => 'views',
    'delta' => 'videos-block_4',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-60',
    'region' => 'content_new',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'Videos',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-27',
    'region' => 'content_top',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3155',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_2'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_2',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-28',
    'region' => 'content_top',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3156',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_3'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_3',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-26',
    'region' => 'content_top',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3157',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_4'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_4',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-29',
    'region' => 'content_top',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3158',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_5'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_5',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-28',
    'region' => 'preface_top',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_mudra-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_mudra-block_1',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '-57',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'yoga_sequence',
    'title' => 'Your yoga sequence',
    'cache' => '-1',
  );

  $theme['webform-client-block-1773'] = array(
    'module' => 'webform',
    'delta' => 'client-block-1773',
    'theme' => 'divine',
    'status' => 0,
    'weight' => '-48',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-4067'] = array(
    'module' => 'webform',
    'delta' => 'client-block-4067',
    'theme' => 'divine',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'contact-us',
    'title' => '<none>',
    'cache' => '-1',
  );

  $export['divine'] = $theme;

  // dw_theme
  $theme = array();

  $theme['block-newspaper_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '0',
    'region' => 'footer',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
    'machine_name' => 'newspaper_feature',
  );

  $theme['block-wellness_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-75',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'wellness_feature',
  );

  $theme['block-livesession_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-74',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'livesession_feature',
  );

  $theme['block-meetguru_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-73',
    'region' => 'footer_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'meetguru_feature',
  );

  $theme['block-liveconsultation_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-72',
    'region' => 'footer_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'liveconsultation_feature',
  );

  $theme['block-corporatewellness_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-71',
    'region' => 'footer_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'corporatewellness_feature',
  );

  $theme['block-explore_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-74',
    'region' => 'explore_programs',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'EXPLORE OUR PROGRAMS',
    'cache' => '-1',
    'machine_name' => 'explore_feature',
  );

  $theme['block-askanexpert_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-73',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
admin/*
instructor',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'askanexpert_feature',
  );

  $theme['block-recentpost_static'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-72',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'recentpost_static',
  );

  $theme['block-userprofile_fav_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-57',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Favourites',
    'cache' => '-1',
    'machine_name' => 'userprofile_fav_feature',
  );

  $theme['block-userprofile_community_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-56',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Community',
    'cache' => '-1',
    'machine_name' => 'userprofile_community_feature',
  );

  $theme['block-howitworks_static'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-70',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => 'How it Works',
    'cache' => '-1',
    'machine_name' => 'howitworks_static',
  );

  $theme['block-mypackage_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-59',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Packages',
    'cache' => '-1',
    'machine_name' => 'mypackage_feature',
  );

  $theme['block-bookedclass_feature'] = array(
    'module' => 'block',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-58',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'Booked Schedules',
    'cache' => '-1',
    'machine_name' => 'bookedclass_feature',
  );

  $theme['blog-0'] = array(
    'module' => 'blog',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-26',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-0'] = array(
    'module' => 'comment',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-0'] = array(
    'module' => 'faq',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-8',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-1'] = array(
    'module' => 'faq',
    'delta' => '1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-4',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-2'] = array(
    'module' => 'faq',
    'delta' => '2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-6',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['fivestar-0'] = array(
    'module' => 'fivestar',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '6',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-0'] = array(
    'module' => 'forum',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-73',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'community',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-1'] = array(
    'module' => 'forum',
    'delta' => '1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-1',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['homebox-custom'] = array(
    'module' => 'homebox',
    'delta' => 'custom',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-7',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['logintoboggan-0'] = array(
    'module' => 'logintoboggan',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '17',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-devel'] = array(
    'module' => 'menu',
    'delta' => 'devel',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-2',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-features'] = array(
    'module' => 'menu',
    'delta' => 'features',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-27',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-authentication-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-authentication-menu',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-48',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-community'] = array(
    'module' => 'menu',
    'delta' => 'menu-community',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-64',
    'region' => 'footer_links',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-customerservice'] = array(
    'module' => 'menu',
    'delta' => 'menu-customerservice',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-65',
    'region' => 'footer_links',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footer-navigation'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer-navigation',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-45',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-footermenu',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-66',
    'region' => 'footer',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu1'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-69',
    'region' => 'header',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu2'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu2',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-66',
    'region' => 'header',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['menu-menu-join-divine-wellness'] = array(
    'module' => 'menu',
    'delta' => 'menu-join-divine-wellness',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-66',
    'region' => 'footer_links',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-myaccount'] = array(
    'module' => 'menu',
    'delta' => 'menu-myaccount',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-39',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-resource'] = array(
    'module' => 'menu',
    'delta' => 'menu-resource',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-63',
    'region' => 'footer_links',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-usermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-usermenu',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-68',
    'region' => 'header',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-22',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-secondary-links'] = array(
    'module' => 'menu',
    'delta' => 'secondary-links',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-24',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['nice_menus-1'] = array(
    'module' => 'nice_menus',
    'delta' => '1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-70',
    'region' => 'topmenu',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['node-0'] = array(
    'module' => 'node',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-11',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['poll-0'] = array(
    'module' => 'poll',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-61',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>
node/*/edit
admin',
    'title' => '',
    'cache' => '1',
  );

  $theme['print-0'] = array(
    'module' => 'print',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '8',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['print-1'] = array(
    'module' => 'print',
    'delta' => '1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '7',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '8',
  );

  $theme['profile-0'] = array(
    'module' => 'profile',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-33',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '5',
  );

  $theme['question-0'] = array(
    'module' => 'question',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-10',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['question-1'] = array(
    'module' => 'question',
    'delta' => '1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-5',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['quicktabs-1'] = array(
    'module' => 'quicktabs',
    'delta' => '1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-55',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
node/*/edit
admin',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-10'] = array(
    'module' => 'quicktabs',
    'delta' => '10',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-58',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-11'] = array(
    'module' => 'quicktabs',
    'delta' => '11',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-55',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
user/*
yoga
ayurveda
diet-nutrition
alternatives',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['quicktabs-12'] = array(
    'module' => 'quicktabs',
    'delta' => '12',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/*',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['quicktabs-2'] = array(
    'module' => 'quicktabs',
    'delta' => '2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-40',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-3'] = array(
    'module' => 'quicktabs',
    'delta' => '3',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-57',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-4'] = array(
    'module' => 'quicktabs',
    'delta' => '4',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-29',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['quicktabs-5'] = array(
    'module' => 'quicktabs',
    'delta' => '5',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-13',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-6'] = array(
    'module' => 'quicktabs',
    'delta' => '6',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-71',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3762',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-8'] = array(
    'module' => 'quicktabs',
    'delta' => '8',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-63',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'video/*',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-9'] = array(
    'module' => 'quicktabs',
    'delta' => '9',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-56',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['search-0'] = array(
    'module' => 'search',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-69',
    'region' => 'topmenu',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['sharethis-sharethis'] = array(
    'module' => 'sharethis',
    'delta' => 'sharethis',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-3',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['site_map-0'] = array(
    'module' => 'site_map',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '21',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['statistics-0'] = array(
    'module' => 'statistics',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-17',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['system-0'] = array(
    'module' => 'system',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-38',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['uc_cart-0'] = array(
    'module' => 'uc_cart',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-67',
    'region' => 'header',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['uc_catalog-0'] = array(
    'module' => 'uc_catalog',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-31',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['uc_coupon-0'] = array(
    'module' => 'uc_coupon',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-9',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-0'] = array(
    'module' => 'user',
    'delta' => '0',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-76',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['user-1'] = array(
    'module' => 'user',
    'delta' => '1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-76',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['user-2'] = array(
    'module' => 'user',
    'delta' => '2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '25',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-3'] = array(
    'module' => 'user',
    'delta' => '3',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '26',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views--exp-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => '-exp-ask_an_expert-block_3',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-69',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'question',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-Category_related_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'Category_related_video-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-62',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-aea2bcc4980651448a7febf07d7c6729'] = array(
    'module' => 'views',
    'delta' => 'aea2bcc4980651448a7febf07d7c6729',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '14',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'articles-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-36',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => 'node/*/edit',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_2'] = array(
    'module' => 'views',
    'delta' => 'articles-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-34',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_1'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-49',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>
community',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_2'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '12',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_3',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-68',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'question',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_1'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-67',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_2'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_2',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-65',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_3'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_3',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-66',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_4'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_4',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-64',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-23',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_2'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '23',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-current_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'current_video-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '1',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-dashboard_forum-block_1'] = array(
    'module' => 'views',
    'delta' => 'dashboard_forum-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '13',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-events_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'events_view-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-20',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-f673a5c15fdb840a8081477f9413598e'] = array(
    'module' => 'views',
    'delta' => 'f673a5c15fdb840a8081477f9413598e',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '19',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-faq_list-block_1'] = array(
    'module' => 'views',
    'delta' => 'faq_list-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-76',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'resource_lib',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_articles-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-43',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_kidzone-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_kidzone-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '20',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-favourite_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'favourite_articles-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-19',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-featured_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'featured_videos-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-71',
    'region' => 'right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_1'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '3',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_2'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-25',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'community',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-glossery-block_1'] = array(
    'module' => 'views',
    'delta' => 'glossery-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-75',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'resource_lib',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_az-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_az-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-59',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
node/*/edit
admin',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-21',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_2'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-62',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-14',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna_extra-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '15',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-12',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip_extra-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '16',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-18',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles_extra-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '18',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_1'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-53',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_2'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-54',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-most_viewed_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'most_viewed_articles-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-15',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-nodequeue_1-block'] = array(
    'module' => 'views',
    'delta' => 'nodequeue_1-block',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-30',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'yoga_sequence',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-poll_questions-block_2'] = array(
    'module' => 'views',
    'delta' => 'poll_questions-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '24',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '2',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_2'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '22',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_recepies-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-72',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_videos-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '4',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-rotor-block_1'] = array(
    'module' => 'views',
    'delta' => 'rotor-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-60',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-smartqueue_users_user_1-block_1'] = array(
    'module' => 'views',
    'delta' => 'smartqueue_users_user_1-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '5',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-testimonies-block_1'] = array(
    'module' => 'views',
    'delta' => 'testimonies-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-44',
    'region' => 'footer_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'Our customer say..',
    'cache' => '-1',
  );

  $theme['views-user_profile_info-block_1'] = array(
    'module' => 'views',
    'delta' => 'user_profile_info-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '0',
    'region' => 'left',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['views-video_related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'video_related_recepies-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-16',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'videos-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-74',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'resource_lib',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_3'] = array(
    'module' => 'views',
    'delta' => 'videos-block_3',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-37',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
node/*/edit',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_4'] = array(
    'module' => 'views',
    'delta' => 'videos-block_4',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-51',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_1',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-68',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3155',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_2'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_2',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-66',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3156',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_3'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_3',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-71',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3157',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_4'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_4',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-65',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'node/3158',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_5'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_5',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-64',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_mudra-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_mudra-block_1',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-70',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'yoga_sequence',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-1773'] = array(
    'module' => 'webform',
    'delta' => 'client-block-1773',
    'theme' => 'dw_theme',
    'status' => 0,
    'weight' => '-28',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-4067'] = array(
    'module' => 'webform',
    'delta' => 'client-block-4067',
    'theme' => 'dw_theme',
    'status' => '1',
    'weight' => '-61',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'contact-us',
    'title' => '',
    'cache' => '-1',
  );

  $export['dw_theme'] = $theme;

  // fusion_core
  $theme = array();

  $theme['block-newspaper_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
    'machine_name' => 'newspaper_feature',
  );

  $theme['block-wellness_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'wellness_feature',
  );

  $theme['block-livesession_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'livesession_feature',
  );

  $theme['block-meetguru_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'meetguru_feature',
  );

  $theme['block-liveconsultation_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'liveconsultation_feature',
  );

  $theme['block-corporatewellness_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'corporatewellness_feature',
  );

  $theme['block-explore_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'EXPLORE OUR PROGRAMS',
    'cache' => '-1',
    'machine_name' => 'explore_feature',
  );

  $theme['block-askanexpert_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
admin/*
instructor',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'askanexpert_feature',
  );

  $theme['block-recentpost_static'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'recentpost_static',
  );

  $theme['block-userprofile_fav_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Favourites',
    'cache' => '-1',
    'machine_name' => 'userprofile_fav_feature',
  );

  $theme['block-userprofile_community_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Community',
    'cache' => '-1',
    'machine_name' => 'userprofile_community_feature',
  );

  $theme['block-howitworks_static'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => 'How it Works',
    'cache' => '-1',
    'machine_name' => 'howitworks_static',
  );

  $theme['block-mypackage_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Packages',
    'cache' => '-1',
    'machine_name' => 'mypackage_feature',
  );

  $theme['block-bookedclass_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'Booked Schedules',
    'cache' => '-1',
    'machine_name' => 'bookedclass_feature',
  );

  $theme['blog-0'] = array(
    'module' => 'blog',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-0'] = array(
    'module' => 'comment',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-0'] = array(
    'module' => 'faq',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-1'] = array(
    'module' => 'faq',
    'delta' => '1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-2'] = array(
    'module' => 'faq',
    'delta' => '2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['fivestar-0'] = array(
    'module' => 'fivestar',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-0'] = array(
    'module' => 'forum',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-1'] = array(
    'module' => 'forum',
    'delta' => '1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['homebox-custom'] = array(
    'module' => 'homebox',
    'delta' => 'custom',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['logintoboggan-0'] = array(
    'module' => 'logintoboggan',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-devel'] = array(
    'module' => 'menu',
    'delta' => 'devel',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-features'] = array(
    'module' => 'menu',
    'delta' => 'features',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-authentication-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-authentication-menu',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-community'] = array(
    'module' => 'menu',
    'delta' => 'menu-community',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-customerservice'] = array(
    'module' => 'menu',
    'delta' => 'menu-customerservice',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footer-navigation'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer-navigation',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-footermenu',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu1'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu2'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-join-divine-wellness'] = array(
    'module' => 'menu',
    'delta' => 'menu-join-divine-wellness',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-myaccount'] = array(
    'module' => 'menu',
    'delta' => 'menu-myaccount',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-resource'] = array(
    'module' => 'menu',
    'delta' => 'menu-resource',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-usermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-usermenu',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-secondary-links'] = array(
    'module' => 'menu',
    'delta' => 'secondary-links',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['nice_menus-1'] = array(
    'module' => 'nice_menus',
    'delta' => '1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['node-0'] = array(
    'module' => 'node',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['poll-0'] = array(
    'module' => 'poll',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['print-0'] = array(
    'module' => 'print',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['print-1'] = array(
    'module' => 'print',
    'delta' => '1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '8',
  );

  $theme['profile-0'] = array(
    'module' => 'profile',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '5',
  );

  $theme['question-0'] = array(
    'module' => 'question',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['question-1'] = array(
    'module' => 'question',
    'delta' => '1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['quicktabs-1'] = array(
    'module' => 'quicktabs',
    'delta' => '1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-10'] = array(
    'module' => 'quicktabs',
    'delta' => '10',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-11'] = array(
    'module' => 'quicktabs',
    'delta' => '11',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-12'] = array(
    'module' => 'quicktabs',
    'delta' => '12',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-2'] = array(
    'module' => 'quicktabs',
    'delta' => '2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-3'] = array(
    'module' => 'quicktabs',
    'delta' => '3',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-4'] = array(
    'module' => 'quicktabs',
    'delta' => '4',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-5'] = array(
    'module' => 'quicktabs',
    'delta' => '5',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-6'] = array(
    'module' => 'quicktabs',
    'delta' => '6',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-8'] = array(
    'module' => 'quicktabs',
    'delta' => '8',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-9'] = array(
    'module' => 'quicktabs',
    'delta' => '9',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['search-0'] = array(
    'module' => 'search',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['sharethis-sharethis'] = array(
    'module' => 'sharethis',
    'delta' => 'sharethis',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['site_map-0'] = array(
    'module' => 'site_map',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['statistics-0'] = array(
    'module' => 'statistics',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['system-0'] = array(
    'module' => 'system',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => '1',
    'weight' => '10',
    'region' => 'footer',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['uc_cart-0'] = array(
    'module' => 'uc_cart',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['uc_catalog-0'] = array(
    'module' => 'uc_catalog',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['uc_coupon-0'] = array(
    'module' => 'uc_coupon',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-0'] = array(
    'module' => 'user',
    'delta' => '0',
    'theme' => 'fusion_core',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['user-1'] = array(
    'module' => 'user',
    'delta' => '1',
    'theme' => 'fusion_core',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['user-2'] = array(
    'module' => 'user',
    'delta' => '2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-3'] = array(
    'module' => 'user',
    'delta' => '3',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views--exp-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => '-exp-ask_an_expert-block_3',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-Category_related_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'Category_related_video-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-aea2bcc4980651448a7febf07d7c6729'] = array(
    'module' => 'views',
    'delta' => 'aea2bcc4980651448a7febf07d7c6729',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'articles-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_2'] = array(
    'module' => 'views',
    'delta' => 'articles-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_1'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_2'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_3',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_1'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_2'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_3'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_3',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_4'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_4',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_2'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-current_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'current_video-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-dashboard_forum-block_1'] = array(
    'module' => 'views',
    'delta' => 'dashboard_forum-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-events_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'events_view-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-f673a5c15fdb840a8081477f9413598e'] = array(
    'module' => 'views',
    'delta' => 'f673a5c15fdb840a8081477f9413598e',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-faq_list-block_1'] = array(
    'module' => 'views',
    'delta' => 'faq_list-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_articles-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_kidzone-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_kidzone-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-favourite_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'favourite_articles-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-featured_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'featured_videos-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_1'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_2'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-glossery-block_1'] = array(
    'module' => 'views',
    'delta' => 'glossery-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_az-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_az-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_2'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna_extra-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip_extra-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles_extra-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_1'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_2'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-most_viewed_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'most_viewed_articles-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-nodequeue_1-block'] = array(
    'module' => 'views',
    'delta' => 'nodequeue_1-block',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-poll_questions-block_2'] = array(
    'module' => 'views',
    'delta' => 'poll_questions-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_2'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_recepies-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_videos-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-rotor-block_1'] = array(
    'module' => 'views',
    'delta' => 'rotor-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-smartqueue_users_user_1-block_1'] = array(
    'module' => 'views',
    'delta' => 'smartqueue_users_user_1-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-testimonies-block_1'] = array(
    'module' => 'views',
    'delta' => 'testimonies-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-user_profile_info-block_1'] = array(
    'module' => 'views',
    'delta' => 'user_profile_info-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-video_related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'video_related_recepies-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'videos-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_3'] = array(
    'module' => 'views',
    'delta' => 'videos-block_3',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_4'] = array(
    'module' => 'views',
    'delta' => 'videos-block_4',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_2'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_2',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_3'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_3',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_4'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_4',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_5'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_5',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_mudra-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_mudra-block_1',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-1773'] = array(
    'module' => 'webform',
    'delta' => 'client-block-1773',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-4067'] = array(
    'module' => 'webform',
    'delta' => 'client-block-4067',
    'theme' => 'fusion_core',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $export['fusion_core'] = $theme;

  // fusion_starter
  $theme = array();

  $theme['block-newspaper_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
    'machine_name' => 'newspaper_feature',
  );

  $theme['block-wellness_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'wellness_feature',
  );

  $theme['block-livesession_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'livesession_feature',
  );

  $theme['block-meetguru_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'meetguru_feature',
  );

  $theme['block-liveconsultation_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'liveconsultation_feature',
  );

  $theme['block-corporatewellness_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'corporatewellness_feature',
  );

  $theme['block-explore_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'EXPLORE OUR PROGRAMS',
    'cache' => '-1',
    'machine_name' => 'explore_feature',
  );

  $theme['block-askanexpert_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
admin/*
instructor',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'askanexpert_feature',
  );

  $theme['block-recentpost_static'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'recentpost_static',
  );

  $theme['block-userprofile_fav_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Favourites',
    'cache' => '-1',
    'machine_name' => 'userprofile_fav_feature',
  );

  $theme['block-userprofile_community_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Community',
    'cache' => '-1',
    'machine_name' => 'userprofile_community_feature',
  );

  $theme['block-howitworks_static'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => 'How it Works',
    'cache' => '-1',
    'machine_name' => 'howitworks_static',
  );

  $theme['block-mypackage_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Packages',
    'cache' => '-1',
    'machine_name' => 'mypackage_feature',
  );

  $theme['block-bookedclass_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'Booked Schedules',
    'cache' => '-1',
    'machine_name' => 'bookedclass_feature',
  );

  $theme['blog-0'] = array(
    'module' => 'blog',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-0'] = array(
    'module' => 'comment',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-0'] = array(
    'module' => 'faq',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-1'] = array(
    'module' => 'faq',
    'delta' => '1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-2'] = array(
    'module' => 'faq',
    'delta' => '2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['fivestar-0'] = array(
    'module' => 'fivestar',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-0'] = array(
    'module' => 'forum',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-1'] = array(
    'module' => 'forum',
    'delta' => '1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['homebox-custom'] = array(
    'module' => 'homebox',
    'delta' => 'custom',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['logintoboggan-0'] = array(
    'module' => 'logintoboggan',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-devel'] = array(
    'module' => 'menu',
    'delta' => 'devel',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-features'] = array(
    'module' => 'menu',
    'delta' => 'features',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-authentication-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-authentication-menu',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-community'] = array(
    'module' => 'menu',
    'delta' => 'menu-community',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-customerservice'] = array(
    'module' => 'menu',
    'delta' => 'menu-customerservice',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footer-navigation'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer-navigation',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-footermenu',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu1'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu2'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-join-divine-wellness'] = array(
    'module' => 'menu',
    'delta' => 'menu-join-divine-wellness',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-myaccount'] = array(
    'module' => 'menu',
    'delta' => 'menu-myaccount',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-resource'] = array(
    'module' => 'menu',
    'delta' => 'menu-resource',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-usermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-usermenu',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-secondary-links'] = array(
    'module' => 'menu',
    'delta' => 'secondary-links',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['nice_menus-1'] = array(
    'module' => 'nice_menus',
    'delta' => '1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['node-0'] = array(
    'module' => 'node',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['poll-0'] = array(
    'module' => 'poll',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['print-0'] = array(
    'module' => 'print',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['print-1'] = array(
    'module' => 'print',
    'delta' => '1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '8',
  );

  $theme['profile-0'] = array(
    'module' => 'profile',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '5',
  );

  $theme['question-0'] = array(
    'module' => 'question',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['question-1'] = array(
    'module' => 'question',
    'delta' => '1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['quicktabs-1'] = array(
    'module' => 'quicktabs',
    'delta' => '1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-10'] = array(
    'module' => 'quicktabs',
    'delta' => '10',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-11'] = array(
    'module' => 'quicktabs',
    'delta' => '11',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-12'] = array(
    'module' => 'quicktabs',
    'delta' => '12',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-2'] = array(
    'module' => 'quicktabs',
    'delta' => '2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-3'] = array(
    'module' => 'quicktabs',
    'delta' => '3',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-4'] = array(
    'module' => 'quicktabs',
    'delta' => '4',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-5'] = array(
    'module' => 'quicktabs',
    'delta' => '5',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-6'] = array(
    'module' => 'quicktabs',
    'delta' => '6',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-8'] = array(
    'module' => 'quicktabs',
    'delta' => '8',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-9'] = array(
    'module' => 'quicktabs',
    'delta' => '9',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['search-0'] = array(
    'module' => 'search',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['sharethis-sharethis'] = array(
    'module' => 'sharethis',
    'delta' => 'sharethis',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['site_map-0'] = array(
    'module' => 'site_map',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['statistics-0'] = array(
    'module' => 'statistics',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['system-0'] = array(
    'module' => 'system',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => '1',
    'weight' => '10',
    'region' => 'footer',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['uc_cart-0'] = array(
    'module' => 'uc_cart',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['uc_catalog-0'] = array(
    'module' => 'uc_catalog',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['uc_coupon-0'] = array(
    'module' => 'uc_coupon',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-0'] = array(
    'module' => 'user',
    'delta' => '0',
    'theme' => 'fusion_starter',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['user-1'] = array(
    'module' => 'user',
    'delta' => '1',
    'theme' => 'fusion_starter',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['user-2'] = array(
    'module' => 'user',
    'delta' => '2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-3'] = array(
    'module' => 'user',
    'delta' => '3',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views--exp-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => '-exp-ask_an_expert-block_3',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-Category_related_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'Category_related_video-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-aea2bcc4980651448a7febf07d7c6729'] = array(
    'module' => 'views',
    'delta' => 'aea2bcc4980651448a7febf07d7c6729',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'articles-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_2'] = array(
    'module' => 'views',
    'delta' => 'articles-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_1'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_2'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_3',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_1'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_2'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_3'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_3',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_4'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_4',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_2'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-current_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'current_video-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-dashboard_forum-block_1'] = array(
    'module' => 'views',
    'delta' => 'dashboard_forum-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-events_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'events_view-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-f673a5c15fdb840a8081477f9413598e'] = array(
    'module' => 'views',
    'delta' => 'f673a5c15fdb840a8081477f9413598e',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-faq_list-block_1'] = array(
    'module' => 'views',
    'delta' => 'faq_list-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_articles-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_kidzone-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_kidzone-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-favourite_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'favourite_articles-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-featured_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'featured_videos-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_1'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_2'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-glossery-block_1'] = array(
    'module' => 'views',
    'delta' => 'glossery-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_az-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_az-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_2'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna_extra-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip_extra-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles_extra-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_1'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_2'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-most_viewed_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'most_viewed_articles-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-nodequeue_1-block'] = array(
    'module' => 'views',
    'delta' => 'nodequeue_1-block',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-poll_questions-block_2'] = array(
    'module' => 'views',
    'delta' => 'poll_questions-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_2'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_recepies-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_videos-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-rotor-block_1'] = array(
    'module' => 'views',
    'delta' => 'rotor-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-smartqueue_users_user_1-block_1'] = array(
    'module' => 'views',
    'delta' => 'smartqueue_users_user_1-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-testimonies-block_1'] = array(
    'module' => 'views',
    'delta' => 'testimonies-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-user_profile_info-block_1'] = array(
    'module' => 'views',
    'delta' => 'user_profile_info-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-video_related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'video_related_recepies-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'videos-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_3'] = array(
    'module' => 'views',
    'delta' => 'videos-block_3',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_4'] = array(
    'module' => 'views',
    'delta' => 'videos-block_4',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_2'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_2',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_3'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_3',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_4'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_4',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_5'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_5',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_mudra-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_mudra-block_1',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-1773'] = array(
    'module' => 'webform',
    'delta' => 'client-block-1773',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-4067'] = array(
    'module' => 'webform',
    'delta' => 'client-block-4067',
    'theme' => 'fusion_starter',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $export['fusion_starter'] = $theme;

  // fusion_starter_lite
  $theme = array();

  $theme['block-newspaper_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => '-1',
    'machine_name' => 'newspaper_feature',
  );

  $theme['block-wellness_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'wellness_feature',
  );

  $theme['block-livesession_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'livesession_feature',
  );

  $theme['block-meetguru_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'meetguru_feature',
  );

  $theme['block-liveconsultation_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'liveconsultation_feature',
  );

  $theme['block-corporatewellness_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'corporatewellness_feature',
  );

  $theme['block-explore_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => 'EXPLORE OUR PROGRAMS',
    'cache' => '-1',
    'machine_name' => 'explore_feature',
  );

  $theme['block-askanexpert_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>
admin/*
instructor',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'askanexpert_feature',
  );

  $theme['block-recentpost_static'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'user/*',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'recentpost_static',
  );

  $theme['block-userprofile_fav_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Favourites',
    'cache' => '-1',
    'machine_name' => 'userprofile_fav_feature',
  );

  $theme['block-userprofile_community_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Community',
    'cache' => '-1',
    'machine_name' => 'userprofile_community_feature',
  );

  $theme['block-howitworks_static'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => 'How it Works',
    'cache' => '-1',
    'machine_name' => 'howitworks_static',
  );

  $theme['block-mypackage_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'My Packages',
    'cache' => '-1',
    'machine_name' => 'mypackage_feature',
  );

  $theme['block-bookedclass_feature'] = array(
    'module' => 'block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '2',
    'pages' => '<?php
global $user;
if (arg(0) == \'user\' && $user->uid == arg(1) && is_numeric(arg(1)) && (arg(2) == NULL) )
{
  return TRUE;
}

else {
  return FALSE;
}
?>',
    'title' => 'Booked Schedules',
    'cache' => '-1',
    'machine_name' => 'bookedclass_feature',
  );

  $theme['blog-0'] = array(
    'module' => 'blog',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['comment-0'] = array(
    'module' => 'comment',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-0'] = array(
    'module' => 'faq',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-1'] = array(
    'module' => 'faq',
    'delta' => '1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['faq-2'] = array(
    'module' => 'faq',
    'delta' => '2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['fivestar-0'] = array(
    'module' => 'fivestar',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-0'] = array(
    'module' => 'forum',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['forum-1'] = array(
    'module' => 'forum',
    'delta' => '1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['homebox-custom'] = array(
    'module' => 'homebox',
    'delta' => 'custom',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['logintoboggan-0'] = array(
    'module' => 'logintoboggan',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-devel'] = array(
    'module' => 'menu',
    'delta' => 'devel',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-features'] = array(
    'module' => 'menu',
    'delta' => 'features',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-authentication-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-authentication-menu',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-community'] = array(
    'module' => 'menu',
    'delta' => 'menu-community',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-customerservice'] = array(
    'module' => 'menu',
    'delta' => 'menu-customerservice',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footer-navigation'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer-navigation',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-footermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-footermenu',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu1'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-headermenu2'] = array(
    'module' => 'menu',
    'delta' => 'menu-headermenu2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-join-divine-wellness'] = array(
    'module' => 'menu',
    'delta' => 'menu-join-divine-wellness',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-myaccount'] = array(
    'module' => 'menu',
    'delta' => 'menu-myaccount',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-resource'] = array(
    'module' => 'menu',
    'delta' => 'menu-resource',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-menu-usermenu'] = array(
    'module' => 'menu',
    'delta' => 'menu-usermenu',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-primary-links'] = array(
    'module' => 'menu',
    'delta' => 'primary-links',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['menu-secondary-links'] = array(
    'module' => 'menu',
    'delta' => 'secondary-links',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['nice_menus-1'] = array(
    'module' => 'nice_menus',
    'delta' => '1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['node-0'] = array(
    'module' => 'node',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['poll-0'] = array(
    'module' => 'poll',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['print-0'] = array(
    'module' => 'print',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['print-1'] = array(
    'module' => 'print',
    'delta' => '1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '8',
  );

  $theme['profile-0'] = array(
    'module' => 'profile',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '5',
  );

  $theme['question-0'] = array(
    'module' => 'question',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['question-1'] = array(
    'module' => 'question',
    'delta' => '1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['quicktabs-1'] = array(
    'module' => 'quicktabs',
    'delta' => '1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-10'] = array(
    'module' => 'quicktabs',
    'delta' => '10',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-11'] = array(
    'module' => 'quicktabs',
    'delta' => '11',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-12'] = array(
    'module' => 'quicktabs',
    'delta' => '12',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-2'] = array(
    'module' => 'quicktabs',
    'delta' => '2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-3'] = array(
    'module' => 'quicktabs',
    'delta' => '3',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-4'] = array(
    'module' => 'quicktabs',
    'delta' => '4',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-5'] = array(
    'module' => 'quicktabs',
    'delta' => '5',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-6'] = array(
    'module' => 'quicktabs',
    'delta' => '6',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-8'] = array(
    'module' => 'quicktabs',
    'delta' => '8',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-9'] = array(
    'module' => 'quicktabs',
    'delta' => '9',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['search-0'] = array(
    'module' => 'search',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['sharethis-sharethis'] = array(
    'module' => 'sharethis',
    'delta' => 'sharethis',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['site_map-0'] = array(
    'module' => 'site_map',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['statistics-0'] = array(
    'module' => 'statistics',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['system-0'] = array(
    'module' => 'system',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => '1',
    'weight' => '10',
    'region' => 'footer',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['uc_cart-0'] = array(
    'module' => 'uc_cart',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['uc_catalog-0'] = array(
    'module' => 'uc_catalog',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '4',
  );

  $theme['uc_coupon-0'] = array(
    'module' => 'uc_coupon',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-0'] = array(
    'module' => 'user',
    'delta' => '0',
    'theme' => 'fusion_starter_lite',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['user-1'] = array(
    'module' => 'user',
    'delta' => '1',
    'theme' => 'fusion_starter_lite',
    'status' => '1',
    'weight' => '0',
    'region' => 'sidebar_first',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['user-2'] = array(
    'module' => 'user',
    'delta' => '2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['user-3'] = array(
    'module' => 'user',
    'delta' => '3',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views--exp-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => '-exp-ask_an_expert-block_3',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['views-Category_related_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'Category_related_video-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-aea2bcc4980651448a7febf07d7c6729'] = array(
    'module' => 'views',
    'delta' => 'aea2bcc4980651448a7febf07d7c6729',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'articles-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-articles-block_2'] = array(
    'module' => 'views',
    'delta' => 'articles-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_1'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_2'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-ask_an_expert-block_3'] = array(
    'module' => 'views',
    'delta' => 'ask_an_expert-block_3',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_1'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_2'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_3'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_3',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-block_all-block_4'] = array(
    'module' => 'views',
    'delta' => 'block_all-block_4',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-blogs_view-block_2'] = array(
    'module' => 'views',
    'delta' => 'blogs_view-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-current_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'current_video-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-dashboard_forum-block_1'] = array(
    'module' => 'views',
    'delta' => 'dashboard_forum-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-events_view-block_1'] = array(
    'module' => 'views',
    'delta' => 'events_view-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-f673a5c15fdb840a8081477f9413598e'] = array(
    'module' => 'views',
    'delta' => 'f673a5c15fdb840a8081477f9413598e',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-faq_list-block_1'] = array(
    'module' => 'views',
    'delta' => 'faq_list-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_articles-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-fav_kidzone-block_1'] = array(
    'module' => 'views',
    'delta' => 'fav_kidzone-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-favourite_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'favourite_articles-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-featured_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'featured_videos-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_1'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-forum_section-block_2'] = array(
    'module' => 'views',
    'delta' => 'forum_section-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-glossery-block_1'] = array(
    'module' => 'views',
    'delta' => 'glossery-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_az-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_az-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_news-block_2'] = array(
    'module' => 'views',
    'delta' => 'health_news-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_qna_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_qna_extra-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-health_tip_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'health_tip_extra-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-hot_articles_extra-block_1'] = array(
    'module' => 'views',
    'delta' => 'hot_articles_extra-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_1'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-knowledge_base-block_2'] = array(
    'module' => 'views',
    'delta' => 'knowledge_base-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-most_viewed_articles-block_1'] = array(
    'module' => 'views',
    'delta' => 'most_viewed_articles-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-nodequeue_1-block'] = array(
    'module' => 'views',
    'delta' => 'nodequeue_1-block',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-poll_questions-block_2'] = array(
    'module' => 'views',
    'delta' => 'poll_questions-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_article_video-block_2'] = array(
    'module' => 'views',
    'delta' => 'related_article_video-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_recepies-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-related_videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'related_videos-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-rotor-block_1'] = array(
    'module' => 'views',
    'delta' => 'rotor-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-smartqueue_users_user_1-block_1'] = array(
    'module' => 'views',
    'delta' => 'smartqueue_users_user_1-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-testimonies-block_1'] = array(
    'module' => 'views',
    'delta' => 'testimonies-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-user_profile_info-block_1'] = array(
    'module' => 'views',
    'delta' => 'user_profile_info-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-video_related_recepies-block_1'] = array(
    'module' => 'views',
    'delta' => 'video_related_recepies-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_1'] = array(
    'module' => 'views',
    'delta' => 'videos-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_3'] = array(
    'module' => 'views',
    'delta' => 'videos-block_3',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-videos-block_4'] = array(
    'module' => 'views',
    'delta' => 'videos-block_4',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_2'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_2',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_3'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_3',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_4'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_4',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_banner-block_5'] = array(
    'module' => 'views',
    'delta' => 'yoga_banner-block_5',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-yoga_mudra-block_1'] = array(
    'module' => 'views',
    'delta' => 'yoga_mudra-block_1',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-1773'] = array(
    'module' => 'webform',
    'delta' => 'client-block-1773',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['webform-client-block-4067'] = array(
    'module' => 'webform',
    'delta' => 'client-block-4067',
    'theme' => 'fusion_starter_lite',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $export['fusion_starter_lite'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
