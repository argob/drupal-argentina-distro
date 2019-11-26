<?php $element['#theme_wrappers'] = ''; ?>
<div class="form-group">
    <label><strong><?= $element['#title'] ?></strong></label>
    <div class="form-group">
        <div class="input-group date">
            <span class="input-group-addon">
              <span class="fa fa-calendar"></span>
            </span>
            <input id="<?= $element['date']['#id'] ?>" name="<?= $element['date']['#name'] ?>" class="form-control" type="text" value="<?= $element['date']['#value'] ?>">
        </div>
    </div>
</div>
