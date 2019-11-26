<?php if(isset($imagen_path)){ ?>
<div style="background-image:url(<?php print $imagen_path; ?>);" class="panel-heading"></div>
<?php } ?>
<div class="panel-body">
  <?php if(isset($fecha)){ ?><time><?php print strtolower($fecha); ?></time><?php } ?>
  <?php if(isset($titulo)){ ?><h3><?php echo $titulo; ?></h3><?php } ?>
  <?php if(isset($texto)){ ?><p class="text-muted"><?php print $texto; ?></p><?php } ?>
</div>
