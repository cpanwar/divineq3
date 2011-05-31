<?php
/**
 * Sets the body-tag class attribute.
 */
function framework_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $string));
  // If the first character is not a-z, add 'id' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
    $string = 'id' . $string;
  }
  return $string;
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function framework_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
// uncomment the next line to enable current page in the breadcrumb trail
//    $breadcrumb[] = drupal_get_title();
    return '<nav class="breadcrumb">'. implode(' » ', $breadcrumb) .'</nav>';
  }
}

/**
 * Allow themable wrapping of all comments.
 */
function framework_comment_wrapper($content, $node) {
  if (!$content || $node->type == 'forum') {
    return '<section id="comments">'. $content .'</section>';
  }
  else {
    return '<section id="comments"><h2>'. t('Comments') .'</h2>'. $content .'</section>';
  }
}

/**
 * Allow theming of publishing information.
 */
function framework_node_submitted($node) {
  return t('Published by !username on !datetime',
    array(
      '!username' => '<span class="author">'. theme('username', $node). '</span>',
      '!datetime' => '<time datetime="!fulldatetime">'. format_date($node->created). '</time>',
      '!fulldatetime' => format_date($node->created, 'custom', 'Y-m-d\TH:i:sZ')
    ));
}

function framework_comment_submitted($comment) {
  return t('!username | !datetime',
    array(
      '!username' => '<span class="author">'. theme('username', $comment). '</span>',
      '!datetime' => '<time datetime="!fulldatetime">'. format_date($comment->timestamp). '</time>',
      '!fulldatetime' => format_date($comment->created, 'custom', 'Y-m-d\TH:i:sZ')
    ));
}

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function framework_preprocess_block(&$vars, $hook) {
  $block = $vars['block'];

  // Drupal 7 uses a $content variable instead of $block->content.
  $vars['content'] = $block->content;
  // Drupal 7 should use a $title variable instead of $block->subject.
  $vars['title'] = $block->subject;

  // Special classes for blocks.
  $vars['classes_array'][] = 'block-' . $block->module;
  $vars['classes_array'][] = 'region-' . $vars['block_zebra'];
  $vars['classes_array'][] = $vars['zebra'];
  $vars['classes_array'][] = 'region-count-' . $vars['block_id'];
  $vars['classes_array'][] = 'count-' . $vars['id'];

  // Create the block ID.
  $vars['block_html_id'] = 'block-' . $block->module . '-' . $block->delta;

  $vars['edit_links_array'] = array();
  if (user_access('administer blocks')) {
    include_once './' . drupal_get_path('theme', 'framework') . '/template.block-editing.inc';
    framework_preprocess_block_editing($vars, $hook);
    $vars['classes_array'][] = 'with-block-editing';
  }
  $vars['edit_links'] = !empty($vars['edit_links_array']) ? '<div class="edit">' . implode(' ', $vars['edit_links_array']) . '</div>' : '';
}

function framework_taxonomy_term_page($tids, $result) {
  drupal_add_css(drupal_get_path('module', 'taxonomy') .'/taxonomy.css');

  $output = '';

  // Only display the description if we have a single term, to avoid clutter and confusion.
  if (count($tids) == 1) {
    $term = taxonomy_get_term($tids[0]);
    $description = $term->description;

    // Check that a description is set.
    if (!empty($description)) {
      $output .= '<div class="taxonomy-term-description">';
      $output .= filter_xss_admin($description);
      $output .= '</div>';
    }
    
      //$output .= 'anjan';
      $output .= '<div class="category_image">'.taxonomy_image_display($term->tid, "alt='$term->name'").'</div>';
  }

  //$output .= taxonomy_render_nodes($result);

  return $output;
}

function framework_preprocess_page(&$vars, $hook) {
   if (arg(0) == 'node' && arg(1) == 'add' && arg(2) == 'class-shedule') {
      $vars['title'] = 'Shedule a Trial Class';
      //$vars['title']['#suffix'] = 'Shedule a Trial Class';
   }
}

function framework_form_element($element, $value) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  $output = '<div class="form-item"';
  if (!empty($element['#id'])) {
    $output .= ' id="'. $element['#id'] .'-wrapper"';
  }
  $output .= ">\n";
  $required = !empty($element['#required']) ? '<span class="form-required" title="'. $t('This field is required.') .'">*</span>' : '';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    if (!empty($element['#id'])) {
      $output .= ' <label for="'. $element['#id'] .'">'. $t('!title !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
    else {
      $output .= ' <label>'. $t('!title !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
  }

  $output .= " $value\n";

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">'. $element['#description'] ."</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}