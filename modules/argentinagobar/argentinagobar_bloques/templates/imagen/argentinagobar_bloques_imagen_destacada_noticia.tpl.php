<header>
  <section class="jumbotron jumboarticle" style="background-image:url(<?=$campos['imagen_destacada']?>)">
    <div class="jumbotron_bar">
      <div class="container">
        <div class="row">
          <div class="col-md-12">
            <?=$breadcrumb?>
          </div>
        </div>
      </div>
    </div>
  </section>
  <div class="container">
    <div class="row">
      <div class="col-md-8 col-md-offset-2 overlap">
        <div class="title-description">
          <h1><?=$campos['titulo']?></h1>
          <p><?=$campos['resumen']?></p>
          <div class="row">
            <?php
              $block = module_invoke('argentinagobar_bloques', 'block_view', 'redes_sociales_generico');
              print render($block['content']);
            ?>
            <div class="col-md-6 additional_data">
              <time class="text-muted">Publicado el <?= strtolower($campos['fecha'])?></time>
            </div>
          </div>
          <hr>
        </div>
      </div>
    </div>
  </div>
</header>