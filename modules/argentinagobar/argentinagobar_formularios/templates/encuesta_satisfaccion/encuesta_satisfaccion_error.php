<div class="col-md-8 col-md-offset-2 text-center">
  <img id="mano" src="<?= $file_public_path; ?>/error.png">
  <p id="gracias" class="m-t-2"><?= t('Ha ocurrido un error'); ?></p>
  <a class="btn btn-success btn-md m-t-1" href="<?= drupal_lookup_path('alias', current_path()); ?>">Volver a intentar</a>
</div>