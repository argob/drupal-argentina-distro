<?php print $breadcrumb; ?>
<div class="col-md-8 col-md-offset-2">
  <h1><?php print $campos['titulo']; ?></h1>
  <div class="row">
    

    <?php
      $block = module_invoke('argentinagobar_bloques', 'block_view', 'redes_sociales_generico');
      print render($block['content']);
    ?>
    
  </div>
  <hr>
</div>