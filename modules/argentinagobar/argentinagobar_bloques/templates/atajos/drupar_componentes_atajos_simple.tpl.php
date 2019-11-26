<div class="panel-body">
  <div class="media">
    <?php if(isset($atajo['icono']) && $atajo['icono'] != 'sin_icono'){ ?>
    <div class="media-left padding-20">
      <i class="fa fa-fw fa-3x <?php print $atajo['icono'] . ' ' . $atajo['color_icono']; ?>"></i>
    </div>
    <?php } ?>
    <div class="media-body">
      <h3><?php print $atajo['titulo']; ?></h3>
      <?php if(isset($atajo['texto']) && !empty($atajo['texto']['value'])){ ?>
      <div class="text-muted">
        <?php print check_markup($atajo['texto']['value'], $atajo['texto']['format']); ?>
      </div>
      <?php } ?>
    </div>
  </div>
</div>
