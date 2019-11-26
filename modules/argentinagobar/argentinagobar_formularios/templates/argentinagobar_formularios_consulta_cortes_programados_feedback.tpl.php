<div class="text-center lead"><i class="fa <?php print $data['icono'] ?> fa-4x"></i></div>
<h1 class="text-center m-y-2"><?php print $data['titulo']; ?></h1>
<p class="text-center lead"><?php print $data['mensaje']; ?></p>
<div class="text-center m-t-3">
  <p class="text-muted m-b-1">
    <strong><?php print t('Para más información'); ?> <br><?php print $data['empresa']; ?></strong>
  </p>
  <p class="text-center m-b-4">
    <a href="<?php drupal_lookup_path('alias', current_path()); ?>" class="btn btn-link">Hacer otra consulta</a>
  </p>
</div>
<div class="alert alert-success">
  <div class="media">
    <div class="media-body">
      <h5 class="m-y-0">Entrá a Mi Argentina</h5>
      <p class="m-b-0">¡Es rápido! Podés recibir notificaciones cuando tengas cortes programados en tu zona.  </p>
    </div>
    <div class="media-right hidden-xs">
      <a href="<?php print $data['mi_argentina_link']; ?>" class="btn btn-success m-b-0">Entrar</a>
    </div>
  </div>
</div>
