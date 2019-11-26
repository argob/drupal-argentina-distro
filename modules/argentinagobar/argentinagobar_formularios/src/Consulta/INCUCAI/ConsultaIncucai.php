<?php

class ConsultaIncucai extends Consulta
{

  function get_form($form, &$form_state, $consulta)
  {
    $form = array();

    $form['contenedor'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'documento' => 'contenedor'
      ),
    );

    $form['contenedor']['id_tipo_documento'] = array(
      '#prefix' => '<div class="col-md-5">',
      '#suffix' => '</div>',
      '#type' => 'select',
      '#title' => t('Tipo de documento'),
      '#required' => TRUE,
      '#default_value' => 1,
      '#options' => array(
         1 => t('DNI'),
         2 => t('CI'),
         3 => t('LC'),
         4 => t('LE'),
         5 => t('PAS'),
         6 => t('SD'),
       ),
    );

    $form['contenedor']['docnro'] = array(
      '#prefix' => '<div class="col-md-7">',
      '#suffix' => '</div>',
      '#type' => 'textfield',
      '#title' => t('Número de documento'),
      '#required' => TRUE,
      '#rules' => array('numeric', 'length[4, 9]'),

    );

    $form['contenedor']['fecha_nacimiento'] = array(
      '#prefix' => '<div class="col-md-12">',
      '#suffix' => '</div>',
      '#type' => 'date_popup',
      '#title' => t('Fecha de nacimiento'),
      '#date_format' => 'd/m/Y',
      '#required' => TRUE,
      '#default_value' =>  time(),
      '#date_year_range' => '-200:+0',
      '#theme' => array('form_element_date_no_calendar'),
      '#title_display' => 'invisible',
    );


    $submitButton = new FieldSubmit();
    $submitButton->addClass('btn btn-success btn-lg btn-block');
    $submitButton->setValue("Buscar");

    $form['contenedor']['submit']= $submitButton->render();
    # serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
    $form_state['handler']['class'] = serialize($this);

    //chequea si hay parámetros cargados y en caso afirmativo realiza la consulta

    if ($this->hayParametros()) {
      $this->setValues($this->getParametros());

      $response = $this->consultar();

      $form['contenedor'] = array(
        '#type' => 'markup',
        '#markup' => $this->renderResponse($form, $form_state, $response),
      );
    }
    return $form;
  }

  function get_params()
  {
    $parametros = array();
    $parametros['id_tipo_documento'] =  $this->values['id_tipo_documento'];
    $parametros['docnro'] =  $this->values['docnro'];
    $parametros['fecha_nacimiento'] =  $this->values['fecha_nacimiento'];

    return $parametros;
  }

  function get_request_url()
  {
    $endpoint = $this->get_endpoint();

    if(is_null($endpoint) || $enpoint = '') {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }

    $params = $this->get_params();
    return $endpoint . '?' . http_build_query($params);
  }

  function handleError($request)
  {
    if ($request->code = 404) {
    }
    elseif ($request->code = 500) {
      throw new ConsultaSinDatosException($request->error, $request->userMessage);
    } else {
      parent::handleError($request);
    }
  }

  function mayorDeEdad($value)
  {
      // calculo la edad en dias para saber si es menor de 18
      $date1 = new Datetime($value);
      $date2 = new DateTime(date("Y/m/d"));
      $diff = $date2->diff($date1);

       return ($diff->days < 6571);
  }
}
