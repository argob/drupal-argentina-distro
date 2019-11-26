<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<?php if ($pane_prefix): ?>
  <?= $pane_prefix ?>
<?php endif; ?>

<div class="<?=$classes?>" <?= $id ?> <?= $attributes ?> >
  <?php if ($admin_links): ?>
    <?= $admin_links; ?>
  <?php endif; ?>

  <?php if ($feeds): ?>
    <div class="feed">
      <?= $feeds; ?>
    </div>
  <?php endif; ?>

  <div class="pane-content">
    <?= render($content); ?>
  </div>

  <?php if ($links): ?>
    <div class="links">
      <?= $links; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <div class="more-link">
      <?= $more; ?>
    </div>
  <?php endif; ?>
</div>
<?php if ($pane_suffix): ?>
  <?= $pane_suffix; ?>
<?php endif; ?>
