<?php if(isset($titulo)): ?>
  <h2 class="text-left m-b-2"><?= $titulo ?></h2>
<?php endif ?>

<?php if(isset($subtitulo)): ?>
  <p class="text-center">
    <small><?= $subtitulo ?></small>
  </p>
<?php endif ?>

<?php if(isset($alerta)): ?>
  <div class="alert alert-warning">
    <p><?= $alerta ?></p>
  </div>
<?php endif ?>

<?php if(isset($paneles)): ?>
  <?php foreach ($paneles as $panel): ?>
    <?= $panel ?>
  <?php endforeach ?>
<?php endif ?>

<?php if(isset($leyenda)): ?>
  <p class="text-center">
    <small><?= $leyenda ?></small>
  </p>
<?php endif ?>

<p class="text-center m-t-3 m-b-1 hidden-print">
  <a href="javascript:window.print();" class="btn btn-default">Imprimí la consulta</a> &nbsp; &nbsp;
  <a href="<?= $href ?>" class="btn  use-ajax btn-primary">Hacer otra consulta</a>
</p>
