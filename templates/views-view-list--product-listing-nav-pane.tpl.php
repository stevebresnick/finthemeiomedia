<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <div data-magellan-expedition="fixed" class="product-nav-wrapper">
    <dl class="sub-nav">
      <?php //<dd><a href="#all" class="product-nav-item"><img class="product-nav-icon webicon small" src="/sites/default/files/all-icon.svg"><span class="product-nav-title">All</span></a></dd> ?>
      <?php foreach ($rows as $id => $row): ?>
      <dd class="<?php print $classes_array[$id]; ?>"><?php print $row; ?></dd>
    <?php endforeach; ?>
    </dl>
  </div>
<?php print $wrapper_suffix; ?>
