<?php
/**
 * @file
 * Code for the Migración de noticias.
 */

// Esta funcion era para setear una variable de la migración de noticias
function argentinagobar_migtram_img_form($form, &$form_state) {

 $form['imagen'] = array(
    '#type' => 'textfield', //you can find a list of available types in the form api
    '#title' => 'FID de la imagen para el módulo de noticias',
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => TRUE, //make this field required
    '#default_value' => variable_get('imagen_migracion_noticias'),
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Setear'),
  );
  
  return $form;
}

function argentinagobar_migtram_img_form_submit($form, &$form_state) {
  variable_set('imagen_migracion_noticias', $form_state['values']['imagen']);
}


?>