<section>
  <div class="row">
    <div class="col-md-8 col-md-offset-2">
      <div class="m-b-2">
        <h1 class="<?php print $legajo['color'];?> text-center"><i class="fa <?php print $legajo['icono'];?>"></i></h1>
        <h1 class="text-center margin-40">El ciudadano <br><?php print $legajo['texto'];?></h1>
        <h6 class="text-center margin-40"><?php print $legajo['sub_texto'];?></h6>
        <p class="text-center m-t-2">CUIL consultado: <?php print $cuil ?></p>
        <div class="text-center m-t-2">
          <a href="<?php drupal_lookup_path('alias', current_path()); ?>" class="btn btn-link">Hacer otra consulta</a>
        </div>
      </div>
    </div>
  </div>
</section>
