<?php
foreach ($element['#options'] as $key => $option)
{
?>
  <div <?php if(form_get_error($element)) { print 'class="has-error"'; } ?>>
  <div class="radio">
    <label class="label-block" for="<?= $element['#id'] . '-' . $key ?>" class="m-t-1">
      <input id="<?= $element['#id'] . '-' . $key ?>" <?php $element['#value'] == $key ? print 'checked' : ''; ?> type="radio" name="<?= $element['#name'] ?>" value="<?= $key ?>">
      <?= $option ?>
    </label>
    </div>
  </div>
<?php   
}
?>