<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Encabezado Migracion'),
  'description' => t(''),
  'category' => t('Argentina'),
  'render callback' => 'argentinagobar_migtram_imagen_destacada_render',
  'admin info' => 'argentinagobar_migtram_imagen_destacada_admin_info',
  'defaults' => array(
    'imagen_destacada' =>   NULL,
  )
);

/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_migtram_imagen_destacada_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = t('Imagen dest migrar');
    $block->content = t('Imagen destacada migración.');
    return $block;
  }
}

function argentinagobar_migtram_imagen_destacada_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  $node = node_load(arg(1));
  $block->content = theme(
      'argentinagobar_migtram_imagen_destacada_argentinagobar_migtram', 
        array(
          'campos' => argentinagobar_migtram_obtenerData($node),
          'breadcrumb' => theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb()))
        )
  );
  return $block;
}

function argentinagobar_migtram_obtenerData($node){
  $campos = array();
  $campos['titulo'] = $node->title;
  $costo = field_get_items('node', $node, 'field_migtram_costo', NULL);

  $campos['costo'] = $costo[0]['summary'];
  $acciones = field_get_items('node', $node, 'field_migtram_acciones', NULL);
  $campos['acciones'] = $acciones[0]['value'];
  
  return $campos;
}