<?php

  function argentinagobar_ciudadano_digital_completar_datos($form, &$form_state){
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Completar',
      '#attributes' => array(
        'class' => array("btn", "btn-success", "m-b-0"),
      )
    );
    /*$form['#attached']['js'] = array(
      drupal_get_path('module', 'argentinagobar_ciudadano_digital') . '/js/autocompletarCiudadanoDigital.js',
    );*/
    return $form;
  }

  function argentinagobar_ciudadano_digital_completar_datos_submit($form, &$form_state){
    user_cookie_save(array('ciudadanodigitalautocompletar' => TRUE));
  }
