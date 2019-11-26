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

 <div class="col-md-12">
 <?php  foreach ($content['#items'] as $item => $value):?>
   <?php  $uri = $value['uri'];
   $image = file_create_url($uri);?>
   <img src="<?php print $image ?>" alt="" class="m-b-2">
 <?php endforeach ?>
</div>
