<?php
/**
 * @file
 * argentinagobar_libros.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function argentinagobar_libros_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:book:default';
  $panelizer->title = 'Predeterminado';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'book';
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
  $display->layout = 'pagina-navegacion';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'header_full' => NULL,
      'header_contained' => NULL,
      'header_left' => NULL,
      'header_right' => NULL,
      'content' => NULL,
      'content_bottom' => NULL,
      'section_1' => NULL,
      'section_2' => NULL,
      'section_3' => NULL,
      'footer' => NULL,
      'footer_2' => NULL,
      'footer_2a' => NULL,
      'footer_2b' => NULL,
      'aside' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'cd374599-db45-4fa7-963b-5c5829b4061d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0bdd1d01-ca1b-4001-a7b9-cc9efa18eaa1';
    $pane->panel = 'aside';
    $pane->type = 'node_book_nav';
    $pane->subtype = 'node_book_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
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
    $pane->uuid = '0bdd1d01-ca1b-4001-a7b9-cc9efa18eaa1';
    $display->content['new-0bdd1d01-ca1b-4001-a7b9-cc9efa18eaa1'] = $pane;
    $display->panels['aside'][0] = 'new-0bdd1d01-ca1b-4001-a7b9-cc9efa18eaa1';
    $pane = new stdClass();
    $pane->pid = 'new-2c8c097e-8550-42c8-9db9-1f6bf0fbfe16';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2c8c097e-8550-42c8-9db9-1f6bf0fbfe16';
    $display->content['new-2c8c097e-8550-42c8-9db9-1f6bf0fbfe16'] = $pane;
    $display->panels['content'][0] = 'new-2c8c097e-8550-42c8-9db9-1f6bf0fbfe16';
    $pane = new stdClass();
    $pane->pid = 'new-b814d7d8-a26b-47af-b755-a60b46f9849b';
    $pane->panel = 'content';
    $pane->type = 'titulo';
    $pane->subtype = 'titulo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'tag' => 'h1',
      'texto' => '',
      'sobreescribir_titulo' => 0,
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
    $pane->uuid = 'b814d7d8-a26b-47af-b755-a60b46f9849b';
    $display->content['new-b814d7d8-a26b-47af-b755-a60b46f9849b'] = $pane;
    $display->panels['content'][1] = 'new-b814d7d8-a26b-47af-b755-a60b46f9849b';
    $pane = new stdClass();
    $pane->pid = 'new-f6b97594-cb60-422d-b4bf-fd4eb5b4f934';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f6b97594-cb60-422d-b4bf-fd4eb5b4f934';
    $display->content['new-f6b97594-cb60-422d-b4bf-fd4eb5b4f934'] = $pane;
    $display->panels['content'][2] = 'new-f6b97594-cb60-422d-b4bf-fd4eb5b4f934';
    $pane = new stdClass();
    $pane->pid = 'new-e67d6664-223e-44cf-b1f8-d6e2e9f500bf';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e67d6664-223e-44cf-b1f8-d6e2e9f500bf';
    $display->content['new-e67d6664-223e-44cf-b1f8-d6e2e9f500bf'] = $pane;
    $display->panels['content'][3] = 'new-e67d6664-223e-44cf-b1f8-d6e2e9f500bf';
    $pane = new stdClass();
    $pane->pid = 'new-2c717df4-daa4-4c8a-9d08-c6b684ec968a';
    $pane->panel = 'content';
    $pane->type = 'texto';
    $pane->subtype = 'texto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'destacado' => 0,
      'texto' => array(
        'value' => '',
        'format' => 'filtered_html',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '2c717df4-daa4-4c8a-9d08-c6b684ec968a';
    $display->content['new-2c717df4-daa4-4c8a-9d08-c6b684ec968a'] = $pane;
    $display->panels['content'][4] = 'new-2c717df4-daa4-4c8a-9d08-c6b684ec968a';
    $pane = new stdClass();
    $pane->pid = 'new-03ae2137-a9fa-4015-ba41-b9958ccc3fc8';
    $pane->panel = 'content';
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
      'context' => 'panelizer',
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
    $pane->uuid = '03ae2137-a9fa-4015-ba41-b9958ccc3fc8';
    $display->content['new-03ae2137-a9fa-4015-ba41-b9958ccc3fc8'] = $pane;
    $display->panels['content'][5] = 'new-03ae2137-a9fa-4015-ba41-b9958ccc3fc8';
    $pane = new stdClass();
    $pane->pid = 'new-1bca4480-e2d7-4928-88f1-7ace8b3b665c';
    $pane->panel = 'content';
    $pane->type = 'token';
    $pane->subtype = 'node:field-creditos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'panelizer',
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
    $pane->uuid = '1bca4480-e2d7-4928-88f1-7ace8b3b665c';
    $display->content['new-1bca4480-e2d7-4928-88f1-7ace8b3b665c'] = $pane;
    $display->panels['content'][6] = 'new-1bca4480-e2d7-4928-88f1-7ace8b3b665c';
    $pane = new stdClass();
    $pane->pid = 'new-13460206-3296-4732-9a64-ecf919aae2e8';
    $pane->panel = 'header_contained';
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
    $pane->uuid = '13460206-3296-4732-9a64-ecf919aae2e8';
    $display->content['new-13460206-3296-4732-9a64-ecf919aae2e8'] = $pane;
    $display->panels['header_contained'][0] = 'new-13460206-3296-4732-9a64-ecf919aae2e8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-13460206-3296-4732-9a64-ecf919aae2e8';
  $panelizer->display = $display;
  $export['node:book:default'] = $panelizer;

  return $export;
}
