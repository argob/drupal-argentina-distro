<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Reporte'),
  'description' => t('Formulario de reporte de errores para nodos.'),
  'category' => t('Argentina.gob.ar'),
  'admin info' => 'argentinagobar_bloques_reporte_admin_info',
  #'edit form' => 'argentinagobar_bloques_reporte_edit_form',
  'render callback' => 'argentinagobar_bloques_reporte_render',
  'defaults' => array(
    'tipo' => 'success',
    'texto' => NULL,
  )
);

/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_bloques_reporte_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Alerta');
    $block->content = t('Formulario de reporte de un nodo');
    return $block;
  }
}

/**
* 'Edit form' callback for the content type.
*/
function argentinagobar_bloques_reporte_edit_form($form, &$form_state) {
  return $form;
}

/**
* The submit form stores the data in $conf.
*/
function argentinagobar_bloques_reporte_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function argentinagobar_bloques_reporte_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = '';
  $block->content = drupal_get_form('argentinagobar_bloques_reporte');
  return $block;
}