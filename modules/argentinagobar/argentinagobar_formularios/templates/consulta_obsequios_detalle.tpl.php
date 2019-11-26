<div class="row">
  <?php print $breadcrumb; ?>
</div>
<section>
  <article class="content_format row">
    <div class="col-md-8 col-md-offset-2">
      <h1><?php print $titulo; ?></h1>
      <hr>
      <div>
        <h3 class="m-b-1">Datos del funcionario:</h3>
        <?php if (isset($element['numero'])){ ?><label class="control-label m-t-1">Nombre: </label>
        <p ><?php print $element['nombres'] . " " .  $element['apellidos'];  ?></p><?php }?>
        <?php if (isset($element['bandbox_jurisidccion'])){ ?><label class="control-label m-t-1">Organismo: </label>
        <p ><?php print $element['bandbox_jurisidccion'];  ?></p><?php }?>
        <?php if (isset($element['bandbox_reparticion'])){ ?><label class="control-label m-t-1">Repartición: </label>
        <p ><?php print $element['bandbox_reparticion'];  ?></p><?php }?>
        <?php if (isset($element['cargo_funcion'])){ ?><label class="control-label m-t-1">Cargo: </label>
        <p ><?php print $element['cargo_funcion'];  ?></p><?php }?>
      </div>
      <hr>
      <div>
        <h3 class="m-b-1">Datos del obsequio:</h3>
        <?php if (isset($element['combo_caracter_excepcion'])){ ?><label class="control-label m-t-1">Motivo del Obsequio: </label>
        <p ><?php print $element['combo_caracter_excepcion'];  ?></p><?php }?>
        <?php if (isset($element['combo_tipo_obsequio'])){ ?><label class="control-label m-t-1">Tipo de Obsequio: </label>
        <p ><?php print $element['combo_tipo_obsequio'];  ?></p><?php }?>
        <?php if (isset($element['descripcion'])){ ?><label class="control-label m-t-1">Descripción del Obsequio: </label>
        <p ><?php print $element['descripcion'];  ?></p><?php }?>
        <?php if (isset($element['fecha_recepcion'])){ ?><label class="control-label m-t-1">Fecha de Recepción: </label>
        <p ><?php print $element['fecha_recepcion'];  ?></p><?php }?>
        <?php if (isset($element['combo_valor_estimado'])){ ?><label class="control-label m-t-1">Valor Estimado: </label>
        <p ><?php print $element['combo_valor_estimado'];  ?></p><?php }?>
        <?php if (isset($element['combo_finalidad_obsequioo'])){ ?><label class="control-label m-t-1">Finalidad que se le dará al Obsequio: </label>
        <p ><?php print $element['combo_finalidad_obsequioo'];  ?></p><?php }?>
        <?php if (isset($element['destino'])){ ?><label class="control-label m-t-1">Destino: </label>
        <p ><?php print $element['destino'];  ?></p><?php }?>
      </div>
      <hr>
      <div>
        <h3 class="m-b-1">Recepción del obsequio:</h3>
        <?php if (isset($element['combo_donde_fue_recibido'])){ ?><label class="control-label m-t-1">Lugar donde se recibió el obsequio: </label>
        <p ><?php print $element['combo_donde_fue_recibido']; ?></p><?php }?>
        <?php if (isset($element['domicilio_despacho'])){ ?><label class="control-label m-t-1">Dirección dónde se recibió el obsequio: </label>
        <p ><?php print $element['domicilio_despacho'];  ?></p><?php }?>
        <?php if (isset($element['descripcion_0'])){ ?><label class="control-label m-t-1"> Descripción: </label>
        <p ><?php print $element['descripcion_0'];  ?></p><?php }?>
        <?php if (isset($element['lugar_realizacion'])){ ?><label class="control-label m-t-1">Lugar de Realización: </label>
        <p ><?php print $element['lugar_realizacion'];  ?></p><?php }?>
        <?php if (isset($element['descripcioon'])){ ?><label class="control-label m-t-1">Descripción: </label>
        <p ><?php print $element['descripcioon'];  ?></p><?php }?>
        <?php if (isset($element['combo_quien_otorgo'])){ ?><label class="control-label m-t-1">Quién otorgó el obsequio: </label>
        <p ><?php print $element['combo_quien_otorgo'];  ?></p><?php }?>
        <?php if (isset($element['nombres_a']) && isset($element['apellidos_a'])){ ?><label class="control-label m-t-1">Nombre de quién otorgó el obsequio: </label>
        <p ><?php print $element['apellidos_a'] . " " . $element['nombres_a'] ;  ?></p><?php }?>
        <?php if (isset($element['descripcion_a'])){ ?><label class="control-label m-t-1">Descripción: </label>
        <p ><?php print $element['descripcion_a'];  ?></p><?php }?>
        <?php if (isset($element['razon_social'])){ ?><label class="control-label m-t-1">Razón social: </label>
        <p ><?php print $element['razon_social'];  ?></p><?php }?>
        <?php if (isset($element['denominacion_organismo'])){ ?><label class="control-label m-t-1">Denominación del Organismo: </label>
        <p ><?php print $element['denominacion_organismo'];  ?></p><?php }?>
        <?php if (isset($element['primer_apellido_representante']) && isset($element['primer_nombre_representante'])){ ?><label class="control-label m-t-1">Nombre del representante: </label>
        <p ><?php print $element['primer_apellido_representante'] . " " . $element['primer_nombre_representante'] ;  ?></p><?php }?>
        <?php if (isset($element['cargo_representante'])){ ?><label class="control-label m-t-1">Cargo del Representante: </label>
        <p ><?php print $element['cargo_representante'] ?></p><?php }?>
      </div>
  </div>
</article>
</section>
