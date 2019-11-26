<?php if (isset($titulo)):?>
  <h2><?= $titulo ?></h2>
<?php endif?>

<?php if (isset($paneles)): ?>
  <?php foreach ($paneles as $panel): ?>
    <?= $panel ?>
  <?php endforeach ?>
<?php endif ?>

<p class="text-center m-t-3 m-b-1 hidden-print">
  <a href="<?php drupal_lookup_path('alias', current_path()); ?>" class="btn btn-block btn-primary">Hacer otra consulta</a>
</p>
<hr class="m-t-4">

<?php if(isset($alerta)): ?>
  <div class="alert alert-warning">
    <p><?= $alerta ?></p>
  </div>
<?php endif ?>

<?php if(isset($footer)): ?>
  <h3><?= $footer['titulo'] ?> </h3>
  <?php foreach ($footer['data'] as $foot): ?>
    <label class="control-label"><?= $foot['label'] ?></label>
    <p><?= $foot['value'] ?></p>
  <?php endforeach ?>
<?php endif ?>

<hr class="m-t-4">
<p class="text-muted text-muted">La información de las consultas es proporcionada por la DNRPA</p>
