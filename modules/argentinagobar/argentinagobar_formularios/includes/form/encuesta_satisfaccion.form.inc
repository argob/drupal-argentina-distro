<?php

function encuesta_satisfaccion($form, &$form_state){
  
  $form = array();

  $form['contenedor'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contenedor',
     ),
  );
  
  if(isset($form_state['values']['provincia']) || isset($_GET['u']))
  {
    
    $consulta = new ConsultaGeoRefLocalidades(ApiGatewayAuth::getInstance());
    
    $consulta->set_values($form_state['values']);
     
    if(isset($_GET['u'])){
      $localidades[$_GET['u']] = 'localidad Get';
    }else{
      foreach ($consulta->consultar() as $localidad){
        $localidades[$localidad['id']] = $localidad['nombre'];
      }
    }  
    
    $localidad_disabled = FALSE;
    
  }
  else
  {
    
    $localidades = array();
    
    $localidad_disabled = TRUE;
    
  }
  
  if(isset($form_state['values']['organismo']) || isset($_GET['ot']))
  {
    
    $consulta = new ConsultaMSCRMTramitesCategorias(ApiGatewayAuth::getInstance());
    
    $consulta->set_values($form_state['values']);
      
    foreach ($consulta->consultar() as $categoria)
    {
      $categorias[$categoria['cod_categoria']] = $categoria['categoria'];
    }
    
    $tramite_disabled = FALSE;
    
  }
  else
  {
    
    $tramite_disabled = TRUE;
    
    $categorias = array();
    
  }
    
  $modalidad = array(
    '#type' => 'radios',
    '#title' => t('Indicá el medio por el cual realizaste el trámite'),
    '#title_display' => 'invisible',
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['modalidad']) ? $form_state['values']['modalidad'] : NULL,
    '#attributes' => array(
      'class' => array('habilitarSiguiente'),
    ),
    '#theme' => array('form_element_radios'),
    '#options' => array(
      'D6BFF86A-BF22-435F-B6F0-72578968138A' => t('Presencial'),
      'A1EF2AE5-DDA7-4CDF-B09A-44C82F5F2586' => t('Telefónico'),
      'E20A397D-1FBC-436E-B99D-0E742305B0D6' => t('Correo electrónico'),
    ),
  );
    
  $organismo = array(
      '#type' => 'select',
      '#empty_option' => t('Elegir...'),
      '#title' => t('Organismo'),
      '#attributes' => array(
        'class' => array('habilitaPregunta2'),
      ),
      '#required' => TRUE,
      '#options' => organismos(),
      '#ajax' => array(
        'callback' => 'actualizar_formulario', 
        'event' => 'change',
        'wrapper' => 'contenedor',
        'method' => 'replace',
        'effect' => 'none',
        'progress' => FALSE
      ),
  );
  
  $provincia = array(
    '#type' => 'select',
    '#empty_option' => t('Elegir...'),
    '#title' => t('Provincia'),
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array('habilitaPregunta2'),
    ),
    '#options' => provincias(),
    '#ajax' => array(
      'callback' => 'actualizar_formulario', 
      'event' => 'change',
      'wrapper' => 'contenedor',
      'method' => 'replace',
      'effect' => 'none',
       'progress' => FALSE
    ),
  );

  $localidad = array(
      '#type' => 'select',
      '#empty_option' => t('Elegir...'),
      '#title' => t('Localidad'),
      '#disabled' => $localidad_disabled,
      '#attributes' => array(
        'class' => array('habilitaPregunta2'),
        'name' => 'localidad'
      ),
      '#options' => $localidades,
      '#required' => TRUE,
      '#prefix' => '<div id="localidad-wrapper">',
      '#suffix' => '</div>'
  );

  
  
  $tramite = array(
    '#type' => 'select',
    '#empty_option' => t('Elegir...'),
    '#title' => t('Trámite'),
    '#required' => TRUE,
    '#disabled' => $tramite_disabled,
    '#attributes' => array(
      'id' => array('tramite'),
    ),
    '#options' => $categorias,
  );
  
  $calidad_atencion = array(
      '#type' => 'radios',
      '#title' => t('Calidad de atención'),
      '#title_display' => 'invisible',
      '#default_value' => isset($form_state['values']['calidad_atencion']) ? $form_state['values']['calidad_atencion'] : NULL,
      '#required' => TRUE,
      '#theme' => array('form_element_radios'),
      '#attributes' => array(
        'class' => array('habilitarSiguiente'),
      ),
      '#options' => array(
        'AD4E993F-1D23-48C1-8F39-24702740BB0D' => t('Muy mala'),
        '2C9DFA9B-EA09-4CA3-85AE-ADD98E50D493' => t('Mala'),
        '6CCDDC6F-355F-4B1D-A6D5-7C5F1BC03B1E' => t('Regular'),
        '5C312B6D-1ACA-4F57-B375-9209F8F325F6' => t('Buena'),
        '87D34D0B-CC2B-4DF7-8BD9-A32AF54A18EE' => t('Muy Buena'),
      ),
  );
    
  $tiempo_espera = array(
    '#type' => 'radios',
    '#title' => t('Tiempo de espera'),
    '#title_display' => 'invisible',
    '#default_value' => isset($form_state['values']['tiempo_espera']) ? $form_state['values']['tiempo_espera'] : NULL,
    '#required' => TRUE,
    '#theme' => array('form_element_radios'),
    '#attributes' => array(
      'class' => array('habilitarSiguiente'),
    ),
    '#options' => array(
      '81C81819-12C0-4846-9026-9FAA240DB6C4' => t('Más de 20 minutos de espera'),
      '9B4D1112-2128-42B6-84E7-3A264E2C84CE' => t('Entre 20 y 15 minutos de espera'),
      'E6EFB896-107B-4166-B03B-4D27077A668B' => t('Entre 15 y 10 minutos de espera'),
      'C07932D6-0E42-4102-BC16-6FB7626DD9C6' => t('Entre 10 y 5 minutos de espera'),
      'B97E49AF-204C-4551-81EF-D333AD116E66' => t('Menos de 5 minutos de espera'),
    ),
  );
  
  $tiempo_espera_tramite = array(
    '#type' => 'radios',
    '#title' => t('Tiempo de realización del trámite'),
    '#title_display' => 'invisible',
    '#default_value' => isset($form_state['values']['tiempo_espera_tramite']) ? $form_state['values']['tiempo_espera_tramite'] : NULL,
    '#required' => TRUE,
    '#theme' => array('form_element_radios'),
    '#attributes' => array(
        'class' => array('habilitarSiguiente'),
    ),
    '#options' => array(
        'CEDD8FFD-ED9E-4FFE-A585-73039E670310' => t('Más de 20 minutos de espera'),
        '0C03CE97-0ED6-439A-AC1B-03BE5618208D' => t('Entre 20 y 15 minutos de espera'),
        '41BD956E-FBB5-4C37-8498-45322241EFDA' => t('Entre 15 y 10 minutos de espera'),
        '7C78B0C4-B5B3-4108-89B6-C835D2AC2EBE' => t('Entre 10 y 5 minutos de espera'),
        'A59E93F0-5D45-45E3-B345-B2A3656F540C' => t('Menos de 5 minutos de espera'),
    ),
  );
  
  $utilidad = array(
    '#type' => 'radios',
    '#title' => t('Útilidad'),
    '#title_display' => 'invisible',
    '#default_value' => isset($form_state['values']['utilidad']) ? $form_state['values']['utilidad'] : NULL,
    '#theme' => array('form_element_radios'),
    '#required' => TRUE,
    '#attributes' => array(
        'class' => array('habilitarSiguiente'),
        'data-qid' => '4F1CFF65-6B78-E711-80F1-E0071B6E8DC1',
    ),
    '#options' => array(
        'B77060F2-54AF-4605-A106-1E9074DECAA2' => t('Inútil'),
        '84569F70-6FBC-4EAC-BFF1-7CF45B480308' => t('Poco útil'),
        'D80BAFA3-CDA5-44A0-B40E-C4C6190CE5B0' => t('Regular'),
        '4B1B7964-40A0-4218-9BC0-FA23F1A4D7E0' => t('Útil'),
        '90DF9129-0289-4983-A254-B4594E190A37' => t('Muy útil'),
    ),
  );
  
  $conoce_argobar = array(
    '#type' => 'radios',
    '#title' => t('Conoce argentina.gob.ar'),
    '#title_display' => 'invisible',
    '#default_value' => isset($form_state['values']['conoce']) ? $form_state['values']['conoce'] : NULL,
    '#theme' => array('form_element_radios'),
    '#required' => TRUE,
    '#options' => array(
        'NO' => t('No'),
        'SI' => t('Sí'),
    ),
  );
  
  $dni = array(
    '#type' => 'textfield',
    '#title' => t('DNI'),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => 'DNI'
    ),
    '#rules' => array(
      'numeric',
      array('rule' => 'length[7, 8]', 'error' => 'El DNI debe tener entre 7 y 8 números'), 
	),
    '#default_value' => isset($form_state['values']['dni']) ? $form_state['values']['dni'] : NULL,
  );
  
  $comentario = array(
    '#type' => 'textarea',
    '#title' => t('Comentarios'),
    '#title_display' => 'invisible',
    '#resizable' => FALSE,
    '#attributes' => array(
      'placeholder' => 'Dejanos tu comentario'
    ),
    '#default_value' => isset($form_state['values']['comentario']) ? $form_state['values']['comentario'] : NULL,
  );

  // modalidad
  $form['contenedor']['contenedor-pregunta-1'] = contenedor_pregunta(
      1,
      panel(
          'Indicá el medio por el cual realizaste el trámite',
          array('modalidad' => $modalidad)
      )
  );
  
  if(isset($_GET['m'])){
    
    $medio = obtenerMedio($_GET['m']);
    if($medio != ''){
      $form['contenedor']['contenedor-pregunta-1']['panel'][0]['panel-body-media-form-group']['modalidad']['#default_value'] = $medio;
      
      $atributes = $form['contenedor']['contenedor-pregunta-1']['panel']['#attributes']['class'][0];
      $form['contenedor']['contenedor-pregunta-1']['panel']['#attributes'] = array('class' => array($atributes.' hidden'));
    }
  }

  // provincia - localidad
  $form['contenedor']['contenedor-pregunta-2'] = contenedor_pregunta(
      2,
      panel('Indicá la provincia y localidad donde realizaste el trámite', array(
          'provincia' => $provincia,
          'localidad' => $localidad,
        )
      )
  );

  if(isset($_GET['u'])){
    
    $localidad = $_GET['u'];
    $provincia = substr($localidad, 0, 2);

    if($localidad != ''){
      $form['contenedor']['contenedor-pregunta-2']['panel'][0]['panel-body-media-form-group']['provincia']['#default_value'] = $provincia;
      $form['contenedor']['contenedor-pregunta-2']['panel'][0]['panel-body-media-form-group']['localidad']['#default_value'] = $localidad;
        
      $atributes = $form['contenedor']['contenedor-pregunta-2']['panel']['#attributes']['class'][0];
      $form['contenedor']['contenedor-pregunta-2']['panel']['#attributes'] = array('class' => array($atributes.' hidden'));
    }
  }


  
  // organismo - tramite
  $form['contenedor']['contenedor-pregunta-3'] = contenedor_pregunta(
    3,
    panel('Indicá el organismo y el trámite que realizaste', array(
      'organismo' => $organismo,
      'tramite' => $tramite,
      )
    )
  );

  if(isset($_GET['ot'])){
    
    $ot = explode('-', $_GET['ot']);

    $organismo = strtoupper(($ot[0]));
    $tramite = $ot[1];
    
    if($_GET['ot'] != ''){
      
      $form['contenedor']['contenedor-pregunta-3']['panel'][0]['panel-body-media-form-group']['organismo']['#default_value'] = $organismo;
      $form['contenedor']['contenedor-pregunta-3']['panel'][0]['panel-body-media-form-group']['tramite']['#default_value'] = $tramite;
        
      $atributes = $form['contenedor']['contenedor-pregunta-3']['panel']['#attributes']['class'][0];
      $form['contenedor']['contenedor-pregunta-3']['panel']['#attributes'] = array('class' => array($atributes.' hidden'));
    }
  }

  
  $form['contenedor']['contenedor-pregunta-4'] = contenedor_pregunta(
      4,
      panel('En general, ¿qué te pareció la atención que te brindaron durante el trámite?', array('calidad_atencion' => $calidad_atencion))
  );
  
  $form['contenedor']['contenedor-pregunta-5'] = contenedor_pregunta(
      5,
      panel('¿Cuánto tiempo esperaste hasta que te atendieron?', array('tiempo_espera' => $tiempo_espera))
  );
  
  $form['contenedor']['contenedor-pregunta-6'] = contenedor_pregunta(
      6,
      panel('A partir de que te atendieron, ¿cuánto tiempo tardó en realizarse el trámite?', array('tiempo_espera_tramite' => $tiempo_espera_tramite))
  );
  
  $form['contenedor']['contenedor-pregunta-7'] = contenedor_pregunta(
      7,
      panel('¿Qué tan útil te resultó la atención que te brindaron?', array('utilidad' => $utilidad))
  );
  
  $form['contenedor']['contenedor-pregunta-8'] = contenedor_pregunta(
      8,
      panel('¿Querés contar qué pasó o algún detalle sobre la atención del trámite? (opcional)', array('comentario' => $comentario))
  );
  
  // dni
  $form['contenedor']['contenedor-pregunta-9'] = contenedor_pregunta(
      9,
      panel('Para poder hacer un mejor seguimiento por favor ingresá tu DNI (opcional)', array('dni' => $dni))
  );

  if(isset($_GET['d'])){
   
    $getdni = $_GET['d'] != '' ? $_GET['d'] : '';
    if($getdni != ''){

      $form['contenedor']['contenedor-pregunta-9']['panel'][0]['panel-body-media-form-group']['dni']['#default_value'] = $getdni;

      $atributes = $form['contenedor']['contenedor-pregunta-9']['panel']['#attributes']['class'][0];
      $form['contenedor']['contenedor-pregunta-9']['panel']['#attributes'] = array('class' => array($atributes.' hidden'));
    }
  }
  
  $form['contenedor']['contenedor-pregunta-10'] = contenedor_pregunta(
      10,
      panel('¿Conocés la guía de trámites de Argentina.gob.ar?', array('conoce_argobar' => $conoce_argobar)),
      boton_finalizar()
  );
  
  $form['#attached']['js'] = array(
      drupal_get_path('module', 'argentinagobar_formularios') . '/js/accionesEncuestaSatisfaccion.js',
  );
  
  return $form;
}



  /*
    medio:

    1 => 'D6BFF86A-BF22-435F-B6F0-72578968138A' => t('Presencial'),
    2 => 'A1EF2AE5-DDA7-4CDF-B09A-44C82F5F2586' => t('Telefónico'),
    3 => 'E20A397D-1FBC-436E-B99D-0E742305B0D6' => t('Correo electrónico'),

  */
  function obtenerMedio($getMedio){
    
    switch ($getMedio) {
      case '1':
        $medio = 'D6BFF86A-BF22-435F-B6F0-72578968138A';
        break;
      case '2':
        $medio = 'A1EF2AE5-DDA7-4CDF-B09A-44C82F5F2586';
        break;
      case '3':
        $medio = 'E20A397D-1FBC-436E-B99D-0E742305B0D6';
        break;
      default:
        $medio = '';
        break;
    }

    return $medio;
  }

// Al seleccionar una opción del select, el cuál tiene asociado el evento change,
// el formulario se vuelve a crear usando el valor elegido al ejecutar la consulta correspondiente
function actualizar_formulario($form, &$form_state){
  
  $dniForm = $form['contenedor']['contenedor-pregunta-9']['panel'][0]['panel-body-media-form-group']['dni']['#value'];

  if($dniForm != '' && isset($_GET['d'])){
    $atributes = $form['contenedor']['contenedor-pregunta-9']['panel']['#attributes']['class'][0];
    $form['contenedor']['contenedor-pregunta-9']['panel']['#attributes'] = array('class' => array($atributes.' hidden'));
  }

  $modalidadForm = $form['contenedor']['contenedor-pregunta-1']['panel'][0]['panel-body-media-form-group']['modalidad']['#value'];  
  
  if($modalidadForm != '' && isset($_GET['m'])){
    $atributes = $form['contenedor']['contenedor-pregunta-1']['panel']['#attributes']['class'][0];
    $form['contenedor']['contenedor-pregunta-1']['panel']['#attributes'] = array('class' => array($atributes.' hidden'));
  }

  $tramiteForm = $form['contenedor']['contenedor-pregunta-3']['panel'][0]['panel-body-media-form-group']['tramite']['#value']; 

  if($tramiteForm != '' && isset($_GET['ot'])){
    $atributes = $form['contenedor']['contenedor-pregunta-3']['panel']['#attributes']['class'][0];
    $form['contenedor']['contenedor-pregunta-3']['panel']['#attributes'] = array('class' => array($atributes.' hidden'));
  }

  $localidadForm = $form['contenedor']['contenedor-pregunta-2']['panel'][0]['panel-body-media-form-group']['localidad']['#value']; 

  if($localidadForm != '' && isset($_GET['u'])){
    $atributes = $form['contenedor']['contenedor-pregunta-2']['panel']['#attributes']['class'][0];
    $form['contenedor']['contenedor-pregunta-2']['panel']['#attributes'] = array('class' => array($atributes.' hidden'));
  }

  return $form;
}

function provincias(){
  
  $consultaProvincias = new ConsultaGeoRefProvincias(ApiGatewayAuth::getInstance());
  
  $provincias = array();
  
  if($consultaProvincias->consultar()){
    foreach ($consultaProvincias->consultar() as $provincia){
      $provincias[$provincia['id']] = $provincia['nombre'];
    }
  }
  
  return $provincias;
}

function organismos(){

  $consultaOrganismos = new ConsultaMSCRMOrganismos(ApiGatewayAuth::getInstance());
  
  $organismos = array();
  
  if($consultaOrganismos->consultar()){
    foreach ($consultaOrganismos->consultar() as $organismo){
      $organismos[$organismo['cod_organismo']] = $organismo['nombre'];
    }
  }
  
  return $organismos;
}

function boton_finalizar(){
  
  return array(
    '#type' => 'submit',
    '#value' => t('Enviar'),
    '#attributes' => array(
        'class' => array('btn', 'btn-success', 'btn-md', 'sig')
    ),
    '#submit' => array(),
    '#ajax' => array(
      'callback' => 'encuesta_satisfaccion_submit_ajax',
      'wrapper' => 'contenedor',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#prefix' => '<div class="row"><div class="text-right col-md-6 col-md-offset-3">',
    '#suffix' => '</div></div>'
  );
}

function boton_anterior()
{
  return array(
    '#type' => 'link',
    '#title' => 'Anterior',
    '#href' => '#',
    '#attributes' => array(
        'class' => array('btn btn-success btn-m')
    ),
  );
}

function contenedor_pregunta($nro, $panel, $boton = NULL)
{
  
  $form = array();
    
  $form['panel'] = array(
    '#type' => 'container',
    '#prefix' => '<div id="pregunta-'. $nro .'" class="preguntas col-md-6 col-md-offset-3">',
    '#suffix' => '</div>',
    '#attributes' => array(
      'class' => array('panel panel-default m-t-2'),
     ),
  );
  
  $form['panel'][] = $panel;
  
  $form['boton-siguiente-wrapper'] = $boton;
  
  return $form;
  
}

function panel($titulo, $contenidos = array())
{
  
  $form = array();
  
  $form['panel-body-media-form-group'] = array(
    '#type' => 'container',
    '#prefix' => '<div class="panel-body"><div class="media"><div class="">',
    '#suffix' => '</div></div></div>',
    '#attributes' => array(
      'class' => array('media-body'),
     ),
  );
  
  $form['panel-body-media-form-group']['panel-titulo'] = array(
      '#type' => 'markup',
      '#markup' => '<h3 class="m-b-2">' . $titulo . '</h3>',
  );
  
  foreach ($contenidos as $key => $contenido) {
    $form['panel-body-media-form-group'][$key] = $contenido;
  }
  
  return $form;
}

function encuesta_satisfaccion_submit_ajax($form, &$form_state)
{

  $form_id = $form_state['build_info']['form_id'];
  drupal_validate_form($form_id, $form, $form_state);
  
  if (form_get_errors()) {
    $form_state['rebuild'] = TRUE;
    return $form;
  }
  
  $consulta = new ConsultaEncuestaSatisfaccion(ApiGatewayAuth::getInstance(), $form_state['values']);
  
  $consulta->set_values($form_state['values']);
  
  $form['contenedor'] = array(
    '#type' => 'markup',
    '#markup' => $consulta->consultar()
  );
  
  return $form;
  
}