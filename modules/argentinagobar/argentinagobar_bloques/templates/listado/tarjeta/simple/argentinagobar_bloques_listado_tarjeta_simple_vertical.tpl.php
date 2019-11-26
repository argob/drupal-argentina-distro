<h2 class="h3 section-title"><?php echo $titulo; ?></h2>
<?php foreach (array_chunk($links, 3) as $key => $row) { ?>
  <div class="row">
  <?php foreach ($row as $item) { ?>
    <div>
      <?php echo $item; ?>
    </div>
  <?php } ?>
  </div>
  <?php } ?>
<?php if(isset($boton)) { print $boton; } ?>
<?php if(isset($paginador)) { print $paginador; } ?>