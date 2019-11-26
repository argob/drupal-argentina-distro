<h2 class="table_title m-b-0">Datos del expediente:</h2>
<h4><?php print $data['caratula']['tipoActuacion'] . $data['caratula']['anio'] . $data['caratula']['numero'] . "-" . $data['caratula']['descripcionReparticionActuacion'] . "-" . $data['caratula']['codigoReparticionUsuario']; ?></h4>
<div class="row  m-t-3">
  <div class="col-md-6">
    <label class="control-label">Tipo de Expediente: </label>
    <p><?php print $data['tipoExpediente']; ?></p>
    <label class="control-label">Año Expediente: </label>
    <p><?php print $data['caratula']['anio']; ?></p>
    <label class="control-label">Número Expediente: </label>
    <p><?php print $data['caratula']['numero']; ?></p>
    <label class="control-label">Fecha Caratulación: </label>
    <p><?php print date('d-m-Y', $data['caratula']['fechaCaratulacion'] / 1000); ?></p>
    <label class="control-label">Codigo Trámite: </label>
    <p><?php print $data['caratula']['codigoTrata']; ?></p>
    <label class="control-label">Descripcion Trámite: </label>
    <p><?php print $data['caratula']['descripcionTrata']; ?></p>
  </div>
  <div class="col-md-6">
    <label class="control-label">Estado Actual: </label>
    <p><?php print ($data['tipoExpediente'] == "Expediente Digital") ?  $data['caratula']['estadoActual']: "No disponible en expedientes papel"; ?></p>

    <label class="control-label">Ubicación Actual: </label>
    <p>
      <?php
      $ubicacion_actual = array_pop($data['historialPases']);
      print $ubicacion_actual['destinoPaseCodigoReparticion'];
      ?>
    </p>
    <label class="control-label">Descripcion Repartición de Actuación: </label>
    <p><?php print $data['caratula']['descripcionReparticionActuacion']; ?></p>
    <label class="control-label">Codigo Repartición Iniciadora: </label>
    <p><?php print $data['caratula']['codigoReparticionUsuario']; ?></p>
    <label class="control-label">Descripcion Repartición Iniciadora: </label>
    <p><?php print $data['caratula']['descripcionReparticionUsuario']; ?></p>
  </div>
</div>
<div class="row">
  <div class="col-md-12 m-t-3">
    <h4 class="h3 text-muted m-y-1">Historial de pases</h4>
  </div>

  <div class="col-md-12 text-center">
      <table class="table table-striped table-mobile">
        <thead>
          <tr>
            <th class="text-center">Fecha</th>
            <th class="text-center">Emisor</th>
            <th class="text-center">Destino</th>
          </tr>
        </thead>
        <tbody>

          <?php foreach ($data['historialPases'] as $key => $pase) { ?>
            <tr>
              <td>
                <span class="td-label">Fecha</span>
                <?php print date('d-m-Y', $pase['fechaIngreso'] / 1000); ?>
              </td>
              <td>
                <span class="td-label">Emisor</span>
                <?php print $pase['origenPaseCodigoReparticion']; ?>
              </td>
              <td>
                <span class="td-label">Destino</span>
                <?php print $pase['destinoPaseCodigoReparticion']; ?>
              </td>
            </tr>
          <?php } ?>
        </tbody>
      </table>
  </div>
</div>
<p class="text-center m-t-3 m-b-1">
  <a href="<?php drupal_lookup_path('alias', current_path()); ?>" class="btn btn-primary">Hacer otra consulta</a>
</p>
