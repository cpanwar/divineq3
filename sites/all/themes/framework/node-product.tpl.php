<?php if (!$page): ?>
  <article id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clearfix">
<?php endif; ?>

  <?php if ($picture || $submitted || !$page): ?>
    <?php if (!$page): ?>
      <header>
	<?php endif; ?>

      <?php print $picture ?>

	  <?php if (!$page): ?>
        <h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php //print $title ?></a></h2>
      <?php endif; ?>

	  <?php if ($submitted): ?>
        <p class="submitted"><?php print $submitted; ?></p>
      <?php endif; ?>

    <?php if (!$page): ?>
      </header>
	<?php endif; ?>
  <?php endif;?>

    <div class="product-left">
      <div class="field-field-product-image">
	<?php global $base_url; ?>
	<img width="810" src="<?php print $base_url.'/'.$node->field_product_image[0]['filepath']; ?>" alt="<?php print $node->field_product_image[0]['data']['alt']; ?>">
      </div>
    </div>

  <div class="content" id="pro_detials">
    <h1 id="page-title" class="title"><?php print $title ?></h1>
    <?php print $content ?>
  </div>
   
  <?php if (!empty($links) || !empty($terms)): ?>
    <footer>
      <?php if ($terms): ?>
        <div class="terms">
          <span><?php print t('Tags: ') ?></span><?php print $terms ?>
        </div>
      <?php endif;?>
      <?php if ($links): ?>
        <div class="links">
          <?php print $links; ?>
        </div>
      <?php endif; ?>
    </footer>
  <?php endif;?>

<?php if (!$page): ?>
  </article>
<?php endif;?> <!-- /.node -->
