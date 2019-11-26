<div class="form-item form-item-pais-residencia form-type-radios form-group">
  <div id="<?php print $element['#id'] ?>" class="btn-group btn-group-justified" data-toggle="buttons">
    <?php foreach($element['#options'] as $key => $option) { ?>
      <label class="btn btn-default <?php print ($element['#value']==$key) ? 'active' : '' ?>" for="<?php print $element['#id'] . '-' . $key ?>">
        <input <?php print ($element['#value']==$key) ? 'checked="checked"' : '' ?> class="form-radio" type="radio" id="<?php print $element['#id'] . '-' . $key ?>" name="<?php print $element['#name'] ?>" value="<?php print $key; ?>">
        <?php print $option; ?>
      </label>
    <?php } ?>
  </div>
</div>
