<?php

function argentinagobar_formularios_sugerencias_argentinagobar($form, &$form_state) {

$form = array();

$form['contenedor'] = array(
  '#type' => 'container',
  '#attributes' => array(
    'id' => 'contenedor',
  ),
);

$form['contenedor']['item_titulo'] = array(
  '#type' => 'markup',
  '#markup' => "<h2 class=\"h3 section-title\">".t('Dejanos tu comentario')."</h2>",
);

$form['contenedor']['nombres'] = array(
  '#type' => 'textfield',
  '#title' => 'Nombre y Apellido',
  '#size' => 10,
  '#maxlength' => 100,
  '#form_placeholder' => t('ingresa texto'),
  '#description' => t('Completa tu nombre y apellido'),
  '#required' => TRUE,
  '#placeholder' => t( 'Username' ),
);
$form['contenedor']['nombres']['#attributes']['placeholder'] = t('ingresa texto');

$form['contenedor']['mail'] = array(
  '#type' => 'textfield',
  '#title' => 'Correo Electrónico',
  '#description' => t('Juan@argentina.gob.ar'),
  '#size' => 10,
  '#maxlength' => 100,
  '#required' => TRUE,
  '#rules' => array('email'),
);
$form['contenedor']['mail']['#attributes']['placeholder'] = t('ingresa tu correo electrónico');

$form['contenedor']['comentario'] = array(
  '#title' => t('Comentario'),
  '#description' => t('Escribí tu comentario'),
  '#type' => 'textarea',
  '#required' => TRUE,
  '#size' => 500,
);

$form['contenedor']['link_nodo'] = array(
  '#type' => 'link',
  '#value' => drupal_get_query_parameters(),
);

  $form['contenedor']['envio_formulario'] = array(
    '#type' => 'submit',
    '#value' => t('Enviar mi consulta'),
    '#attributes' => array(
      'class' => array(
        'btn-success',
        'btn',
      ),
    ),
    '#ajax' => array(
      'callback' => 'argentinagobar_formularios_sugerencias_argentinagobar_submit_ajax',
      'wrapper' => 'contenedor',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  return $form;
}

function argentinagobar_formularios_sugerencias_argentinagobar_submit_ajax($form, &$form_state) {

    drupal_validate_form('argentinagobar_formularios_sugerencias_argentinagobar', $form, $form_state);

    if (form_get_errors()) {
      $form_state['rebuild'] = TRUE;

      return $form;
    }

    $nombre = "Argentinagobar";
    $emailEmisor = variable_get('sugerencias_mail');
    $asunto = "Sugerencia enviado por:\n\n";
    $cuerpoMailPuedeSerHTML = theme(
      'argentinagobar_formularios_respuesta',array(
        'nombre' => $form['contenedor']['nombres']['#value'],
        'email'=> $form['contenedor']['mail']['#value'],
        'comentario' => $form['contenedor']['comentario']['#value'],
        'url_refence' => $form['contenedor']['link_nodo']['#value']['url_refence'],
        'fecha' => date('d/m/Y', time()),
      )
    );
    argentinagobar_mailgun_enviar(
      $nombre.' <'.$emailEmisor.'>',
      $asunto,
      $cuerpoMailPuedeSerHTML
    );
    $response = theme('argentinagobar_formularios_mensaje_enviado');
    return '<div id="contenedor">' . $response . '</div>';
}
