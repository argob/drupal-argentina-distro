<?php

class ConsultaRLMTestListado extends Consulta
{
  //form ingreso busqueda
  function get_form($form, &$form_state, $consulta)
  {
    // ValorInput FORM
    global $valorInput;
    global $valorCodigo;

    $form['#attached']['css'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/css/RLMTest/estilosRLMTest.css',
    );

    $form = array();

    //CONTENEDOR
    $wrapper = new FieldContainer('wrapper');
    $form['wrapper'] = $wrapper->render();
    $form['wrapper']['#prefix'] = '<div id="wrapp">';
    $form['wrapper']['#suffix'] = '</div>';

    //la validacion(#rules) se ejecuta desde la funcion argentinagobar_formularios_fapi_validation_rules
    $codigo = new FieldTextfield('Código Responsable Completo');
    $form['wrapper']['codigo'] = $codigo->render();
    $form['wrapper']['codigo']['#rules'] =
      array('notOnlySpaces',
        array('rule' => 'length[20, 31]', 'error' => 'Por favor ingrese toda la informacion en Codigo Responsable Completo.'),
      );
    $form['wrapper']['codigo']['#prefix'] = '<div class=row id="testRlmRow"><div class="col-md-4">';
    $form['wrapper']['codigo']['#suffix'] = '</div>';

    //CAMPO 2 - CUIT
    $cuit = new FieldNumeric('CUIT/CUIL (sin guiones)');
    $form['wrapper']['cuit'] = $cuit->render();
    $form['wrapper']['cuit']['#rules'] =
      array(
        array('rule' => 'numeric', 'error' => 'El campo CUIT/CUIL solo admite numeros'),
        array('rule' => 'length[11]', 'error' => 'La longitud ingresada en el campo CUIT/CUIL es incorrecta.'),
        'validaCuit',
      );
    $form['wrapper']['cuit']['#prefix'] = '<div class="col-md-4">';
    $form['wrapper']['cuit']['#suffix'] = '</div>';

    $form['wrapper']['captcha']['#type'] = 'captcha';
    $form['wrapper']['captcha']['#captcha_type'] = 'captcha/Math';
    $form['wrapper']['captcha']['#required'] = 'true';
    $form['wrapper']['captcha']['#prefix'] = '<div class=row><div class="col-md-4">';
    $form['wrapper']['captcha']['#suffix'] = '</div>';

    $valorInput = isset($form_state['input']['cuit']) ? $form_state['input']['cuit'] : null;
    $valorCodigo = isset($form_state['input']['codigo']) ? $form_state['input']['codigo'] : null;

    //Validation Captcha
    $csid_form = (isset($form_state['input']['captcha_sid'])) ? $form_state['input']['captcha_sid'] : NULL;
    $captcha_response_form = (isset($form_state['input']['captcha_response'])) ? $form_state['input']['captcha_response'] : NULL;

    $csid_base = db_query(
      "SELECT csid FROM {captcha_sessions} WHERE csid = :csid",
      array(':csid' => $csid_form)
        )->fetchField();
        
    if ($csid_form == $csid_base) {
      $captcha_response_base =  db_query(
        "SELECT solution FROM {captcha_sessions} WHERE csid = :csid",
          array(':csid' => $csid_form)
        )->fetchField();
        
    }

    if(is_string($captcha_response_base) && is_string($captcha_response_form) && $captcha_response_base == $captcha_response_form) {
      
      $this->setValues($this->getParametros());
      $response = $this->consultar();
      
      $form['response'] = array(
        '#type' => 'markup',
        '#markup' => $this->renderResponse($form, $form_state, $response),
      );
    }else{
        
      $form['response'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'response'
        ),
      );
    }

    //Inicio BOTON BUSCAR
    $form['wrapper']['submit-wrapper'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'submit-wrapper',
      ),
    );

    $submitButton = new FieldSubmit();
    $submitButton->addClass('btn-primary');
    $submitButton->addClass('btn-block');
    $submitButton->setValue("Generar Código");

    $form['wrapper']['submit-wrapper']['submit'] = $submitButton->render();
    $form['wrapper']['submit-wrapper']['#prefix'] = '<div class="col-md-4" style="align: center; margin-top:26px" id="w_generarCodigo">';
    $form['wrapper']['submit-wrapper']['#suffix'] = '</div>';
    //Fin boton buscar

    $form_state['handler']['class'] = serialize($this);

    return $form;
  }

  function get_request(){

    $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
    return $request;
  }
 
  //Consulta a la API
  function get_endpoint(){

    return variable_get('consulta_rlm_72');
  }

  //Funcion que construye la URL en funcion de lo que devuelve el GET, para hacer la consulta a la API
  function get_request_url(){
    
    $endpoint = $this->get_endpoint();
    if(is_null($endpoint)) {
      throw new EndpointNuloException("Falta endpoint para la Consulta", 1);
    }
    global $valorInput;

    return $endpoint . '?filtro=' . str_replace(' ','+', $valorInput);

  }

  //Token
  function get_response($request)
  {
    $items = [];

    if ($request->code == 401) {

      $this->api_gateway_auth->refresh_token();
      $this->consultar();

    }

    if ($request->code == 500 || $request->code == 503) {
      $response = null;
      throw new ConsultaException('', 1);
    }

    if ($request->code == 200) {
      $data = drupal_json_decode($request->data);
      $items = $this->formatItems($data['results']);

    }

    return $items;
  }

  //Da formato a los items que trae del Json
  function formatItems($data)
  {
    global $base_url;
    global $valorCodigo;

    $items = array();

    foreach ($data as $result){

      $item = array();
      $item['cuit'] = $result['cuit'];
      $item['ref_number'] =  $result['letra'];;
      $item['ref_number'] .= '-' . $result['anio'];
      $item['ref_number'] .= '-' . $result['numero'];
      $item['ref_number'] .= '-' . $result['reparticionActuacion'];
      $item['ref_number'] .= '-' . $result['reparticionUsuario'];
      $item['link'] = $base_url . '/' . variable_get('rlmtest_alias') . '/'  . $result['cuit'] . '--' . $item['ref_number']  ;
      $items[] = $item;
    }

    $convcodusuario = explode('-',$valorCodigo);

    $itemsapi = array(
      $result['letra'],
      $result['anio'],
      $result['numero'],
      $result['reparticionActuacion'],
      $result['reparticionUsuario']
    );

    $contador = 0;
    foreach ($itemsapi as $i){
      foreach($convcodusuario as $c ){
        if($i == $c){
          $contador += 1;
        }
      }
    }

    if ($contador == 5) {
      return $items;
    }
  }

  //muestra el mensaje cuando se da click al boton de busqueda
  function renderResponse($form, &$form_state, $response) {
    
    $theme = count($response) == 0 ? 'rlmtest_error' : 'rlmtest_ok';

    return theme($theme, array(
      'cuit' => $response[0]['cuit'],
      'ref_number' => $response[0]['ref_number']
    ));
  }
}
