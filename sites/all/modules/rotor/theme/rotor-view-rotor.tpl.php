<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if ($rows): ?>
  <?php $display_tabs = $view->style_plugin->options['tabs']['show_tabs'] && $view->style_plugin->options['tabs']['group_tabs'] == ROTOR_GROUP_TABS; ?>
  <div class='rotor' id="rotor-view-id-<?php print $name; ?>-view-display-id-<?php print $display_id; ?>">
    <?php if ($display_tabs && $options['tabs']['position'] == ROTOR_TAB_POSITION_TOP): ?>
      <?php print theme('rotor_tabs', $view->result); ?>
    <?php endif ?>
    <div class='rotor-items' <?php if (!empty($style)) { print 'style="'. $style .'"'; } ?>>
      <?php foreach ($rows as $id => $row): ?>
        <div class="rotor-content"><?php print $row; ?></div>
      <?php endforeach; ?>
    </div>
    <?php if ($display_tabs && $options['tabs']['position'] == ROTOR_TAB_POSITION_BOTTOM): ?>
      <?php print theme('rotor_tabs', $view->result); ?>
    <?php endif ?>
  </div>
<?php endif; ?>
