<div class="row">
  <div class="col-md-12 m-b-2">
    <h1><?= $campos['titulo'];?></h1>
    <p class="lead">
      <?= check_markup($campos['resumen'], 'filtered_html', $langcode = '', $cache = FALSE); ?>
  </p>
    <div>
      <?php if(sizeof($campos['duracion']) > 0 && $campos['duracion'][0]['cantidad'] && $campos['duracion'][0]['medida']): ?>
        <span class="ribbon">
          <i class="fa fa-clock-o text-arandano"></i>
          <?= $campos['duracion'][0]['cantidad'] . " " . $campos['duracion'][0]['medida']; ?>
        </span>
      <?php endif ?>

      <?php if(isset($campos['es_gratuito'])): ?>
        <?php if($campos['es_gratuito']):?>
          <span class="ribbon"><i class="fa fa-usd text-arandano"></i> Gratuito</span>
        <?php endif ?>
      <?php endif ?>

      <?php  if ($campos['es_digital']): ?>
        <span class="ribbon"><i class="fa fa-desktop text-arandano"></i> 100% Digital</span>
      <?php endif ?>

      <?php  if ($campos['organismo']): ?>
        <span class="ribbon"><i class="fa fa-map-marker text-arandano"></i> <?= $campos['organismo'] ?></span>
      <?php endif ?>
    </div>
    <hr>
  </div>
</div>
