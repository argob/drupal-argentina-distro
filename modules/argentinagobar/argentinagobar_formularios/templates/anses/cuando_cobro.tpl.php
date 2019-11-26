<?php global $base_url?>
<article class="row">
  <div class="alert alert-success">
    <h5>¿Querés que te avisemos todos los meses cuándo cobrás?</h5>
    <p class="margin-0">Es muy fácil: <a href="https://www.argentina.gob.ar/miargentina">registrate en Mi Argentina</a> y todos los meses vamos a enviarte una notificación a tu correo electrónico.</p>
  </div>
  <div class="row">
    <div class="col-md-12">
      <h2 class="m-t-2 m-b-2 font-weight-bold">Datos personales</h2>
      
      <div class="row">
        <div class="col-sm-6">
          <label>Nombre</label> <p><?= $beneficios[0]['apellidoYNombre']?> </p>
        </div>
        
        <div class="col-sm-6">
          <label>CUIL</label> <p><?= $beneficios[0]['cuil']?></p>
        </div>
      </div>
    </div>
  </div>
  
  
  <?php foreach ($beneficios as $beneficio ): ?>
    
    <div class="panel">
      <div class="panel-body">
        
        <div class="row">
          <div class="col-md-12">
            <h2><?= $beneficio['nombreBeneficio']?></h2>
            <hr class="m-t-1 m-b-1">
            
            <div class="row numbers p-y-1">
              <div class="col-md-3">
                <div class="h3 m-b-0"><?=$beneficio['pagoAnterior']['pagoDesde'][2]?></div>
                <p class="lead"><?=t($beneficio['pagoAnterior']['pagoDesde'][1])?></p>
                <p class="text-muted">Hasta el <?=$beneficio['pagoAnterior']['pagoHasta']?></p>
              </div>
              <div class="col-md-3">
                <div class="h3 m-b-0 text-success"><?=$beneficio['pagoActual']['pagoDesde'][2]?></div>
                <p class="lead text-success"><?=t($beneficio['pagoActual']['pagoDesde'][1])?></p>
                <p class="text-muted">Hasta el <?=$beneficio['pagoActual']['pagoHasta']?></p>
              </div>
              <div class="col-md-3">
                <div class="h3 m-b-0"><?=$beneficio['pagoActual']['proxPagoDesde'][2]?></div>
                <p class="lead"><?=t($beneficio['pagoActual']['proxPagoDesde'][1])?></p>
              </div>
            </div>
            
            <p class="m-t-1"><strong>Lugar de cobro</strong></p>
            <div><?= $beneficio['lugarDeCobro']?></div>
          </div>
        </div>
      </div>
    </div>
  <?php endforeach;?>
  <div class="panel">
    <div class="panel-body">
      
      <a href=# class="btn btn-link btn-block"> Hacé otra consulta</a>
      
      <div class="text-muted">
        <p class="small">Los datos son suministrados por la Administración Nacional de la Seguridad Social, Ministerio de Trabajo, Empleo y Seguridad Social de la Nación.</p>
      </div>
    </div>
  </div>
  
  <?php global $base_url?>
  <div class="row">
    <div class="col-md-12">
      <hr>
      <p class="pull-right">
        <img src="<?= $base_url ?>/sites/default/files/logo_anses.png" class="img-responsive m-b-2" alt="Anses" width="150">
      </p>
    </div>
  </div>
  
  
  </div>
</article>
