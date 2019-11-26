<div class="downloads">
  <hr>
  <h4><?php print $titulo; ?></h4>

  <div class="row row-flex">

    <?php foreach ($campo as $key  => $value): ?>

      <div class="col-xs-12 col-sm-6">
        <p class="m-t-1 m-b-1"><?php print $value["description"] ?> <small class="text-muted">(<?php print( round( $value["filesize"] / 1024 / 1024, 2 )); ?> MB)</small></p>
        <a class="btn btn-primary btn-sm m-b-2" href="<?php print file_create_url( $value["uri"] ); ?>">&nbsp;<i class="fa fa-download"></i>&nbsp;&nbsp; Descargar archivo</a>
      </div>

    <?php endforeach; ?>

  </div>
</div>
