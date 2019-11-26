<?php if (isset($footer)):?>
  <h3><?= $footer['titulo'] ?></h3>
  <?php foreach ($footer['data'] as $foot): ?>
    <label class="control-label"><?= $foot['label'] ?></label>
    <p><?= $foot['value'] ?></p>
  <?php endforeach ?>
<?php endif ?>

<div class="text-center">
  <p class="text-muted text-muted">La información de las consultas es proporcionada por la DNRPA</p>
</div>
