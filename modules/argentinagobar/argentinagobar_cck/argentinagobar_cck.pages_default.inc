<?php
/**
 * @file
 * argentinagobar_cck.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function argentinagobar_cck_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'noticias';
  $page->task = 'page';
  $page->admin_title = 'Noticias';
  $page->admin_description = '';
  $page->path = 'node/%node/noticias';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Contenido: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_noticias__panel_context_81a1937c-3914-41c9-a735-d0691c836918';
  $handler->task = 'page';
  $handler->subtask = 'noticias';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Listado de Noticias por Área',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'pagina';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
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
      'navegacion_atajos' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '14dc2ddb-7ed4-4dd0-9670-975239604f4a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-19927f19-53d3-45dd-ab1f-7ee082dba52d';
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
    $pane->uuid = '19927f19-53d3-45dd-ab1f-7ee082dba52d';
    $display->content['new-19927f19-53d3-45dd-ab1f-7ee082dba52d'] = $pane;
    $display->panels['header_contained'][0] = 'new-19927f19-53d3-45dd-ab1f-7ee082dba52d';
    $pane = new stdClass();
    $pane->pid = 'new-5d5fda6d-3841-4de1-998b-15d6267c7f60';
    $pane->panel = 'header_contained';
    $pane->type = 'titulo_listado_noticias';
    $pane->subtype = 'titulo_listado_noticias';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'linea' => FALSE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5d5fda6d-3841-4de1-998b-15d6267c7f60';
    $display->content['new-5d5fda6d-3841-4de1-998b-15d6267c7f60'] = $pane;
    $display->panels['header_contained'][1] = 'new-5d5fda6d-3841-4de1-998b-15d6267c7f60';
    $pane = new stdClass();
    $pane->pid = 'new-57cbf41f-aee7-4aa5-9dc8-71456492bf73';
    $pane->panel = 'header_contained';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'destacar_primer_fila' => 0,
      'cantidad_links' => '400',
      'tipo_de_listado' => 'relacionados',
      'contenido_custom' => array(),
      'entity_types' => 'ListadoNodes',
      'taxonomy_vocabularies' => '4',
      'tipos_de_contenido' => 'noticia',
      'formato_de_listado' => 'FormatoListadoTarjeta',
      'titulo' => '',
      'icono' => 'iconarg-mod-lupa',
      'tipo_noticia' => FALSE,
      'tipo_tramite' => array(),
      'orientacion_de_listado' => 'horizontal',
      'todos_los_items' => 0,
      'paginador' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'mostrar_fecha' => 1,
      'mostrar_resumen' => 1,
      'mostrar_imagen' => 1,
      'filtro' => 0,
      'ga' => array(),
      'all_ga' => array(),
      'order_by' => 'fecha',
      'order_type' => 'desc',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '57cbf41f-aee7-4aa5-9dc8-71456492bf73';
    $display->content['new-57cbf41f-aee7-4aa5-9dc8-71456492bf73'] = $pane;
    $display->panels['header_contained'][2] = 'new-57cbf41f-aee7-4aa5-9dc8-71456492bf73';
    $pane = new stdClass();
    $pane->pid = 'new-a7280c16-5cb7-4bd5-b8fa-0fe298d51e92';
    $pane->panel = 'header_contained';
    $pane->type = 'atajos';
    $pane->subtype = 'atajos';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'atajos' => array(
        1 => array(
          'titulo' => 'VER NOTICIAS ANTERIORES',
          'texto' => array(
            'value' => '',
            'format' => 'filtered_html',
          ),
          'link_interno' => FALSE,
          'link_externo' => 'http://www.mininterior.gov.ar/prensa/buscador.php',
          'imagen' => array(
            'fid' => 0,
            'upload_button' => 'Subir al servidor',
            'remove_button' => 'Eliminar',
            'upload' => '',
          ),
          'icono' => 'sin_icono',
          'color_icono' => 'text-primary',
          'color_fondo' => 'bg-primary',
          'color_boton' => 'btn-primary',
        ),
      ),
      'cantidadAtajos' => 1,
      'opciones' => array(
        'formato' => 'FormatoAtajoBoton',
        'columnas' => '1',
        'destacar' => 0,
      ),
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
    $pane->uuid = 'a7280c16-5cb7-4bd5-b8fa-0fe298d51e92';
    $display->content['new-a7280c16-5cb7-4bd5-b8fa-0fe298d51e92'] = $pane;
    $display->panels['header_contained'][3] = 'new-a7280c16-5cb7-4bd5-b8fa-0fe298d51e92';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-57cbf41f-aee7-4aa5-9dc8-71456492bf73';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['noticias'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'tramites';
  $page->task = 'page';
  $page->admin_title = 'Servicios';
  $page->admin_description = '';
  $page->path = 'servicios';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_tramites__default';
  $handler->task = 'page';
  $handler->subtask = 'tramites';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'default',
    'access' => array(
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
  $display->title = '';
  $display->uuid = '567acbe9-f165-4088-abf4-d057a8e0ba0e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2107616f-0941-450a-97d2-bdd8ee4ec9c1';
    $pane->panel = 'content_bottom';
    $pane->type = 'listado';
    $pane->subtype = 'listado';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'cantidad_links' => '16',
      'tipo_de_listado' => 'recientes',
      'tipos_de_contenido' => 'argentinagobar_migtram',
      'formato_de_listado' => 'argentinagobar_bloques_listado_tarjeta_simple',
      'titulo' => '',
      'icono' => 'glyphicon-star',
      'tipo_noticia' => FALSE,
      'tipo_tramite' => array(),
      'orientacion_de_listado' => 'horizontal',
      'todos_los_items' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'contenido_custom' => array(),
      'paginador' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2107616f-0941-450a-97d2-bdd8ee4ec9c1';
    $display->content['new-2107616f-0941-450a-97d2-bdd8ee4ec9c1'] = $pane;
    $display->panels['content_bottom'][0] = 'new-2107616f-0941-450a-97d2-bdd8ee4ec9c1';
    $pane = new stdClass();
    $pane->pid = 'new-8fd74cad-4d9e-4442-9d13-3bdc3d208e3c';
    $pane->panel = 'header_full';
    $pane->type = 'block';
    $pane->subtype = 'argentinagobar_search-ApacheSolrInput';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '8fd74cad-4d9e-4442-9d13-3bdc3d208e3c';
    $display->content['new-8fd74cad-4d9e-4442-9d13-3bdc3d208e3c'] = $pane;
    $display->panels['header_full'][0] = 'new-8fd74cad-4d9e-4442-9d13-3bdc3d208e3c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tramites'] = $page;

  return $pages;

}
