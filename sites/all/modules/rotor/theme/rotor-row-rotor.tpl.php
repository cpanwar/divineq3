<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php $display_tabs = $view->style_plugin->options['tabs']['show_tabs'] && $view->style_plugin->options['tabs']['group_tabs'] == ROTOR_DONT_GROUP_TABS; ?>
<?php $node = node_load($row->nid); ?>
<?php if ($display_tabs && $view->style_plugin->options['tabs']['position'] == ROTOR_TAB_POSITION_TOP): ?>
  <?php print theme('rotor_tab', $node); ?>
<?php endif ?>
<div class="rotor-content-detail"><?php print theme('rotor_item', $node, $options['imagecache_preset']); ?></div>
<?php if ($display_tabs && $view->style_plugin->options['tabs']['position'] == ROTOR_TAB_POSITION_BOTTOM): ?>
  <?php print theme('rotor_tab', $node); ?>
<?php endif ?>
