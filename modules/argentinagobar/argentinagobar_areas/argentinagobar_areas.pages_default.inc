<?php
/**
 * @file
 * argentinagobar_areas.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function argentinagobar_areas_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__area';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Área',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'area',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'area' => 'area',
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
  $display->layout = 'pagina';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'body-middle' => NULL,
      'full' => NULL,
      'body-left' => NULL,
      'body-right' => NULL,
      'header_full' => NULL,
      'header_left' => NULL,
      'header_right' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'content_bottom' => NULL,
      'footer_2' => NULL,
      'section_1' => NULL,
      'section_2' => NULL,
      'section_3' => NULL,
      'header_contained' => NULL,
      'navegacion_atajos' => NULL,
      'footer_2a' => NULL,
      'footer_2b' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '511fcd63-a745-4c73-af8e-0dbc7679c8e5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8da57751-580e-42a4-aada-0cb70a470b31';
    $pane->panel = 'content';
    $pane->type = 'redes_sociales';
    $pane->subtype = 'redes_sociales';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'titulo' => 'Compartir',
      'tipo_widget' => 'share',
      'tipo_widget_timeline' => 'facebook',
      'fb_page_url' => 'https://www.facebook.com/facebook',
      'fb_altura' => '500',
      'fb_mostrar_post' => 1,
      'fb_mostrar_fotos_amigos' => 1,
      'fb_ocultar_portada' => 0,
      'tw_widget_id' => '',
      'tw_screen_name' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'widget_share_alineacion' => 'centrado',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8da57751-580e-42a4-aada-0cb70a470b31';
    $display->content['new-8da57751-580e-42a4-aada-0cb70a470b31'] = $pane;
    $display->panels['content'][0] = 'new-8da57751-580e-42a4-aada-0cb70a470b31';
    $pane = new stdClass();
    $pane->pid = 'new-7e40d6c6-a685-4bbb-9c79-8a1a550884f6';
    $pane->panel = 'content';
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
    $pane->uuid = '7e40d6c6-a685-4bbb-9c79-8a1a550884f6';
    $display->content['new-7e40d6c6-a685-4bbb-9c79-8a1a550884f6'] = $pane;
    $display->panels['content'][1] = 'new-7e40d6c6-a685-4bbb-9c79-8a1a550884f6';
    $pane = new stdClass();
    $pane->pid = 'new-d84f2e6f-93fc-4521-9a79-9382140003b7';
    $pane->panel = 'content';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'sobreescribir' => 0,
      'cuerpo_o_resumen' => 'body',
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
    $pane->uuid = 'd84f2e6f-93fc-4521-9a79-9382140003b7';
    $display->content['new-d84f2e6f-93fc-4521-9a79-9382140003b7'] = $pane;
    $display->panels['content'][2] = 'new-d84f2e6f-93fc-4521-9a79-9382140003b7';
    $pane = new stdClass();
    $pane->pid = 'new-01107345-9016-4414-a209-44d66553f703';
    $pane->panel = 'content_bottom';
    $pane->type = 'campo';
    $pane->subtype = 'campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'links_relacionados',
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
    $pane->uuid = '01107345-9016-4414-a209-44d66553f703';
    $display->content['new-01107345-9016-4414-a209-44d66553f703'] = $pane;
    $display->panels['content_bottom'][0] = 'new-01107345-9016-4414-a209-44d66553f703';
    $pane = new stdClass();
    $pane->pid = 'new-3ee943a4-ec58-41cc-a1ce-5632aa7dc5b1';
    $pane->panel = 'footer';
    $pane->type = 'area_estructura';
    $pane->subtype = 'area_estructura';
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
    $pane->uuid = '3ee943a4-ec58-41cc-a1ce-5632aa7dc5b1';
    $display->content['new-3ee943a4-ec58-41cc-a1ce-5632aa7dc5b1'] = $pane;
    $display->panels['footer'][0] = 'new-3ee943a4-ec58-41cc-a1ce-5632aa7dc5b1';
    $pane = new stdClass();
    $pane->pid = 'new-4fe6188a-4d43-4fb0-8631-5c97dd01578d';
    $pane->panel = 'footer_2';
    $pane->type = 'area_contacto';
    $pane->subtype = 'area_contacto';
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
    $pane->uuid = '4fe6188a-4d43-4fb0-8631-5c97dd01578d';
    $display->content['new-4fe6188a-4d43-4fb0-8631-5c97dd01578d'] = $pane;
    $display->panels['footer_2'][0] = 'new-4fe6188a-4d43-4fb0-8631-5c97dd01578d';
    $pane = new stdClass();
    $pane->pid = 'new-59fa82a7-1a86-402e-9fdf-50568db273dc';
    $pane->panel = 'header_full';
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
    $pane->uuid = '59fa82a7-1a86-402e-9fdf-50568db273dc';
    $display->content['new-59fa82a7-1a86-402e-9fdf-50568db273dc'] = $pane;
    $display->panels['header_full'][0] = 'new-59fa82a7-1a86-402e-9fdf-50568db273dc';
    $pane = new stdClass();
    $pane->pid = 'new-aaf236c7-995c-471f-89b5-514da6aed537';
    $pane->panel = 'section_1';
    $pane->type = 'campo';
    $pane->subtype = 'campo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'campo' => 'paginas_relacionadas',
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
    $pane->uuid = 'aaf236c7-995c-471f-89b5-514da6aed537';
    $display->content['new-aaf236c7-995c-471f-89b5-514da6aed537'] = $pane;
    $display->panels['section_1'][0] = 'new-aaf236c7-995c-471f-89b5-514da6aed537';
    $pane = new stdClass();
    $pane->pid = 'new-324fd34a-e1cb-402e-90b2-758bcf29e4fe';
    $pane->panel = 'section_2';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'cantidad_links' => '10',
      'tipo_de_listado' => 'relacionados',
      'tipos_de_contenido' => 'noticia',
      'formato_de_listado' => 'FormatoListadoTarjeta',
      'titulo' => 'Novedades',
      'icono' => 'glyphicon-paperclip',
      'tipo_noticia' => FALSE,
      'tipo_tramite' => array(),
      'orientacion_de_listado' => 'horizontal',
      'todos_los_items' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'destacar_primer_fila' => 0,
      'mostrar_fecha' => 0,
      'mostrar_resumen' => 0,
      'mostrar_imagen' => 0,
      'contenido_custom' => array(),
      'ga' => array(),
      'all_ga' => array(),
      'entity_types' => 'ListadoNodes',
      'taxonomy_vocabularies' => '13',
      'order_by' => 'fecha',
      'order_type' => 'desc',
      'paginador' => 0,
      'filtro' => 0,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '324fd34a-e1cb-402e-90b2-758bcf29e4fe';
    $display->content['new-324fd34a-e1cb-402e-90b2-758bcf29e4fe'] = $pane;
    $display->panels['section_2'][0] = 'new-324fd34a-e1cb-402e-90b2-758bcf29e4fe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__area'] = $handler;

  return $export;
}
