<?php

function smartqueue_users_views_default_views() {
  $views = array();
  $qids = smartqueue_users_get_qids();
  if (!empty($qids)) {
    foreach ($qids as $qid) {
      $queue = nodequeue_load($qid);
      $view = new view;
      $view->name = 'smartqueue_users_user_'. $qid;
      $view->description = 'Displays the nodes in the '. $queue->title ." user smartqueue";
      $view->tag = 'nodequeue';
      $view->view_php = '';
      $view->base_table = 'node';
      $view->is_cacheable = FALSE;
      $view->api_version = 2;
      $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
      $handler = $view->new_display('default', 'Defaults', 'default');
      $handler->override_option('relationships', array(
        'nodequeue_rel' => array(
          'label' => 'queue',
          'required' => 1,
          'limit' => 1,
          'qids' => array(
            $qid => $qid,
          ),
          'id' => 'nodequeue_rel',
          'table' => 'node',
          'field' => 'nodequeue_rel',
          'relationship' => 'none',
        ),
      ));
      $handler->override_option('sorts', array(
        'position' => array(
          'order' => 'ASC',
          'id' => 'position',
          'table' => 'nodequeue_nodes',
          'field' => 'position',
          'relationship' => 'nodequeue_rel',
        ),
      ));
      $handler->override_option('arguments', array(
        'reference' => array(
          'default_action' => 'ignore',
          'style_plugin' => 'default_summary',
          'style_options' => array(),
          'wildcard' => 'all',
          'wildcard_substitution' => 'All',
          'title' => '',
          'default_argument_type' => 'fixed',
          'default_argument' => '',
          'validate_type' => 'none',
          'validate_fail' => 'not found',
          'glossary' => 0,
          'limit' => '0',
          'case' => 'none',
          'path_case' => 'none',
          'transform_dash' => 0,
          'id' => 'reference',
          'table' => 'nodequeue_subqueue',
          'field' => 'reference',
          'relationship' => 'nodequeue_rel',
          'default_options_div_prefix' => '',
          'default_argument_user' => 0,
          'default_argument_fixed' => '',
          'default_argument_php' => '',
          'validate_argument_node_type' => array(
            'blog' => 0,
            'poll' => 0,
            'forum' => 0,
            'book' => 0,
            'page' => 0,
            'story' => 0,
          ),
          'validate_argument_node_access' => 0,
          'validate_argument_nid_type' => 'nid',
          'validate_argument_vocabulary' => array(
            '2' => 0,
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
      $handler->override_option('cache', array(
        'type' => 'none',
      ));
      $handler->override_option('empty', 'This user does not have a queue that contains any posts.');
      $handler->override_option('empty_format', '1');
      $handler->override_option('use_pager', '1');
      $handler->override_option('style_plugin', 'list');
      $handler->override_option('row_plugin', 'node');
      
      $views[$view->name] = $view;
    }
    
  }
  
  return $views;
}