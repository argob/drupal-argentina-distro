<div class="row">
  <div class="col-md-12">
    <?=$breadcrumb?>
  </div>
</div>
<div class="col-md-12">
  <div class="text-muted m-t-3 lead">
    <span class="<?=$detalleFronterizo['clase_estado']?>"><?=$detalleFronterizo['estado']?></span>
    Actualizado hace <?=$detalleFronterizo['actualizacion']?>
  </div>
  <h2>
    <?=$detalleFronterizo['titulo']?>
    <br>
    <small><?=$detalleFronterizo['subtitulo']?></small>
  </h2>
  <hr>
</div>

<section class="p-t-0">
  <div class="container">
    <div class="row">
      <div class="col-md-8">
        <div class="media">
          <div class="media-left hidden-xs">
            <i class="text-secondary fa fa-home fa-fw fa-2x" aria-hidden="true"></i>
          </div>
          <div class="media-body">
            <h3 class="m-t-0 clearfix"><i class="text-secondary fa fa-info-circle fa-fw fa-2x visible-xs-inline pull-left" aria-hidden="true"></i> Información general</h3>
            <div class="row">
              <div class="col-xs-12 col-md-6">
                <small>Horarios de atención</small>
                <p><?=$detalleFronterizo['horarios']?></p>
                <small>Teléfono</small>
                <p><?=$detalleFronterizo['contacto']?></p>
              </div>
            </div>
          </div>
        </div>
        <div class="media m-t-2">
          <div class="media-left hidden-xs">
            <i class="text-secondary fa fa-list-ul fa-fw fa-2x" aria-hidden="true"></i>
          </div>
          <div class="media-body">
            <h3 class="m-t-0 clearfix"><i class="text-secondary fa fa-exchange fa-fw fa-2x visible-xs-inline pull-left" aria-hidden="true"></i> Información del cruce</h3>
            <small>Tipo de paso</small>
            <p><?=$detalleFronterizo['origen']?></p>

            <?php if($detalleFronterizo['origen'] == 'Ruta'):?>

              <small>Temperatura</small>
              <p><?=$detalleFronterizo['informacion']['temperatura']?> °</p>

              <small>Tiempo</small>
              <p><?=$detalleFronterizo['informacion']['sensacion']?></p>

              <small>Cielo</small>
              <p><?=$detalleFronterizo['informacion']['nubosidad']?></p>

              <small>Viento</small>
              <p><?=$detalleFronterizo['informacion']['viento']?></p>

              <small>Visibilidad</small>
              <p><?=$detalleFronterizo['informacion']['visibilidad']?></p>

            <?php elseif($detalleFronterizo['origen'] == 'Rio'): ?>

              <small>Altura del río</small>
              <p><?=$detalleFronterizo['informacion']['altura']?></p>

              <small>Alerta</small>
              <p><?=$detalleFronterizo['informacion']['alerta']?></p>

              <small>Evacuación</small>
              <p><?=$detalleFronterizo['informacion']['evacuacion']?></p>

              <small>Medios utilizados para el cruce</small>
              <p><?=$detalleFronterizo['informacion']['medios']?></p>
            <?php endif ?>
          </div>
        </div>

        <div class="m-y-4">
          <p><a href=<?php print $url_doc ?> class="btn btn-primary">VER DOCUMENTACIÓN REQUERIDA</a></p>
          <?php if (!empty($_SERVER['HTTP_REFERER'])) :?>
          <p><a href="<?=$_SERVER['HTTP_REFERER']?>" class="btn btn-link">VER TODAS LAS FRONTERAS</a></p>
        <?php endif ?>
        </div>

      </div>

      <div class="col-md-4">
        <!-- <div class="media-left">
          <i class="fa fa-map-marker fa-fw fa-2x text-primary m-b-0"></i>
        </div>
        <div class="media-body">
          <p class="m-b-0" id="direccionMapa"></p>
          <p class="m-t-0"></p>
        </div> -->

        <div id="map" style="height:300px;"></div>
        <script async defer src="https://maps.googleapis.com/maps/api/js?key=<?= $keyMap ?>&region=AR&callback=initMap"></script>

        <h3 class="h5 m-t-2">¿Querés tener esta información en tu celular?</h3>
        <p>
          <a href="https://www.argentina.gob.ar/fronteras-argentinas" class="btn btn-primary btn-sm">DESCARGATE LA APLICACIÓN MÓVIL</a>
        </p>

      </div>
    </div>
  </div>
</section>
