<?php
function argentinagobar_bloques_theme($existing, $type, $theme, $path) {
  return array(

    /*
     * ALERTA
    */
    'argentinagobar_bloques_alerta' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_alerta'
    ),
    /*
     * CAMPO
    */
    'argentinagobar_bloques_campo_acciones' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_acciones'
    ),
    'argentinagobar_bloques_campo_categoria_noticia' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_categoria_noticia'
    ),
    'argentinagobar_bloques_campo_costo' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_costo'
    ),
    'argentinagobar_bloques_campo_servicios_relacionados' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_servicios_relacionados'
    ),
    'argentinagobar_bloques_campo_acciones' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_campo_acciones'
    ),
      'argentinagobar_bloques_campo_vigencia' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_vigencia'
    ),
    'argentinagobar_bloques_campo_links_relacionados' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_links_relacionados'
    ),
    'argentinagobar_bloques_campo_paginas_relacionadas' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_paginas_relacionadas'
    ),
    'argentinagobar_bloques_campo_requisitos' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_requisitos'
    ),
    'argentinagobar_bloques_campo_siglas_area' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_siglas_area'
    ),
    'argentinagobar_bloques_campo_tags' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_tags'
    ),
    'argentinagobar_bloques_campo_tipo_tramite' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_tipo_tramite'
    ),
    'argentinagobar_bloques_campo_creditos' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_creditos'
    ),
    'argentinagobar_bloques_campo_download' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_download'
    ),
    'argentinagobar_bloques_campo_store' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_store'
    ),
    'argentinagobar_bloques_campo_audio' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_audio'
    ),
    'argentinagobar_bloques_campo_audiencia' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_audiencia'
    ),
    'argentinagobar_bloques_campo_pasos' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_pasos'
    ),
    'argentinagobar_bloques_campo_duracion' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/campo',
      'template' => 'argentinagobar_bloques_campo_duracion'
    ),
    /*
     * GALERIA
    */
    'argentinagobar_bloques_galeria_imagenes_min' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/galeria',
      'template' => 'argentinagobar_bloques_galeria_imagenes_min'
    ),
    'argentinagobar_bloques_galeria_imagenes_min_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/galeria',
      'template' => 'argentinagobar_bloques_galeria_imagenes_min_item'
    ),
    /*
     * Listados
    */
    'argentinagobar_bloques_listado_tarjeta_simple_horizontal' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/tarjeta/simple',
      'template' => 'argentinagobar_bloques_listado_tarjeta_simple_horizontal'
    ),
    'argentinagobar_bloques_titulo_noticias' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/lista',
      'template' => 'argentinagobar_bloques_titulo_noticias'
    ),
    'argentinagobar_bloques_listado_tarjeta_simple_horizontal_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/tarjeta/simple',
      'template' => 'argentinagobar_bloques_listado_tarjeta_simple_horizontal_item'
    ),
    'argentinagobar_bloques_listado_tarjeta_simple_vertical' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/tarjeta/simple',
      'template' => 'argentinagobar_bloques_listado_tarjeta_simple_vertical'
    ),
    'argentinagobar_bloques_listado_tarjeta_simple_vertical_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/tarjeta/simple',
      'template' => 'argentinagobar_bloques_listado_tarjeta_simple_vertical_item'
    ),
    'argentinagobar_bloques_listado_tarjeta_con_imagen_horizontal' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/tarjeta/conImagen',
      'template' => 'argentinagobar_bloques_listado_tarjeta_con_imagen_horizontal'
    ),
    'argentinagobar_bloques_listado_tarjeta_con_imagen_horizontal_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/tarjeta/conImagen',
      'template' => 'argentinagobar_bloques_listado_tarjeta_con_imagen_horizontal_item'
    ),
    'argentinagobar_bloques_listado_tarjeta_con_imagen_vertical' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/tarjeta/conImagen',
      'template' => 'argentinagobar_bloques_listado_tarjeta_con_imagen_vertical'
    ),
    'argentinagobar_bloques_listado_tarjeta_con_imagen_vertical_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/tarjeta/conImagen',
      'template' => 'argentinagobar_bloques_listado_tarjeta_con_imagen_vertical_item'
    ),
    'argentinagobar_bloques_listado_lista_simple_horizontal' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/lista',
      'template' => 'argentinagobar_bloques_listado_lista_simple_horizontal'
    ),
    'argentinagobar_bloques_listado_lista_simple_horizontal_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/lista',
      'template' => 'argentinagobar_bloques_listado_lista_simple_horizontal_item'
    ),
    'argentinagobar_bloques_listado_lista_simple_vertical' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/lista',
      'template' => 'argentinagobar_bloques_listado_lista_simple_vertical'
    ),
    'argentinagobar_bloques_listado_lista_simple_vertical_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/lista',
      'template' => 'argentinagobar_bloques_listado_lista_simple_vertical_item'
    ),
    'argentinagobar_bloques_listado_persona_buscada_horizontal' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/persona_buscada',
      'template' => 'argentinagobar_bloques_listado_persona_buscada_horizontal'
    ),
    'argentinagobar_bloques_listado_persona_buscada_horizontal_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/persona_buscada',
      'template' => 'argentinagobar_bloques_listado_persona_buscada_horizontal_item'
    ),
    'argentinagobar_bloques_listado_vacio' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/listado/',
      'template' => 'argentinagobar_bloques_listado_vacio'
    ),
    /*
     * IMAGEN
    */
    'argentinagobar_bloques_imagen_destacada_area' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/imagen',
      'template' => 'argentinagobar_bloques_imagen_destacada_area'
    ),
    'argentinagobar_bloques_imagen_destacada_aplicacion' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/imagen',
      'template' => 'argentinagobar_bloques_imagen_destacada_aplicacion'
    ),
    'argentinagobar_bloques_imagen_destacada_noticia' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/imagen',
      'template' => 'argentinagobar_bloques_imagen_destacada_noticia'
    ),
    'argentinagobar_bloques_imagen_destacada_tramite' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/imagen',
      'template' => 'argentinagobar_bloques_imagen_destacada_tramite'
    ),
    /*
     * TITULO
    */
    'argentinagobar_bloques_titulo' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_titulo'
    ),
    /*
     * TEXTO
    */
    'argentinagobar_bloques_texto' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_texto'
    ),
    /*
     * SHORTCUT
    */
    'argentinagobar_bloques_shortcut_simple' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_simple'
    ),
    'argentinagobar_bloques_shortcut_simple_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_simple_item'
    ),
    'argentinagobar_bloques_shortcut_destacado' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_destacado'
    ),
    'argentinagobar_bloques_shortcut_destacado_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_destacado_item'
    ),
    'argentinagobar_bloques_shortcut_destacado_html' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_destacado_html'
    ),
    'argentinagobar_bloques_shortcut_destacado_html_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_destacado_html_item'
    ),
    'argentinagobar_bloques_shortcut_boton' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_boton'
    ),
    'argentinagobar_bloques_shortcut_boton_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_boton_item'
    ),
    'argentinagobar_bloques_shortcut_boton_con_descripcion' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_boton_con_descripcion'
    ),
    'argentinagobar_bloques_shortcut_boton_con_descripcion_item' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/shortcut',
      'template' => 'argentinagobar_bloques_shortcut_boton_con_descripcion_item'
    ),
    /*
     * SEPARADOR
    */
    'argentinagobar_bloques_separador' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_separador'
    ),
    'argentinagobar_bloques_separador_linea' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_separador_linea'
    ),
    /*
     * REDES
    */
    'argentinagobar_bloques_redes_sociales_compartir_izquierda' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/redes',
      'template' => 'argentinagobar_bloques_redes_sociales_compartir_izquierda'
    ),
    'argentinagobar_bloques_redes_sociales_compartir_centrado' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/redes',
      'template' => 'argentinagobar_bloques_redes_sociales_compartir_centrado'
    ),
    'argentinagobar_bloques_redes_sociales_timeline_facebook' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/redes',
      'template' => 'argentinagobar_bloques_redes_sociales_timeline_facebook'
    ),
    'argentinagobar_bloques_redes_sociales_timeline_twitter' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/redes',
      'template' => 'argentinagobar_bloques_redes_sociales_timeline_twitter'
    ),
    /*
     * AREA
    */
    'argentinagobar_bloques_area_estructura' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_area_estructura'
    ),
    'argentinagobar_bloques_area_contacto' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_area_contacto'
    ),
    /*
     * RATE_BUTTON
    */
    'argentinagobar_rate_button_service_rating' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_rate_button_service_rating'
    ),
    /*
     * DRUPAR - COMPONENTES - ATAJOS
    */
    'drupar_componentes_atajos_boton' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/atajos',
      'template' => 'drupar_componentes_atajos_boton'
    ),
    'drupar_componentes_atajos_simple' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/atajos',
      'template' => 'drupar_componentes_atajos_simple'
    ),
    'drupar_componentes_atajos_destacado_icono' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/atajos',
      'template' => 'drupar_componentes_atajos_destacado_icono'
    ),
    'drupar_componentes_atajos_destacado_imagen' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/atajos',
      'template' => 'drupar_componentes_atajos_destacado_imagen'
    ),
    'drupar_componentes_atajos_circular' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/atajos',
      'template' => 'drupar_componentes_atajos_circular'
    ),
    /*
     * DRUPAR - COMPONENTES
    */
    'drupar_componentes_panels_row' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'drupar_componentes_panels_row'
    ),
    'drupar_componentes_row' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'drupar_componentes_row'
    ),
    'argentinagobar_bloques_admin_info' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_admin_info'
    ),
    'drupar_componentes_nav_icons' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'drupar_componentes_nav_icons'
    ),
    'drupar_componentes_atajos_imagen' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates/atajos',
      'template' => 'drupar_componentes_atajos_imagen',
    ),
    /*
     * ADMIN
    */
    'argentinagobar_bloques_admin_info' => array(
      'path' => drupal_get_path('module', 'argentinagobar_bloques') . '/templates',
      'template' => 'argentinagobar_bloques_admin_info'
    ),
  );
}
