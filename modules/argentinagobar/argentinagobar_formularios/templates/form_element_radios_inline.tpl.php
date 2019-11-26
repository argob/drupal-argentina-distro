<div class="form-item form-type-radios form-group">
  <div id="<?php print $element['#id'] ?>">
    <?php foreach (array_chunk($element['#options'], 4, TRUE) as $rkey => $row) { ?>
      <div class="row">
        <?php foreach($row as $key => $option) { ?>
          <div class="col-sm-2 col-md-6">
            <div class="radio ">
              <label class="radio-inline" for="<?php print $element['#id'] . '-'. $key ?>">
                <input  id="<?php print $element['#id'] . '-' . $key ?>" type="radio" name="<?php print $element['#name'] ?>" value="<?php print $key; ?>">
                <?php print $option; ?>
              </label>
            </div>
          </div>
        <?php } ?>
      </div>
    <?php } ?>
  </div>
</div>
