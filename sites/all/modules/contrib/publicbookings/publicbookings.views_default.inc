<?php
/**
 * @file
 * Default and internal views.
 *
 */

/**
 * Implementation of hook_views_default_views().
 *
 */
function publicbookings_views_default_views() {
  $view = publicbookings_view_schedules();
  $views[$view->name] = $view;

  $view = publicbookings_view_schedules_ad();
  $views[$view->name] = $view;
  
  $view = publicbookings_view_currently_happening();
  $views[$view->name] = $view;
  
  $view = publicbookings_view_current();
  $views[$view->name] = $view;
  
  $view = publicbookings_view_availability_admin();
  $views[$view->name] = $view;
  
  $view = publicbookings_view_resources_admin();
  $views[$view->name] = $view;

  $view = publicbookings_view_resources();
  $views[$view->name] = $view;
  
  $view = publicbookings_view_upcoming();
  $views[$view->name] = $view;
  
  return $views;
}

function publicbookings_default_view_object() {
  include_once('./'. drupal_get_path('module', 'views') .'/includes/view.inc');
  $view = new view;
  $view->description = '';
  $view->tag = 'Public Bookings';
  $view->view_php = '';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE;
  return $view;
}

function publicbookings_view_schedules_ad() {
  $view = publicbookings_default_view_object();
  $view->name = 'publicbookings_view_schedules_ad';
  $view->base_table = 'bookings_schedules';
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('use_pager', TRUE);
  $handler->override_option('items_per_page', '10');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('use_more_text', 'Next');
  $handler->override_option('fields', array(
    'name' => array(
      'label' => 'Name',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'bookings_records',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'start' => array(
      'label' => 'Starts',
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'start',
      'table' => 'bookings_schedules',
      'field' => 'start',
      'relationship' => 'none',
    ),
    'end' => array(
      'label' => 'Ends',
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'end',
      'table' => 'bookings_schedules',
      'field' => 'end',
      'relationship' => 'none',
    ),
    'resource_name' => array(
      'label' => 'Resource',
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'resource_id',
    ),
    'edit_booking' => array(
      'label' => '',
      'id' => 'edit_booking',
      'table' => 'bookings_records',
      'field' => 'edit_booking',
    ),
    'delete_booking' => array(
      'label' => '',
      'id' => 'delete_booking',
      'table' => 'bookings_records',
      'field' => 'delete_booking',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(1),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'type_op',
        'identifier' => 'type',
        'label' => 'Type',
        'optional' => 0,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'type',
      'table' => 'bookings_records',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'type' => array(
      'default_action' => 'ignore',
      'style_plugin' => 'not found',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'type',
      'table' => 'bookings_records',
      'field' => 'status',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'poll' => 0,
        'feedapi_node' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_php' => '',
    ),
  'date_argument' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'Alle',
    'title' => '',
    'breadcrumb' => '',
    'default_argument_type' => 'php',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'date_fields' => array(
      'bookings_schedules.end' => 'bookings_schedules.end',
    ),
    'year_range' => '-3:+3',
    'date_method' => 'OR',
    'granularity' => 'day',
    'id' => 'date_argument',
    'table' => 'bookings_records',
    'field' => 'date_argument',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '@--P1Y',
    'default_argument_user' => 0,
    'default_argument_php' => '$now = date_now();
$secPerYear = 60*60*24 * date_days_in_year($now);
$end = date_convert(date_convert($now, DATE_OBJECT, DATE_UNIX)+$secPerYear, DATE_UNIX, DATE_DATETIME, date_default_timezone_name());
return "@--$end";',
    'validate_argument_node_type' => array(
      'bookingsapi_resource' => 0,
      'page' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
    'role' => array(),
    'perm' => '',
  ));
  $handler->override_option('empty', t('None.'));

  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 1,
    'order' => 'asc',
    'columns' => array(
      'end' => 'end',
      'start' => 'start',
      'name' => 'name',
      'resource_name' => 'resource_name',
      'type' => 'type',
    ),
    'info' => array(
      'end' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'start' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'resource_name' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => 'start',
  ));

  return $view;
}
function publicbookings_view_schedules() {
  $view = publicbookings_default_view_object();
  $view->name = 'publicbookings_view_schedules';
  $view->description = '';
  $view->tag = 'Public Bookings';
  $view->view_php = '';
  $view->base_table = 'bookings_schedules';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('use_more_text', 'Next');
  $handler->override_option('relationships', array(
        'resource_id' => array(
          'label' => 'Resource',
          'required' => 0,
          'id' => 'resource_id',
          'table' => 'bookings_schedules',
          'field' => 'resource_id',
          'relationship' => 'none',
          ),
        ));
  $handler->override_option('fields', array(
        'name' => array(
          'label' => 'Name',
          'alter' => array(
            'alter_text' => 0,
            'text' => '',
            'make_link' => 0,
            'path' => '',
            'link_class' => '',
            'alt' => '',
            'prefix' => '',
            'suffix' => '',
            'target' => '',
            'help' => '',
            'trim' => 0,
            'max_length' => '',
            'word_boundary' => 1,
            'ellipsis' => 1,
            'strip_tags' => 0,
            'html' => 0,
            ),
          'empty' => '',
          'hide_empty' => 0,
          'empty_zero' => 0,
          'exclude' => 0,
          'id' => 'name',
          'table' => 'bookings_records',
          'field' => 'name',
          'relationship' => 'none',
          ),
          'start' => array(
              'label' => 'Start date',
              'alter' => array(
                'alter_text' => 0,
                'text' => '',
                'make_link' => 0,
                'path' => '',
                'link_class' => '',
                'alt' => '',
                'prefix' => '',
                'suffix' => '',
                'target' => '',
                'help' => '',
                'trim' => 0,
                'max_length' => '',
                'word_boundary' => 1,
                'ellipsis' => 1,
                'strip_tags' => 0,
                'html' => 0,
                ),
              'empty' => '',
              'hide_empty' => 0,
              'empty_zero' => 0,
              'date_format' => 'small',
              'custom_date_format' => '',
              'exclude' => 0,
              'id' => 'start',
              'table' => 'bookings_schedules',
              'field' => 'start',
              'relationship' => 'none',
              ),
              'end' => array(
                  'label' => 'End date',
                  'alter' => array(
                    'alter_text' => 0,
                    'text' => '',
                    'make_link' => 0,
                    'path' => '',
                    'link_class' => '',
                    'alt' => '',
                    'prefix' => '',
                    'suffix' => '',
                    'target' => '',
                    'help' => '',
                    'trim' => 0,
                    'max_length' => '',
                    'word_boundary' => 1,
                    'ellipsis' => 1,
                    'strip_tags' => 0,
                    'html' => 0,
                    ),
                  'empty' => '',
                  'hide_empty' => 0,
                  'empty_zero' => 0,
                  'date_format' => 'small',
                  'custom_date_format' => '',
                  'exclude' => 0,
                  'id' => 'end',
                  'table' => 'bookings_schedules',
                  'field' => 'end',
                  'relationship' => 'none',
                  ),
                  'title' => array(
                      'label' => 'Resource',
                      'alter' => array(
                        'alter_text' => 0,
                        'text' => '',
                        'make_link' => 0,
                        'path' => '',
                        'link_class' => '',
                        'alt' => '',
                        'prefix' => '',
                        'suffix' => '',
                        'target' => '',
                        'help' => '',
                        'trim' => 0,
                        'max_length' => '',
                        'word_boundary' => 1,
                        'ellipsis' => 1,
                        'strip_tags' => 0,
                        'html' => 0,
                        ),
                      'empty' => '',
                      'hide_empty' => 0,
                      'empty_zero' => 0,
                      'link_to_node' => 0,
                      'exclude' => 0,
                      'id' => 'title',
                      'table' => 'node',
                      'field' => 'title',
                      'relationship' => 'resource_id',
                      ),
                      'edit_booking' => array(
                          'label' => 'Edit booking link',
                          'alter' => array(
                            'alter_text' => 0,
                            'text' => '',
                            'make_link' => 0,
                            'path' => '',
                            'link_class' => '',
                            'alt' => '',
                            'prefix' => '',
                            'suffix' => '',
                            'target' => '',
                            'help' => '',
                            'trim' => 0,
                            'max_length' => '',
                            'word_boundary' => 1,
                            'ellipsis' => 1,
                            'strip_tags' => 0,
                            'html' => 0,
                            ),
                          'empty' => '',
                          'hide_empty' => 0,
                          'empty_zero' => 0,
                          'exclude' => 0,
                          'id' => 'edit_booking',
                          'table' => 'bookings_records',
                          'field' => 'edit_booking',
                          'relationship' => 'none',
                          ),
                          ));
  $handler->override_option('arguments', array(
        'status' => array(
          'default_action' => 'ignore',
          'style_plugin' => 'default_summary',
          'style_options' => array(),
          'wildcard' => 'all',
          'wildcard_substitution' => 'All',
          'title' => '',
          'breadcrumb' => '',
          'default_argument_type' => 'fixed',
          'default_argument' => '',
          'validate_type' => 'none',
          'validate_fail' => 'not found',
          'break_phrase' => 0,
          'not' => 0,
          'id' => 'status',
          'table' => 'bookings_records',
          'field' => 'status',
          'validate_user_argument_type' => 'uid',
          'validate_user_roles' => array(
            '2' => 0,
            ),
          'relationship' => 'none',
          'default_options_div_prefix' => '',
          'default_argument_user' => 0,
          'default_argument_fixed' => '',
          'default_argument_php' => '',
          'validate_argument_node_type' => array(
              'bookingsapi_resource' => 0,
              'page' => 0,
              'story' => 0,
              ),
          'validate_argument_node_access' => 0,
          'validate_argument_nid_type' => 'nid',
          'validate_argument_vocabulary' => array(),
          'validate_argument_type' => 'tid',
          'validate_argument_transform' => 0,
          'validate_user_restrict_roles' => 0,
          'validate_argument_php' => '',
          ),
          ));
  $handler->override_option('filters', array(
        'type' => array(
          'operator' => 'in',
          'value' => array(
            '1' => '1',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'type',
          'table' => 'bookings_records',
          'field' => 'type',
          'relationship' => 'none',
          ),
        'end' => array(
          'operator' => '>=',
          'value' => array(
            'type' => 'offset',
            'value' => 'NOW',
            'min' => '',
            'max' => '',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'end',
          'table' => 'bookings_schedules',
          'field' => 'end',
          'relationship' => 'none',
          ),
        ));
  $handler->override_option('access', array(
        'type' => 'none',
        ));
  $handler->override_option('cache', array(
        'type' => 'none',
        ));
  $handler->override_option('empty', 'None.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
        'grouping' => '',
        'override' => 1,
        'sticky' => 0,
        'order' => 'asc',
        'columns' => array(
          'name' => 'name',
          'end' => 'end',
          'start' => 'start',
          'title' => 'title',
          'edit_booking' => 'edit_booking',
          ),
        'info' => array(
          'name' => array(
            'sortable' => 0,
            'separator' => '',
            ),
          'end' => array(
            'sortable' => 0,
            'separator' => '',
            ),
          'start' => array(
            'sortable' => 1,
            'separator' => '',
            ),
          'title' => array(
            'sortable' => 0,
            'separator' => '',
            ),
          'edit_booking' => array(
            'separator' => '',
            ),
          ),
          'default' => 'start',
          ));

  return $view;
}

function publicbookings_view_current() {
  $view = publicbookings_default_view_object();
  $view->name = 'publicbookings_view_current';
  $view->description = '';
  $view->tag = 'Public Bookings';
  $view->view_php = '';
  $view->base_table = 'bookings_schedules';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('use_more_text', 'Next');
  $handler->override_option('relationships', array(
        'resource_id' => array(
          'label' => 'Resource',
          'required' => 0,
          'id' => 'resource_id',
          'table' => 'bookings_schedules',
          'field' => 'resource_id',
          'relationship' => 'none',
          ),
        ));
  $handler->override_option('fields', array(
        'end' => array(
          'label' => 'Ends',
          'date_format' => 'small',
          'custom_date_format' => '',
          'exclude' => 0,
          'id' => 'end',
          'table' => 'bookings_schedules',
          'field' => 'end',
          'relationship' => 'none',
          ),
        'start' => array(
          'label' => 'Starts',
          'date_format' => 'small',
          'custom_date_format' => '',
          'exclude' => 0,
          'id' => 'start',
          'table' => 'bookings_schedules',
          'field' => 'start',
          'relationship' => 'none',
          ),
        'name' => array(
            'label' => 'Name',
            'exclude' => 0,
            'id' => 'name',
            'table' => 'bookings_records',
            'field' => 'name',
            'relationship' => 'none',
            ),
        'title' => array(
            'label' => 'Resource',
            'alter' => array(
              'alter_text' => 0,
              'text' => '',
              'make_link' => 0,
              'path' => '',
              'link_class' => '',
              'alt' => '',
              'prefix' => '',
              'suffix' => '',
              'target' => '',
              'help' => '',
              'trim' => 0,
              'max_length' => '',
              'word_boundary' => 1,
              'ellipsis' => 1,
              'strip_tags' => 0,
              'html' => 0,
              ),
            'empty' => '',
            'hide_empty' => 0,
            'empty_zero' => 0,
            'link_to_node' => 0,
            'exclude' => 0,
            'id' => 'title',
            'table' => 'node',
            'field' => 'title',
            'relationship' => 'resource_id',
            ),
            ));
  $handler->override_option('sorts', array(
        'type' => array(
          'id' => 'type',
          'table' => 'bookings_records',
          'field' => 'type',
          ),
        ));
  $handler->override_option('filters', array(
        'type' => array(
          'operator' => 'in',
          'value' => array(
            '1' => 1,
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'type',
          'table' => 'bookings_schedules',
          'field' => 'type',
          'relationship' => 'none',
          ),
        'end' => array(
          'operator' => 'between',
          'value' => array(
            'type' => 'offset',
            'value' => '',
            'min' => '-1 hour',
            'max' => '+1 hour',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'end',
          'table' => 'bookings_schedules',
          'field' => 'end',
          'relationship' => 'none',
          ),
        ));
  $handler->override_option('access', array(
        'type' => 'none',
        'role' => array(),
        'perm' => '',
        ));
  $handler->override_option('cache', array(
        'type' => 'none',
        ));
  $handler->override_option('empty', 'Nothing to display.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('style_plugin', 'table');
  return $view;
}

function publicbookings_view_availability_admin() {
  $view = publicbookings_default_view_object();
  $view->name = 'publicbookings_view_avail_ad';
  $view->base_table = 'bookings_records';
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'type' => array(
      'label' => 'Type',
      'exclude' => 0,
      'id' => 'type',
      'table' => 'bookings_records',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Name',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'bookings_records',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'start' => array(
      'label' => 'Start',
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'start',
      'table' => 'bookings_records',
      'field' => 'start',
      'relationship' => 'none',
    ),
    'end' => array(
      'label' => 'End',
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'end',
      'table' => 'bookings_records',
      'field' => 'end',
      'relationship' => 'none',
    ),
    'rrule' => array(
      'label' => 'Repeat',
      'exclude' => 0,
      'id' => 'rrule',
      'table' => 'bookings_records',
      'field' => 'rrule',
      'relationship' => 'none',
    ),
    'edit_availability' => array(
      'label' => '',
      'exclude' => 0,
      'id' => 'edit_availability',
      'table' => 'bookings_records',
      'field' => 'edit_availability',
      'relationship' => 'none',
    ),
    'delete_availability' => array(
      'label' => '',
      'exclude' => 0,
      'id' => 'delete_availability',
      'table' => 'bookings_records',
      'field' => 'delete_availability',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        '2' => 2,
        '3' => 3,
        '4' => 4,
        '5' => 5,
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 0,
      'id' => 'type',
      'table' => 'bookings_records',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'resource_id' => array(
      'default_action' => 'empty',
      'style_plugin' => 'not found',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'resource_id',
      'table' => 'bookings_records',
      'field' => 'resource_id',
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'poll' => 0,
        'feedapi_node' => 0,
        'page' => 0,
        'story' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
    'role' => array(),
    'perm' => '',
  ));
  $handler->override_option('empty', t('No additional availability information defined for this resource.'));
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'delete_availability' => 'delete_availability',
      'edit_availability' => 'edit_availability',
      'end' => 'end',
      'start' => 'start',
      'name' => 'name',
    ),
    'info' => array(
      'delete_availability' => array(
        'separator' => '',
      ),
      'edit_availability' => array(
        'separator' => '',
      ),
      'type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'end' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'start' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => 'name',
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('use_more_text', 'Next');
  return $view;
}

function publicbookings_view_resources_admin() {
  $view = publicbookings_default_view_object();
  $view->name = 'publicbookings_view_resources_ad';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Standards', 'default');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('use_more_text', 'Next');
  $handler->override_option('fields', array(
        'title' => array(
          'label' => 'Titel',
          'alter' => array(
            'alter_text' => 0,
            'text' => '',
            'make_link' => 0,
            'path' => '',
            'link_class' => '',
            'alt' => '',
            'prefix' => '',
            'suffix' => '',
            'help' => '',
            'trim' => 0,
            'max_length' => '',
            'word_boundary' => 1,
            'ellipsis' => 1,
            'strip_tags' => 0,
            'html' => 0,
            ),
          'link_to_node' => 0,
          'exclude' => 0,
          'id' => 'title',
          'table' => 'node',
          'field' => 'title',
          'relationship' => 'none',
          ),
          'field_ba_location_value' => array(
              'label' => 'Location',
              'alter' => array(
                'alter_text' => 0,
                'text' => '',
                'make_link' => 0,
                'path' => '',
                'link_class' => '',
                'alt' => '',
                'prefix' => '',
                'suffix' => '',
                'help' => '',
                'trim' => 0,
                'max_length' => '',
                'word_boundary' => 1,
                'ellipsis' => 1,
                'strip_tags' => 0,
                'html' => 0,
                ),
              'link_to_node' => 0,
              'label_type' => 'widget',
              'format' => 'default',
              'multiple' => array(
                  'group' => TRUE,
                  'multiple_number' => '',
                  'multiple_from' => '',
                  'multiple_reversed' => FALSE,
                  ),
              'exclude' => 0,
              'id' => 'field_ba_location_value',
              'table' => 'node_data_field_ba_location',
              'field' => 'field_ba_location_value',
              'relationship' => 'none',
              ),
              'status' => array(
                  'label' => 'Bookable',
                  'alter' => array(
                    'alter_text' => 0,
                    'text' => '',
                    'make_link' => 0,
                    'path' => '',
                    'link_class' => '',
                    'alt' => '',
                    'prefix' => '',
                    'suffix' => '',
                    'help' => '',
                    'trim' => 0,
                    'max_length' => '',
                    'word_boundary' => 1,
                    'ellipsis' => 1,
                    'strip_tags' => 0,
                    'html' => 0,
                    ),
                  'type' => 'yes-no',
                  'not' => 0,
                  'exclude' => 0,
                  'id' => 'status',
                  'table' => 'node',
                  'field' => 'status',
                  'relationship' => 'none',
                  ),
                  'field_ba_defaultavailability_value' => array(
                      'label' => 'Default Availability',
                      'alter' => array(
                        'alter_text' => 0,
                        'text' => '',
                        'make_link' => 0,
                        'path' => '',
                        'link_class' => '',
                        'alt' => '',
                        'prefix' => '',
                        'suffix' => '',
                        'help' => '',
                        'trim' => 0,
                        'max_length' => '',
                        'word_boundary' => 1,
                        'ellipsis' => 1,
                        'strip_tags' => 0,
                        'html' => 0,
                        ),
                      'link_to_node' => 0,
                      'label_type' => 'widget',
                      'format' => 'default',
                      'multiple' => array(
                          'group' => TRUE,
                          'multiple_number' => '',
                          'multiple_from' => '',
                          'multiple_reversed' => FALSE,
                          ),
                      'exclude' => 0,
                      'id' => 'field_ba_defaultavailability_value',
                      'table' => 'node_data_field_ba_defaultavailability',
                      'field' => 'field_ba_defaultavailability_value',
                      'relationship' => 'none',
                      ),
                  'field_ba_parent_nid' => array(
                      'label' => 'Parent',
                      'alter' => array(
                        'alter_text' => 0,
                        'text' => '',
                        'make_link' => 0,
                        'path' => '',
                        'link_class' => '',
                        'alt' => '',
                        'prefix' => '',
                        'suffix' => '',
                        'help' => '',
                        'trim' => 0,
                        'max_length' => '',
                        'word_boundary' => 1,
                        'ellipsis' => 1,
                        'strip_tags' => 0,
                        'html' => 0,
                        ),
                      'link_to_node' => 0,
                      'label_type' => 'widget',
                      'format' => 'default',
                      'multiple' => array(
                          'group' => TRUE,
                          'multiple_number' => '',
                          'multiple_from' => '',
                          'multiple_reversed' => FALSE,
                          ),
                      'exclude' => 0,
                      'id' => 'field_ba_parent_nid',
                      'table' => 'node_data_field_ba_parent',
                      'field' => 'field_ba_parent_nid',
                      'relationship' => 'none',
                      ),
                      'view_node' => array(
                          'label' => 'Link',
                          'alter' => array(
                            'alter_text' => 0,
                            'text' => '',
                            'make_link' => 0,
                            'path' => '',
                            'link_class' => '',
                            'alt' => '',
                            'prefix' => '',
                            'suffix' => '',
                            'help' => '',
                            'trim' => 0,
                            'max_length' => '',
                            'word_boundary' => 1,
                            'ellipsis' => 1,
                            'strip_tags' => 0,
                            'html' => 0,
                            ),
                          'text' => '',
                          'exclude' => 0,
                          'id' => 'view_node',
                          'table' => 'node',
                          'field' => 'view_node',
                          'relationship' => 'none',
                          ),
                          'edit_node' => array(
                              'label' => 'Edit‘-Link',
                              'alter' => array(
                                'alter_text' => 0,
                                'text' => '',
                                'make_link' => 0,
                                'path' => '',
                                'link_class' => '',
                                'alt' => '',
                                'prefix' => '',
                                'suffix' => '',
                                'help' => '',
                                'trim' => 0,
                                'max_length' => '',
                                'word_boundary' => 1,
                                'ellipsis' => 1,
                                'strip_tags' => 0,
                                'html' => 0,
                                ),
                              'text' => '',
                              'exclude' => 0,
                              'id' => 'edit_node',
                              'table' => 'node',
                              'field' => 'edit_node',
                              'relationship' => 'none',
                              ),
                          'nid' => array(
                              'label' => 'Availabilities',
                              'alter' => array(
                                'alter_text' => 1,
                                'text' => 'Availability',
                                'make_link' => 1,
                                'path' => 'admin/content/publicbookings/resource/[nid]/availability',
                                'link_class' => '',
                                'alt' => '',
                                'prefix' => '',
                                'suffix' => '',
                                'target' => '',
                                'help' => '',
                                'trim' => 0,
                                'max_length' => '',
                                'word_boundary' => 1,
                                'ellipsis' => 1,
                                'strip_tags' => 0,
                                'html' => 0,
                                ),
                              'empty' => '',
                              'hide_empty' => 0,
                              'empty_zero' => 0,
                              'link_to_node' => 0,
                              'exclude' => 0,
                              'id' => 'nid',
                              'table' => 'node',
                              'field' => 'nid',
                              'relationship' => 'none',
                              ),


                              ));
  $handler->override_option('filters', array(
        'type' => array(
          'operator' => 'in',
          'value' => array(
            'bookingsapi_resource' => 'bookingsapi_resource',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'type',
          'table' => 'node',
          'field' => 'type',
          'relationship' => 'none',
          ),
        ));
  $handler->override_option('access', array(
        'type' => 'none',
        ));
  $handler->override_option('cache', array(
        'type' => 'none',
        ));
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
        'grouping' => '',
        'override' => 1,
        'sticky' => 0,
        'order' => 'asc',
        'columns' => array(
          'field_ba_defaultavailability_value' => 'field_ba_defaultavailability_value',
          'field_ba_location_value' => 'field_ba_location_value',
          'view_node' => 'view_node',
          'title' => 'title',
          'status' => 'status',
          'edit_node' => 'edit_node',

          ),
        'info' => array(
          'field_ba_defaultavailability_value' => array(
            'sortable' => 1,
            'separator' => '',
            ),
          'field_ba_location_value' => array(
            'sortable' => 1,
            'separator' => '',
            ),
          'view_node' => array(
            'separator' => '',
            ),
          'title' => array(
            'sortable' => 1,
            'separator' => '',
            ),
          'status' => array(
            'sortable' => 1,
            'separator' => '',
            ),
          'edit_node' => array(
            'separator' => '',
            ),
          ),
          'default' => 'title',
          ));
  return $view;
}

function publicbookings_view_currently_happening() {
  $view = publicbookings_default_view_object();
  $view->name = 'publicbookings_view_currently_happening';
  $view->description = '';
  $view->tag = 'Public Bookings';
  $view->view_php = '';
  $view->base_table = 'bookings_schedules';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('use_more_text', 'Next');
  $handler->override_option('filters', array(
        'start' => array(
          'operator' => '<=',
          'value' => array(
            'type' => 'date',
            'value' => '+0 hours',
            'min' => '',
            'max' => '',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'start',
          'table' => 'bookings_schedules',
          'field' => 'start',
          'relationship' => 'none',
          ),
        'end' => array(
          'operator' => '>=',
          'value' => array(
            'type' => 'date',
            'value' => '+0 hours',
            'min' => '',
            'max' => '',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'end',
          'table' => 'bookings_schedules',
          'field' => 'end',
          'relationship' => 'none',
          ),
        'type' => array(
            'operator' => 'in',
            'value' => array(
              '1' => 1,
              ),
            'group' => '0',
            'exposed' => FALSE,
            'expose' => array(
              'operator' => FALSE,
              'label' => '',
              ),
            'id' => 'type',
            'table' => 'bookings_records',
            'field' => 'type',
            'relationship' => 'none',
            ),
        'status' => array(
            'operator' => 'in',
            'value' => array(
              '2' => 2,
              ),
            'group' => '0',
            'exposed' => FALSE,
            'expose' => array(
              'operator' => FALSE,
              'label' => '',
              ),
            'case' => 1,
            'id' => 'status',
            'table' => 'bookings_records',
            'field' => 'status',
            'relationship' => 'none',
            ),
        ));
  $handler->override_option('relationships', array(
        'resource_id' => array(
          'label' => 'Resource',
          'required' => 0,
          'id' => 'resource_id',
          'table' => 'bookings_schedules',
          'field' => 'resource_id',
          'relationship' => 'none',
          ),
        ));
  $handler->override_option('fields', array(
        'end' => array(
          'label' => 'Ends',
          'date_format' => 'small',
          'custom_date_format' => '',
          'exclude' => 0,
          'id' => 'end',
          'table' => 'bookings_schedules',
          'field' => 'end',
          'relationship' => 'none',
          ),
        'start' => array(
          'label' => 'Starts',
          'date_format' => 'small',
          'custom_date_format' => '',
          'exclude' => 0,
          'id' => 'start',
          'table' => 'bookings_schedules',
          'field' => 'start',
          'relationship' => 'none',
          ),
        'name' => array(
            'label' => 'Name',
            'exclude' => 0,
            'id' => 'name',
            'table' => 'bookings_records',
            'field' => 'name',
            'relationship' => 'none',
            ),
        'title' => array(
            'label' => 'Resource',
            'alter' => array(
              'alter_text' => 0,
              'text' => '',
              'make_link' => 0,
              'path' => '',
              'link_class' => '',
              'alt' => '',
              'prefix' => '',
              'suffix' => '',
              'target' => '',
              'help' => '',
              'trim' => 0,
              'max_length' => '',
              'word_boundary' => 1,
              'ellipsis' => 1,
              'strip_tags' => 0,
              'html' => 0,
              ),
            'empty' => '',
            'hide_empty' => 0,
            'empty_zero' => 0,
            'link_to_node' => 0,
            'exclude' => 0,
            'id' => 'title',
            'table' => 'node',
            'field' => 'title',
            'relationship' => 'resource_id',
            ),
            ));
  $handler->override_option('sorts', array(
        'type' => array(
          'id' => 'type',
          'table' => 'bookings_records',
          'field' => 'type',
          ),
        ));
  $handler->override_option('access', array(
        'type' => 'none',
        'role' => array(),
        'perm' => '',
        ));
  $handler->override_option('cache', array(
        'type' => 'none',
        ));
  $handler->override_option('empty', 'Nothing to display.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('style_plugin', 'table');


  $handler->override_option('access', array(
        'type' => 'none',
        'role' => array(),
        'perm' => '',
        ));
  $handler->override_option('cache', array(
        'type' => 'none',
        ));
  $handler->override_option('empty', 'Nothing to display.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('style_plugin', 'table');
  return $view;
}

function publicbookings_view_upcoming() { 
  $view = publicbookings_default_view_object();
  $view->name = 'publicbookings_view_upcoming';
  $view->description = '';
  $view->tag = 'Public Bookings';
  $view->view_php = '';
  $view->base_table = 'bookings_schedules';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('use_more_text', 'Next');
  $handler->override_option('relationships', array(
        'resource_id' => array(
          'label' => 'Resource',
          'required' => 0,
          'id' => 'resource_id',
          'table' => 'bookings_records',
          'field' => 'resource_id',
          'relationship' => 'none',
          ),
        ));
  $handler->override_option('fields', array(
        'name' => array(
          'label' => 'Name',
          'exclude' => 0,
          'id' => 'name',
          'table' => 'bookings_records',
          'field' => 'name',
          'relationship' => 'none',
          ),
        'start' => array(
          'label' => 'Start',
          'date_format' => 'small',
          'custom_date_format' => '',
          'exclude' => 0,
          'id' => 'start',
          'table' => 'bookings_schedules',
          'field' => 'start',
          'relationship' => 'none',
          ),
        'end' => array(
          'label' => 'End',
          'date_format' => 'small',
          'custom_date_format' => '',
          'exclude' => 0,
          'id' => 'end',
          'table' => 'bookings_schedules',
          'field' => 'end',
          'relationship' => 'none',
          ),
        'title' => array(
            'label' => 'Resource',
            'alter' => array(
              'alter_text' => 0,
              'text' => '',
              'make_link' => 0,
              'path' => '',
              'link_class' => '',
              'alt' => '',
              'prefix' => '',
              'suffix' => '',
              'target' => '',
              'help' => '',
              'trim' => 0,
              'max_length' => '',
              'word_boundary' => 1,
              'ellipsis' => 1,
              'strip_tags' => 0,
              'html' => 0,
              ),
            'empty' => '',
            'hide_empty' => 0,
            'empty_zero' => 0,
            'link_to_node' => 0,
            'exclude' => 0,
            'id' => 'title',
            'table' => 'node',
            'field' => 'title',
            'relationship' => 'resource_id',
            ),
            ));
  $handler->override_option('filters', array(
        'start' => array(
          'operator' => '>=',
          'value' => array(
            'type' => 'date',
            'value' => '2009-11-06 12:25:23',
            'min' => '',
            'max' => '',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'start',
          'table' => 'bookings_schedules',
          'field' => 'start',
          'relationship' => 'none',
          ),
        'end' => array(
          'operator' => '>=',
          'value' => array(
            'type' => 'offset',
            'value' => '+12 hours',
            'min' => '',
            'max' => '',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'end',
          'table' => 'bookings_schedules',
          'field' => 'end',
          'relationship' => 'none',
          ),
        'type' => array(
            'operator' => 'in',
            'value' => array(
              '1' => 1,
              ),
            'group' => '0',
            'exposed' => FALSE,
            'expose' => array(
              'operator' => FALSE,
              'label' => '',
              ),
            'id' => 'type',
            'table' => 'bookings_records',
            'field' => 'type',
            'relationship' => 'none',
            ),
        'status' => array(
            'operator' => 'in',
            'value' => array(
              '2' => 2,
              ),
            'group' => '0',
            'exposed' => FALSE,
            'expose' => array(
              'operator' => FALSE,
              'label' => '',
              ),
            'case' => 1,
            'id' => 'status',
            'table' => 'bookings_records',
            'field' => 'status',
            'relationship' => 'none',
            ),
        ));
  $handler->override_option('access', array(
        'type' => 'none',
        'role' => array(),
        'perm' => '',
        ));
  $handler->override_option('cache', array(
        'type' => 'none',
        ));
  $handler->override_option('empty', 'None.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
        'grouping' => '',
        'override' => 1,
        'sticky' => 0,
        'order' => 'asc',
        'columns' => array(
          'end' => 'end',
          'start' => 'start',
          'name' => 'name',
          ),
        'info' => array(
          'end' => array(
            'sortable' => 0,
            'separator' => '',
            ),
          'start' => array(
            'sortable' => 0,
            'separator' => '',
            ),
          'name' => array(
            'sortable' => 0,
            'separator' => '',
            ),
          ),
        'default' => 'start',
        ));
  return $view;
}

function publicbookings_view_resources() {
  $view = publicbookings_default_view_object();
  $view->name = 'publicbookings_view_resources';
  $view->description = '';
  $view->tag = 'Public Bookings';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
        'title' => array(
          'label' => 'Title',
          'alter' => array(
            'alter_text' => 0,
            'text' => '',
            'make_link' => 0,
            'path' => '',
            'link_class' => '',
            'alt' => '',
            'prefix' => '',
            'suffix' => '',
            'target' => '',
            'help' => '',
            'trim' => 0,
            'max_length' => '',
            'word_boundary' => 1,
            'ellipsis' => 1,
            'strip_tags' => 0,
            'html' => 0,
            ),
          'empty' => '',
          'hide_empty' => 0,
          'empty_zero' => 0,
          'link_to_node' => 1,
          'exclude' => 0,
          'id' => 'title',
          'table' => 'node',
          'field' => 'title',
          'relationship' => 'none',
          ),
          'teaser' => array(
              'label' => 'Teaser',
              'alter' => array(
                'alter_text' => 0,
                'text' => '',
                'make_link' => 0,
                'path' => '',
                'link_class' => '',
                'alt' => '',
                'prefix' => '',
                'suffix' => '',
                'target' => '',
                'help' => '',
                'trim' => 0,
                'max_length' => '',
                'word_boundary' => 1,
                'ellipsis' => 1,
                'strip_tags' => 0,
                'html' => 0,
                ),
              'empty' => '',
              'hide_empty' => 1,
              'empty_zero' => 0,
              'exclude' => 0,
              'id' => 'teaser',
              'table' => 'node_revisions',
              'field' => 'teaser',
              'relationship' => 'none',
              ),
              'field_ba_location_value' => array(
                  'label' => 'Location',
                  'alter' => array(
                    'alter_text' => 0,
                    'text' => '',
                    'make_link' => 0,
                    'path' => '',
                    'link_class' => '',
                    'alt' => '',
                    'prefix' => '',
                    'suffix' => '',
                    'target' => '',
                    'help' => '',
                    'trim' => 0,
                    'max_length' => '',
                    'word_boundary' => 1,
                    'ellipsis' => 1,
                    'strip_tags' => 0,
                    'html' => 0,
                    ),
                  'empty' => '',
                  'hide_empty' => 1,
                  'empty_zero' => 0,
                  'link_to_node' => 0,
                  'label_type' => 'widget',
                  'format' => 'default',
                  'multiple' => array(
                      'group' => TRUE,
                      'multiple_number' => '',
                      'multiple_from' => '',
                      'multiple_reversed' => FALSE,
                      ),
                  'exclude' => 0,
                  'id' => 'field_ba_location_value',
                  'table' => 'node_data_field_ba_location',
                  'field' => 'field_ba_location_value',
                  'relationship' => 'none',
                  ),
                  ));
  $handler->override_option('filters', array(
        'status' => array(
          'operator' => '=',
          'value' => '1',
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'status',
          'table' => 'node',
          'field' => 'status',
          'relationship' => 'none',
          ),
        'type' => array(
          'operator' => 'in',
          'value' => array(
            'bookingsapi_resource' => 'bookingsapi_resource',
            ),
          'group' => '0',
          'exposed' => FALSE,
          'expose' => array(
            'operator' => FALSE,
            'label' => '',
            ),
          'id' => 'type',
          'table' => 'node',
          'field' => 'type',
          'relationship' => 'none',
          ),
        'field_ba_defaultavailability_value_many_to_one' => array(
            'operator' => 'not',
            'value' => array(
              '2' => '2',
              ),
            'group' => '0',
            'exposed' => FALSE,
            'expose' => array(
              'operator' => FALSE,
              'label' => '',
              ),
            'id' => 'field_ba_defaultavailability_value_many_to_one',
            'table' => 'node_data_field_ba_defaultavailability',
            'field' => 'field_ba_defaultavailability_value_many_to_one',
            'relationship' => 'none',
            'reduce_duplicates' => 0,
            ),
        ));
  $handler->override_option('access', array(
        'type' => 'none',
        ));
  $handler->override_option('cache', array(
        'type' => 'none',
        ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'publicbookings/resources');
  $handler->override_option('menu', array(
        'type' => 'none',
        'title' => '',
        'description' => '',
        'weight' => 0,
        'name' => 'navigation',
        ));
  $handler->override_option('tab_options', array(
        'type' => 'none',
        'title' => '',
        'description' => '',
        'weight' => 0,
        ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('use_more_text', 'Next');
  return $view;
}

