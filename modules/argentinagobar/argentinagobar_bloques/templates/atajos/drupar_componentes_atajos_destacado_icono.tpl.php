<div class="panel-heading hidden-xs"><i class="fa <?php print $atajo['icono']; ?>"></i></div>
<div class="panel-body">
  <h3><span class="visible-xs-inline"><i class="fa <?php print $atajo['icono'];?>"></i>&nbsp; </span><?php print $atajo['titulo']; ?></h3>
  <?php if(isset($atajo['texto']) && !empty($atajo['texto']['value'])){ ?>
  <div class="text-muted">
    <?php print check_markup($atajo['texto']['value'], $atajo['texto']['format']); ?>
  </div>
  <?php } ?>
</div>
