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
<div class="media m-t-0">
  <div class="media-left hidden-xs">
    <i class="text-secondary fa fa-list-ul fa-fw fa-2x" aria-hidden="true"></i>
  </div>
  <div class="media-body">
    <h3 class="m-t-0 clearfix h4"><i class="text-secondary fa fa-list-ul fa-fw fa-2x visible-xs-inline pull-left" aria-hidden="true"></i> Información de la persona buscada</h3>
  <p><?php print render($content) ?></p>
  </div>
  <!-- <?php if (!empty($_SERVER['HTTP_REFERER'])) :?> -->
    <!-- <a class="btn btn-link m-t-1" href=<?php print $_SERVER['HTTP_REFERER']?>>Volver al listado</a> -->
  <!-- <?php endif?> -->
<!-- </div> -->
