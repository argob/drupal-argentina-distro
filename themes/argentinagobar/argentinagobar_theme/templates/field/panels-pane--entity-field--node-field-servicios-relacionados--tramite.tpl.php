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
  <?= $pane_prefix; ?>
<?php endif; ?>

<?php if ($admin_links): ?>
  <?= $admin_links; ?>
<?php endif; ?>

<?= render($title_prefix); ?>
<?php foreach ($content['#items'] as $key => $accion){
    $accion = field_collection_item_load($accion['value'], $reset = FALSE);
}
?>
<?php if ($title&&$accion->field_servicio['und'][0]['entity']->status>0): ?>
  <h4><?= $title; ?></h4>
<?php endif; ?>

<?= render($title_suffix); ?>
<?php if ($accion->field_servicio['und'][0]['entity']->status>0): unset($accion);?>
<div class="col-xs-12 col-sm-6 col-md-12">
<div class="pane-content">
    <?php foreach ($content['#items'] as $key => $accion): ?>
        <?php
          $classes = ($key > 0) ? '' : 'btn btn-success btn-block';
          $accion = field_collection_item_load($accion['value'], $reset = FALSE);
            //echo "<pre> content: ";
              //  print_r($accion->field_servicio['und'][0]['entity']->status);
            //echo "</pre>";
            //die();
          if(isset($accion->field_servicio['und'])&&$accion->field_servicio['und'][0]['entity']->status>0){
            print "<h5>" . l($accion->field_servicio['und'][0]['entity']->title, 'node/' . $accion->field_servicio['und'][0]['entity']->nid) . "</h5>";
            print "<p>" . $accion->field_detalle['und'][0]['safe_value'] . "</p>";
          }
          ?>
    <?php endforeach; ?>
</div>
</div>
  <?php endif;?>
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

<?php if ($pane_suffix): ?>
  <?= $pane_suffix; ?>
<?php endif; ?>
