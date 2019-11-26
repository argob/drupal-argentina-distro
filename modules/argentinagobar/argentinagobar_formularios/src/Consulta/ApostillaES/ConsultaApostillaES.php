<?php


class ConsultaApostillaEs extends Consulta {

  function get_form($form, &$form_state, $consulta) {

    $form = array();

    //LENGUAJE
    //$path = $base_url.'/'.'test-apostilla';
    $path = $base_url . '/' . drupal_get_path_alias();
    $pathen = $path . '/en';
    $pathfr = $path . '/fr';
    //$path = $base_url.'/'.drupal_get_path_alias().'/es';

    //CONTENEDOR 0 - IDIOMA
    $wrapper0 = new FieldContainer('wrapper0');
    $form['wrapper0'] = $wrapper0->render();

    $form['wrapper0']['idiomaen'] = [
      '#markup' => '<a href="' . $pathen . '">English</a>',
      '#prefix' => '<p align="right">',
      '#suffix' => '</p>',
    ];

    $form['wrapper0']['idiomafr'] = [
      '#markup' => '<a href="' . $pathfr . '">Français</a>',
      '#prefix' => '<p align="right">',
      '#suffix' => '</p>',
    ];

    //CONTENEDOR 1
    $wrapper = new FieldContainer('wrapper');
    $form['wrapper'] = $wrapper->render();

    //CAMPO 1
    $anio = new FieldTextfield('Año');
    $anio->set_required(TRUE);
    $form['wrapper']['anio'] = $anio->render();
    $form['wrapper']['anio']['#rules'] = [
      'numeric',
      'length[4]',
      'notOnlySpaces'
    ];
    $form['wrapper']['anio']['#prefix'] = '<div class=row><div class="col-md-4">';
    $form['wrapper']['anio']['#suffix'] = '</div>';
    $form['wrapper']['anio']['#theme'] = 'form_element_addon';
    $form['wrapper']['anio']['#attributes']['data-input-group-addon-left-text'] = 'CE-';
    //$form['wrapper']['anio']['#attributes']['aria-describedby'] =  "addon-";


    //CAMPO 2
    $numero = new FieldTextfield('Número');
    $numero->set_required(TRUE);
    $form['wrapper']['numero'] = $numero->render();
    $form['wrapper']['numero']['#rules'] = [
      'numeric',
      'length[8, 10]',
      'notOnlySpaces'
    ];
    $form['wrapper']['numero']['#prefix'] = '<div class="col-md-4">';
    $form['wrapper']['numero']['#suffix'] = '</div>';
    $form['wrapper']['numero']['#theme'] = 'form_element_addon';
    $form['wrapper']['numero']['#attributes']['data-input-group-addon-left-text'] = '-';


    //CAMPO 3
    $codigoreparticion = new FieldTextfield('Código de Repartición ');
    $codigoreparticion->set_required(TRUE);
    $form['wrapper']['codigoreparticion'] = $codigoreparticion->render();
    $form['wrapper']['codigoreparticion']['#prefix'] = '<div class="col-md-4">';
    $form['wrapper']['codigoreparticion']['#suffix'] = '</div>';
    $form['wrapper']['codigoreparticion']['#theme'] = 'form_element_addon';
    $form['wrapper']['codigoreparticion']['#attributes']['data-input-group-addon-left-text'] = '-APN-';
    //$form['wrapper']['codigoreparticion']['#value'] = 'DTC#MRE';
    //$form['wrapper']['codigoreparticion']['#disabled'] = TRUE;

    //CONTENEDOR 2
    $wrapper2 = new FieldContainer('wrapper2');
    $form['wrapper2'] = $wrapper2->render();

    //CAMPO 4
    $numeroorden = new FieldTextfield('N° de Orden (campo 8 de la Apostilla)');
    $numeroorden->set_required(TRUE);
    $form['wrapper2']['numeroorden'] = $numeroorden->render();
    $form['wrapper2']['numeroorden']['#rules'] = [
      //'numeric',
      'length[2, 20]',
      'notOnlySpaces'
    ];
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
    $submitButton->setValue("REALIZAR CONSULTA");
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


  //Devuelve los parametros cargados en el formulario que se indique
  function get_params() {
    $value = [
      $valuea = isset($this->values['anio']) ? $this->values['anio'] : NULL,
      $valueb = isset($this->values['numero']) ? $this->values['numero'] : NULL,
      $valuec = isset($this->values['codigoreparticion']) ? $this->values['codigoreparticion'] : NULL,
      $valued = isset($this->values['numeroorden']) ? $this->values['numeroorden'] : NULL,
    ];
    //var_dump('ARRAY VALORES INPUT', $value);

    $params = [];
    //$params['?usuario_consulta=MGESPARZA&numero_documento='] = str_replace(' ', '+', $value);
    $params['numerodocumento'] = 'CE-' . $value[0] . '-' . $value[1];
    $params ['filtrob'] = str_replace(' ', '+', $value[3]);
    $params ['filtroc'] = str_replace(' ', '+', $value[2]);
    //$params ['filtroc'] = str_replace('#', '%', $value[2]);

    //var_dump($params ['filtroc']);
    return $params;
  }

  //Funcion que construye la URL de consulta a la API en funcion de lo que devuelve el GET
  function get_request_url() {
    $endpoint = $this->get_endpoint();
    if (is_null($endpoint) || $enpoint = '') {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }
    //return $endpoint . '?id=' . str_replace(' ','+', $_GET['id']);
    //PDF return $endpoint . 'numerodocumento=' . str_replace(' ', '+', $_GET['id']) . '-I.pdf';
    //$urlconsulta = $endpoint . '&numero_documento=' . str_replace(' ', '+', $_GET['numerodocumento']).'-APN-SECEP%23MM' ;
    //$urlconsulta = $endpoint . '&numero_documento=' . str_replace(' ', '+', $_GET['numerodocumento']) . '-APN-DNGT%23JGM';
    //$urlconsulta = $endpoint . '&numero_documento=' . str_replace(' ', '+', $_GET['numerodocumento'].'-APN-'.$_GET['filtroc']);
    $urlconsulta = $endpoint . '&numero_documento=' . str_replace(' ', '+', $_GET['numerodocumento'].'-APN-'.str_replace('#', '%23',$_GET['filtroc']));
    //var_dump('URL CONSULTA API 1', $urlconsulta);

    return $urlconsulta;

  }


  function get_endpoint() {
    //var_dump('API', variable_get('consulta_apostilla'));
    return variable_get('consulta_apostilla');
  }

  //Hace el request a la api
  function get_request() {
    $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
    //var_dump('request HEADERS', $this->get_request_headers());
    //var_dump('request URL', $this->get_request_url());
    //var_dump('request', $request);
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
      $response = theme('apostillaes_error');
      //var_dump('ERROR 400 o 404');
      //var_dump('response 404', $response);
    }

    if ($request->code == 200) {

      $data = drupal_json_decode($request->data);
      //var_dump('DATA 200', $data);
      $datausuario = $_GET['numerodocumento'];

      //Trae la info del campo N° de Orden ingresada en el form
      $numordenuser =  str_replace('+', ' ', $_GET['filtrob']);
      // muestra el array camposFormulario extraido de la consulta a la API
      $camposFormularioApi = $data['camposFormulario'];
      $test = array_column($camposFormularioApi,'valor','nombre' );
      //$key = array_key_sera('numero_orden',$test);
      //var_dump($camposFormularioApi);
      //var_dump($test);
      //var_dump($key);


      // foreach($camposFormularioApi as $key=>$value) {
      //   $numordenapi = $key;
      //
      //   var_dump($numordenapi);
      //   var_dump($camposFormularioApi[$key]);
      // }


      //function consultaNumOrden(){
      foreach($camposFormularioApi as $i){
        //$numordenapi = $i['valor'];
        if($i['nombre'] == 'numero_orden'){
          //var_dump($i['valor']);
          //$numordenapi = $i['valor'];
          $numordenapi = (string) $i['valor'];
          //var_dump($i['nombre']);
          //var_dump($numordenapi);
          //break;
          $encontre=true;
          //return $numordenapi;
        }
        if ($encontre==true){
        break;
        }
      }
    //}

//print_r($numordenapi);

      //$numordenapi = 0;
      $arrayuser = explode('-', $datausuario);
      //var_dump('ARRAYUSER',$arrayuser);
      $arrayapi = explode('-', $data['numeroSade']);
      unset($arrayapi[3], $arrayapi[4]);
      //var_dump('ARRAYAPI',$arrayapi);

        //var_dump('NUM ORDEN USER',$numordenuser);
        //var_dump('NUM ORDEN API',$numordenapi);

      if ($arrayapi == $arrayuser && $numordenuser == $numordenapi ) {

        //var_dump('ES IGUAL');
        //var_dump($numordenapi);
        //die("el id:".$id);
        $consultaPdf = new ConsultaApostillaPdf(ApiGatewayAuth::getInstance(), ['numerodocumento' => $id]);
        //$detallePdf = $consultaPdf->consultar();
        $response = $consultaPdf->consultar();

        //var_dump('CONSULTA API PDF', $consultaPdf);
        //var_dump('CONSULTAR PDF', $response);
      }else{
        $response = theme('apostillaes_error');
      }

    }
    //var_dump('response inicial', $response);
    //return theme($theme);
    return $response;
  }
}
