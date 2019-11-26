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
  <?php print $pane_prefix; ?>
<?php endif; ?>
<div class="downloads <?php print $classes; ?>" <?php print $id; ?> <?php print $attributes; ?>>

  <?php if ($admin_links): ?>
    <?php print $admin_links; ?>
  <?php endif; ?>

  <hr>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <<?php print $title_heading; ?><?php print $title_attributes; ?>>
      <h4><?php print $title; ?></h4>
    </<?php print $title_heading; ?>>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <!-- <h4>Descargas</h4> -->

  <div class="row row-flex">
    <?php foreach ($content['#items'] as $key => $value): ?>
      <div class="col-md-12 col-xs-12 col-sm-6">
        <p class="text-muted m-b-1"><?= $value["description"]?> (<?= human_filesize($value["filesize"]) ?>)</p>
        <a href="<?php print file_create_url( $value["uri"] ); ?>" class="btn btn-primary btn-sm" download><i class="fa fa-download"></i>&nbsp; Descargar archivo</a>
      </div>
    <?php endforeach; ?>
  </div>

<?php if ($links): ?>
  <div class="links">
    <?php print $links; ?>
  </div>
<?php endif; ?>

  <?php if ($more): ?>
    <div class="more-link">
      <?php print $more; ?>
    </div>
  <?php endif; ?>
</div>
<?php if ($pane_suffix): ?>
  <?php print $pane_suffix;?>
<?php endif; ?>
