<?php

function consulta_incucai_organos($form, &$form_state){
  $form = array();

  $form['contenedor'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'documento' => 'contenedor'
    ),
  );

  $form['contenedor']['id_tipo_documento'] = array(
    '#type' => 'textfield',
    '#title' => t('Tipo de documento'),
    '#required' => TRUE,
    '#rules' => array('numeric', 'length[1, 1]'),

  );

  $form['contenedor']['docnro'] = array(
    '#type' => 'textfield',
    '#title' => t('Número de documento'),
    '#required' => TRUE,
    '#rules' => array('numeric', 'length[7, 9]'),

  );
  
  $form['contenedor']['fecha_nacimiento'] = array(
    '#type' => 'date',
    '#title' => t('Fecha de nacimiento'),
    '#date_format' => 'd-m-Y',
    '#required' => TRUE,
    '#default_value' =>  time(),
  );

  $form['contenedor']['submit'] = array(
    '#prefix' => '<div class="text-center">',
    '#suffix' => '</div>',
    '#type' => 'submit',
    '#value' => t('Consultar si sos donante de órganos'),
      '#attributes' => array(
        'class' => array(
        'btn',
        'btn-success',
        'btn-block',
        'btn-lg',
        ),
      ),
  );
  return $form;
}
