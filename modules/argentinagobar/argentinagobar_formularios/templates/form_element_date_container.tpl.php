<div class="row">
  <div class="col-md-12">
    <label><?= $element['#attributes']['data-title'] ?></label>
  </div>
</div>
<div class="row">
  <?php print drupal_render_children($element, NULL); ?>
</div>

