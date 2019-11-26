<?php
/**
 * Implements hook_admin().
 */
function consulta_licencia_conducir_admin() {

  $form = array();

  $form['consulta_legalidad_licencia_conducir'] = array(
    '#type' => 'fieldset',
    '#title' => t('Consulta legalidad de licencia de conducir'),
  );

  $form['consulta_legalidad_licencia_conducir']['consulta_licencia_conducir_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint'),
    '#default_value' => variable_get('consulta_licencia_conducir_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Implements hook_admin().
 */

 function consulta_beneficios_admin(){

   $form = array();

   $form['consulta_beneficios'] = array(
     '#type' => 'fieldset',
     '#title' => t('Consulta Beneficios'),
   );

   $form['consulta_beneficios']['consulta_beneficios_client_endpoint'] = array(
     '#type' => 'textfield',
     '#title' => t('Client endpoint Beneficios'),
     '#default_value' => variable_get('consulta_beneficios_client_endpoint',''),
     '#size' => 60,
     '#maxlength' => 255,
     '#description' => "",
     '#required' => TRUE,
   );

   return system_settings_form($form);
 }

 function consulta_incucai_organos_admin(){

   $form = array();

   $form['consulta_incucai_organos'] = array(
     '#type' => 'fieldset',
     '#title' => t('INCUCAI consulta donante organos'),
   );

   $form['consulta_incucai_organos']['consulta_incucai_organos_endpoint'] = array(
     '#type' => 'textfield',
     '#title' => t('Client endpoint INCUCAI órganos'),
     '#default_value' => variable_get('consulta_incucai_organos_endpoint',''),
     '#size' => 60,
     '#maxlength' => 255,
     '#description' => "",
     '#required' => TRUE,
   );

   return system_settings_form($form);
 }

 function consulta_incucai_medula_admin(){

   $form = array();

   $form['consulta_incucai_medula'] = array(
     '#type' => 'fieldset',
     '#title' => t('INCUCAI consulta donante medula'),
   );

   $form['consulta_incucai_medula']['consulta_incucai_medula_endpoint'] = array(
     '#type' => 'textfield',
     '#title' => t('Client endpoint INCUCAI médula'),
     '#default_value' => variable_get('consulta_incucai_medula_endpoint',''),
     '#size' => 60,
     '#maxlength' => 255,
     '#description' => "",
     '#required' => TRUE,
   );

   return system_settings_form($form);
 }

 function consulta_constancia_cuil_admin(){

   $form = array();

   $form['consulta_constancia_cuil'] = array(
     '#type' => 'fieldset',
     '#title' => t('Consulta Constancia Cuil'),
   );

   $form['consulta_constancia_cuil']['consulta_constancia_cuil_client_endpoint'] = array(
     '#type' => 'textfield',
     '#title' => t('Client endpoint Beneficios'),
     '#default_value' => variable_get('consulta_constancia_cuil_client_endpoint',''),
     '#size' => 60,
     '#maxlength' => 255,
     '#description' => "",
     '#required' => TRUE,
   );

   return system_settings_form($form);
 }

function consulta_obsequios_viajes_admin() {

  $form = array();

  $form['consulta_obsequios_viajes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Obsequios y Viajes'),
  );

  $form['consulta_obsequios_viajes']['consulta_obsequios_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Obsequios'),
    '#default_value' => variable_get('consulta_obsequios_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  $form['consulta_obsequios_viajes']['consulta_viajes_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Viajes'),
    '#default_value' => variable_get('consulta_viajes_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,

  );

  return system_settings_form($form);
}

function apigateway_admin(){

  $form['apigateway'] = array(
    '#type' => 'fieldset',
    '#title' => t('Consulta legalidad de licencia de conducir'),
  );

  $form['apigateway']['apigateway_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('apigateway_username', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['apigateway']['apigateway_password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#default_value' => variable_get('apigateway_password', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['apigateway']['apigateway_grant_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Grant Type'),
    '#default_value' => variable_get('apigateway_grant_type', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['apigateway']['apigateway_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#default_value' => variable_get('apigateway_client_id', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['apigateway']['apigateway_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client secret'),
    '#default_value' => variable_get('apigateway_client_secret', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['apigateway']['apigateway_token_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Token endpoint'),
    '#default_value' => variable_get('apigateway_token_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

function consulta_cortes_programados_admin(){

  $form['consulta_cortes_programados'] = array(
    '#type' => 'fieldset',
    '#title' => t('Consulta Cortes Programados'),
  );

  $form['consulta_cortes_programados']['consulta_cortes_programados_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('consulta_cortes_programados_username', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['consulta_cortes_programados']['consulta_cortes_programados_password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#default_value' => variable_get('consulta_cortes_programados_password', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['consulta_cortes_programados']['consulta_cortes_programados_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#default_value' => variable_get('consulta_cortes_programados_client_id', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['consulta_cortes_programados']['consulta_cortes_programados_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client secret'),
    '#default_value' => variable_get('consulta_cortes_programados_client_secret', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => FALSE,
  );

  $form['consulta_cortes_programados']['consulta_cortes_programados_token_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Token endpoint'),
    '#default_value' => variable_get('consulta_cortes_programados_token_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  $form['consulta_cortes_programados']['consulta_cortes_programados_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint'),
    '#default_value' => variable_get('consulta_cortes_programados_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

function consulta_radicacion_por_dominio_admin() {
  $form = array();

  $form['consulta_radicacion_dominio'] = array(
    '#type' => 'fieldset',
    '#title' => t('Radicacion por Dominio'),
  );

  $form['consulta_radicacion_dominio']['consulta_radicacion_dominio_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Radicacion por Dominio'),
    '#default_value' => variable_get('consulta_radicacion_dominio_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

function consulta_radicacion_por_domicilio_admin() {
  $form = array();

  $form['consulta_radicacion_domicilio'] = array(
    '#type' => 'fieldset',
    '#title' => t('Radicacion por Domicilio'),
  );
  $form['consulta_radicacion_domicilio']['consulta_radicacion_provincias_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Radicacion por Domicilio/Provincias'),
    '#default_value' => variable_get('consulta_radicacion_provincias_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  $form['consulta_radicacion_domicilio']['consulta_radicacion_departamentos_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Radicacion por Domicilio/Departamentos'),
    '#default_value' => variable_get('consulta_radicacion_departamentos_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  $form['consulta_radicacion_domicilio']['consulta_radicacion_localidades_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Radicacion por Domicilio/Localidades'),
    '#default_value' => variable_get('consulta_radicacion_localidades_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  $form['consulta_radicacion_domicilio']['consulta_radicacion_calles_barrios_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Radicacion por Domicilio/Calles-Barrios'),
    '#default_value' => variable_get('consulta_radicacion_calles_barrios_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  $form['consulta_radicacion_domicilio']['consulta_radicacion_calles_barrios_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Radicacion por Domicilio/Calles-Barrios'),
    '#default_value' => variable_get('consulta_radicacion_calles_barrios_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  $form['consulta_radicacion_domicilio']['consulta_radicacion_altura_exacta_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Radicacion por Domicilio/Altura Exacta'),
    '#default_value' => variable_get('consulta_radicacion_altura_exacta_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  $form['consulta_radicacion_domicilio']['consulta_radicacion_registro_seccional_client_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint Radicacion por Domicilio/Registro Seccional'),
    '#default_value' => variable_get('consulta_radicacion_registro_seccional_client_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
    return system_settings_form($form);
}
/**
 * Implements hook_admin().
 */
function consulta_registro_renabap_admin() {
  $form = array();
  $form['consulta_registro_renabap']['consulta_registro_renabap_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint'),
    '#default_value' => variable_get('consulta_registro_renabap_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

function consulta_barrios_populares_admin() {

	$form = array();

	$form['consulta_barrios_populares']['consulta_barrios_populares_endpoint'] = array(
			'#type' => 'textfield',
			'#title' => t('Client endpoint'),
			'#default_value' => variable_get('consulta_barrios_populares_endpoint', ''),
			'#size' => 60,
			'#maxlength' => 255,
			'#description' => "",
			'#required' => TRUE,
	);

	return system_settings_form($form);
}

function consulta_georef_admin()
{

  $form = array();

  $form['consulta_georef']['consulta_georef_provincias_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consultar provincias endpoint'),
    '#default_value' => variable_get('consulta_georef_provincias_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  $form['consulta_georef']['consulta_georef_departamentos_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consultar departamentos endpoint'),
    '#default_value' => variable_get('consulta_georef_departamentos_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  $form['consulta_georef']['consulta_georef_localidades_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consultar localidades endpoint'),
    '#default_value' => variable_get('consulta_georef_localidades_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  return system_settings_form($form);

}

function consulta_mscrm_tramites_admin()
{

  $form = array();

  $form['consulta_mscrm_tramites']['consulta_mscrm_tramites_categorias_tramites_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consultar categorías de trámites endpoint'),
    '#default_value' => variable_get('consulta_mscrm_tramites_categorias_tramites_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  $form['consulta_mscrm_tramites']['consulta_mscrm_tramites_organismos_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consultar Organismos endpoint'),
    '#default_value' => variable_get('consulta_mscrm_tramites_organismos_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  return system_settings_form($form);

}

function consulta_encuesta_atencion_admin()
{

  $form = array();

  $form['consulta_encuesta_atencion']['consulta_consulta_encuesta_satisfaccion_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Encuesta de atención endpoint'),
    '#default_value' => variable_get('consulta_consulta_encuesta_satisfaccion_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  return system_settings_form($form);


}

function consulta_listado_fronteras_admin(){

  $form = array();

  $form['consulta_listado_fronteras']['consulta_listado_fronteras_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consulta Pasos Fronterisos endpoint'),
    '#default_value' => variable_get('consulta_listado_fronteras_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  return system_settings_form($form);


}
function consulta_infoleg_admin(){

  $form = array();

  $form['consulta_infoleg'] = array(
    '#type' => 'fieldset',
    '#title' => t('Infoleg'),

  );
  $form['consulta_infoleg']['consulta_infoleg_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consulta Infoleg endpoint'),
    '#default_value' => variable_get('consulta_infoleg_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );

  $form['consulta_infoleg']['consulta_infoleg_tipo_norma_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consulta Tipo Norma endpoint'),
    '#default_value' => variable_get('consulta_infoleg_tipo_norma_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  $form['consulta_infoleg']['consulta_infoleg_dependencias_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consulta Dependencias endpoint'),
    '#default_value' => variable_get('consulta_infoleg_dependencias_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  $form['consulta_infoleg']['consulta_infoleg_recursos_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Consulta Recursos endpoint'),
    '#default_value' => variable_get('consulta_infoleg_recursos_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );


  return system_settings_form($form);


}

function ConsultaINDECProvinciaDepartamentoLocalidadCiudad_admin() {
  $form = array();
  $form['ConsultaINDECProvinciaDepartamentoLocalidadCiudad']['ConsultaINDECProvinciaDepartamentoLocalidadCiudad_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Client endpoint'),
    '#default_value' => variable_get('ConsultaINDECProvinciaDepartamentoLocalidadCiudad_endpoint', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => "",
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
