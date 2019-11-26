<section class="jumbotron" style="background-image:url(<?php print $image; ?>);">
  <div class="jumbotron_body jumbotron_body-lg">
    <div class="container">
      <div class="row">
        <div class="col-md-12">
          <h2 class="text-center"><?php print t('¿Qué estás buscando?'); ?></h2>
        </div>
      </div>
      <div class="row">
        <div id="buscador" class="col-md-8 col-md-offset-2">
          <?php print drupal_render($form); ?>
        </div>
      </div>
    </div>
  </div>
  <div class="overlay"></div>
</section>
