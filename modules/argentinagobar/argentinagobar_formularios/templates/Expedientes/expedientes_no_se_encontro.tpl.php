<div>
  <i class="fa fa-warning m-t-0 m-b-1 fa-3x text-warning"></i>
  <h2 class="m-t-2 font-weight-bold">No pudimos realizar la consulta</h2>
  <p>Por favor verificá si los datos que cargaste son correctos.<br>
</div>

<div class="panel panel-default">
  <div class="panel-body">
    <h1 class="m-t-2 font-weight-bold">Cargaste estos datos: </h1>
      <div class="row">
        <div class="col-md-12">
          <label class="control-label">Tipo actuación - Año</label>
          <p><?php print $tipo_actuacion.'-'.$year ?></p>
        </div>
        <div class="col-md-12">
          <label class="control-label">Número de expediente</label>
          <p><?php print $numero_expediente ?></p>
        </div>
        <div class="col-md-12">
          <label class="control-label">Código Repartición</label>
          <p><?php print $codigo_reparticion_actuacion.'-'.$codigo_reparticion_usuario ?></p>
        </div>
        <div class="col-md-12">
          <div class="m-t-2">
            <a href="<?php drupal_lookup_path('alias', current_path()); ?>" class="btn btn-primary"> Cargá de nuevo tus datos</a>
          </div>
        </div>
      </div>
  </div>
</div>
