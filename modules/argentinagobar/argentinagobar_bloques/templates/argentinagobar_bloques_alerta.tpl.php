<div class="alert alert-<?php echo isset($tipo) ? $tipo : 'warning'; ?>" role="alert">
  <div class="media">
  <?php if ($con_icono) { ?>
    <div class="media-left">
      <i class="<?php echo $icono; ?> fa-fw fa-4x"></i>
    </div>
    <?php } ?>
    <div class="media-body">
      <h5><strong><?php echo $titulo; ?></strong></h5>
      <p class="margin-0"><?php echo $texto; ?></p>
    </div>
  </div>
</div>