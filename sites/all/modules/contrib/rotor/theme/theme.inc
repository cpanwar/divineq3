<?php

/**
 * @file theme.inc
 * Preprocessing for views themes.
 */

/**
 * Preprocess the primary theme implementation for a view.
 */
function template_preprocess_rotor_view_rotor(&$vars) {
  $view = $vars['view'];
  $vars['css_name']   = views_css_safe($view->name);
  $vars['name']       = $view->name;
  $vars['display_id'] = $view->current_display;
  
  $vars['style'] = '';
  if ($vars['options']['width'] > 0) {
    $vars['style'] .= ' width: '. $vars['options']['width'] .'px;';
  }
  if ($vars['options']['height'] > 0) {
    $vars['style'] .= ' height: '. $vars['options']['height'] .'px;';
  }
}
