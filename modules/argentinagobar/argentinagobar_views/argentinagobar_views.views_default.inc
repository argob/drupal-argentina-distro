<?php
/**
 * @file
 * argentinagobar_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function argentinagobar_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'listado_de_contenido';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Listado de Contenido';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Listado de Contenido';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Imagen destacada */
  $handler->display->display_options['fields']['field_featured_image']['id'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['field'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_featured_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Groups audience (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['arguments']['type']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Categoría (field_categoria) */
  $handler->display->display_options['arguments']['field_categoria_target_id']['id'] = 'field_categoria_target_id';
  $handler->display->display_options['arguments']['field_categoria_target_id']['table'] = 'field_data_field_categoria';
  $handler->display->display_options['arguments']['field_categoria_target_id']['field'] = 'field_categoria_target_id';
  $handler->display->display_options['arguments']['field_categoria_target_id']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_categoria_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_categoria_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_categoria_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_categoria_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Tipo de Trámite (field_tramite_tipo) */
  $handler->display->display_options['arguments']['field_tramite_tipo_target_id']['id'] = 'field_tramite_tipo_target_id';
  $handler->display->display_options['arguments']['field_tramite_tipo_target_id']['table'] = 'field_data_field_tramite_tipo';
  $handler->display->display_options['arguments']['field_tramite_tipo_target_id']['field'] = 'field_tramite_tipo_target_id';
  $handler->display->display_options['arguments']['field_tramite_tipo_target_id']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_tramite_tipo_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tramite_tipo_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tramite_tipo_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tramite_tipo_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'argentinagobar_migtram' => 'argentinagobar_migtram',
    'noticia' => 'noticia',
  );

  /* Display: General */
  $handler = $view->new_display('block', 'General', 'listado_de_contenido_default');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Listado de Tramites Migrados */
  $handler = $view->new_display('attachment', 'Listado de Tramites Migrados', 'listado_de_contenido_tramites');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'argentinagobar_migtram' => 'argentinagobar_migtram',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '1540';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['filters']['nid_1']['table'] = 'node';
  $handler->display->display_options['filters']['nid_1']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_1']['value']['value'] = '15';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['filters']['nid_2']['table'] = 'node';
  $handler->display->display_options['filters']['nid_2']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_2']['value']['value'] = '1528';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_3']['id'] = 'nid_3';
  $handler->display->display_options['filters']['nid_3']['table'] = 'node';
  $handler->display->display_options['filters']['nid_3']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_3']['value']['value'] = '1417';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_4']['id'] = 'nid_4';
  $handler->display->display_options['filters']['nid_4']['table'] = 'node';
  $handler->display->display_options['filters']['nid_4']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_4']['value']['value'] = '1909';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_5']['id'] = 'nid_5';
  $handler->display->display_options['filters']['nid_5']['table'] = 'node';
  $handler->display->display_options['filters']['nid_5']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_5']['value']['value'] = '2263';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_6']['id'] = 'nid_6';
  $handler->display->display_options['filters']['nid_6']['table'] = 'node';
  $handler->display->display_options['filters']['nid_6']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_6']['value']['value'] = '1679';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_7']['id'] = 'nid_7';
  $handler->display->display_options['filters']['nid_7']['table'] = 'node';
  $handler->display->display_options['filters']['nid_7']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_7']['value']['value'] = '1964';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_8']['id'] = 'nid_8';
  $handler->display->display_options['filters']['nid_8']['table'] = 'node';
  $handler->display->display_options['filters']['nid_8']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_8']['value']['value'] = '1904';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_9']['id'] = 'nid_9';
  $handler->display->display_options['filters']['nid_9']['table'] = 'node';
  $handler->display->display_options['filters']['nid_9']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_9']['value']['value'] = '1899';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_10']['id'] = 'nid_10';
  $handler->display->display_options['filters']['nid_10']['table'] = 'node';
  $handler->display->display_options['filters']['nid_10']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_10']['value']['value'] = '2124';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_11']['id'] = 'nid_11';
  $handler->display->display_options['filters']['nid_11']['table'] = 'node';
  $handler->display->display_options['filters']['nid_11']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_11']['value']['value'] = '2004';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_12']['id'] = 'nid_12';
  $handler->display->display_options['filters']['nid_12']['table'] = 'node';
  $handler->display->display_options['filters']['nid_12']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_12']['value']['value'] = '1999';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_13']['id'] = 'nid_13';
  $handler->display->display_options['filters']['nid_13']['table'] = 'node';
  $handler->display->display_options['filters']['nid_13']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_13']['value']['value'] = '1994';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_14']['id'] = 'nid_14';
  $handler->display->display_options['filters']['nid_14']['table'] = 'node';
  $handler->display->display_options['filters']['nid_14']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_14']['value']['value'] = '1989';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_15']['id'] = 'nid_15';
  $handler->display->display_options['filters']['nid_15']['table'] = 'node';
  $handler->display->display_options['filters']['nid_15']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_15']['value']['value'] = '1984';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_16']['id'] = 'nid_16';
  $handler->display->display_options['filters']['nid_16']['table'] = 'node';
  $handler->display->display_options['filters']['nid_16']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_16']['value']['value'] = '1949';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_17']['id'] = 'nid_17';
  $handler->display->display_options['filters']['nid_17']['table'] = 'node';
  $handler->display->display_options['filters']['nid_17']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_17']['value']['value'] = '1944';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_18']['id'] = 'nid_18';
  $handler->display->display_options['filters']['nid_18']['table'] = 'node';
  $handler->display->display_options['filters']['nid_18']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_18']['value']['value'] = '1929';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_19']['id'] = 'nid_19';
  $handler->display->display_options['filters']['nid_19']['table'] = 'node';
  $handler->display->display_options['filters']['nid_19']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_19']['value']['value'] = '2089';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_20']['id'] = 'nid_20';
  $handler->display->display_options['filters']['nid_20']['table'] = 'node';
  $handler->display->display_options['filters']['nid_20']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_20']['value']['value'] = '1889';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_21']['id'] = 'nid_21';
  $handler->display->display_options['filters']['nid_21']['table'] = 'node';
  $handler->display->display_options['filters']['nid_21']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_21']['value']['value'] = '1974';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_22']['id'] = 'nid_22';
  $handler->display->display_options['filters']['nid_22']['table'] = 'node';
  $handler->display->display_options['filters']['nid_22']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_22']['value']['value'] = '1954';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_23']['id'] = 'nid_23';
  $handler->display->display_options['filters']['nid_23']['table'] = 'node';
  $handler->display->display_options['filters']['nid_23']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_23']['value']['value'] = '1809';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_24']['id'] = 'nid_24';
  $handler->display->display_options['filters']['nid_24']['table'] = 'node';
  $handler->display->display_options['filters']['nid_24']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_24']['value']['value'] = '2029';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_25']['id'] = 'nid_25';
  $handler->display->display_options['filters']['nid_25']['table'] = 'node';
  $handler->display->display_options['filters']['nid_25']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_25']['value']['value'] = '2024';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_26']['id'] = 'nid_26';
  $handler->display->display_options['filters']['nid_26']['table'] = 'node';
  $handler->display->display_options['filters']['nid_26']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_26']['value']['value'] = '1894';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_27']['id'] = 'nid_27';
  $handler->display->display_options['filters']['nid_27']['table'] = 'node';
  $handler->display->display_options['filters']['nid_27']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_27']['value']['value'] = '1829';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_28']['id'] = 'nid_28';
  $handler->display->display_options['filters']['nid_28']['table'] = 'node';
  $handler->display->display_options['filters']['nid_28']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_28']['value']['value'] = '1784';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_29']['id'] = 'nid_29';
  $handler->display->display_options['filters']['nid_29']['table'] = 'node';
  $handler->display->display_options['filters']['nid_29']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_29']['value']['value'] = '1684';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_30']['id'] = 'nid_30';
  $handler->display->display_options['filters']['nid_30']['table'] = 'node';
  $handler->display->display_options['filters']['nid_30']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_30']['value']['value'] = '1527';

  /* Display: Listado de Noticias */
  $handler = $view->new_display('attachment', 'Listado de Noticias', 'listado_de_contenido_noticias');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Listado de Noticias';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['arguments']['type']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Categoría (field_categoria) */
  $handler->display->display_options['arguments']['field_categoria_target_id']['id'] = 'field_categoria_target_id';
  $handler->display->display_options['arguments']['field_categoria_target_id']['table'] = 'field_data_field_categoria';
  $handler->display->display_options['arguments']['field_categoria_target_id']['field'] = 'field_categoria_target_id';
  $handler->display->display_options['arguments']['field_categoria_target_id']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_categoria_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_categoria_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_categoria_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_categoria_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Contextual filter: Node Hierarchy: Parent Node ID */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'nh_parent';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'noticia' => 'noticia',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'node/%/noticias/rss';
  $translatables['listado_de_contenido'] = array(
    t('Master'),
    t('Listado de Contenido'),
    t('more'),
    t('Apply'),
    t('Reiniciar'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Todo(s)'),
    t('General'),
    t('Listado de Tramites Migrados'),
    t('Listado de Noticias'),
    t('Feed'),
  );
  $export['listado_de_contenido'] = $view;

  return $export;
}
