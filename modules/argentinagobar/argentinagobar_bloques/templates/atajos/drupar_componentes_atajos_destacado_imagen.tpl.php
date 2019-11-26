<div style="background-image:url(<?php print $atajo['imagen'] ?>);" class="panel-heading"></div>
  <div class="panel-body">
  <h4><?php print $atajo['titulo']; ?></h4>
  <?php if(isset($atajo['texto']) && !empty($atajo['texto']['value'])){ ?>
  <div class="text-muted">
    <?php print check_markup($atajo['texto']['value'], $atajo['texto']['format']); ?>
  </div>
  <?php } ?>
</div>
