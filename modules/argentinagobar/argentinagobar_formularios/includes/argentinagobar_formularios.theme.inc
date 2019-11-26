<?php
/**
 * Implements hook_theme().
 */
function argentinagobar_formularios_theme($existing, $type, $theme, $path){
  return array(
    'dni_pass_estado' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_dni_pass',
    ),
    'defensa_consumidor_error' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_dc_error',
    ),
    'defensa_consumidor_issue_mail' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_dc_issue_mail',
    ),
    'defensa_consumidor_issue' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_dc_issue',
    ),
    'defensa_consumidor_estado' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_dc_estado',
    ),
    'argentinagobar_formularios_consulta_tad_respuesta' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'argentinagobar_formularios_consulta_tad_respuesta',
    ),
    'argentinagobar_formularios_formulario_panel' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'argentinagobar_formularios_formulario_panel',
    ),
    'argentinagobar_formularios_consulta_cortes_programados_feedback' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'argentinagobar_formularios_consulta_cortes_programados_feedback',
    ),
    'argentinagobar_formularios_sugerencias_argentinagobar_feedback' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'argentinagobar_sugerencias_argentinagobar_feedback',
    ),
    'argentinagobar_formularios_respuesta' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'argentinagobar_formularios_respuesta',
    ),
    'argentinagobar_formularios_mensaje_enviado' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'argentinagobar_formularios_mensaje_enviado',
    ),
    'consulta_licencia_conducir_feedback' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'consulta_licencia_conducir_feedback',
    ),
    'form_element_addon' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_addon',
      'render element' => 'element',
    ),
    'form_input_group' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_input_group',
      'render element' => 'element',
    ),
    'form_element_radios_btn' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_radios_btn',
      'render element' => 'element',
    ),
    'form_element_radios_inline' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_radios_inline',
      'render element' => 'element',
    ),
    'form_element_radios' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_radios',
      'render element' => 'element',
    ),
    'form_element_radios' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_radios',
      'render element' => 'element',
    ),
    'form_element_date' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_date',
      'render element' => 'element',
    ),
    'form_element_date_no_calendar' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_date_no_calendar',
      'render element' => 'element',
    ),
    'form_element_date_container' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_date_container',
      'render element' => 'element',
    ),
    'form_element_prefijo' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_prefijo',
      'render element' => 'element',
    ),
    'form_element_telefono_movil' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_telefono_movil',
      'render element' => 'element',
    ),
    'radios_manifestacion' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'radios_manifestacion',
      'render element' => 'element',
    ),
    'consulta_obsequios_detalle' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'consulta_obsequios_detalle',
    ),
    'consulta_viajes_detalle' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'consulta_viajes_detalle',
    ),
    'response_panel_completo' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_panel_completo',
    ),
    'consulta_radicacion_dominio_error' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'consulta_radicacion_dominio_error',
    ),
    'response_panel' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_panel',
    ),
    'response_panel_consulta' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_panel_consulta',
    ),
    'response_panel_consulta_simple' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_panel_consulta_simple',
    ),
    'response_panel_footer' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_panel_footer',
    ),
    'response_panel_error' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_panel_error',
    ),
    'response_panel_completo_consulta' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_panel_completo_consulta',
    ),
    'response_success' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_success',
    ),
    'consulta_registro_renabap_' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/barrios_populares',
      'template' => 'consulta_registro_renabap',
    ),
    'encuesta_satisfaccion_ok' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/encuesta_satisfaccion',
      'template' => 'encuesta_satisfaccion_ok',
    ),
    'encuesta_satisfaccion_error' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/encuesta_satisfaccion',
      'template' => 'encuesta_satisfaccion_error',
    ),

    'response_beneficios' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'response_beneficios',
    ),

    'consulta_pasos_fronterizos' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/pasos_fronterizos/',
      'template' => 'consulta_pasos_fronterizos',
    ),

    'consulta_listado_fronteras_detalle' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/pasos_fronterizos/',
      'template' => 'consulta_listado_fronteras_detalle',
    ),

    'listado_infoleg' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/Infoleg/',
      'template' => 'listado_infoleg',
    ),

    'listado_infoleg_boletin' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/Infoleg/',
      'template' => 'listado_infoleg_boletin',
    ),

    'infoleg_resumen' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/Infoleg/',
      'template' => 'infoleg_resumen',
    ),

    'infoleg_normas_complementarias' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/Infoleg/',
      'template' => 'infoleg_normas_complementarias',
    ),

    'infoleg_detalle_norma' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/Infoleg/',
      'template' => 'infoleg_detalle_norma',
    ),

    'infoleg_actualizacion_norma' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/Infoleg/',
      'template' => 'infoleg_actualizacion_norma',
    ),

    'infoleg_no_se_encontro_norma' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/Infoleg/',
      'template' => 'infoleg_no_se_encontro_norma',
    ),

    'drupar_paginador' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/Paginador/',
      'template' => 'drupar_paginador',
    ),

    'response_cuil_ok' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/cuil/',
      'template' => 'response_cuil_ok',
    ),

    'response_cuil_error' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/cuil/',
      'template' => 'response_cuil_error',
    ),
    'incucai_respuesta_voluntad' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI/',
      'template' => 'incucai_respuesta_voluntad',
    ),

    'incucai_respuesta_error' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI',
      'template' => 'incucai_respuesta_error',
    ),

    //INCUCAI
    'response_incucai_donante_organos' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI/',
      'template' => 'response_incucai_donante_organos',
    ),

    'response_incucai_no_expreso' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI/',
      'template' => 'response_incucai_no_expreso',
    ),

    'response_incucai_medula_no_expreso' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI/',
      'template' => 'response_incucai_medula_no_expreso',
    ),

    'response_incucai_medula_donante' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI/',
      'template' => 'response_incucai_medula_donante',
    ),

    'response_incucai_menor_edad' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI/',
      'template' => 'response_incucai_menor_edad'
    ),

    'response_incucai_donante_sin_confirmacion' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI/',
      'template' => 'response_incucai_donante_sin_confirmacion'
    ),

    'confirmacion_incucai' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI',
      'template' => 'confirmacion_incucai'
    ),

    'confirmacion_incucai_error' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/INCUCAI',
      'template' => 'confirmacion_incucai_error'
    ),

    'form_element_date' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_date',
      'render element' => 'element',
    ),

    'form_element_date_popup' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates',
      'template' => 'form_element_date_popup',
    ),
    'compre_social_listado' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/CompreSocial/',
      'template' => 'compre_social_listado',
    ),
    'compre_social_paginador' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/CompreSocial/',
      'template' => 'compre_social_paginador',
    ),
    'rlm_table_response' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/RLM/',
      'template' => 'rlm_table_response',
    ),
    'detalle_rlm' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RLM',
      'template' => 'detalle_rlm',
    ),
    'rlm_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RLM',
      'template' => 'rlm_error',
    ),
    'rlm_pagina_vacia' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RLM',
      'template' => 'rlm_pagina_vacia',
    ),
    'rlm_servicio_caido' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RLM',
      'template' => 'rlm_servicio_caido',
    ),
    'rlm_noconecta' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RLM',
      'template' => 'rlm_noconecta',
    ),
    'apostillaes_ok' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/ApostillaES',
      'template' => 'apostillaes_ok',
    ),
    'apostillaes_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ApostillaES',
      'template' => 'apostillaes_error',
    ),
    'apostillaen_ok' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/ApostillaEN',
      'template' => 'apostillaen_ok',
    ),
    'apostillaen_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ApostillaEN',
      'template' => 'apostillaen_error',
    ),
    'apostillafr_ok' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/ApostillaFR',
      'template' => 'apostillafr_ok',
    ),
    'apostillafr_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ApostillaFR',
      'template' => 'apostillafr_error',
    ),
    'cuando_cobro' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/anses',
      'template' => 'cuando_cobro',
    ),
    'cuando_cobro_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/anses',
      'template' => 'cuando_cobro_error',

    ),
    'cuando_cobro_no_se_encontro' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/anses',
      'template' => 'cuando_cobro_no_se_encontro',
    ),
    'rlmtest_ok' => array(
      'path' => drupal_get_path('module', 'argentinagobar_formularios') . '/templates/RLMTest/',
      'template' => 'rlmtest_ok',
    ),
    'detalle_rlmtest' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RLMTest',
      'template' => 'detalle_rlmtest',
    ),
    'rlmtest_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RLMTest',
      'template' => 'rlmtest_error',
    ),
    'convocatorias_cultura_ok' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ConvocatoriasCultura/',
      'template' => 'convocatorias_cultura_ok',
    ),
    'convocatorias_cultura_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ConvocatoriasCultura/',
      'template' => 'convocatorias_cultura_error',
    ),
    'cultura_paginador' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ConvocatoriasCultura/',
      'template' => 'cultura_paginador',
    ),
    'detalle_convocatorias' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ConvocatoriasCultura/',
      'template' => 'detalle_convocatorias',
    ),
    'registrosociedades_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RegistroSociedades/',
      'template' => 'registrosociedades_error',
    ),
    'registrosociedades_detalle' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/RegistroSociedades/',
      'template' => 'registrosociedades_detalle',
    ),
    'puertos_ok' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/Puertos/',
      'template' => 'puertos_ok',
    ),
    'puertos_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/Puertos/',
      'template' => 'puertos_error',
    ),
    'expedientes_ok' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/Expedientes/',
      'template' => 'expedientes_ok',
    ),
    'expedientes_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/Expedientes/',
      'template' => 'expedientes_error',
    ),
    'expedientes_no_se_encontro' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/Expedientes/',
      'template' => 'expedientes_no_se_encontro',
    ),
    'chicos_extraviados_ok' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ChicosExtraviados/',
      'template' => 'chicos_extraviados_ok',
    ),
    'chicos_extraviados_error' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ChicosExtraviados/',
      'template' => 'chicos_extraviados_error',
    ),
    'chicos_extraviados_detalle' => array(
      'path' => drupal_get_path('module','argentinagobar_formularios') . '/templates/ChicosExtraviados/',
      'template' => 'chicos_extraviados_detalle',
    )
  );
}

function argentinagobar_formularios_theme_registry_alter(&$theme_registry) {
    $theme_registry['date_text']['function'] = 'argentinagobar_formularios_date_text';
}

function argentinagobar_formularios_date_text($variables){
    $element = $variables['element'];
    return theme('form_element', $element);
}
