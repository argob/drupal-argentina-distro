<?php
/**
 * @file
 * ar_servicios_vista.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ar_servicios_vista_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_view_servicio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Servicios';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Servicios';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    61 => '61',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tramite' => 'tramite',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['offset'] = TRUE;
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Contenido';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::clone_action_clone' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Publicado';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Ver';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Editar';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Borrar';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Título';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    53 => 0,
    61 => 0,
    43 => 0,
    47 => 0,
    59 => 0,
    4 => 0,
    21 => 0,
    65 => 0,
    18 => 0,
    24 => 0,
    38 => 0,
    34 => 0,
    41 => 0,
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Título';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Publicado';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    53 => 0,
    61 => 0,
    43 => 0,
    47 => 0,
    59 => 0,
    4 => 0,
    21 => 0,
    65 => 0,
    18 => 0,
    24 => 0,
    38 => 0,
    34 => 0,
    41 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tramite' => 'tramite',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/content/servicio';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Servicios';
  $handler->display->display_options['menu']['description'] = 'Listar todos los servicios';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-full_servicios.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['style_options']['encoding'] = 'UTF-8';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Organismo */
  $handler->display->display_options['relationships']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['ui_name'] = 'Organismo';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['label'] = 'OG Group';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Publicado';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'Ruta';
  $handler->display->display_options['fields']['path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['path'] = 'www.argentina.gob.ar[path]';
  $handler->display->display_options['fields']['path']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'og_group_ref_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Organismo';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Tipo de transacción */
  $handler->display->display_options['fields']['field_transaccion_tipo']['id'] = 'field_transaccion_tipo';
  $handler->display->display_options['fields']['field_transaccion_tipo']['table'] = 'field_data_field_transaccion_tipo';
  $handler->display->display_options['fields']['field_transaccion_tipo']['field'] = 'field_transaccion_tipo';
  $handler->display->display_options['fields']['field_transaccion_tipo']['element_label_colon'] = FALSE;
  /* Field: Content: Nivel resumen */
  $handler->display->display_options['fields']['field_resumen_nivel']['id'] = 'field_resumen_nivel';
  $handler->display->display_options['fields']['field_resumen_nivel']['table'] = 'field_data_field_resumen_nivel';
  $handler->display->display_options['fields']['field_resumen_nivel']['field'] = 'field_resumen_nivel';
  $handler->display->display_options['fields']['field_resumen_nivel']['element_label_colon'] = FALSE;
  /* Field: Content: ¿Se puede medir digitalización? */
  $handler->display->display_options['fields']['field_digitalizacion_medir']['id'] = 'field_digitalizacion_medir';
  $handler->display->display_options['fields']['field_digitalizacion_medir']['table'] = 'field_data_field_digitalizacion_medir';
  $handler->display->display_options['fields']['field_digitalizacion_medir']['field'] = 'field_digitalizacion_medir';
  $handler->display->display_options['fields']['field_digitalizacion_medir']['element_label_colon'] = FALSE;
  /* Field: Content: Observación de digitalización */
  $handler->display->display_options['fields']['field_digitalizacion_observacion']['id'] = 'field_digitalizacion_observacion';
  $handler->display->display_options['fields']['field_digitalizacion_observacion']['table'] = 'field_data_field_digitalizacion_observacion';
  $handler->display->display_options['fields']['field_digitalizacion_observacion']['field'] = 'field_digitalizacion_observacion';
  $handler->display->display_options['fields']['field_digitalizacion_observacion']['element_label_colon'] = FALSE;
  /* Field: Content: Pago electrónico */
  $handler->display->display_options['fields']['field_pago_electronico_list']['id'] = 'field_pago_electronico_list';
  $handler->display->display_options['fields']['field_pago_electronico_list']['table'] = 'field_data_field_pago_electronico_list';
  $handler->display->display_options['fields']['field_pago_electronico_list']['field'] = 'field_pago_electronico_list';
  $handler->display->display_options['fields']['field_pago_electronico_list']['element_label_colon'] = FALSE;
  /* Field: Content: Sistema de Identificación digital */
  $handler->display->display_options['fields']['field_identificacion_digital']['id'] = 'field_identificacion_digital';
  $handler->display->display_options['fields']['field_identificacion_digital']['table'] = 'field_data_field_identificacion_digital';
  $handler->display->display_options['fields']['field_identificacion_digital']['field'] = 'field_identificacion_digital';
  $handler->display->display_options['fields']['field_identificacion_digital']['element_label_colon'] = FALSE;
  /* Field: Content: Comunicaciones y/o notificaciones electrónicas */
  $handler->display->display_options['fields']['field_posee_notificaciones']['id'] = 'field_posee_notificaciones';
  $handler->display->display_options['fields']['field_posee_notificaciones']['table'] = 'field_data_field_posee_notificaciones';
  $handler->display->display_options['fields']['field_posee_notificaciones']['field'] = 'field_posee_notificaciones';
  $handler->display->display_options['fields']['field_posee_notificaciones']['element_label_colon'] = FALSE;
  /* Field: Content: Tipo Comunicaciones y/o notificaciones electrónicas */
  $handler->display->display_options['fields']['field_notificaciones']['id'] = 'field_notificaciones';
  $handler->display->display_options['fields']['field_notificaciones']['table'] = 'field_data_field_notificaciones';
  $handler->display->display_options['fields']['field_notificaciones']['field'] = 'field_notificaciones';
  $handler->display->display_options['fields']['field_notificaciones']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_notificaciones']['delta_offset'] = '0';
  /* Field: Content: ¿Formulario digital? */
  $handler->display->display_options['fields']['field_formulario_digital']['id'] = 'field_formulario_digital';
  $handler->display->display_options['fields']['field_formulario_digital']['table'] = 'field_data_field_formulario_digital';
  $handler->display->display_options['fields']['field_formulario_digital']['field'] = 'field_formulario_digital';
  $handler->display->display_options['fields']['field_formulario_digital']['element_label_colon'] = FALSE;
  /* Field: Content: ¿Requiere pago? */
  $handler->display->display_options['fields']['field_pago_requerido_list']['id'] = 'field_pago_requerido_list';
  $handler->display->display_options['fields']['field_pago_requerido_list']['table'] = 'field_data_field_pago_requerido_list';
  $handler->display->display_options['fields']['field_pago_requerido_list']['field'] = 'field_pago_requerido_list';
  $handler->display->display_options['fields']['field_pago_requerido_list']['element_label_colon'] = FALSE;
  /* Field: Content: ¿Requiere turno? */
  $handler->display->display_options['fields']['field_turno_requerido']['id'] = 'field_turno_requerido';
  $handler->display->display_options['fields']['field_turno_requerido']['table'] = 'field_data_field_turno_requerido';
  $handler->display->display_options['fields']['field_turno_requerido']['field'] = 'field_turno_requerido';
  $handler->display->display_options['fields']['field_turno_requerido']['element_label_colon'] = FALSE;
  /* Field: Content: ¿Turno digital? */
  $handler->display->display_options['fields']['field_turno_digital']['id'] = 'field_turno_digital';
  $handler->display->display_options['fields']['field_turno_digital']['table'] = 'field_data_field_turno_digital';
  $handler->display->display_options['fields']['field_turno_digital']['field'] = 'field_turno_digital';
  /* Field: Content: ¿Descargas obligatorias de presentar? */
  $handler->display->display_options['fields']['field_descargas_obligatorias']['id'] = 'field_descargas_obligatorias';
  $handler->display->display_options['fields']['field_descargas_obligatorias']['table'] = 'field_data_field_descargas_obligatorias';
  $handler->display->display_options['fields']['field_descargas_obligatorias']['field'] = 'field_descargas_obligatorias';
  $handler->display->display_options['fields']['field_descargas_obligatorias']['element_label_colon'] = FALSE;
  /* Field: Content: Observaciones del relevamiento */
  $handler->display->display_options['fields']['field_relevamiento_observaciones']['id'] = 'field_relevamiento_observaciones';
  $handler->display->display_options['fields']['field_relevamiento_observaciones']['table'] = 'field_data_field_relevamiento_observaciones';
  $handler->display->display_options['fields']['field_relevamiento_observaciones']['field'] = 'field_relevamiento_observaciones';
  $handler->display->display_options['path'] = 'admin/content/servicio/export/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['admin_view_servicio'] = array(
    t('Master'),
    t('Servicios'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Title'),
    t('Page'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Contenido'),
    t('- Choose an operation -'),
    t('Publicado'),
    t('Ver'),
    t('Editar'),
    t('Borrar'),
    t('Título'),
    t('Data export'),
    t('OG Group'),
    t('ID'),
    t('Ruta'),
    t('Organismo'),
    t('Tipo de transacción'),
    t('Nivel resumen'),
    t('¿Se puede medir digitalización?'),
    t('Observación de digitalización'),
    t('Pago electrónico'),
    t('Sistema de Identificación digital'),
    t('Comunicaciones y/o notificaciones electrónicas'),
    t('Tipo Comunicaciones y/o notificaciones electrónicas'),
    t('¿Formulario digital?'),
    t('¿Requiere pago?'),
    t('¿Requiere turno?'),
    t('¿Turno digital?'),
    t('¿Descargas obligatorias de presentar?'),
    t('Observaciones del relevamiento'),
  );
  $export['admin_view_servicio'] = $view;

  return $export;
}
