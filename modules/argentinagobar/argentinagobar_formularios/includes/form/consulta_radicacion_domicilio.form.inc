<?php

function consulta_radicacion_domicilio($form, &$form_state) {

  if(empty($form_state['handler'])) {

    $consulta = new ConsultaRadicacionPorDomicilio(ApiGatewayAuth::getInstance(), array());

    $form_state['handler'] = serialize($consulta);

  } else {
    $consulta = unserialize($form_state['handler']);
  }

  $form = array();

  $form['#prefix'] = '<div id="contenedor-form">';
  $form['#suffix'] = '</div>';

  $form['container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contenedor'
    ),
  );

  // Initialize.
  if ($form_state['rebuild']) {
    // Don't hang on to submitted data in form state input.
    $form_state['input'] = array();
  }

  foreach ($consulta->storage['step_information'] as $step => $step_information) {
    if(isset($step_information['values'])) {
      $consultaActual = $consulta->getConsulta($step);
      foreach ($step_information['storable_values'] as $key => $label) {
        $form['container']['container_' . $key] = array(
          '#type' => 'markup',
          '#markup' => '<div class="form-group"><label>' . $label . '</label><p><strong>' . $consultaActual->traducirValue($step_information['values'][$key]) . '</strong></p></div>'
        );
      }
    }
  }

  $step = $consulta->getStep();

  $form['container'][$step] = $consulta->getStepForm();

  $form['container']['acciones'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'acciones',
      'class' => array('text-center'),
    ),
  );

  if($step < 7) {
    $form['container']['acciones']['siguiente'] = array(
      '#type' => 'submit',
      '#value' => 'Siguiente',
      '#name' => 'siguiente',
      '#attributes' => array(
        'class' => array('btn', 'btn-success','m-b-2', 'btn-block', 'icon-load')
      ),
      '#ajax' => array(
        'callback' => 'consulta_radicacion_domicilio_siguiente_submit',
        'wrapper' => 'contenedor-form',
        'method' => 'replace',
        'progress' => FALSE,
      ),
    );
  
  
  } else{
    $form['container']['acciones']['consultar'] = array(
      '#type' => 'submit',
      '#value' => t('Consultar'),
      '#name' => 'consultar',
      '#attributes' => array(
        'class' => array(
          'btn', 'btn-success', 'btn-block','m-b-2', 'btn-lg', 'icon-load')
      ),
      '#ajax' => array(
        'callback' => 'consulta_radicacion_domicilio_consultar_submit',
        'wrapper' => 'contenedor-form',
        'method' => 'replace',
        'progress' => FALSE,
      ),
    );
    $form['container']['acciones']['de_nuevo'] = array(
      '#type' => 'markup',
      '#markup' =>'<a class="btn btn-block btn-primary" href='.drupal_lookup_path('alias', current_path()).'>Reiniciar Consulta</a>',
      '#attributes' => array(
        'class' => array('btn', 'btn-block','btn-lg','btn-primary','icon-load'),
      ),
    );
  }

  return $form;
}

function consulta_radicacion_domicilio_reset($form, &$form_state) {
  $form_state['rebuild'] = FALSE;
}
function consulta_radicacion_domicilio_submit($form, &$form_state){

    $current_step = &$form_state['storage']['step'];
    $consulta = unserialize($form_state['handler']);
    $consulta->saveValues($form_state['values']);

    if ($consulta->getStep() < $consulta->cantidadPasos()) {
      $consulta->consultar();
      $form_state['rebuild'] = TRUE;
    }

    $form_state['handler'] = serialize($consulta);
}

function consulta_radicacion_domicilio_siguiente_submit($form, &$form_state){
  return $form;
}


function traducir($valor,$valores) {
  foreach ($valores as $campo => $value) {
    if($campo == $valor){
      $denominacion = $value;
    }
  }
  return $denominacion;
}

function consulta_radicacion_domicilio_consultar_submit($form, $form_state) {

  $consulta = unserialize($form_state['handler']);

  $consultaRegistroSeccional = $consulta->getConsulta(8);
  $dataRegistroSeccional = $consultaRegistroSeccional->dataRegistroSeccional;
  $dataConsulta = $consulta;
  $infoDataRegistroSeccional = array(
    'titulo' => t('Información del Registro Automotor'),
    'data' => array(
      array(
        'label' => t('Registro Seccional'),
        'value' => empty($dataRegistroSeccional['denominacion']) ? "-" : t($dataRegistroSeccional['denominacion'])
      ),
      array(
        'label' => t('Dirección'),
        'value' => t($dataRegistroSeccional['domicilio'])
      ),
      array(
        'label' => t('Piso'),
        'value' => empty($dataRegistroSeccional['piso']) ? "-" : t($dataRegistroSeccional['piso'])
      ),
      array(
        'label' => t('Departamento'),
        'value' => empty($dataRegistroSeccional['depto']) ? "-" :  t($dataRegistroSeccional['depto'])
      ),
      array(
        'label' => t('Código postal'),
        'value' => empty($dataRegistroSeccional['codigoPostal']) ? "-" : t($dataRegistroSeccional['codigoPostal'])
      ),
      array(
        'label' => t('Localidad'),
        'value' => empty($dataRegistroSeccional['localidad']) ? "-": t($dataRegistroSeccional['localidad'])
      ),
      array(
        'label' => t('Provincia'),
        'value' => empty($dataRegistroSeccional['provincia']) ? "-": t($dataRegistroSeccional['provincia'])
      ),
      array(
        'label' => t('Teléfono'),
        'value' => empty($dataRegistroSeccional['telefono']) ? "-": t($dataRegistroSeccional['telefono'])
      ),
      array(
        'label' => t('Fax'),
        'value' => empty($dataRegistroSeccional['fax']) ? "-": t($dataRegistroSeccional['fax'])
      ),
      array(
        'label' => t('Horario'),
        'value' => empty($dataRegistroSeccional['horarioAtencion']) ? "-": t($dataRegistroSeccional['horarioAtencion'])
      ),
      array(
        'label' => t('Encargado'),
        'value' => empty($dataRegistroSeccional['encargado']) ? "-": t($dataRegistroSeccional['encargado'])
      ),
    )
  );
  $infoDataRegistroSeccionalBancaria = array(
    'titulo' => t('Información bancaria del Registro'),
    'data' => array(
      array(
        'label' => t('Banco'),
        'value' => empty($dataRegistroSeccional['datosBancarios']['datos']['banco']) ? "-" : t($dataRegistroSeccional['datosBancarios']['datos']['banco'])
      ),
      array(
        'label' => t('Cuit'),
        'value' => empty($dataRegistroSeccional['datosBancarios']['datos']['cuitCuil']) ? "-" : t($dataRegistroSeccional['datosBancarios']['datos']['cuitCuil'])
      ),
      array(
        'label' => t('Sucursal'),
        'value' => empty($dataRegistroSeccional['datosBancarios']['datos']['sucursal']) ? "-" : t($dataRegistroSeccional['datosBancarios']['datos']['sucursal'])
      ),
      array(
        'label' => t('CBU'),
        'value' => empty($dataRegistroSeccional['datosBancarios']['datos']['cbu']) ? "-" : t($dataRegistroSeccional['datosBancarios']['datos']['cbu'])
      ),
      array(
        'label' => t('Cuenta'),
        'value' => empty($dataRegistroSeccional['datosBancarios']['datos']['numeroCuenta']) ? "-" : t($dataRegistroSeccional['datosBancarios']['datos']['numeroCuenta'])
      ),
      array(
        'label' => t('Red'),
        'value' => empty($dataRegistroSeccional['datosBancarios']['datos']['red']) ? "-" : t($dataRegistroSeccional['datosBancarios']['datos']['red'])
      ),
    )
    );

    $infoDataConsulta = array(
      'titulo' => t('Información de la consulta'),
      'data' => array(
        array(
          'label' => t('Tipo de Vehículo'),
          'value' => traducir($dataConsulta->storage['step_information'][1]['values']['tipoVehiculo'],$dataConsulta->consultas[1]->results)
        ),
        array(
          'label' => t('Pronvincia'),
          'value' => traducir($dataConsulta->storage['step_information'][2]['values']['idProvincia'],$dataConsulta->consultas[2]->provincias)
        ),
        array(
          'label' => t('Departamento (partido)'),
          'value' =>traducir($dataConsulta->storage['step_information'][3]['values']['idDepartamento'],$dataConsulta->consultas[3]->departamentos)
        ),
        array(
          'label' => t('Localidad'),
          'value' =>traducir($dataConsulta->storage['step_information'][4]['values']['idLocalidad'],$dataConsulta->consultas[4]->localidades)
        ),
        array(
          'label' => t('Calle o Barrio'),
          'value' => traducir($dataConsulta->storage['step_information'][5]['values']['idCalle'],$dataConsulta->consultas[5]->calles_barrios)
        ),
        array(
          'label' => t('Altura'),
          'value' => $dataConsulta->storage['step_information'][6]['values']['alturaExacta']
          ),
        )
      );

    $alerta = "Si no encontrás tu domicilio o la consulta te muestra un error, por favor primero revisá que los datos sean correctos, y comunicáte con la DNRPA para que asesoremos <strong>antes de hacer la transferencia bancaria</strong>";

    $paneles[] = theme('response_panel', $infoDataRegistroSeccional);
    $paneles[] = theme('response_panel', $infoDataRegistroSeccionalBancaria);
    $paneles[] = theme('response_panel_consulta', $infoDataConsulta);

    $footer = array(
      'titulo' => t('Datos de contacto de DNRPA'),
      'data' => array(
        array(
          'label' => t('Teléfono'),
          'value' => l('0800-122-2227','tel:0800-122-2227') . ' ' . t('(de 07:00hs a 16.00)'),
          ),
        array(
          'label' => t('Correo electrónica'),
          'value' => l('asesoramiento@dnrpa.gob.ar','mailto:asesoramiento@dnrpa.gob.ar'),
        ),
        )
      );

    $response = theme('response_panel_completo', array(
    'titulo' => t('Información del Registro Seccional donde tenés que radicar tu vehículo'),
    'paneles' => $paneles,
    'alerta' => $alerta,
    'footer' => $footer)
    );


  $form = array();

  $form['contenedor'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contenedor-form',
      ),
  );

  $form['contenedor']['response'] = array(
    '#type' => 'markup',
    '#markup' => $response,
  );

  return $form;
}

function consulta_radicacion_domicilio_anterior_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['input'];
  if ($current_step > 1) {
    $current_step--;
    $form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
  }
  $form_state['rebuild'] = TRUE;
}
