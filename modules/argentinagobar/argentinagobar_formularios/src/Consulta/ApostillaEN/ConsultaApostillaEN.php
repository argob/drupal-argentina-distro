<?php


class ConsultaApostillaEN extends Consulta {

  function get_form($form, &$form_state, $consulta) {

    $form = array();

    //LENGUAJE

    $path = $base_url . '/' . drupal_get_path_alias();
    $nuevo_path = substr($path,0, strlen($path)-3);
    $pathes=$nuevo_path;
    $pathfr = $pathes.'/fr';

    //CONTENEDOR 0 - IDIOMA
    $wrapper0 = new FieldContainer('wrapper0');
    $form['wrapper0'] = $wrapper0->render();

    $form['wrapper0']['idiomaes'] = array(
      '#markup' =>'<a href="'.$pathes.'">Español</a>',
      '#prefix' => '<p align="right">',
      '#suffix' => '</p>',
    );
    $form['wrapper0']['idiomafr'] = array(
      '#markup' =>'<a href="'.$pathfr.'">Français</a>',
      '#prefix' => '<p align="right">',
      '#suffix' => '</p>',
    );

    //CONTENEDOR 1
    $wrapper = new FieldContainer('wrapper');
    $form['wrapper'] = $wrapper->render();

    //CAMPO 1
    $anio = new FieldTextfield(' Year ');
    $anio->set_required(true);
    $form['wrapper']['anio'] = $anio->render();
    $form['wrapper']['anio']['#rules'] =
    array(
      array('rule' => 'numeric', 'error' => 'The field Year only supports numbers'),
      array('rule' => 'length[4]', 'error' => 'The length entered in field Year is incorrect'),
      array('rule' => 'notOnlySpaces', 'error' => 'The field Year not supports spaces'),
    );
    $form['wrapper']['anio']['#prefix'] = '<div class=row><div class="col-md-4">';
    $form['wrapper']['anio']['#suffix'] = '</div>';
    $form['wrapper']['anio']['#theme'] = 'form_element_addon';
    $form['wrapper']['anio']['#attributes']['data-input-group-addon-left-text'] =  'CE-';


    //CAMPO 2
    $numero = new FieldTextfield(' Number ');
    $form['wrapper']['numero'] = $numero->render();
    $form['wrapper']['numero'] ['#required'] = TRUE;
    $form['wrapper']['numero'] ['#required_error'] = t('Please enter a name.');

    $form['wrapper']['numero']['#rules'] =
    array(
      array('rule' => 'numeric', 'error' => 'The field Number only supports numbers'),
      array('rule' => 'length[8, 10]', 'error' => 'The length entered in field Number is incorrect'),
      array('rule' => 'notOnlySpaces','error' => 'The field Number not supports spaces'),
    );
    $form['wrapper']['numero']['#prefix'] = '<div class="col-md-4">';
    $form['wrapper']['numero']['#suffix'] = '</div>';
    $form['wrapper']['numero']['#theme'] = 'form_element_addon';
    $form['wrapper']['numero']['#attributes']['data-input-group-addon-left-text'] =  '-';

    //CAMPO 3
    $codigoreparticion = new FieldTextfield('Dependency Code');
    $codigoreparticion->set_required(true);
    $form['wrapper']['codigoreparticion'] = $codigoreparticion->render();
    $form['wrapper']['codigoreparticion']['#prefix'] = '<div class="col-md-4">';
    $form['wrapper']['codigoreparticion']['#suffix'] = '</div>';
    $form['wrapper']['codigoreparticion']['#theme'] = 'form_element_addon';
    $form['wrapper']['codigoreparticion']['#attributes']['data-input-group-addon-left-text'] =  '-APN-';

    //CONTENEDOR 2
    $wrapper2 = new FieldContainer('wrapper2');
    $form['wrapper2'] = $wrapper2->render();

    //CAMPO 4
    $numeroorden = new FieldTextfield('N° de Orden | N° of order (field 8 of the Apostille) ');
    $numeroorden->set_required(true);
    $form['wrapper2']['numeroorden'] = $numeroorden->render();
    $form['wrapper2']['numeroorden']['#rules'] =
    array(
      array('rule' => 'length[2, 20]', 'error' => 'The length entered in field N° of order is incorrect'),
      array('rule' => 'notOnlySpaces','error' => 'The field N° of order not supports spaces'),
    );
    $form['wrapper2']['numeroorden']['#prefix'] = '<div class=row><div class="col-md-8">';
    $form['wrapper2']['numeroorden']['#suffix'] = '</div>';


    //BOTON BUSQUEDA
    $form['wrapper2']['submit-wrapper'] = [
      '#type' => 'container',
      '#attributes' => [
        'id' => 'submit-wrapper',
      ],
    ];

    $submitButton = new FieldSubmit();
    $submitButton->addClass('btn-primary');
    $submitButton->addClass('btn-block');
    $submitButton->setValue("SUBMIT INQUIRY");
    $submitButton->addClass('m-t-2');

    $form['wrapper2']['submit-wrapper']['submit'] = $submitButton->render();
    $form['wrapper2']['submit-wrapper']['#prefix'] = '<div class="col-md-8 col-md-offset-2">';
    $form['wrapper2']['submit-wrapper']['submit']['#suffix'] = '</div>';


    //chequea si hay parámetros cargados y en caso afirmativo realiza la consulta
    if ($this->hayParametros()) {
      $this->setValues($this->getParametros());
      $response = $this->consultar();
      $form['response'] = [
        '#type' => 'markup',
        '#markup' => $this->renderResponse($form, $form_state, $response),
      ];
    }
    else {
      $form['response'] = [
        '#type' => 'container',
        '#attributes' => [
          'id' => 'response'
        ],
      ];
    }


    # serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
    $form_state['handler']['class'] = serialize($this);

    return $form;
  }


  //Devuelve los parametros cargados en el formulario que se indiquen
  function get_params() {
    $value = [
      $valuea = isset($this->values['anio']) ? $this->values['anio'] : NULL,
      $valueb = isset($this->values['numero']) ? $this->values['numero'] : NULL,
      $valuec = isset($this->values['codigoreparticion']) ? $this->values['codigoreparticion'] : NULL,
      $valued = isset($this->values['numeroorden']) ? $this->values['numeroorden'] : NULL,
    ];

    $params = [];
    $params['numerodocumento'] = 'CE-' . $value[0] . '-' . $value[1];
    $params ['filtrob'] = str_replace(' ', '+', $value[3]);
    $params ['filtroc'] = str_replace(' ', '+', $value[2]);

    return $params;
  }

  //Funcion que construye la URL de consulta a la API en funcion de lo que devuelve el GET
  function get_request_url() {
    $endpoint = $this->get_endpoint();
    if (is_null($endpoint) || $enpoint = '') {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }

    //PDF return $endpoint . 'numerodocumento=' . str_replace(' ', '+', $_GET['id']) . '-I.pdf';
    $urlconsulta = $endpoint . '&numero_documento=' . str_replace(' ', '+', $_GET['numerodocumento'].'-APN-'.str_replace('#', '%23',$_GET['filtroc']));

    return $urlconsulta;

  }


  function get_endpoint() {
    return variable_get('consulta_apostilla');
  }

  //Hace el request a la api
  function get_request() {
    $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
    return $request;

  }

  //Token
  function get_response($request) {

    $response = NULL;
    $data = NULL;

    if ($request->code == 401) {

      $this->api_gateway_auth->refresh_token();
      $this->consultar();

    }

    if ($request->code == 500 || $request->code == 503) {

      throw new ConsultaException('El servicio de APOSTILLA no esta funcionando', 1);

    }

    if ($request->code == 400 || $request->code == 404) {
      $response = theme('apostillaen_error');
    }

    if ($request->code == 200) {

      $data = drupal_json_decode($request->data);
      $datausuario = $_GET['numerodocumento'];

      //Trae la info del campo N° de Orden ingresada en el form
      $numordenuser =  str_replace('+', ' ', $_GET['filtrob']);

      // muestra el array camposFormulario extraido de la consulta a la API
      $camposFormularioApi = $data['camposFormulario'];
      $test = array_column($camposFormularioApi,'valor','nombre' );

      foreach($camposFormularioApi as $i){
        if($i['nombre'] == 'numero_orden'){
          $numordenapi = (string) $i['valor'];
          $encontre=true;
        }
        if ($encontre==true){
        break;
        }
      }

      $arrayuser = explode('-', $datausuario);
      $arrayapi = explode('-', $data['numeroSade']);
      unset($arrayapi[3], $arrayapi[4]);

      if ($arrayapi == $arrayuser && $numordenuser == $numordenapi ) {

        $consultaPdf = new ConsultaApostillaPdfEn(ApiGatewayAuth::getInstance(), ['numerodocumento' => $id]);
        $response = $consultaPdf->consultar();
      }else{
        $response = theme('apostillaen_error');
      }

    }
    return $response;
  }
}
