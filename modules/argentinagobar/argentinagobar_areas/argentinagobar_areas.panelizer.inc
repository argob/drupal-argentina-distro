<?php
/**
 * @file
 * argentinagobar_areas.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function argentinagobar_areas_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:area:default';
  $panelizer->title = 'Predeterminado';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'area';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'pagina';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header_full' => NULL,
      'header_left' => NULL,
      'header_right' => NULL,
      'content' => NULL,
      'content_bottom' => NULL,
      'section_1' => NULL,
      'section_2' => NULL,
      'section_3' => NULL,
      'footer' => NULL,
      'footer_2' => NULL,
      'header_contained' => NULL,
      'footer_2a' => NULL,
      'footer_2b' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '135102af-5613-4116-885b-c4c50f9f74ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-85d0aa6a-35a3-4504-8835-335a49021478';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '85d0aa6a-35a3-4504-8835-335a49021478';
    $display->content['new-85d0aa6a-35a3-4504-8835-335a49021478'] = $pane;
    $display->panels['content'][0] = 'new-85d0aa6a-35a3-4504-8835-335a49021478';
    $pane = new stdClass();
    $pane->pid = 'new-a6378c48-1533-4a20-a99e-68a9946e11e1';
    $pane->panel = 'content_bottom';
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
    $pane->uuid = 'a6378c48-1533-4a20-a99e-68a9946e11e1';
    $display->content['new-a6378c48-1533-4a20-a99e-68a9946e11e1'] = $pane;
    $display->panels['content_bottom'][0] = 'new-a6378c48-1533-4a20-a99e-68a9946e11e1';
    $pane = new stdClass();
    $pane->pid = 'new-f7766aca-c9be-466a-b7d3-40c39318f2cb';
    $pane->panel = 'footer';
    $pane->type = 'area_estructura';
    $pane->subtype = 'area_estructura';
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
    $pane->uuid = 'f7766aca-c9be-466a-b7d3-40c39318f2cb';
    $display->content['new-f7766aca-c9be-466a-b7d3-40c39318f2cb'] = $pane;
    $display->panels['footer'][0] = 'new-f7766aca-c9be-466a-b7d3-40c39318f2cb';
    $pane = new stdClass();
    $pane->pid = 'new-e97265fd-b7b2-42d6-b4ca-490ae6364fa8';
    $pane->panel = 'footer_2a';
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
    $pane->uuid = 'e97265fd-b7b2-42d6-b4ca-490ae6364fa8';
    $display->content['new-e97265fd-b7b2-42d6-b4ca-490ae6364fa8'] = $pane;
    $display->panels['footer_2a'][0] = 'new-e97265fd-b7b2-42d6-b4ca-490ae6364fa8';
    $pane = new stdClass();
    $pane->pid = 'new-ef3cb5b9-a36c-466b-a516-1d13132a3309';
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
    $pane->uuid = 'ef3cb5b9-a36c-466b-a516-1d13132a3309';
    $display->content['new-ef3cb5b9-a36c-466b-a516-1d13132a3309'] = $pane;
    $display->panels['header_full'][0] = 'new-ef3cb5b9-a36c-466b-a516-1d13132a3309';
    $pane = new stdClass();
    $pane->pid = 'new-bb411520-16f2-4698-9f23-f889f458369d';
    $pane->panel = 'header_left';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bb411520-16f2-4698-9f23-f889f458369d';
    $display->content['new-bb411520-16f2-4698-9f23-f889f458369d'] = $pane;
    $display->panels['header_left'][0] = 'new-bb411520-16f2-4698-9f23-f889f458369d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:area:default'] = $panelizer;

  return $export;
}
