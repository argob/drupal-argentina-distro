<article class="content_format row">
  <div class="col-md-8 col-md-offset-2">
    <h1>Detalle del viaje</h1>
    <hr>
    <div>
      <h3 class="m-b-1">Datos del funcionario:</h3>
      <?php if (isset($element['apellido_1']) && isset($element['nombre_1'])): ?>
        <label class="control-label m-t-1">Nombre: </label>
        <p><?=$element['apellido_1']." ".$element['nombre_1']?></p>
      <?php endif ?>
      <?php if (isset($element['jurisdiccioon'])):?>
        <label class="control-label m-t-1">Organismo: </label>
        <p><?=$element['jurisdiccioon']?></p>
      <?php endif ?>
      <?php if (isset($element['reparticioon'])):?>
        <label class="control-label m-t-1">Repartición: </label>
        <p><?=$element['reparticioon']?></p>
      <?php endif ?>
      <?php if (isset($element['cargo_funcion'])):?>
        <label class="control-label m-t-1">Etiqueta Cargo: </label>
        <p><?=$element['cargo_funcion']?></p>
      <?php endif ?>
    </div>
    <hr>
    <div>
      <h3 class="m-b-1">Datos del viaje:</h3>
      <?php if (isset($element['destino_viaje'])):?>
        <label class="control-label m-t-1">Lugar de Destino:</label>
        <p><?=$element['destino_viaje']?></p>
      <?php endif ?>
      <?php if (isset($element['date_fecha_inicio'])):?>
        <label class="control-label m-t-1">Fecha de Inicio del Viaje: </label>
        <p><?=$element['date_fecha_inicio']?></p>
      <?php endif ?>
      <?php if (isset($element['date_fecha_finalizacion'])):?>
        <label class="control-label m-t-1">Fecha de Fin del Viaje: </label>
        <p><?=$element['date_fecha_finalizacion']?></p>
      <?php endif ?>
      <?php if (isset($element['medio_transporte'])):?>
        <label class="control-label m-t-1">Medio de Transporte: </label>
        <p><?=$element['medio_transporte']?></p>
      <?php endif ?>
    </div>
    <hr>
    <div>
      <h3 class="m-b-1">Financiamiento del Viaje:</h3>
      <?php if (isset($element['combo_fuente_financiamiento'])):?>
        <label class="control-label m-t-1">Fuente de Financiamiento: </label>
        <p><?=$element['combo_fuente_financiamiento']?></p>
      <?php endif ?>
      <?php if (isset($element['pais_prov_municipio'])):?>
        <label class="control-label m-t-1">Pais/Provincia/Municipio que Financió el Viaje: </label>
        <p><?=$element['pais_prov_municipio']?></p>
      <?php endif ?>
      <?php if (isset($element['denominacion_organismo_gub'])):?>
        <label class="control-label m-t-1">Organismo que Financió el Viaje: </label>
        <p><?=$element['denominacion_organismo_gub']?></p>
      <?php endif ?>
      <?php if (isset($element['area_gobierno_contacto'])):?>
        <label class="control-label m-t-1">Area del Organismo que Realizó el Contacto: </label>
        <p><?=$element['area_gobierno_contacto']?></p>
      <?php endif ?>
      <?php if (isset($element['nombres']) && isset($element['apellidos'])):?>
        <label class="control-label m-t-1">Nombre: </label>
        <p><?=$element['nombres']." ".$element['apellidos']?></p>
      <?php endif ?>
      <?php if (isset($element['razon_social_fuente_financiami'])):?>
        <label class="control-label m-t-1">Razón Social: </label>
        <p><?=$element['razon_social_fuente_financiami']?></p>
      <?php endif ?>
      <?php if (isset($element['nombre_rep']) && isset($element['apellido_rep'])):?>
        <label class="control-label m-t-1">Nombre del Representante: </label>
        <p><?=$element['nombre_rep']." ".$element['apellido_rep']?></p>
      <?php endif ?>
      <?php if (isset($element['cargo_representante'])):?>
        <label class="control-label m-t-1">Cargo del Representante: </label>
        <p><?=$element['cargo_representante']?></p>
      <?php endif ?>
      <?php if (isset($element['nombres_ref']) && isset($element['apellidos_ref'])):?>
        <label class="control-label m-t-1">Nombre del Contacto de Referencia: </label>
        <p><?=$element['apellidos_ref']." ".$element['nombres_ref']?></p>
      <?php endif ?>
      <?php if (isset($element['cargo_contacto'])):?>
        <label class="control-label m-t-1">Cargo del Contacto de Referencia: </label>
        <p><?=$element['cargo_contacto']?></p>
      <?php endif ?>
      <?php if (isset($element['combo_erogacion'])):?>
        <label class="control-label m-t-1">Tuvo Erogación del Estado Nacional: </label>
        <p><?=$element['combo_erogacion']?></p>
      <?php endif ?>
    </div>
    <hr>
    <div>
      <h3 class="m-b-1">Erogación del Estado Nacional:</h3>
      <?php if (isset($element['check_estadia'])):?>
        <label class="control-label m-t-1">Estadía: </label>
        <p><?=$element['check_estadia'] == "true" ? "Si" : "No";?></p>
      <?php endif ?>
      <?php if (isset($element['check_pasajes'])):?>
        <label class="control-label m-t-1">Pasaje: </label>
        <p><?=$element['check_pasajes'] == "true" ? "Si" : "No";?></p>
      <?php endif ?>
      <?php if (isset($element['check_viaticos_100'])):?>
        <label class="control-label m-t-1">Viáticos 100%: </label>
        <p><?=$element['check_viaticos_100'] == "true" ? "Si" : "No";?></p>
      <?php endif ?>
      <?php if (isset($element['check_viaticos_25'])):?>
        <label class="control-label m-t-1">Viáticos 25%: </label>
        <p><?=$element['check_viaticos_25'] == "true" ? "Si" : "No";?></p>
      <?php endif ?>
      <?php if (isset($element['check_arancel_evento'])):?>
        <label class="control-label m-t-1">Arancel del Evento: </label>
        <p><?=$element['check_arancel_evento'] == "true" ? "Si" : "No";?></p>
    <?php endif ?>
    </div>
    <hr>
    <div>
      <h3 class="m-b-1">Datos del evento:</h3>
      <?php if (isset($element['evento_participara'])):?>
        <label class="control-label m-t-1">Evento en el que Participó: </label>
        <p><?=$element['evento_participara']?></p>
      <?php endif ?>
      <?php if (isset($element['date_inicio_evento'])):?>
        <label class="control-label m-t-1">Fecha de Inicio del Evento: </label>
        <p><?=$element['date_inicio_evento']?></p>
      <?php endif ?>
      <?php if (isset($element['date_finalizacoin_evento'])):?>
        <label class="control-label m-t-1">Fecha de Fin del Evento: </label>
        <p><?=$element['date_finalizacoin_evento']?></p>
      <?php endif ?>
      <label class="control-label m-t-1">Carácter de la Participación: </label>
      <?php if($element['expositor'] == "true" || $element['expositor'] == '1'):?>
        <p>Expositor</p>
      <?php endif ?>
      <?php if($element['capacitador'] == "true" || $element['capacitador'] == '1'):?>
        <p>Capacitador</p>
      <?php endif ?>
      <?php if($element['participante'] == "true" || $element['participante'] == '1'):?>
        <p>Participante</p>
      <?php endif ?>
      <?php if($element['otro'] == "true" || $element['otro'] == '1'):?>
        <p>Otro</p>
        <?php if(isset($element['descripcion'])):?>
          <p><?="Descripcion: ".$element['descripcion']?></p>
        <?php endif ?>
      <?php endif ?>
    </div>
  </div>
</article>
