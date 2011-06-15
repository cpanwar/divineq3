<?php
// $id$


/*
 * Implementation of hook_views_data()
 */
function tellafriend_node_views_data() {
  $data = array(
    'tellafriend_node_data' => array(
      'table' => array(
        'join' => array(
          'node' => array(
            'left_field' => 'nid',
            'field' => 'nid',
          ),
        ),
      ),
      'tellafriend_node_send_ecard_link' => array(
        'real field' => 'nid',
        'title' => t('Send this ecard link'),
        'group' => 'Tellafriend Node',
        'help' => t('Include a "Send this ecard" link'),
        'field' => array(
          'handler' => 'tellafriend_node_handler_field_tellafriend_node_send_ecard_link',
        ),
      ),
      'tellafriend_node_subject' => array(
        'title' => t('Subject'),
        'group' => 'Tellafriend Node',
        'help' => t(''),
        'field' => array(
          'handler' => 'views_handler_field',
        ),
      ),
      'tellafriend_node_message' => array(
        'title' => t('Message'),
        'group' => 'Tellafriend Node',
        'help' => t(''),
        'field' => array(
          'handler' => 'views_handler_field',
        ),
      ),
      'tellafriend_node_format_as_ecard' => array(
        'title' => t('Format node as ecard'),
        'group' => 'Tellafriend Node',
        'help' => t('This is just a boolean value.'),
        'field' => array(
          'handler' => 'views_handler_field',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_boolean_operator',
        ),
      ),
      'tellafriend_node_ecard_thumbnail_image' => array(
        'title' => t('Ecard thumbnail image'),
        'group' => 'Tellafriend Node',
        'field' => array(
          'handler' => 'tellafriend_node_handler_field_tellafriend_node_thumbnail_image',
        ),
      ),
      'tellafriend_node_ecard_fullsize_image' => array(
        'title' => t('Ecard full size image'),
        'group' => 'Tellafriend Node',
        'field' => array(
          'handler' => 'tellafriend_node_handler_field_tellafriend_node_fullsize_image',
        ),
      ),
    ),
  );
  return $data;
}

function tellafriend_node_views_handlers() {
  $data = array(
    'info' => array(
      'path' => drupal_get_path('module', 'tellafriend_node'),
    ),
    'handlers' => array(
      'tellafriend_node_handler_field_tellafriend_node_thumbnail_image' => array(
        'parent' => 'views_handler_field',
        'file' => 'tellafriend_node_handler_field_tellafriend_node_thumbnail_image.inc',
      ),
      'tellafriend_node_handler_field_tellafriend_node_fullsize_image' => array(
        'parent' => 'views_handler_field',
        'file' => 'tellafriend_node_handler_field_tellafriend_node_fullsize_image.inc',
      ),
      'tellafriend_node_handler_field_tellafriend_node_send_ecard_link' => array(
        'parent' => 'views_handler_field',
        'file' => 'tellafriend_node_handler_field_tellafriend_node_send_ecard_link.inc',
      ),
    ),
  );
  return $data;
}
