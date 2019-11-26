<h2 class="h3 section-title"><?php echo $titulo; ?></h2>
<?php foreach (array_chunk($links, 4) as $key => $row) { ?>
  <div class="row panels-row">
  <?php foreach ($row as $item) { ?>
    <div class="col-xs-12 col-sm-3">
      <?php echo $item; ?>
    </div>
  <?php } ?>
  </div>
  <?php } ?>
<?php if(isset($boton)) { print $boton; } ?>
<?php if(isset($paginador)) { print $paginador; } ?>
