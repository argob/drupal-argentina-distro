<?php

include_once 'form/argentinagobar_formularios_sugerencias_argentinagobar.form.inc';
include_once 'form/argentinagobar_formularios_consulta_cortes_programados.form.inc';
include_once 'form/consulta_licencia_conducir.form.inc';
include_once 'form/consulta_listado_fronteras.form.inc';
include_once 'form/argentinagobar_formularios_consulta_tad.form.inc';
include_once 'form/argentinagobar_formularios_postulaciones.form.inc';
include_once 'form/argentinagobar_formularios_casadelfuturo.form.inc';
include_once 'form/defensa_consumidor/argentinagobar_consultaDC.form.inc';
include_once 'form/defensa_consumidor/argentinagobar_reclamoDC.form.inc';
include_once 'form/consulta_obsequios_viajes.form.inc';
include_once 'form/consulta_radicacion_dominio.form.inc';
include_once 'form/consulta_radicacion_domicilio.form.inc';
include_once 'form/encuesta_satisfaccion.form.inc';
include_once 'form/consulta_beneficios.form.inc';

function argentinagobar_formularios_block_info()
{
  $blocks = array();

  $blocks['consulta_anses'] = array(
    'info'=>t('Cuando y donde cobro'),
  );

  $blocks['rlm_consulta'] = array(
    'info'=>t('Registro Base de datos'),
  );

  $blocks['rlmtest_consulta'] = array(
    'info'=>t('Validacion RLM'),
  );

  $blocks['apostillaes_consulta'] = array(
    'info'=>t('Apostilla ES'),
  );

  $blocks['apostillaen_consulta'] = array(
    'info'=>t('Apostilla EN'),
  );

  $blocks['apostillafr_consulta'] = array(
    'info'=>t('Apostilla FR'),
  );

  $blocks['convocatorias_consulta'] = array(
    'info'=>t('Convocatorias Cultura'),
  );

  $blocks['consulta_registrosociedades'] = array(
    'info'=>t('Registro Sociedades'),
  );

  $blocks['puertos_consulta'] = array(
    'info'=>t('Puertos'),
  );

  $blocks['infoleg_consulta_simple'] = array(
    'info' => t('Infoleg Consulta Simple'),
  );

  $blocks['infoleg_consulta_avanzada'] = array(
    'info' => t('Infoleg Consulta Avanzada'),
  );

  $blocks['infoleg_consulta_boletin'] = array(
    'info' => t('Infoleg Consulta Boletin'),
  );

  $blocks['postulaciones'] = array(
    'info' => t('Formulario de Postulaciones'),
  );

  $blocks['formulario_defensaconsumidor'] = array(
    'info' => t('Formulario de denuncias de Defensa del Consumidor'),
  );

  // Form de consulta de ID de reclamo tuve que cambiar a dc porque el nombre de las funciones es muy largo para drupal
  $blocks['formulario_consultadc'] = array(
    'info' => t('Formulario de consulta de Defensa del Consumidor'),
  );

  $blocks['casadelfuturo'] = array(
    'info' => t('Cuestionario índice IVS Casa del Futuro'),
  );

  $blocks['consulta_tad'] = array(
    'info' => t('Consulta de Trámites a distancia'),
  );

  $blocks['consulta_cortes_programados'] = array(
    'info' => t('Consulta de Cortes Programados'),
  );

  $blocks['consulta_licencia_conducir'] = array(
    'info' => t('Consulta de Licencia de Conducir'),
  );

  $blocks['consulta_listado_fronteras'] = array(
    'info' => t('Consulta de Pasos Fronterizos'),
  );

  $blocks['sugerencias_argentinagobar'] = array(
    'info' => t('¿Querés sugerirnos algo para mejorar Argentina.gob.ar?'),
  );

  $blocks['consulta_obsequios_viajes'] = array(
    'info' => t('Registro de obsequios y viajes'),
  );

  $blocks['radicacion_dominio'] = array(
    'info' => t('Consultas de Radicación por Dominio'),
  );

  $blocks['consulta_radicacion_domicilio'] = array(
    'info' => t('Consulta de Radicación por Domicilio'),
  );

  $blocks['consulta_registro_renabap'] = array(
    'info' => t('Consulta estoy en RENABAP'),
  );

  $blocks['consulta_registro_renabap'] = array(
    'info' => t('Consulta estoy en RENABAP'),
  );

  $blocks['encuesta_satisfaccion'] = array(
    'info' => t('Encuesta de Atención'),
  );

  $blocks['consulta_beneficios'] = array(
    'info' => t('Consulta de beneficios'),
  );

  $blocks['consulta_constancia_cuil'] = array(
    'info' => t('Consulta de Constancia CUIL'),
  );

  $blocks['consulta_incucai_organos'] = array(
    'info' => t('Consulta si sos donante de órganos en INCUCAI'),
  );

  $blocks['consulta_incucai_medula'] = array(
    'info' => t('Consulta si sos donante de médula en INCUCAI'),
  );

  $blocks['expresar_voluntad'] = array(
    'info' => t('Expresa tu voluntad si sos donante'),
  );

  $blocks['expedientes_consulta'] = array(
    'info' => t('Consulta de Expedientes y PAMI'),
  );

  $blocks['chicos_extraviados_consulta'] = array(
    'info' => t('Consulta Chicos Extraviados'),
  );

  return $blocks;
}

function argentinagobar_formularios_block_configure($delta = '')
{
  $form = array();

  switch ($delta) {

    case 'consulta_tad' :

      $form['consulta_tad_descripcion'] = array(
        '#type' => 'textarea',
        '#title' => t('Descripción'),
        '#description' => t(''),
        '#default_value' => variable_get('consulta_tad_descripcion', ''),
      );

      break;

    case 'sugerencias_argentinagobar':

      $form['sugerencias'] = array(
        '#type' => 'textfield',
        '#title' => t('Título'),
        '#description' => t(''),
        '#default_value' => variable_get('sugerencias', '')
      );

      $form['sugerencias_mail'] = array(
        '#type' => 'textfield',
        '#title' => t('Email destinatario'),
        '#description' => t('Mail que recibe'),
        '#default_value' => variable_get('sugerencias_mail', '')
      );

      break;
  }

  return $form;
}

function argentinagobar_formularios_block_view($delta = '')
{
  $block = array();

  switch($delta) {

    case 'postulaciones' :
      $block['content'] = drupal_get_form('argentinagobar_formularios_postulaciones');
      break;

    case 'formulario_defensaconsumidor' :
      $block['content'] = drupal_get_form('argentinagobar_defensaconsumidor_form');
      break;
    case 'formulario_consultadc' :
      $block['content'] = drupal_get_form('argentinagobar_consultadc_form');
      break;

    case 'casadelfuturo' :

      $block['content'] = drupal_get_form('argentinagobar_formularios_casadelfuturo');
      break;

    case 'consulta_tad' :

      $block['content'] = theme(
        'argentinagobar_formularios_formulario_panel',
        array(
          'descripcion' => variable_get('consulta_tad_descripcion', ''),
          'formulario' => drupal_get_form('argentinagobar_formularios_consulta_tad'),
        )
      );

      break;

    case 'consulta_cortes_programados':

      $block['content'] = drupal_get_form('argentinagobar_formularios_consulta_cortes_programados');
      break;

    case 'consulta_licencia_conducir':

      $block['content'] = drupal_get_form('consulta_licencia_conducir');
      break;

    case 'sugerencias_argentinagobar':

      $block['content'] = drupal_get_form('argentinagobar_formularios_sugerencias_argentinagobar');
      break;

    case 'consulta_obsequios_viajes':

      $block['content'] = drupal_get_form('consulta_obsequios_viajes');
      break;

    case 'radicacion_dominio':

      $block['content'] = drupal_get_form('consulta_radicacion_dominio');
      break;

    case 'consulta_radicacion_domicilio':

      $block['content'] = drupal_get_form('consulta_radicacion_domicilio');
      break;

    case 'consulta_listado_fronteras':

      $block['content'] = drupal_get_form('consulta_listado_fronteras');
      break;

    case 'infoleg_consulta_simple':

      $block['content'] = drupal_get_form('argobar_consulta_infoleg_consulta_simple', InfolegFactory::crearConsulta(ApiGatewayAuth::getInstance(), $delta));
      break;

    case 'infoleg_consulta_avanzada':

      $block['content'] = drupal_get_form('argobar_consulta_infoleg_consulta_avanzada', InfolegFactory::crearConsulta(ApiGatewayAuth::getInstance(), $delta));
      break;

    case 'infoleg_consulta_boletin':

      $block['content'] = drupal_get_form('argobar_consulta_infoleg_consulta_boletin', InfolegFactory::crearConsulta(ApiGatewayAuth::getInstance(), $delta));
      break;

    case 'consulta_beneficios':
      $block['content'] = drupal_get_form('consulta_beneficios');
      break;

    case 'consulta_constancia_cuil':
      $consulta = new ConsultaConstanciaCuil(ApiGatewayAuth::getInstance());
      $block['content'] = drupal_get_form('argobar_consulta_constancia_cuil', $consulta);
      break;

    case 'consulta_registro_renabap':

      $consulta = new ConsultaRegistroRenabap(ApiGatewayAuth::getInstance());
      $consulta->add_response_theme(1, new ConsultaRegistroRenabapResponse1());
      $consulta->add_response_theme(2, new ConsultaRegistroRenabapResponse2());
      $consulta->add_response_theme(3, new ConsultaRegistroRenabapResponse3());

      $block['content'] = drupal_get_form('argobar_consulta_registro_renabap', $consulta);

      break;

    case 'encuesta_satisfaccion':

      $block['content'] = drupal_get_form('encuesta_satisfaccion');

      break;

    case 'consulta_incucai_organos':

      $consulta = new ConsultaIncucaiOrganos(ApiGatewayAuth::getInstance());

      $block['content'] = drupal_get_form('argobar_consulta_incucai_organos', $consulta);
      break;

    case 'consulta_incucai_medula':

      $consulta = new ConsultaIncucaiMedula(ApiGatewayAuth::getInstance());

      $block['content'] = drupal_get_form('argobar_consulta_incucai_medula', $consulta);

    break;

    case 'expresar_voluntad':

      $consulta = new ExpresarVoluntad(ApiGatewayAuth::getInstance());

      $block['content'] = drupal_get_form('argobar_consulta_expresar_voluntad', $consulta);
    break;

    case 'consulta_anses':

      $consulta = new ConsultaAnses(ApiGatewayAuth::getInstance());

      $block['content'] = drupal_get_form('argobar_consulta_anses', $consulta);
    break;

    case 'consulta_registrosociedades':

      $consulta = new ConsultaRegistroSociedades(ApiGatewayAuth::getInstance());

      $block['content'] = drupal_get_form('argobar_consulta_registrosociedades', $consulta);
    break;

    case 'apostillaes_consulta':

      if(drupal_get_path_alias() != variable_get('apostilla_alias')) {

        variable_set('apostilla_alias', drupal_get_path_alias());
        menu_rebuild();

      }

        $consulta = new ConsultaApostillaEs(ApiGatewayAuth::getInstance());
        $block['content'] = drupal_get_form('argobar_consulta_apostillaes_consulta', $consulta);
    break;

    case 'apostillaen_consulta':

      if(drupal_get_path_alias() != variable_get('apostilla_alias')) {

        variable_set('apostilla_alias', drupal_get_path_alias());
        menu_rebuild();

      }

        $consulta = new ConsultaApostillaEn(ApiGatewayAuth::getInstance());
        $block['content'] = drupal_get_form('argobar_consulta_apostillaen_consulta', $consulta);
    break;

    case 'apostillafr_consulta':

      if(drupal_get_path_alias() != variable_get('apostilla_alias')) {

        variable_set('apostilla_alias', drupal_get_path_alias());
        menu_rebuild();

      }

        $consulta = new ConsultaApostillaFr(ApiGatewayAuth::getInstance());
        $block['content'] = drupal_get_form('argobar_consulta_apostillafr_consulta', $consulta);
    break;

    case 'rlmtest_consulta':

      if(drupal_get_path_alias() != variable_get('rlmtest_alias')) {
        variable_set('rlmtest_alias', drupal_get_path_alias());
        menu_rebuild();
      }

      $consulta = new ConsultaRLMTestListado(ApiGatewayAuth::getInstance());
      $block['content'] = drupal_get_form('argobar_consulta_rlmtest_consulta', $consulta);

      break;

    case 'convocatorias_consulta':

      if(drupal_get_path_alias() != variable_get('convocatorias_alias')) {

        variable_set('convocatorias_alias', drupal_get_path_alias());
        menu_rebuild();
      }

      $consulta = new ConsultaConvocatorias(ApiGatewayAuth::getInstance());
      $response = $consulta->consultar();
      $block['content'] = $response;
      break;

    case 'puertos_consulta':

        $consulta = new ConsultaPuertos(ApiGatewayAuth::getInstance());
        /*$block['content'] = drupal_get_form('argobar_consulta_convocatorias_consulta', $consulta);*/
        $response = $consulta->consultar();
        $block['content'] = $response;

    break;

    case 'chicos_extraviados_consulta':

        if(drupal_get_path_alias() != variable_get('chicos_extraviados_alias')) {

          variable_set('chicos_extraviados_alias', drupal_get_path_alias());
          menu_rebuild();
        }

        $consulta = new ConsultaChicosExtraviados(ApiGatewayAuth::getInstance());
        $response = $consulta->consultar();
        $block['content'] = $response;

    break;

    case 'rlm_consulta':

      if(drupal_get_path_alias() != variable_get('rlm_alias')) {

        variable_set('rlm_alias', drupal_get_path_alias());
        menu_rebuild();

      }

      $consulta = new ConsultaRLMListado(ApiGatewayAuth::getInstance());

      $block['content'] = drupal_get_form('argobar_consulta_rlm_consulta', $consulta);
      break;

      case 'expedientes_consulta':

          $consulta = new ConsultaExpedientes(ApiGatewayAuth::getInstance());
          $block['content'] = drupal_get_form('argobar_consulta_expedientes_consulta', $consulta);
        break;

  }

  return $block;
}

function argentinagobar_formularios_block_save($delta = '', $edit = array())
{
  switch ($delta) {

    case 'consulta_tad' :

      variable_set('consulta_tad_descripcion', $edit['consulta_tad_descripcion']);
      break;

    case 'sugerencias_argentinagobar' :

      variable_set('sugerencias', $edit['sugerencias']);
      variable_set('sugerencias_mail', $edit['sugerencias_mail']);
      break;
  }
}
