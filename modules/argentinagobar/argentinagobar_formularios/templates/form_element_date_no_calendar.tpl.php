<div class="form-group">
    
    <label for=""><strong><?= $element['#title'] ?> <?= $element['#required'] ? '*' : ''?> </strong></label>

    <input id="<?= $element['date']['#id'] ?>" name="<?= $element['date']['#name'] ?>" class="form-control required" type="text" required="" value="<?= $element['date']['#value'] ?>">

</div>
