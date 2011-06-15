<?php

/**
 * Field handler to allow linking to a comment.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_nodehierarchy_actions extends views_handler_field {
  function render($values) {
    $node = new stdClass();
    $node->nid = $values->{$this->field_alias};
    return theme("nodehierarchy_actions", $node);
  }
}