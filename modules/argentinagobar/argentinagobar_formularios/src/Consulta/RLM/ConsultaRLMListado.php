<?php

  class ConsultaRLMListado extends Consulta
  {

    function get_form($form, &$form_state, $consulta)
    {
      $required = false;

      $options = array(
        'cuit' => 'CUIT/CUIL',
        'razon' => 'Nombre o Razón Social',
      );

      $form = array();

      $form['#attached']['js'][] = array(
        'type' => 'file',
        'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/RLM/unSetFieldRLM.js',
      );

      $form['#attached']['js'][] = array(
        'type' => 'file',
        'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/RLM/setDefaultRadio.js',
      );

      $form['#attached']['js'][] = array(
        'type' => 'file',
        'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/RLM/emptyValidation.js',
      );

      $form['#attached']['js'][] = array(
        'type' => 'file',
        'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/RLM/submitShow.js',
      );

      $wrapper2 = new FieldContainer('wrapper2');
      $form['wrapper2'] = $wrapper2->render();
      $form['wrapper2']['#prefix'] = '<div class="row"><h3 id="frlm" style="text-align: center; padding: 0 0 25px 0">Realizá tu búsqueda</h3>';
      $form['wrapper2']['#subffix'] = '</div>';


      $wrapper = new FieldContainer('wrapper');
      $form['wrapper'] = $wrapper->render();
      $form['wrapper']['#prefix'] = '<div class="row rowhide">';
      $form['wrapper']['#subffix'] = '</div>';

      $searchBy = new FieldRadios('Buscar Por');
      $searchBy->set_required($required);
      $searchBy->set_options($options);
      $form['wrapper']['searchBy'] = $searchBy->render();
      $form['wrapper']['searchBy']['#theme'] = 'form_element_radios_inline';
      $form['wrapper']['#prefix'] = '<div class="row"><div class="col-xs-12 col-md-4 p-r-0 m-t-1">';
      $form['wrapper']['searchBy']['#suffix'] = '</div></div>';

      $wrapperTexto = new FieldContainer('wrapperTexto');
      $form['wrapper']['wrapperTexto'] = $wrapperTexto->render();
      $form['wrapper']['wrapperTexto']['#prefix'] = '<div class="col-xs-12 col-md-8 p-r-0 m-t-1">';
      $form['wrapper']['wrapperTexto']['#subffix'] = '</div>';

      $search2 = new FieldTextfield('Nombre o Razón Social *');
      $form['wrapper']['wrapperTexto']['razon'] = $search2->render();
      $form['wrapper']['wrapperTexto']['razon']['#states'] = array(
        'invisible' => array(
          ':input[name="searchBy"]' => array('value' => 'cuit'),
        ),
      );

      $searchPagina = new FieldNumeric('Pagina');
      $form['wrapper']['wrapperTexto']['pagina'] = $searchPagina->render();
      $form['wrapper']['wrapperTexto']['pagina']['#attributes'] = array('id' => array('paginaHidden'));
      $form['wrapper']['wrapperTexto']['pagina']["#value"] = 1;

      global $valorPagina;
      $valorPagina = (isset($form_state['input']['pagina'])) ? $form_state['input']['pagina'] : 1;

      
      $search = new FieldNumeric(' CUIT/CUIL *');
      $form['wrapper']['wrapperTexto']['cuit'] = $search->render();
      $form['wrapper']['wrapperTexto']['cuit']['#states'] = array(
        'visible' => array(
          ':input[name="searchBy"]' => array('value' => 'cuit'),
        ),
      );
      $form['wrapper']['wrapperTexto']['cuit']['#rules'] = array('numeric', 'length[2, 11]', 'notOnlySpaces');

      $form['wrapper']['captcha'] = array(
        '#type' => 'captcha',
        '#captcha_type' => 'captcha/Math',
        '#required' => 'true',
      );

      //ValorInput FORM
      global $valorInput;

      if(isset($form_state['input']['searchBy'])){
        if($form_state['input']['searchBy'] == 'cuit') {
          $valorInput = $form_state['input']['cuit'];
        }
        else {
          $valorInput = $form_state['input']['razon'];
        }
      }

      $valorInput = $this->normaliza($valorInput);

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

      $form['wrapper']['submit-wrapper'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'submit-wrapper',
          'class' => array(
            'col-md-4'
          ),
        ),
      );

      $submitButton = new FieldSubmit();
      $submitButton->addClass('btn-primary');
      $submitButton->addClass('btn-block');
      $submitButton->setValue("Buscar");

      $submitButton->addClass('m-t-2');
      $form['wrapper']['submit-wrapper']['submit'] = $submitButton->render();
      $form['wrapper']['submit-wrpper']['submit']['#suffix'] = '</div>';

      # serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
      $form_state['handler']['class'] = serialize($this);
     
      
      return $form;
    }


    function get_endpoint()
    {
      return variable_get('consulta_rlm_72');
    }

    function get_params()
    {
      global $valorInput;

      $params = array();
      $params['filtro'] = str_replace(' ','+', $valorInput);
      return $params;
    }

    function get_request()
    {
      $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
     
      return $request;
    }

    function get_request_id($id){
      return drupal_http_request($this->get_endpoint().'?filtro='.$id, $this->get_request_headers());
    }

    //Funcion que construye la URL de consulta a la API en funcion de lo que devuelve el GET
    function get_request_url()
    {
      $endpoint = $this->get_endpoint();
      if(is_null($endpoint) || $enpoint = '') {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }

      global $valorInput;
      global $valorPagina;

      return $endpoint . '?filtro=' . str_replace(' ','%20', $valorInput) . '&pagina='. $valorPagina;
    }

    function normaliza ($cadena){
        $originales = 'ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõöøùúûýýþÿŔŕ';
        $modificadas = 'aaaaaaaceeeeiiiidnoooooouuuuybsaaaaaaaceeeeiiiidnoooooouuuyybyRr';
        $cadena = utf8_decode($cadena);
        $cadena = strtr($cadena, utf8_decode($originales), $modificadas);
        $cadena = strtolower($cadena);
        return utf8_encode($cadena);
    }

    function get_response($request, $completo = false)
    {
      $items = [];
      $data = null;
      $contador = $this->getContador();
      
      if ($request->code == 401) {
        global $noconecta;
        $noconecta = true;
        
        //Se creo un while que contabiliza la acantidad de refresh que se solicitan del token
        //De esta manera se limita la cantidad de intentos de refesh a 3
        $contador = $this->getContador();
        $count = 0;
        $limite = 3;

        while ($contador < $limite ){
          $count++;
          $this->setContador($count);
          $contador = $this->getContador();
          
        }
      }

      if ($request->code == 500 || $request->code == 503) {

        throw new ConsultaException('El servicio de RLM no esta funcionando', 1);

      }

      if ($request->code == 404){
      }

      if ($request->code == 200) {

        if($completo){

          $items = drupal_json_decode($request->data);
        }
        else{

          $data = drupal_json_decode($request->data);
          $items = $this->formatItems($data['results']);

          //  lol
          if($items == array() && (explode('=', explode('&', $request->request)[1])[1][0]) != 1){
            $items = 'paginaVacia';
          }

        }
      }
      return $items;
    }

    function renderResponse($form, &$form_state, $response)
    {
      global $noconecta;

      $theme = $noconecta == true ? 'rlm_servicio_caido' : (count($response) == 0  ? 'rlm_error' : 'rlm_table_response');
      $theme = $response == 'paginaVacia' ? 'rlm_pagina_vacia' : $theme;

      return theme($theme, array(
        'items' => $response,
      ));
    }

    function formatItems($data)
    {
      $alias = variable_get('rlm_alias');
      global $base_url;
      $items = array();
      foreach ($data as $result){

        $item = array();
        $item['id'] = $result['id'];
        $item['cuit'] = $result['cuit'];
        $item['name'] = isset($result['razonsocial']) ? $result['razonsocial'] : $result['nombre'] .' '. $result['apellido'];
        $item['responsable'] = str_replace(' ','_', strtolower($item['name']));
        $item['ref_number'] =  $result['letra'];;
        $item['ref_number'] .= '-' . $result['anio'];
        $item['ref_number'] .= '-' . $result['numero'];
        $item['ref_number'] .= '-' . $result['reparticionActuacion'];
        $item['ref_number'] .= '-' . $result['reparticionUsuario'];
        $item['link'] = $base_url . '/' . $alias . '/'  . $result['cuit'] . '--' . $item['ref_number']  ;
        $item['tipoPersona'] = isset($result['razonsocial']) ? 'Juridica' : 'Fisica';
        $item['numero'] = $result['numero'];
        $items[] = $item;
      }

      return $items;
    }
  }
