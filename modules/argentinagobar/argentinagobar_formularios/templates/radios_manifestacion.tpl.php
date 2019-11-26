<div class="col-md-12">
  <div class="form-group">
      <?php foreach($element['#options'] as $key => $text): ?>

          <div class="col-md-6">
           <div class="radio-inline">
             <label for="<?= $element[$key]['#id'] ?>" style="font-size: 20px">

                <?php if (!is_null($element['#value']) && $element['#value'] == $key): ?>

                <input
                  name="<?= $element[$key]['#name'] ?>"
                  id="<?= $element[$key]['#id'] ?>"
                  value="<?= $key ?>"
                  tabindex="4"
                  required=""
                  type="radio"
                  checked
                >

                <?php else: ?>

                <input
                  name="<?= $element[$key]['#name'] ?>"
                  id="<?= $element[$key]['#id'] ?>"
                  value="<?= $key ?>"
                  tabindex="4"
                  required=""
                  type="radio"
                  >

                <?php endif; ?>
                   <?= $text ?>
             </label>
           </div>
           <p><?= $element['#attributes']['data-description-' . $key] ?></p>
           </div>

      <?php endforeach; ?>
  </div>
</div>
