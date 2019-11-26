<?php


class ConsultaRegistroSociedades extends Consulta {

  function get_form($form, &$form_state, $consulta) {

    $form = array();

    //CSS
    $form['#attached']['css'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/css/RegistroSociedades.css',
    );

    //Javascript
    $form['#attached']['js'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/RegistroSociedades/setDefaultRadio.js',
    );

    $form['#attached']['js'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/RegistroSociedades/unSetFieldRegSoc.js',
    );

    $form['#attached']['js'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/RegistroSociedades/emptyFieldsRegSoc.js',
    );

    $form['#attached']['js'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/RegistroSociedades/submitShow.js',
    );

    //Valor required del Radio Election
    $required = false;

    //Options Radio
    $options = array(
      'cuit' => 'CUIT / CDI',
      'razon' => 'Razón Social',
    );

    //CONTENEDOR 0
    $wrapper0 = new FieldContainer('wrapper0');
    $form['wrapper0'] = $wrapper0->render();
    $form['wrapper0']['#attributes'] = array('id' => array('frlm'));



    //RADIO ELECTION
    $searchBy = new FieldRadios('Buscar por');
    $searchBy->set_required($required);
    $searchBy->set_options($options);
    $form['wrapper0']['searchBy'] = $searchBy->render();
    $form['wrapper0']['searchBy']['#theme'] = 'form_element_radios_inline';
    $form['wrapper0']['searchBy']['#prefix'] = '<div class=row><div class="col-md-3">';
    $form['wrapper0']['searchBy']['#suffix'] = '</div>';

    //CAMPO 1.1 CUIT
    $search2 = new FieldNumeric('CUIT / CDI (ingresá 11 números)');
    $form['wrapper0']['cuit'] = $search2->render();
    $form['wrapper0']['cuit']['#states'] = array(
      'invisible' => array(
        ':input[name="searchBy"]' => array('value' => 'razon'),
      ),
    );
    $form['wrapper0']['cuit']['#rules'] =
      array(
        array('rule' => 'numeric', 'error' => 'El campo CUIT / CDI solo admite números'),
        array('rule' => 'length[11]', 'error' => 'La longitud ingresada en el campo CUIT / CDI es incorrecta.'),
        'validaCuit',
      );
    $form['wrapper0']['cuit']['#prefix'] = '<div class="col-md-6">';


    //CAMPO 1.2 RAZON
    $search = new FieldTextfield('Razón Social (Ingresá al menos 3 letras. No incluir el tipo societario.)');
    $form['wrapper0']['razon'] = $search->render();
    $form['wrapper0']['razon']['#states'] = array(
      'visible' => array(
        ':input[name="searchBy"]' => array('value' => 'razon'),
      ),
    );
    $form['wrapper0']['razon']['#rules'] = ['textNumberSpaces','length[3, *]', 'notOnlySpaces'];
    $form['wrapper0']['razon']['#suffix'] = '</div>';

    //BOTON BUSQUEDA
    $form['wrapper0']['submit-wrapper'] = [
      '#type' => 'container',
      '#attributes' => [
        'id' => 'submit-wrapper',
      ],
    ];

    $submitButton = new FieldSubmit();
    $submitButton->addClass('btn-primary');
    $submitButton->addClass('btn-block');
    $submitButton->addClass('form-control');
    $submitButton->setValue("BUSCAR");

    $form['wrapper0']['submit'] = $submitButton->render();
    $form['wrapper0']['submit']['#prefix'] = '<div class="col-md-3">';
    $form['wrapper0']['submit']['#suffix'] = '</div></div>';

    //chequea si hay parámetros cargados en el formulario y en caso afirmativo realiza la consulta
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


  //Devuelve los parametros cargados en el formulario
  function get_params() {
    $value = NULL;
    $value_cuit = NULL;
    $value_razon = NULL;

    if(isset($this->values['searchBy']) && $this->values['searchBy'] == 'cuit') {
      $value_cuit = $this->values['cuit'];
    }
    else {
      $value_razon = isset($this->values['razon']) ? $this->values['razon'] : null ;
    }

    $params = array();

    $params['cuit'] = str_replace(' ','+', $value_cuit);
    $params['razon'] = str_replace(' ','+', $value_razon);
    return $params;
  }

  //Construye la URL de consulta a la API en funcion de lo que devuelve GET
  function get_request_url() {
    $endpoint = $this->get_endpoint();

    $razon_may = mb_strtoupper($_GET['razon'], 'UTF-8');
    $urlcuit = strlen($_GET['cuit']) >= 11 ? '?cuit='. str_replace(' ', '+', $_GET['cuit']) : ' ';
    $urlrazon_social = strlen($razon_may) >= 3 ? '?razon_social='. $razon_may : ' ';
    $urlconsulta = strlen($_GET['razon']) == 0 ?  $endpoint . $urlcuit :  $endpoint . $urlrazon_social ;

    return $urlconsulta;

  }

  //Get de la variable del endpoint ubicada en settings.php
  function get_endpoint() {

    return variable_get('consulta_registro_sociedades');

  }

  //Hace el request a la api
  function get_request() {
    $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
    return $request;

  }

  //Token
  function get_response($request) {
    $items = array();
    $response = NULL;
    $data = NULL;

    if ($request->code == 401) {

      $this->api_gateway_auth->refresh_token();
      $this->consultar();

    }

    if ($request->code == 500 || $request->code == 503) {

      throw new ConsultaException('El servicio no esta funcionando', 1);

    }

    if ($request->code == 400 || $request->code == 404) {
      $theme = 'registrosociedades_error';
    }

    if ($request->code == 200) {
      $data = drupal_json_decode($request->data);
      $items = $this->formatItems($data['results']); //este funciona
    }
    return $items;
  }

  function renderResponse($form, &$form_state, $response)
  {
    $theme = count($response) == 0  ? 'registrosociedades_error' : 'registrosociedades_detalle' ;
    return theme($theme, array(
        'items' => $response,
      )
    );
  }

  function formatItems($data)
  {


    $items = array();
    if(!empty($data)){
      foreach ($data as $data3) {

        $item = array();
        $item['cuit'] = $data3['CUIT'];
        $item['razon_social'] = $data3['RAZON_SOCIAL'];
        $item['fecha_contrato_social'] = substr($data3['FECHA_CONTRATO_SOCIAL'], 0, 10);
        $item['tipo_societario'] = $data3['TIPO_SOCIETARIO'];
        $item['numero_inscripcion'] = $data3['NUMERO_INSCRIPCION'];

        $item['fecha_actualizacion'] = is_null($data3['FECHA_ACTUALIZACION']) ? ' ': substr($data3['FECHA_ACTUALIZACION'], 0, 10);

        $item['correo'] = is_null($data3['CORREO']) ? ' ': $data3['CORREO'];
        $item['domicilio_fiscal'] = is_null($data3['DOMICILIO_FISCAL']) ? ' ': $data3['DOMICILIO_FISCAL'];
        $item['df_provincia'] = is_null($data3['DF_PROVINCIA']) ? ' ': $data3['DF_PROVINCIA'];
        $item['df_localidad'] = is_null($data3['DF_LOCALIDAD']) ? ' ': $data3['DF_LOCALIDAD'];
        $item['df_calle'] = is_null($data3['DF_CALLE']) ? ' ': $data3['DF_CALLE'];
        $item['df_numero'] = is_null($data3['DF_NUMERO']) ? ' ': $data3['DF_NUMERO'];
        $item['df_piso'] = is_null($data3['DF_PISO']) ? ' ': $data3['DF_PISO'];
        $item['df_departamento'] = is_null($data3['DF_DEPARTAMENTO']) ? ' ': $data3['DF_DEPARTAMENTO'];
        $item['df_domicilio'] = $item['df_calle'].' '.$item['df_numero'].' '.$item['df_piso'].' '.$item['df_departamento'];
        $item['df_cp'] = is_null($data3['DF_CP']) ? ' ': $data3['DF_CP'];

        $item['df_estado_domicilio'] = is_null($data3['DF_ESTADO_DOMICILIO']) ? ' ': $data3['DF_ESTADO_DOMICILIO'];
        $item['domicilio_legal'] = is_null($data3['DOMICILIO_LEGAL']) ? ' ': $data3['DOMICILIO_LEGAL'];
        $item['dl_provincia'] = is_null($data3['DL_PROVINCIA']) ? ' ': $data3['DL_PROVINCIA'];
        $item['dl_localidad'] = is_null($data3['DL_LOCALIDAD']) ? ' ': $data3['DL_LOCALIDAD'];
        $item['dl_calle'] = is_null($data3['DL_CALLE']) ? ' ': $data3['DL_CALLE'];
        $item['dl_numero'] = is_null($data3['DL_NUMERO']) ? ' ': $data3['DL_NUMERO'];
        $item['dl_piso'] = is_null($data3['DL_PISO']) ? ' ': $data3['DL_PISO'];
        $item['dl_departamento'] = is_null($data3['DL_DEPARTAMENTO']) ? ' ': $data3['DL_DEPARTAMENTO'];
        $item['dl_domicilio'] = $item['dl_calle'].' '.$item['dl_numero'].' '.$item['dl_piso'].' '.$item['dl_departamento'];
        $item['dl_cp'] = is_null($data3['DL_CP']) ? ' ': $data3['DL_CP'];
        $item['dl_estado_domicilio'] = is_null($data3['DL_ESTADO_DOMICILIO']) ? ' ': $data3['DL_ESTADO_DOMICILIO'];
        $item['fecha_corte'] = is_null($data3['FECHA_CORTE']) ? ' ': substr($data3['FECHA_CORTE'], 0, 10);
        $items[] = $item;
      }
    }

    return $items;
  }

}
