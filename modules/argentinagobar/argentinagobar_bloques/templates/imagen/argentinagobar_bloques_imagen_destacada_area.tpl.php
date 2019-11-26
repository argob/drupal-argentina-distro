<section class="jumbotron" style="background-image: url(<?php print $campos['imagen_destacada']; ?>);">
  <div class="jumbotron_bar">
    <div class="container">
      <div class="row">
        <div class="col-md-12">
            <?php
              $block = module_invoke('og_menu_single', 'block_view', 'menu');
              print render($block['content']);
            ?>
            <?php print $breadcrumb; ?>
        </div>
      </div>
    </div>
  </div>
  <div class="jumbotron_body">
    <div class="container">
      <div class="row">
        <div class="col-xs-12 col-md-8 col-md-offset-2 text-center">
          <h1><?php print $campos['titulo']; ?></h1>
          <p><?php print $campos['resumen']; ?></p>
        </div>
      </div>
    </div>
  </div>
  <div class="overlay"></div>
</section>
