<?php
/**
 * @file
 * argentinagobar_tramites.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function argentinagobar_tramites_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_descargas_obligatorias'.
  $permissions['create field_descargas_obligatorias'] = array(
    'name' => 'create field_descargas_obligatorias',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_digitalizacion_medir'.
  $permissions['create field_digitalizacion_medir'] = array(
    'name' => 'create field_digitalizacion_medir',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_digitalizacion_observacion'.
  $permissions['create field_digitalizacion_observacion'] = array(
    'name' => 'create field_digitalizacion_observacion',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_es_migrado'.
  $permissions['create field_es_migrado'] = array(
    'name' => 'create field_es_migrado',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_formulario_digital'.
  $permissions['create field_formulario_digital'] = array(
    'name' => 'create field_formulario_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_identificacion_digital'.
  $permissions['create field_identificacion_digital'] = array(
    'name' => 'create field_identificacion_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_notificaciones'.
  $permissions['create field_notificaciones'] = array(
    'name' => 'create field_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pago_electronico_list'.
  $permissions['create field_pago_electronico_list'] = array(
    'name' => 'create field_pago_electronico_list',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pago_requerido_list'.
  $permissions['create field_pago_requerido_list'] = array(
    'name' => 'create field_pago_requerido_list',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_posee_notificaciones'.
  $permissions['create field_posee_notificaciones'] = array(
    'name' => 'create field_posee_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_relevamiento_observaciones'.
  $permissions['create field_relevamiento_observaciones'] = array(
    'name' => 'create field_relevamiento_observaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_resumen_nivel'.
  $permissions['create field_resumen_nivel'] = array(
    'name' => 'create field_resumen_nivel',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_transaccion_tipo'.
  $permissions['create field_transaccion_tipo'] = array(
    'name' => 'create field_transaccion_tipo',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_turno_digital'.
  $permissions['create field_turno_digital'] = array(
    'name' => 'create field_turno_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_turno_requerido'.
  $permissions['create field_turno_requerido'] = array(
    'name' => 'create field_turno_requerido',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_descargas_obligatorias'.
  $permissions['edit field_descargas_obligatorias'] = array(
    'name' => 'edit field_descargas_obligatorias',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_digitalizacion_medir'.
  $permissions['edit field_digitalizacion_medir'] = array(
    'name' => 'edit field_digitalizacion_medir',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_digitalizacion_observacion'.
  $permissions['edit field_digitalizacion_observacion'] = array(
    'name' => 'edit field_digitalizacion_observacion',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_es_migrado'.
  $permissions['edit field_es_migrado'] = array(
    'name' => 'edit field_es_migrado',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_formulario_digital'.
  $permissions['edit field_formulario_digital'] = array(
    'name' => 'edit field_formulario_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_identificacion_digital'.
  $permissions['edit field_identificacion_digital'] = array(
    'name' => 'edit field_identificacion_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_notificaciones'.
  $permissions['edit field_notificaciones'] = array(
    'name' => 'edit field_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pago_electronico_list'.
  $permissions['edit field_pago_electronico_list'] = array(
    'name' => 'edit field_pago_electronico_list',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pago_requerido_list'.
  $permissions['edit field_pago_requerido_list'] = array(
    'name' => 'edit field_pago_requerido_list',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_posee_notificaciones'.
  $permissions['edit field_posee_notificaciones'] = array(
    'name' => 'edit field_posee_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_relevamiento_observaciones'.
  $permissions['edit field_relevamiento_observaciones'] = array(
    'name' => 'edit field_relevamiento_observaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_resumen_nivel'.
  $permissions['edit field_resumen_nivel'] = array(
    'name' => 'edit field_resumen_nivel',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_transaccion_tipo'.
  $permissions['edit field_transaccion_tipo'] = array(
    'name' => 'edit field_transaccion_tipo',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_turno_digital'.
  $permissions['edit field_turno_digital'] = array(
    'name' => 'edit field_turno_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_turno_requerido'.
  $permissions['edit field_turno_requerido'] = array(
    'name' => 'edit field_turno_requerido',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_descargas_obligatorias'.
  $permissions['edit own field_descargas_obligatorias'] = array(
    'name' => 'edit own field_descargas_obligatorias',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_digitalizacion_medir'.
  $permissions['edit own field_digitalizacion_medir'] = array(
    'name' => 'edit own field_digitalizacion_medir',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_digitalizacion_observacion'.
  $permissions['edit own field_digitalizacion_observacion'] = array(
    'name' => 'edit own field_digitalizacion_observacion',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_es_migrado'.
  $permissions['edit own field_es_migrado'] = array(
    'name' => 'edit own field_es_migrado',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_formulario_digital'.
  $permissions['edit own field_formulario_digital'] = array(
    'name' => 'edit own field_formulario_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_identificacion_digital'.
  $permissions['edit own field_identificacion_digital'] = array(
    'name' => 'edit own field_identificacion_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_notificaciones'.
  $permissions['edit own field_notificaciones'] = array(
    'name' => 'edit own field_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pago_electronico_list'.
  $permissions['edit own field_pago_electronico_list'] = array(
    'name' => 'edit own field_pago_electronico_list',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pago_requerido_list'.
  $permissions['edit own field_pago_requerido_list'] = array(
    'name' => 'edit own field_pago_requerido_list',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_posee_notificaciones'.
  $permissions['edit own field_posee_notificaciones'] = array(
    'name' => 'edit own field_posee_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_relevamiento_observaciones'.
  $permissions['edit own field_relevamiento_observaciones'] = array(
    'name' => 'edit own field_relevamiento_observaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_resumen_nivel'.
  $permissions['edit own field_resumen_nivel'] = array(
    'name' => 'edit own field_resumen_nivel',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_transaccion_tipo'.
  $permissions['edit own field_transaccion_tipo'] = array(
    'name' => 'edit own field_transaccion_tipo',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_turno_digital'.
  $permissions['edit own field_turno_digital'] = array(
    'name' => 'edit own field_turno_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_turno_requerido'.
  $permissions['edit own field_turno_requerido'] = array(
    'name' => 'edit own field_turno_requerido',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_descargas_obligatorias'.
  $permissions['view field_descargas_obligatorias'] = array(
    'name' => 'view field_descargas_obligatorias',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_digitalizacion_medir'.
  $permissions['view field_digitalizacion_medir'] = array(
    'name' => 'view field_digitalizacion_medir',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_digitalizacion_observacion'.
  $permissions['view field_digitalizacion_observacion'] = array(
    'name' => 'view field_digitalizacion_observacion',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_es_migrado'.
  $permissions['view field_es_migrado'] = array(
    'name' => 'view field_es_migrado',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_formulario_digital'.
  $permissions['view field_formulario_digital'] = array(
    'name' => 'view field_formulario_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_identificacion_digital'.
  $permissions['view field_identificacion_digital'] = array(
    'name' => 'view field_identificacion_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_notificaciones'.
  $permissions['view field_notificaciones'] = array(
    'name' => 'view field_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pago_electronico_list'.
  $permissions['view field_pago_electronico_list'] = array(
    'name' => 'view field_pago_electronico_list',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pago_requerido_list'.
  $permissions['view field_pago_requerido_list'] = array(
    'name' => 'view field_pago_requerido_list',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_posee_notificaciones'.
  $permissions['view field_posee_notificaciones'] = array(
    'name' => 'view field_posee_notificaciones',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_relevamiento_observaciones'.
  $permissions['view field_relevamiento_observaciones'] = array(
    'name' => 'view field_relevamiento_observaciones',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_resumen_nivel'.
  $permissions['view field_resumen_nivel'] = array(
    'name' => 'view field_resumen_nivel',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_transaccion_tipo'.
  $permissions['view field_transaccion_tipo'] = array(
    'name' => 'view field_transaccion_tipo',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_turno_digital'.
  $permissions['view field_turno_digital'] = array(
    'name' => 'view field_turno_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_turno_requerido'.
  $permissions['view field_turno_requerido'] = array(
    'name' => 'view field_turno_requerido',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_descargas_obligatorias'.
  $permissions['view own field_descargas_obligatorias'] = array(
    'name' => 'view own field_descargas_obligatorias',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_digitalizacion_medir'.
  $permissions['view own field_digitalizacion_medir'] = array(
    'name' => 'view own field_digitalizacion_medir',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_digitalizacion_observacion'.
  $permissions['view own field_digitalizacion_observacion'] = array(
    'name' => 'view own field_digitalizacion_observacion',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_es_migrado'.
  $permissions['view own field_es_migrado'] = array(
    'name' => 'view own field_es_migrado',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_formulario_digital'.
  $permissions['view own field_formulario_digital'] = array(
    'name' => 'view own field_formulario_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_identificacion_digital'.
  $permissions['view own field_identificacion_digital'] = array(
    'name' => 'view own field_identificacion_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_notificaciones'.
  $permissions['view own field_notificaciones'] = array(
    'name' => 'view own field_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pago_electronico_list'.
  $permissions['view own field_pago_electronico_list'] = array(
    'name' => 'view own field_pago_electronico_list',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pago_requerido_list'.
  $permissions['view own field_pago_requerido_list'] = array(
    'name' => 'view own field_pago_requerido_list',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_posee_notificaciones'.
  $permissions['view own field_posee_notificaciones'] = array(
    'name' => 'view own field_posee_notificaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_relevamiento_observaciones'.
  $permissions['view own field_relevamiento_observaciones'] = array(
    'name' => 'view own field_relevamiento_observaciones',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_resumen_nivel'.
  $permissions['view own field_resumen_nivel'] = array(
    'name' => 'view own field_resumen_nivel',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_transaccion_tipo'.
  $permissions['view own field_transaccion_tipo'] = array(
    'name' => 'view own field_transaccion_tipo',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_turno_digital'.
  $permissions['view own field_turno_digital'] = array(
    'name' => 'view own field_turno_digital',
    'roles' => array(
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_turno_requerido'.
  $permissions['view own field_turno_requerido'] = array(
    'name' => 'view own field_turno_requerido',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
