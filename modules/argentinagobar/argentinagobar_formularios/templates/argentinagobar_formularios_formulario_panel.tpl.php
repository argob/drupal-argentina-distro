<?php if(isset($formulario) && !empty($formulario)){ ?>
  <?php if(isset($descripcion) && !empty($descripcion)){ ?>
  <p><?php print $descripcion; ?></p>
  <?php } ?>
  <div class="panel panel-default panel-disabled m-b-3">
    <div class="panel-body">
      <?php print render($formulario); ?>
    </div>
  </div>
<?php } ?>
