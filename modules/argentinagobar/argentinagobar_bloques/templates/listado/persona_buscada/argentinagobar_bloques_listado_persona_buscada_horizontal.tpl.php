<h2 class="h3 section-title"><?= $titulo; ?></h2>

<?php foreach (array_chunk($links, 4) as $key => $row): ?>

  <div class="row panels-row">

      <?php foreach ($row as $item): ?>

          <div class="col-xs-12 col-sm-3">
              <?= $item; ?>
          </div>

      <?php endforeach ?>

  </div>

<?php endforeach ?>

<?php if (isset($boton)): ?>
    <?= $boton ?>
<?php endif ?>

<?php if($paginador): ?>

  <?= theme('pager'); ?>

<?php endif ?>
