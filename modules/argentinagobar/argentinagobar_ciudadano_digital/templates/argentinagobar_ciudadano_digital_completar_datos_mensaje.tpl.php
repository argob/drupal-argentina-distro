<div class= "<?php print(estaLogueado() ? 'alert alert-info' : 'alert alert-success');?>" >
  <div class="media">
    <div class="media-body">
      <h5 class="m-y-0"><?php print $titulo; ?></h5>
      <p class="m-b-0"><?php print $mensaje; ?></p>
    </div>
    <div class="media-right hidden-xs">
      <?php print render($formulario); ?>
    </div>
  </div>
  <div class="visible-xs text-center m-t-1">
    <!--<a class="btn btn-success">Completar mis datos</a>-->
    <?php print render($data['formulario']); ?>
  </div>
</div>
