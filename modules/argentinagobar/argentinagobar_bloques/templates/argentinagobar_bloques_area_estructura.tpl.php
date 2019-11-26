  <div class="row">
    <?php if(!empty($autoridad->foto)){ ?>
    <div class="col-xs-6 col-sm-3 col-md-2">
      <img class="img-responsive img-rounded" alt="" src="<?php print $autoridad->foto; ?>">
    </div>
    <?php } ?>
    <div class="col-md-9">
      <?php if(!empty($autoridad->nombre)){ ?>
      <h2 class="h1"><?php print $autoridad->nombre; ?>
        <?php if(!empty($autoridad->cargo)){ ?>
        <br>
        <small><?php print $autoridad->cargo; ?></small>
        <?php } ?>
      </h2>
      <?php } ?>
      <?php if(!empty($autoridad->resumen)){ ?><p><?php print $autoridad->resumen; ?></p><?php } ?>
    </div>
  </div>
  <?php if(isset($nivelesJerarquicos)) { ?>
    <?php foreach ($nivelesJerarquicos as $key => $nivelJerarquico) { ?>
      <div class="row">
        <div class="col-md-12">
          <br>
          <h2 class="h3 section-title"><?php print $nivelJerarquico->titulo; ?></h2>
        </div>
      </div>
      <?php foreach ($nivelJerarquico->subareas as $row) { ?>
        <div class="row panels-row  row-news row-ministerios">
          <?php foreach ($row as $item) { ?>
          <div class="col-xs-12 col-sm-3">
          <?php print $item; ?>
          </div>
          <?php } ?>
        </div>
      <?php } ?>
    <?php } ?>
  <?php } ?>