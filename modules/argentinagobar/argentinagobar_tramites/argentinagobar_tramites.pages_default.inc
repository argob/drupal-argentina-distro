<?php
/**
 * @file
 * argentinagobar_tramites.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function argentinagobar_tramites_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__tramite';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Trámite',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'tramite',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'tramite' => 'tramite',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'pagina-navegacion-derecha';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'body-middle' => NULL,
      'full' => NULL,
      'sidebar' => NULL,
      'column' => NULL,
      'header_full' => NULL,
      'header_left' => NULL,
      'header_right' => NULL,
      'content' => NULL,
      'content_bottom' => NULL,
      'footer' => NULL,
      'footer_2' => NULL,
      'header_contained' => NULL,
      'section_1' => NULL,
      'section_2' => NULL,
      'section_3' => NULL,
      'footer_2a' => NULL,
      'footer_2b' => NULL,
      'aside' => NULL,
      'aside_hidden_xs' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fcd44812-9926-482b-8052-9ad5d0eb985e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-68c9f4c7-05d8-4e24-8e7f-d050027eb933';
    $pane->panel = 'aside';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_servicios_relacionados';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '68c9f4c7-05d8-4e24-8e7f-d050027eb933';
    $display->content['new-68c9f4c7-05d8-4e24-8e7f-d050027eb933'] = $pane;
    $display->panels['aside'][0] = 'new-68c9f4c7-05d8-4e24-8e7f-d050027eb933';
    $pane = new stdClass();
    $pane->pid = 'new-ee47191a-7b9f-443a-bf79-a61348539857';
    $pane->panel = 'aside';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_download';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ee47191a-7b9f-443a-bf79-a61348539857';
    $display->content['new-ee47191a-7b9f-443a-bf79-a61348539857'] = $pane;
    $display->panels['aside'][1] = 'new-ee47191a-7b9f-443a-bf79-a61348539857';
    $pane = new stdClass();
    $pane->pid = 'new-9dbb4f51-13cf-40de-9068-92d5ed18dcea';
    $pane->panel = 'aside_hidden_xs';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acciones';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9dbb4f51-13cf-40de-9068-92d5ed18dcea';
    $display->content['new-9dbb4f51-13cf-40de-9068-92d5ed18dcea'] = $pane;
    $display->panels['aside_hidden_xs'][0] = 'new-9dbb4f51-13cf-40de-9068-92d5ed18dcea';
    $pane = new stdClass();
    $pane->pid = 'new-0499635a-e6cc-45ff-b8ad-f1cb25159669';
    $pane->panel = 'content';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0499635a-e6cc-45ff-b8ad-f1cb25159669';
    $display->content['new-0499635a-e6cc-45ff-b8ad-f1cb25159669'] = $pane;
    $display->panels['content'][0] = 'new-0499635a-e6cc-45ff-b8ad-f1cb25159669';
    $pane = new stdClass();
    $pane->pid = 'new-1a629c7c-5ab8-4c47-8455-a75b70543dcc';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_dirigido';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1a629c7c-5ab8-4c47-8455-a75b70543dcc';
    $display->content['new-1a629c7c-5ab8-4c47-8455-a75b70543dcc'] = $pane;
    $display->panels['content'][1] = 'new-1a629c7c-5ab8-4c47-8455-a75b70543dcc';
    $pane = new stdClass();
    $pane->pid = 'new-12ca08cd-01ae-4b5c-b470-17c9c936c010';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_requisitos_collection';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '12ca08cd-01ae-4b5c-b470-17c9c936c010';
    $display->content['new-12ca08cd-01ae-4b5c-b470-17c9c936c010'] = $pane;
    $display->panels['content'][2] = 'new-12ca08cd-01ae-4b5c-b470-17c9c936c010';
    $pane = new stdClass();
    $pane->pid = 'new-d00f666a-619e-4ad6-b2f7-1dd13567ecb7';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_pasos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd00f666a-619e-4ad6-b2f7-1dd13567ecb7';
    $display->content['new-d00f666a-619e-4ad6-b2f7-1dd13567ecb7'] = $pane;
    $display->panels['content'][3] = 'new-d00f666a-619e-4ad6-b2f7-1dd13567ecb7';
    $pane = new stdClass();
    $pane->pid = 'new-65fb41bc-d745-4ff6-b196-dd19578aea93';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_duracion';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => 'Editar',
        'delete' => 'Eliminar',
        'add' => 'Agregar',
        'description' => 1,
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '65fb41bc-d745-4ff6-b196-dd19578aea93';
    $display->content['new-65fb41bc-d745-4ff6-b196-dd19578aea93'] = $pane;
    $display->panels['content'][4] = 'new-65fb41bc-d745-4ff6-b196-dd19578aea93';
    $pane = new stdClass();
    $pane->pid = 'new-f2a07143-49be-4411-ae0f-8a24a6d2dcaa';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_costo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'f2a07143-49be-4411-ae0f-8a24a6d2dcaa';
    $display->content['new-f2a07143-49be-4411-ae0f-8a24a6d2dcaa'] = $pane;
    $display->panels['content'][5] = 'new-f2a07143-49be-4411-ae0f-8a24a6d2dcaa';
    $pane = new stdClass();
    $pane->pid = 'new-91ab36ab-3faa-4f7c-bfdb-b2abb3eb33a1';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_vigencia';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '91ab36ab-3faa-4f7c-bfdb-b2abb3eb33a1';
    $display->content['new-91ab36ab-3faa-4f7c-bfdb-b2abb3eb33a1'] = $pane;
    $display->panels['content'][6] = 'new-91ab36ab-3faa-4f7c-bfdb-b2abb3eb33a1';
    $pane = new stdClass();
    $pane->pid = 'new-f2ff0416-22e4-493d-9f3c-4c90e26703ba';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_acciones';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'f2ff0416-22e4-493d-9f3c-4c90e26703ba';
    $display->content['new-f2ff0416-22e4-493d-9f3c-4c90e26703ba'] = $pane;
    $display->panels['content'][7] = 'new-f2ff0416-22e4-493d-9f3c-4c90e26703ba';
    $pane = new stdClass();
    $pane->pid = 'new-b2625b34-8c45-4942-8261-1ef124a89f19';
    $pane->panel = 'content';
    $pane->type = 'separador';
    $pane->subtype = 'separador';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'linea' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'b2625b34-8c45-4942-8261-1ef124a89f19';
    $display->content['new-b2625b34-8c45-4942-8261-1ef124a89f19'] = $pane;
    $display->panels['content'][8] = 'new-b2625b34-8c45-4942-8261-1ef124a89f19';
    $pane = new stdClass();
    $pane->pid = 'new-48765f44-732e-4810-8f99-3dcc3d251432';
    $pane->panel = 'content';
    $pane->type = 'redes_sociales';
    $pane->subtype = 'redes_sociales';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'titulo' => 'Compartir en<br>redes sociales',
      'tipo_widget' => 'share',
      'tipo_widget_timeline' => 'facebook',
      'fb_page_url' => '',
      'fb_altura' => '70',
      'fb_mostrar_post' => 1,
      'fb_mostrar_fotos_amigos' => 1,
      'fb_ocultar_portada' => 0,
      'tw_widget_id' => '',
      'tw_screen_name' => '',
      'widget_share_alineacion' => 'izquierda',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '48765f44-732e-4810-8f99-3dcc3d251432';
    $display->content['new-48765f44-732e-4810-8f99-3dcc3d251432'] = $pane;
    $display->panels['content'][9] = 'new-48765f44-732e-4810-8f99-3dcc3d251432';
    $pane = new stdClass();
    $pane->pid = 'new-f7d10b2f-19b7-4cc9-9e5b-3e1788511a4d';
    $pane->panel = 'content_bottom';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'cantidad_links' => '3',
      'tipo_de_listado' => 'relacionados',
      'tipos_de_contenido' => 'tramite',
      'formato_de_listado' => 'argentinagobar_bloques_listado_con_imagen',
      'titulo' => 'Relacionados',
      'icono' => 'glyphicon-paperclip',
      'tipo_noticia' => FALSE,
      'tipo_tramite' => array(),
      'orientacion_de_listado' => 'horizontal',
      'todos_los_items' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f7d10b2f-19b7-4cc9-9e5b-3e1788511a4d';
    $display->content['new-f7d10b2f-19b7-4cc9-9e5b-3e1788511a4d'] = $pane;
    $display->panels['content_bottom'][0] = 'new-f7d10b2f-19b7-4cc9-9e5b-3e1788511a4d';
    $pane = new stdClass();
    $pane->pid = 'new-69836f8f-fc82-46b7-a84b-a0799d08abd5';
    $pane->panel = 'footer';
    $pane->type = 'rate_widget';
    $pane->subtype = 'rate_widget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => '1',
      'widget_name' => '3',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '69836f8f-fc82-46b7-a84b-a0799d08abd5';
    $display->content['new-69836f8f-fc82-46b7-a84b-a0799d08abd5'] = $pane;
    $display->panels['footer'][0] = 'new-69836f8f-fc82-46b7-a84b-a0799d08abd5';
    $pane = new stdClass();
    $pane->pid = 'new-f5d29fab-fc9b-49d4-8161-7e1b71a1265e';
    $pane->panel = 'header_contained';
    $pane->type = 'imagen_destacada';
    $pane->subtype = 'imagen_destacada';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'imagen_destacada' => NULL,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f5d29fab-fc9b-49d4-8161-7e1b71a1265e';
    $display->content['new-f5d29fab-fc9b-49d4-8161-7e1b71a1265e'] = $pane;
    $display->panels['header_contained'][0] = 'new-f5d29fab-fc9b-49d4-8161-7e1b71a1265e';
    $pane = new stdClass();
    $pane->pid = 'new-5066c08b-595a-4275-bf92-c2f4eb62ae59';
    $pane->panel = 'header_contained';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5066c08b-595a-4275-bf92-c2f4eb62ae59';
    $display->content['new-5066c08b-595a-4275-bf92-c2f4eb62ae59'] = $pane;
    $display->panels['header_contained'][1] = 'new-5066c08b-595a-4275-bf92-c2f4eb62ae59';
    $pane = new stdClass();
    $pane->pid = 'new-f830ed86-a2e1-4b7f-bb65-d69f69a5554c';
    $pane->panel = 'header_full';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f830ed86-a2e1-4b7f-bb65-d69f69a5554c';
    $display->content['new-f830ed86-a2e1-4b7f-bb65-d69f69a5554c'] = $pane;
    $display->panels['header_full'][0] = 'new-f830ed86-a2e1-4b7f-bb65-d69f69a5554c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__tramite'] = $handler;

  return $export;
}
