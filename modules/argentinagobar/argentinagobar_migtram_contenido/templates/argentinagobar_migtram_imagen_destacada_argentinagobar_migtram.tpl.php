<?php //print $breadcrumb; ?>
<div class="col-md-8 col-md-offset-2">
  <h1><?php print $campos['titulo']; ?></h1>
  <div class="row">
    <!-- <div class="section-actions col-md-7 social-share">
      <p>Compartí <br>este servicio</p>
      <ul class="list-inline">
        <li><a href="#"><i class="fa fa-facebook"></i></a></li>
        <li><a href="#"><i class="fa fa-twitter "></i></a></li>
        <li><a href="#"><i class="fa fa-google-plus"></i></a></li>
        <li><a href="#"><i class="fa fa-print"></i></a></li>
        <li><a href="#"><i class="fa fa-envelope-o"></i></a></li>
      </ul>
    </div> -->
    <?php 
        $block = module_invoke('argentinagobar_bloques', 'block_view', 'redes_sociales_generico');
          print render($block['content']); 
    ?>
    <div class="col-md-5 additional_data">
      <h3 class="text-success"><?php print $campos['costo']; ?></h3>
    </div>
  </div>
  <hr>
</div>