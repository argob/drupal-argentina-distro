<?php

define('INFOLEG_BASE_URL', 'normativa/%/%norma');

/**
 * Implements hook_menu().
 */
function argentinagobar_formularios_menu()
{
  $items = array();

  $items['admin/config/argentinagobar-formularios'] = array(
    'title' => 'Formularios',
    'description' => 'Configuración de los formularios definidos en el módulo.',
    'position' => 'left',
    'weight' => -100,
    'page callback' => 'system_admin_menu_block_page',
    'access arguments' => array('administer site configuration'),
    'file' => 'system.admin.inc',
    'file path' => drupal_get_path('module', 'system'),
  );

  $items['admin/config/argentinagobar-formularios/apigateway'] = array(
    'title' => 'ApiGateway',
    'description' => 'Configuraciónes Generales API.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('apigateway_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/obsequios-viajes'] = array(
    'title' => 'Obsequios y viajes',
    'description' => 'Endpoint de Obsequios y Viajes.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_obsequios_viajes_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/licencia-conducir'] = array(
    'title' => 'Licencia de Conducir',
    'description' => 'Endpoint Licencia de Conducir.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_licencia_conducir_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/consulta-beneficios'] = array(
    'title' => 'Consulta Beneficios',
    'description' => 'Endpoint Beneficios.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_beneficios_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );
  $items['admin/config/argentinagobar-formularios/consulta-constancia-cuil'] = array(
    'title' => 'Consulta Constancia Cuil',
    'description' => 'Endpoint Constancia Cuil.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_constancia_cuil_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/cortes-programados'] = array(
    'title' => 'Cortes programados',
    'description' => 'Configuraciónes, endpoint y token de cortes programados.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_cortes_programados_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['anticorrupcion/obsequiosyviajes/%'] = array(
    'title' => 'Detalle',
    'page callback' => 'obsequios_y_viajes_detalle',
    'page arguments' => array(2),
    'access arguments' => array('access content'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['pasosinternacionales/detalle/%'] = array(
    'title' => 'Detalle',
    'page callback' => 'consulta_listado_fronteras_detalle',
    'page arguments' => array(2,3),
    'access arguments' => array('access content'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/radicacion-dominio'] = array(
    'title' => 'Radicacion por Dominio',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_radicacion_por_dominio_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/radicacion-domicillio'] = array(
    'title' => 'Radicacion por Domicilio',
    'description' => 'Configuraciónes endpoints radicaciion Provincias, Despartamentos, Localidades, Calles-Barrios, Alturas, Seccional.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_radicacion_por_domicilio_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/consulta_registro_renabap'] = array(
    'title' => 'Registro RENABAP',
    'description' => 'Configuraciónes, endpoint barrios-populares/consultar-padron.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_registro_renabap_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/consulta-barrios-populares'] = array(
    'title' => 'Barrios Populares',
    'description' => 'Configuraciónes, endpoint barrios-populares',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_barrios_populares_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/consulta-incucai-organos'] = array(
    'title' => 'Consulta INCUCAI órganos',
    'description' => 'Consulta si sos donante de órganos',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_incucai_organos_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/consulta-incucai-medula'] = array(
    'title' => 'Consulta INCUCAI médula',
    'description' => 'Consulta si sos donante de médula',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_incucai_medula_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/ConsultaINDECProvinciaDepartamentoLocalidadCiudad'] = array(
    'title' => 'Barrios Populares Provincia / Partido / Localidad /',
    'description' => 'Configuraciónes, endpoint: fronteras',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('ConsultaINDECProvinciaDepartamentoLocalidadCiudad_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/DefensaDelConsumidor'] = array( //this creates a URL that will call this form at "examples/form-example"
    'title' => 'Defensa del consumidor', //page title
    'description' => 'Configurar el formulario para cambiar adonde apunta',
    'page callback' => 'drupal_get_form', //this is the function that will be called when the page is accessed.  for a form, use drupal_get_form
    'page arguments' => array('argentinagobar_formularios_configuracionDC'), //put the name of the form here
    //'access callback' => TRUE,
    'access arguments' => array('administer users'),
  );

  $items['admin/reports/DefensaDelConsumidor'] = array(
    'title' => 'Defensa del consumidor', //page title
    'description' => 'Configurar el formulario para cambiar adonde apunta',
    'page callback' => 'drupal_get_form', //this is the function that will be called when the page is accessed.  for a form, use drupal_get_form
    'page arguments' => array('argentinagobar_formularios_logDC'), //put the name of the form here
    //'access callback' => TRUE,
    'access arguments' => array('administer users'),
  );

  $items['admin/config/argentinagobar-formularios/consulta-georef'] = array(
    'title' => 'GeoRef',
    'description' => 'Consultas de Provincias, departamentos, localidades, endpoints',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_georef_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );


  $items['admin/config/argentinagobar-formularios/consulta-pasos-fronteras'] = array(
    'title' => 'Pasos Fronterizos',
    'description' => 'Configuraciónes, endpoint: fronteras',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_listado_fronteras_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );


  $items['admin/config/argentinagobar-formularios/consulta_mscrm_tramites'] = array(
    'title' => 'MS CRM',
    'description' => 'Configuraciónes, endpoint: categorias de tramites y categorias Organismos',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_mscrm_tramites_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/nps'] = array(
    'title' => 'Encuesta de atención',
    'description' => 'Configuraciónes, endpoint: encuesta de atencion',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_encuesta_atencion_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['admin/config/argentinagobar-formularios/infoleg'] = array(
    'title' => 'Infoleg',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('consulta_infoleg_admin'),
    'access arguments' => array('administrar formularios'),
    'type' => MENU_NORMAL_ITEM,
  );

  $items['donar-organos/confirmacion/%'] = array(
    'title' => 'Formulario de expresión de voluntad de donación de órganos y tejidos',
    'page callback' => 'getConfirmacion',
    'page arguments' => array(2),
    'access callback' => true,
    'access arguments' => array('access content'),
    'type' => MENU_CALLBACK,
  );

  $items[INFOLEG_BASE_URL] = array(
    'title' => '%norma',
    'title callback' => 'getNormativaTitulo',
    'title arguments' => array(2),
    'page callback' => 'getNormativa',
    'page arguments' => array(2),
    'access callback' => true,
    'load arguments' => ['%map', '%index'],
    'type' => MENU_CALLBACK,
  );

  $items[INFOLEG_BASE_URL . '/actualizacion'] = array(
    'title' => 'Texto actualizado',
    'page callback' => 'getNormativaTextoActualizado',
    'page arguments' => array(2),
    'access callback' => true,
    'load arguments' => ['%map', '%index'],
    'type' => MENU_CALLBACK,
  );

  $items['normativa/recurso/%/%/%'] = array(
    'title' => 'Normativa',
    'page callback' => 'getRecursoHtm',
    'page arguments' => array(2,3,4),
    'access callback' => true,
    'access arguments' => array('access content'),
    'type' => MENU_CALLBACK,
  );

  $items[INFOLEG_BASE_URL . '/normas-modifican'] = array(
    'title' => 'Normas que la modifican',
    'page callback' => 'getNormasQueModifican',
    'page arguments' => array(2),
    'load arguments' => ['%map', '%index'],
    'access callback' => true,
    'type' => MENU_CALLBACK,
  );

  $items[INFOLEG_BASE_URL . '/normas-modificadas'] = array(
    'title' => 'Normas modificadas',
    'page callback' => 'getNormasModificadas',
    'page arguments' => array(2),
    'load arguments' => ['%map', '%index'],
    'access callback' => true,
    'type' => MENU_CALLBACK,
  );

  $items[INFOLEG_BASE_URL . '/texto'] = array(
    'title' => 'Texto completo',
    'page callback' => 'getNormativaTextoCompleto',
    'page arguments' => array(2),
    'load arguments' => ['%map', '%index'],
    'access callback' => true,
    'type' => MENU_CALLBACK,
  );

  $items['normativa/%/archivo'] = array(
    'title' => 'Archivo infoleg',
    'description' => 'Configuración de los formularios definidos en el módulo.',
    'page callback' => 'getInfolegResource',
    'page arguments' => array(1),
    'access callback' => true,
    'type' => MENU_CALLBACK,
  );

  $items['normativaProv/%/archivo'] = array(
    'title' => 'Archivo infoleg',
    'description' => 'Configuración de los formularios definidos en el módulo.',
    'page callback' => 'getInfolegResourcesProvinciales',
    'page arguments' => array(1),
    'access callback' => true,
    'type' => MENU_CALLBACK,
  );

  // MENU ROUTE VARIABLE PARA RLM
  $alias = variable_get('rlm_alias', null);
  if(!empty($alias)) {

    // ESTO POR SI EL ALIAS SELECCIONADO TIENE MÁS PARÁMETROS
    $menu = $alias . '/%';
    foreach (explode('/', $menu) as $key => $value) {
      if($value == '%'){
        $argument = $key;
      }
    }

    $items[$menu] = [
      'title' => 'Responsable',
      'page callback' => 'getDetalleRLM',
      'page arguments' => array($argument),
      'access callback' => true,
      'type' => MENU_CALLBACK,
    ];
  }

  // URL ROUTE VARIABLE PARA CONVOCATORIAS
  $alias = variable_get('convocatorias_alias', null);
  if(!empty($alias)) {

    // ESTO POR SI EL ALIAS SELECCIONADO TIENE MÁS PARÁMETROS
    $menu = $alias . '/%';
    foreach (explode('/', $menu) as $key => $value) {
      if($value == '%'){
        $argument = $key;
      }
    }

    $items[$menu] = [
      'title' => 'Convocatorias Cultura',
      'page callback' => 'getDetalleConvocatoriasCultura',
      'page arguments' => array($argument),
      'access callback' => true,
      'type' => MENU_CALLBACK,
    ];

  }
    // URL ROUTE VARIABLE PARA CHICOS EXTRAVIADOS
    $alias = variable_get('chicos_extraviados_alias', null);
    if(!empty($alias)) {

    // ESTO POR SI EL ALIAS SELECCIONADO TIENE MÁS PARÁMETROS
    $menu = $alias . '/%';
    foreach (explode('/', $menu) as $key => $value) {
      if($value == '%'){
        $argument = $key;
      }
    }

    //ACCESO DETALLE CHICOS EXTRAVIADOS
    $items[$menu] = [
      'title' => 'Chicos Extraviados',
      'page callback' => 'getDetalleChicosExtraviados',
      'page arguments' => array($argument),
      'access callback' => true,
      'type' => MENU_CALLBACK,
    ];

  }

  return $items;
 }

function jsSort()
{
  return("(function ($) {
    Drupal.behaviors.listjs = {
      attach: function(context) {
        $('#listado-infoleg-lista tbody').addClass('list');
        var listadoInfolegListConfig = {
          valueNames: ['numero', 'fecha', 'descripcion','titulo'],
        }
        var listadoInfolegList = new List('normas', listadoInfolegListConfig)
        listadoInfolegList.sort('numero','descripcion','titulo')
          }
      }
  })(jQuery)");
}

function getInfolegResource($src)
{
  $src = explode('_', $src);

  $consulta = new ConsultaInfolegResources(ApiGatewayAuth::getInstance());
  $consulta->setValues(
    array(
      'id' => check_plain($src[0]),
      'filename' => check_plain($src[1]),
      'extension' => check_plain($src[2]),
    )
  );

  $extension = $consulta->values['extension'];
  $base = '';
  $data = $consulta->consultar();
  switch ($extension){

    case 'jpg':
      $base = 'data:image/jpeg;base64';
      break;

    case 'pdf':
      $base = 'data:application/pdf;base64';
      break;

    case 'png':
      $base = 'data:image/png;base64';
      break;
  }


  if(!empty($data)){

    $file = file_save_data(base64_decode(str_replace($base, '', $data)),'public://infoleg/'.$consulta->values['filename'].'.'.$consulta->values['extension'],FILE_EXISTS_REPLACE);

    $file->status = 0;
    file_save($file);

    drupal_goto(file_create_url($file->uri));

  }else{

    return 'Archivo inexistente';

  }

}

function getInfolegResourcesProvinciales($src){

  $consultaResourcesProv = new ConsultaInfolegResourcesProv(ApiGatewayAuth::getInstance(), $src);
  $dataResourcesProv = $consultaResourcesProv->consultar();

  $jpg = 'data:image/jpeg;base64';
  $pdf = 'data:application/pdf;base64';
  $png = 'data:image/png;base64';
  $htm = '<!doctype html public';

  if (strpos($dataResourcesProv, $jpg) === 0){
    $base = $jpg;
    $extension = 'jpg';
  }elseif(strpos($dataResourcesProv, $png) === 0){
    $base = $png;
    $extension = 'png';
  }elseif(strpos($dataResourcesProv, $pdf) === 0){
    $base = $pdf;
    $extension = 'pdf';
  }elseif(strpos($dataResourcesProv, $htm) === 0){
    $base = $htm;
    $extension = 'htm';
  }else{
    $base = 'No extension';
  }

  if(!empty($dataResourcesProv) &&   $base !== 'No extension' && $base !== 'htm'){

    $file = file_save_data(base64_decode(str_replace($base, '', $dataResourcesProv)),'public://infoleg/'.$src.'.'.$extension,FILE_EXISTS_REPLACE);
    $file->status = 0;
    file_save($file);
    drupal_goto(file_create_url($file->uri));

  }else{

    return 'Archivo inexistente';

  }
}

function infolegProcesarResources($texto, $norma = null)
{
  $matchesProv = array();
  $patternProv = '/%%server_name%%\/api\/v2.0\/provinciales\/normativos\/resources\/(\w+)-(\w+)-(\w+)-(\w+)-(\w+)\s(\w+):(\w+)\.(?im)(jpg|pdf|doc|gif|jpeg|bmp|xls|xslx|htm)/';
  preg_match_all($patternProv, $texto, $matchesProv, PREG_SET_ORDER);

  $matchesNac = array();
  $patternNac = '/%%server_name%%\/api\/v2.0\/nacionales\/normativos\/resources\/([0-9]*)\/(\S*)\.(?im)(jpg|pdf|doc|gif|jpeg|bmp|xls|xslx|htm)/';
  preg_match_all($patternNac, $texto, $matchesNac, PREG_SET_ORDER);

  if ( !empty($matchesNac)){

    foreach ($matchesNac as $match) {

      if ($match[3] == 'htm') {
        // 1 => id  // 2 => filename // 3 => extension
        $texto = str_replace($match[0], '/normativa/' .  'recurso' . '/' . $match[1] . "/" .$match[2] . "/" . $match[3], $texto);
      } else {
        // Cambiamos para que cargue sin problemas la resolución y el link aparte
        $texto = str_replace($match[0], '../../../normativa/'.$match[1].'_'.$match[2].'_'.$match[3].'/archivo', $texto);

      }

    }

  }else{

    foreach ($matchesProv as $match){
      #ID de la Ley
      $id = substr(mb_substr($match[7], 0, -2), 3);
      $nameFile = str_replace(' ', '%20', substr($match[0], 59));

      if ($match[8] == 'HTM') {
        $texto = str_replace($match[0], '/normativa/' .  'recurso' . '/' . $match[5] . '/' . $match[7] . "/" . $match[8], $texto);
      }else{
        $texto = str_replace($match[0], '../../../normativaProv/'.$nameFile.'/archivo', $texto);
      }

    }

  }

    return $texto;
}


function infolegProcesarLinks($texto)
{
  $matches = array();
  $pattern = '/%%server_name%%\/api\/v2.0\/nacionales\/normativos\?id=([0-9]*)/';
  preg_match_all($pattern, $texto, $matches, PREG_SET_ORDER);

  foreach ($matches as $match) {

    $norma = getNormativaPorID($match[1]);
    $año = $norma['tipoNorma'] == "Ley" ? "" : "-". mb_substr($norma['sancion'], 0 , 4);
    $texto = str_replace ($match[0], '/normativa/nacional/' . strtolower(str_replace(" ","_", $norma['tipoNorma'])).'-' . $norma['idNormas'][0]['numero'] .  $año . '-' . $match[1] , $texto);  }

  return $texto;
}

function getNormativaPorID($id, $jurisdiccion = 'nacional')
{
  $cid = 'infoleg_norma_' . $id;
  $cache = cache_get($cid);

  if (isset($cache->data)) {

    $norma = $cache->data;

  } else {

    switch ($jurisdiccion) {

      case 'nacional':

        $consulta = new ConsultaInfolegNorma(ApiGatewayAuth::getInstance(), array('id' => $id));

        break;

      case 'provincial':

        $consulta = new ConsultaInfolegNormaProvincial(ApiGatewayAuth::getInstance(), array('id' =>$id));

        break;

    }

    $norma = $consulta->consultar();

    ConsultaInfoleg::crearNorma($norma);

    cache_set($cid, $norma);
  }

  return $norma;
}

function norma_load($normaID, $args, $index)
{

  $norma = false;

  if($args[1] == 'nacional' || $args[1] == 'provincial') {

    $norma = getNormativaPorID(ConsultaInfoleg::extraerID($normaID), $args[1]);

  }

  return $norma;
}

function getNormativaTitulo($norma)
{
  return $norma['breadcrumb']['titulo'];
}

function getNormativaTextoActualizado($norma)
{

  $output = MENU_NOT_FOUND;
  $normativaURL = drupal_lookup_path('source', 'normativa', $path_language = NULL);

  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Normativa', $normativaURL);
  $breadcrumb[] = l($norma['breadcrumb']['titulo'], $norma['breadcrumb']['url']);

  drupal_add_js(jsSort(),'inline');
  drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/list.js/1.5.0/list.min.js','external');


  if (!empty($norma)) {

    $texto = infolegProcesarLinks($norma['textoNormaAct']);
    $texto = infolegProcesarResources($texto, $norma);

    $output = theme(
      'infoleg_detalle_norma',
      array(
        'norma' => $norma,
        'texto' => $texto,
        'breadcrumb' => theme('breadcrumb', array('breadcrumb' => $breadcrumb)),
      )
    );
  }

  return $output;
}

function getNormasQueModifican($norma)
{
  return normasComplementarias($norma, 'listaNormasQueLaComplementanCompleta');
}

function getNormasModificadas($norma)
{
  return normasComplementarias($norma, 'listaNormasQueComplementaCompleta');
}

function normasComplementarias($norma, $lista) {

  $output = MENU_NOT_FOUND;
  $normativaURL = drupal_lookup_path('source', 'normativa', $path_language = NULL);

  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Normativa', $normativaURL);
  $breadcrumb[] = l($norma['breadcrumb']['titulo'], $norma['breadcrumb']['url']);

  drupal_add_js(jsSort(),'inline');
  drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/list.js/1.5.0/list.min.js','external');

  $codigosProvincias = array('A' => 'SALTA','B' => 'BUENOS AIRES','D' => 'SAN LUIS','E' => 'ENTRE RIOS','F' => 'LA RIOJA','G' => 'SANTIAGO DEL ESTERO','H' => 'CHACO','J' => 'SAN JUAN','K' => 'CATAMARCA','L' => 'LA PAMPA','M' => 'MENDOZA','N' => 'MISIONES','O' => 'CORDOBA','P' => 'FORMOSA','Q' => 'NEUQUEN','R' => 'RIO NEGRO'	,'S' => 'SANTA FE','T' => 'TUCUMAN','U' => 'CHUBUT','V' => 'TIERRA DEL FUEGO','W' => 'CORRIENTES','X' => 'CIUDAD DE BUENOS AIRES','Y' => 'JUJUY','Z' => 'SANTA CRUZ');

  if (!empty($norma)) {

    $normasComplementariasNac = [];
    $normasComplementarias = [];
    $normasComplementariasSinID = [];
    $refNormas = [];

    foreach ($norma[$lista] as $idNormaComplementaria) {

      #caso Normas Nacionales
      if(es_multiArray($idNormaComplementaria) == false){
        $normasComplementariasNac[$idNormaComplementaria] = getNormativaPorID($idNormaComplementaria, $norma['jurisdiccion']);
      }else{


        for ($i=0; $i<count($idNormaComplementaria); $i++){

          $normasComplementarias_array = array();

          #caso uuid Normas Provinciales
          if(strlen($idNormaComplementaria[$i]['uuid']) != 0){

              $normasComplementarias_array = getNormativaPorID($idNormaComplementaria[$i]['uuid'], $norma['jurisdiccion']);
              $normasComplementarias_array['agrupacion'] = $idNormaComplementaria[$i]['id'];
              $normasComplementarias[] = $normasComplementarias_array;
              unset($normasComplementarias_array);

            #caso urlAPI Normas Provinciales - consulta por URL a Normas Nacionales
            }elseif (strlen($idNormaComplementaria[$i]['urlApi']) != 0) {


              $numNormaNac = substr($idNormaComplementaria[$i]['urlApi'], strpos($idNormaComplementaria[$i]['urlApi'], '=')+1);
              $tipoNorma = explode('/', strtok($idNormaComplementaria[$i]['urlApi'], '?'));
              $tipoNorma= $tipoNorma[6];

              $consulta = new ConsultaInfolegNorma(ApiGatewayAuth::getInstance());
              $requestNorma = $consulta->get_request_id($numNormaNac, $tipoNorma);
              $dataNorma = drupal_json_decode($requestNorma->data);
              $idNormaNac = $dataNorma['results'][0]['id'];

              $normasComplementarias_array =  getNormativaPorID($idNormaNac, 'nacional');
              $normasComplementarias_array['agrupacion'] = $idNormaComplementaria[$i]['id'];
              $normasComplementarias[] = $normasComplementarias_array;
              unset($normasComplementarias_array);

            #casoNormas Provinciales sin urlApi, ni uuid
            }elseif(strlen($idNormaComplementaria[$i]['urlApi']) == 0 && strlen($idNormaComplementaria[$i]['uuid']) == 0 && !is_null($idNormaComplementaria[$i]['ref'])){

              $refNormas[] = explode(' ', $idNormaComplementaria[$i]['ref']);

              $consulta = new ConsultaInfolegTipoNormaProvincial(ApiGatewayAuth::getInstance());
              $consulta = $consulta->consultar();

              if(isset($consulta)){

                foreach ($refNormas as $value){

                   $normaComplementariaSinID = [];
                   $normaComplementariaSinID['titulo'] = $consulta[array_search($value[0], array_column($consulta, 'route'))]['detalle'].' '.intval($value[2]);
                   $normaComplementariaSinID['fecha'] = $value[3].'-'.$value[4].'-'.$value[5];
                   $normaComplementariaSinID['descripcion'] = $consulta[array_search($value[0], array_column($consulta, 'route'))]['detalle'];
                   $normaComplementariaSinID['descripcion'] = $value[1] == 'C' ? $consulta[array_search($value[0], array_column($consulta, 'route'))]['detalle'].' Nacional': $consulta[array_search($value[0], array_column($consulta, 'route'))]['detalle'].' Provincial';

                   foreach ($codigosProvincias as $key => $valueB) {

                     if($value[1] == $key){
                       $normaComplementariaSinID['provincia'] = ucwords(strtolower($valueB));
                       $normaComplementariaSinID['provincia'] = $normaComplementariaSinID['provincia'] == 'Cuidad de Buenos Aires' ? 'Cuidad de Buenos Aires' : 'Provincia de '.$normaComplementariaSinID['provincia'];
                     }

                   }
                   $normaComplementariaSinID['agrupacion'] = $idNormaComplementaria[$i]['id'];
                   $normasComplementariasSinID[] = $normaComplementariaSinID;
                }
              }
            }
          }



      }

    }

    $normasComplementariasSinID = groupArray(array_unique($normasComplementariasSinID, SORT_REGULAR), 'agrupacion');
    $normasComplementarias = groupArray(unique_multi_array($normasComplementarias, 'id'), 'agrupacion');

    if(isset($normasComplementariasSinID) || isset($normasComplementarias) ){
      $output = theme(
        'infoleg_normas_complementarias',
        array(
          'norma' => $norma,
          'normasComplementarias' => $normasComplementarias,
          'normasComplementariasSinID' => $normasComplementariasSinID,
          'textoDescriptivo' => 'Normas modificadas y/o complementadas por',
          'breadcrumb' => theme('breadcrumb', array('breadcrumb' => $breadcrumb)),
        )
      );
    }

    if(count($normasComplementariasNac)>0){
      $output = theme(
        'infoleg_normas_complementarias',
        array(
          'norma' => $norma,
          'normasComplementariasNac' => $normasComplementariasNac,
          'textoDescriptivo' => 'Normas modificadas y/o complementadas por',
          'breadcrumb' => theme('breadcrumb', array('breadcrumb' => $breadcrumb)),
        )
      );
    }

  }

  return $output;

}

/*
Ordena el array de acuerdo a la key que se le pase
*/
function groupArray($array,$groupkey)
{
	if (count($array)>0)
	{
		$keys = array_keys($array[0]);
		$removekey = array_search($groupkey, $keys);

		if ($removekey===false)
			return array("Clave \"$groupkey\" no existe");
		else
			unset($keys[$removekey]);

		$groupcriteria = array();
		$return=array();

		foreach($array as $value)
		{

      $item=null;
			$item=array();
  			foreach ($keys as $key)
  			{
          if(isset($value[$key])){
  				 $item[$key] = $value[$key];
          }
  			}

			$busca = array_search($value[$groupkey], $groupcriteria);
			if ($busca === false)
			{
				$groupcriteria[]=$value[$groupkey];
				$return[]=array($groupkey=>$value[$groupkey],'groupeddata'=>array());
				$busca=count($return)-1;
			}
			$return[$busca]['groupeddata'][]=$item;
		}
		return $return;
	}
	else
		return array();
}


/*
Convierte un multiArry en un Array
*/
function unique_multi_array($array, $key) {
  $temp_array = array();
  $i = 0;
  $key_array = array();

  foreach($array as $val) {
    if(count($val)>1){
      if (!in_array($val[$key], $key_array)) {
          $key_array[$i] = $val[$key];
          $temp_array[$i] = $val;
      }
      $i++;
    }
  }

  return $temp_array;
}

/*
Define si un array es multiarray
*/
function es_multiArray($myarray){
  if(count($myarray) !== count($myarray, COUNT_RECURSIVE)){
    return true;
  }else{
    return false;
  }
}

function getRecursoHtm($id, $filename, $extension)
{
  $consulta = new ConsultaInfolegResources(ApiGatewayAuth::getInstance());

  $consulta->setValues(
    array(
      'id' => $id,
      'filename' => $filename,
      'extension' => $extension,
    )
  );

  $texto = $consulta->consultar();
  $texto = infolegProcesarLinks($texto);
  $texto = infolegProcesarResources($texto);

  return $texto;
}

function getNormativaTextoCompleto($norma)
{
  $output = MENU_NOT_FOUND;
  $normativaURL = drupal_lookup_path('source', 'normativa', $path_language = NULL);
  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Normativa', $normativaURL);
  $breadcrumb[] = l($norma['breadcrumb']['titulo'], $norma['breadcrumb']['url']);

  if (!empty($norma)) {

    $texto = infolegProcesarLinks($norma['textoNorma']);
    $texto = infolegProcesarResources($texto);

    $output = theme(
      'infoleg_detalle_norma',
      array(
        'norma' => $norma,
        'texto' => $texto,
        'breadcrumb' => theme('breadcrumb', array('breadcrumb' => $breadcrumb)),
      )
    );
  }

  return $output;
}

function getNormativa($norma)
{
  $output = MENU_NOT_FOUND;
  $normativaURL = drupal_lookup_path('source', 'normativa', $path_language = NULL);

  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Normativa', $normativaURL);

  if (!empty($norma)) {

    # Si la ley es Normativa Nacional Cero no la cuenta en las normas que complementa
    $termToSearch = 'CON C 000000';
    $matches = array_filter($norma['listaNormasQueComplementaCount'], function($var) use ($termToSearch) { return stristr($var, $termToSearch); });
    if($matches) {
        unset($norma['listaNormasQueComplementaCount'][0]);
    }

    $output = theme(
      'infoleg_resumen',
      array(
        'norma' => $norma,
        'cantidadNormasComplementa' => count($norma['listaNormasQueComplementaCount']),
        'cantidadNormasQueLaComplementan' => count($norma['listaNormasQueLaComplementanCount']),
        'breadcrumb' => theme('breadcrumb', array('breadcrumb' => $breadcrumb)),
      )
    );
  }

  return $output;
}

function argentinagobar_formularios_logDC($form, &$form_state) {
  $informe = variable_get('logDC');

  $opciones[0] = '---';
  foreach($informe as $key => $value){
    $opciones[$key] = date('Y-m-d h:i:s', $key);
  }
  $form['fecha'] = array(
    '#type' => 'select',
    '#title' => 'Fecha',
    '#options' => $opciones,
    '#ajax' => array(
      'callback' => 'argentinagobar_formularios_logDC_submit_fecha',
      'wrapper' => 'log-date',
      'method' => 'replace',
      'effect' => 'fade',
    )
  );

  $form['display'] = array(
    '#prefix' => '<div id="log-date">',
    '#suffix' => '</div>',
  );

  return $form;

}

function argentinagobar_formularios_logDC_submit_fecha($form, &$form_state) {

  $informe = variable_get('logDC');

  $form_state['rebuild'] = true;

  return $form['display'] = array(
    '#title' => 'Log',
    '#prefix' => '<div id="log-date">',
    '#suffix' => '</div>',
    '#markup' => '<pre>'.print_r($informe[$form_state['values']['fecha']], true).'</pre>'
  );

}

function obsequios_y_viajes_detalle($id) {

  $data = cache_get('obsequio_' . $id);

  if(!$data) {

    drupal_not_found();

  }

  $element = $data->data['elemento'];
  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Oficina Anticorrupción', 'node/1551');
  $breadcrumb[] = l('Registro de obsequios y viajes', 'node/8739');

  $hook = isset($element['medio_transporte']) ? 'consulta_viajes_detalle' : 'consulta_obsequios_detalle';

  return theme($hook, [
    'titulo' => t('Detalle'),
    'breadcrumb' => theme('breadcrumb', array('breadcrumb' => $breadcrumb)),
    'element' => $element
  ]);

}

/**
 ** @param $id
 ** devuelve el detalle del paso fronterizo
 **/

function convertOrigin($origen)
{
  switch ($origen) {
    case 'ruta':
      $origen = '0';
      break;
    case 'rio':
      $origen = '1';
      break;
  }
  return $origen;
}

function obtener_detalle_paso_fronterizo($origen, $id)
{
  $frontera = null;

  $pasosFronterizos = variable_get('pasos_fronterizos',array());
  foreach ($pasosFronterizos as $data){
    if($id == $data['id'] && convertOrigin($origen) == $data['origen'] ){
      $frontera = $data;
    }
  }

  if($frontera){
    return $frontera;
  }
  else{
    throw new PasoFronterizoException("#obtener_detalle_paso_fronterizo - No se encuentra id: ".$id." dentro de los pasos fronterizos");
  }
}

/**
 ** @param $id
 ** devuelve el detalle la frontera
 **/
function obtener_detalle_frontera($id, $origen){

  $detalleFrontera = new ConsultaPasosDetalle(ApiGatewayAuth::getInstance());
  $detalleFrontera->setValues(array('id' => $id, 'origen'  => $origen));
  $detalleFrontera = $detalleFrontera->consultar();

  return $detalleFrontera;
}

function setear_origen_paso_fronterizo($origenPaso){

  switch ($origenPaso) {
    case 'ruta':
      $origen = 'gna';
      break;
    case 'rio':
      $origen = 'pna';
      break;
    default:
      $origen = null;
      break;
  }

  if($origen){
    return $origen;
  }
  else{
    throw new PasoFronterizoException("#setear_origen_paso_fronterizo - No se encuentra el origen: ".$origenPaso);
  }
}

function ultimaActualizacion($horaApi){

  $fechaActualizada = null;

  $fecha_ultima_actualizacion = str_replace("T", " ", $horaApi);
  $fecha_actual = date('Y-m-d H:i:s');

  $fecha_ultima_actualizacion = new DateTime($fecha_ultima_actualizacion);
  $fecha_actual = new DateTime($fecha_actual);

  $fecha = $fecha_actual->diff($fecha_ultima_actualizacion);

  $anios    = ($fecha->y != 0) ? ($fecha->y == 1) ? $fecha->y . " año "      : $fecha->y . " años "    : "";
  $meses    = ($fecha->m != 0) ? ($fecha->m == 1) ? $fecha->m . " mes "      : $fecha->m . " meses "   : "";
  $dias     = ($fecha->d != 0) ? ($fecha->d == 1) ? $fecha->d . " día "      : $fecha->d . " días "    : "";
  $horas    = ($fecha->h != 0) ? ($fecha->h == 1) ? $fecha->h . " hora "     : $fecha->h . " horas "   : "";
  $minutos  = ($fecha->i != 0) ? ($fecha->i == 1) ? $fecha->i . " minuto "   : $fecha->i . " minutos " : "";
  $segundos = ($fecha->s != 0) ? ($fecha->s == 1) ? $fecha->s . " segundo"   : $fecha->s . " segundos" : "";

  $fechaActualizada = $anios.$meses.$dias.$horas.$minutos.$segundos.'.';

  if($fechaActualizada !== null){
    return $fechaActualizada;
  }
  else{
    throw new PasoFronterizoException("#ultimaActualizacion - No se encuentra el la hora de origen");
  }
}


function consulta_listado_fronteras_detalle($origen, $id){
  global $base_url;

  $frontera         = obtener_detalle_paso_fronterizo($origen, $id);
  $origenPaso       = setear_origen_paso_fronterizo($origen);
  $detalleFrontera  = obtener_detalle_frontera($frontera['id'], $origenPaso);
  $informacion = array();

  if($origenPaso == 'gna'){
    $informacion['temperatura'] = $detalleFrontera['clima']['temperatura'];
    $informacion['sensacion']   = $detalleFrontera['clima']['sensacion'];
    $informacion['nubosidad']   = $detalleFrontera['clima']['nubosidad'];
    $informacion['viento']      = $detalleFrontera['clima']['viento'];
    $informacion['visibilidad'] = $detalleFrontera['clima']['visibilidad'];
  }
  elseif($origenPaso == 'pna'){
    $informacion['altura']      = $detalleFrontera['altura_rio'];
    $informacion['alerta']      = $detalleFrontera['etapa_alerta'];
    $informacion['evacuacion']  = $detalleFrontera['etapa_evacuacion'];
    $informacion['medios']      = $detalleFrontera['medios'];
  }

  $detalleFronterizo = array(
    'estado' => $frontera['estado']['estado'],
    'actualizacion' => ultimaActualizacion($frontera['estado']['ultima_actualizacion']),
    'origen' => $origenPaso == 'gna' ? 'Ruta' : 'Rio',
    'nombre' => $frontera['nombre'],
    'titulo' => $detalleFrontera['descripcion_general'],
    'subtitulo' => $frontera['pais']['nombre'].' / '.$frontera['provincia']['nombre'],
    'horarios' => $detalleFrontera['horario_atencion'],
    'contacto' => $detalleFrontera['contacto'],
    'informacion' => $informacion,
    'clase_estado' => $frontera['estado']['estado'] == "Abierto" ? "label label-success m-r-2" : "label label-danger m-r-2",


    'mapa' => array(
      'latitud'   => $frontera["latitud"],
      'longitud'  => $frontera["longitud"],
    ),
  );

  $keyMap = 'AIzaSyAnjrx-mfaup3A-TQS4DyL0ngfxEqDDBqc';

  drupal_add_js('https://ajax.googleapis.com/ajax/libs/jquery/2.2.4/jquery.min.js');
  drupal_add_js('var myLatLng = {lat: '.$detalleFronterizo['mapa']['latitud'].' , lng: '.$detalleFronterizo['mapa']['longitud'].'};', 'inline');
  drupal_add_js(drupal_get_path('module','drupar_mapa'). '/js/mapa.js');

  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Listado Pasos Fronterizos', 'node/45453');

  return theme('consulta_listado_fronteras_detalle',array(
    'titulo' => t('Detalle listado fronteras'),
    'detalleFronterizo' => $detalleFronterizo,
    'breadcrumb' => theme('breadcrumb', array('breadcrumb' => $breadcrumb)),
    'keyMap' => $keyMap,
    'url_doc' => url_doc($frontera['pais']['nombre']),
  ));
}

function url_doc($pais)
{
  global $base_url;

  return $base_url . '/aplicaciones/fronteras/recomendaciones/' . strtolower($pais);
}

function getConfirmacion($data)
{
  $breadcrumb = drupal_get_breadcrumb();
  $breadcrumb[] = l('Ministerio de Salud', 'node/9063');
  $breadcrumb[] = l('Sumá tu voluntad de donar organos', 'node/56894');

  $uri = 'public://';
  $path= file_create_url($uri);
  $logo = $path . 'incucai_logo.png';

  $parametros = decode_parameters($data);

  $consulta = new ConsultaIncucaiConfirmacion(ApiGatewayAuth::getInstance(), $parametros);

  $confirmacion_response = $consulta->consultar();

  if(empty($confirmacion_response)){
    $theme = 'confirmacion_incucai_error';
  }else {
    $theme = 'confirmacion_incucai';
  }

  $confirmacion_response['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => $breadcrumb));
  $confirmacion_response['logo'] = $logo;

  return theme($theme, $confirmacion_response);
}

function getBreadcrumbRLM()
{
  $alias = variable_get('rlm_alias');

  $nid = substr(drupal_lookup_path('source', $alias), 5);

  $padre = node_load((int)$nid);

  $breadcrumb = ARCrearBreadcrumb($padre);

  $breadcrumb[] = l($padre->title, $alias);

  return $breadcrumb;
}

function getDetalleRlM($id)
{
  drupal_add_css(drupal_get_path('module', 'ar_compre_social') . '/css/compreSocialProducto.css');

  $consultaRLM = array();
  $id = explode('--', $id);
  $id = $id[0];

  //  2
  $rlmListado = new ConsultaRLMListado(ApiGatewayAuth::getInstance());
  $requestListado = $rlmListado->get_request_id($id);
  $rlmListadoData = $rlmListado->get_response($requestListado, true);

  if(isset($rlmListadoData['results'])){
    if($rlmListadoData['results'][0]['valoresFC']['cmb_resp_publico_privado'] == 'Privado'){
      //  4
      $consultaPrivada = new ConsultaRLMPrivada(ApiGatewayAuth::getInstance(), array('filter' => $id));
      $consultaRLM = $consultaPrivada->consultar();
    }
    else if ($rlmListadoData['results'][0]['valoresFC']['cmb_resp_publico_privado'] == 'Público'){
      //  3
      $consultaPublica = new ConsultaRLMPublica(ApiGatewayAuth::getInstance(), array('filter' => $id));
      $consultaRLM = $consultaPublica->consultar();
    }
  }

  $path = explode('/', drupal_get_path_alias());
  array_pop($path);

  return $consultaRLM == array() ? theme('rlm_servicio_caido', array('nuevo_path'=> implode('/', $path))) : $consultaRLM;

}

function getBreadcrumbConvocatoriasCultura()
{
  $alias = variable_get('convocatorias_alias');

  $nid = substr(drupal_lookup_path('source', $alias), 5);

  $padre = node_load((int)$nid);

  $breadcrumb = ARCrearBreadcrumb($padre);

  $breadcrumb[] = l($padre->title, $alias);

  return $breadcrumb;
}

function getDetalleConvocatoriasCultura($id)
{
  $items = cache_get('cacheCultura');
  return theme('detalle_convocatorias',[
    'items' => $items,
    'breadcrumb' => getBreadcrumbConvocatoriasCultura(),
  ]);
}

//Chicos Extraviados breadcrumb y detalle
function getBreadcrumbChicosExtraviados()
{
  $alias = variable_get('chicos_extraviados_alias');

  $nid = substr(drupal_lookup_path('source', $alias), 5);

  $padre = node_load((int)$nid);

  $breadcrumb = ARCrearBreadcrumb($padre);

  $breadcrumb[] = l($padre->title, $alias);

  return $breadcrumb;
}

function getDetalleChicosExtraviados($id)
{
  $consultaDetalle = new ConsultaChicosExtraviadosDetalle(ApiGatewayAuth::getInstance());
  $idDetalle = $consultaDetalle->get_request_id($id);
  $dataDetalle = $consultaDetalle->get_response($idDetalle, true);

  $theme = count($dataDetalle) >= 1  ? 'chicos_extraviados_detalle' : 'chicos_extraviados_error' ;

  return theme($theme,[
    'items' => $dataDetalle,
    'breadcrumb' => getBreadcrumbChicosExtraviados(),
  ]);
}
