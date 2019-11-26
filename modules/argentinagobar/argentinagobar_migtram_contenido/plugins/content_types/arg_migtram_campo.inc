<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Campo Migracion'),
  'description' => t('Renderiza un campo del nodo'),
  'category' => t('Argentina'),
  'render callback' => 'argentinagobar_migtram_campo_render',
  'edit form' => 'argentinagobar_migtram_campo_edit_form',
  'admin info' => 'argentinagobar_migtram_campo_admin_info',
  'defaults' => array(
    'campo' => '',
  ),
);

/**
* 'admin info' callback for panel pane.
*/
function argentinagobar_migtram_campo_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : $conf['campo'];
    $block->content = $conf['campo'];
    return $block;
  }
}

/**
* 'Edit form' callback for the content type.
*/
function argentinagobar_migtram_campo_edit_form($form, &$form_state) {

  $form['campo'] = array(
    '#type' => 'select',
    '#title' => t('Campo'),
    '#required' => TRUE,
    '#options' => argentinagobar_migtram_array_campos(),
    '#default_value' => $form_state['conf']['campo'],
    '#description' => t('Campo a mostrar'),
  );
  
  return $form;
}

/**
* The submit form stores the data in $conf.
*/
function argentinagobar_migtram_campo_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function argentinagobar_migtram_campo_render($subtype, $conf, $panel_args, $context = NULL){
  $campo = argentinagobar_migtram_obtenerCampo(node_load(arg(1)), $conf['campo']);
  if(!empty($campo['contenido'])){
    $block = new stdClass();
    $block->title = '';
    $block->content = theme('argentinagobar_migtram_campo', 
      array('campo' => argentinagobar_migtram_obtenerCampo(node_load(arg(1)), $conf['campo']))
    );
    return $block;
  }
}

function argentinagobar_migtram_obtenerCampo($nodo, $tipo_campo) {
  foreach (argentinagobar_migtram_array_campos() as $campo => $value){
    if($campo == $tipo_campo){
      $campo = field_get_items('node', $nodo, 'field_migtram_'.$campo, NULL);
      $campo['contenido'] = $campo[0]['safe_value'];
      $campo['titulo'] = ($value=='Acciones' ? '' : $value);

      return $campo;
    }
  }
}