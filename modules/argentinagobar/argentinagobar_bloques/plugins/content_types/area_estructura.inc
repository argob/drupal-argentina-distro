<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Estructura de Área'),
  'description' => t('Muestra la estructura de un área.'),
  'category' => t('Argentina.gob.ar'),
  'render callback' => 'argentinagobar_bloques_area_estructura_render',
  'admin info' => 'argentinagobar_bloques_area_estructura_admin_info',
  'defaults' => array()
);

/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_bloques_area_estructura_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Estructura de área');
    $block->content = t('Estructura de área');
    return $block;
  }
}
function argentinagobar_bloques_area_estructura_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  if(esArea()) {
    $node = esRevisionDeNodo() ? node_load(arg(1), arg(3)) : node_load(arg(1));
    $autoridad = new stdClass;
    $autoridad->nombre = field_get_items('node', $node, 'field_autoridad_nombre', NULL);
    $autoridad->nombre = isset($autoridad->nombre[0]) ? $autoridad->nombre[0]['safe_value'] : '';
    $autoridad->foto = field_get_items('node', $node, 'field_autoridad_foto', NULL);
    $autoridad->foto = isset($autoridad->foto[0]) ? image_style_url('cuadrada',$autoridad->foto[0]['uri']) : '';
    $autoridad->cargo = field_get_items('node', $node, 'field_autoridad_cargo', NULL);
    $autoridad->cargo = isset($autoridad->cargo[0]) ? $autoridad->cargo[0]['safe_value'] : '';
    $autoridad->resumen = field_get_items('node', $node, 'field_autoridad_descripcion', NULL);
    $autoridad->resumen = isset($autoridad->resumen[0]) ? $autoridad->resumen[0]['safe_value'] : '';
    $nivelesJerarquicos = field_get_items('node', $node, 'field_niveles_jerarquicos', NULL);
    $block->content = !empty($autoridad) || !empty($nivelesJerarquicos) ? theme(
      'argentinagobar_bloques_area_estructura',
      array(
        'autoridad' => $autoridad,
        'nivelesJerarquicos' => isset($nivelesJerarquicos) && !empty($nivelesJerarquicos) ? obtenerDependencias($nivelesJerarquicos) : NULL,
      )
    ) : NULL;
  } else {
    $block->content = '';
  }

  return $block;
}
function obtenerDependencias($nivelesJerarquicos){
  foreach ($nivelesJerarquicos as $item) {
    $fieldCollectionItemNivelJerarquico = field_collection_item_revision_load($item['revision_id']);
    $nivelJerarquico = new stdClass;
    $nivelJerarquico->titulo = field_get_items('field_collection_item', $fieldCollectionItemNivelJerarquico, 'field_nivel_jerarquico_titulo');
    $nivelJerarquico->titulo = $nivelJerarquico->titulo[0]['safe_value'];
    $nivelJerarquico->subareas = obtenerSubareas(field_get_items('field_collection_item', $fieldCollectionItemNivelJerarquico, 'field_subarea'));
    $nivelJerarquico->subareas = array_chunk($nivelJerarquico->subareas, 4);
    $items[] = $nivelJerarquico;
  }
  return $items;
}

function obtenerSubareas($subareas){
  foreach ($subareas as $key => $field) {
    
    $fieldCollectionItemSubarea = field_collection_item_revision_load($field['revision_id']);

    $subarea = new stdClass;
    $subarea->referencia  = field_get_items('field_collection_item', $fieldCollectionItemSubarea, 'field_subarea_referencia');
    $subarea->referencia  = propertyExists($subarea->referencia[0], 'entity') ? $subarea->referencia[0]['entity']->vid : NULL;
    $subarea->nombre      = field_get_items('field_collection_item', $fieldCollectionItemSubarea, 'field_subarea_nombre');
    $subarea->nombre      = isset($subarea->nombre[0]) ? $subarea->nombre[0]['safe_value'] : $subarea->referencia[0]['entity']->title;
    $subarea->linkExterno = field_get_items('field_collection_item', $fieldCollectionItemSubarea, 'field_referencia_url');
    $subarea->linkExterno = isset($subarea->linkExterno[0]) ? $subarea->linkExterno[0]['url'] : NULL;

    $items[] = isset($subarea->referencia) || isset($subarea->linkExterno) ? l(
      theme(
        'argentinagobar_bloques_listado_tarjeta_simple_horizontal_item',
        array(
          'titulo' => $subarea->nombre,
        )
      ),
      isset ($subarea->referencia) ? 'node/' . $subarea->referencia : $subarea->linkExterno,
      array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('panel panel-default'),
        )
      )
    ) : theme(
      'html_tag',
      array(
        'element' => array(
          '#tag' => 'div',
          '#attributes' => array(
            'class' => 'panel panel-default panel-disabled'
          ),
          '#value' => theme(
            'argentinagobar_bloques_listado_tarjeta_simple_horizontal_item',
            array(
              'titulo' => $subarea->nombre,
            )
          ),
        ),
      )
    );
  }
  return $items;
}
