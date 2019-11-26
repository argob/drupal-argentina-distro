<?php
  class ConsultaExpedientes extends Consulta
   {

     protected function getFieldSubmit()
     {

       return $submitButton;
     }

    function get_form($form, &$form_state, $consulta)
    {
        $required = true;

        $options = array(
            'APN',
            'INSSJP',
        );

        $form = array();

        // //CSS
        // $form['#attached']['css'][] = array(
        //   'type' => 'file',
        //   'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/css/ConsultaExpedientes/ConsultaExpedientes.css',
        // );


        $wrapper = new FieldContainer('wrapper');
        $form['wrapper'] = $wrapper->render();

        $response = new FieldContainer('response');
        $form['wrapper']['response'] = $response->render();

        $anioExp = new FieldNumeric('Año');
        $anioExp->set_required($required);
        $anioExp->set_maxlength(4);
        $form['wrapper']['anioExp'] = $anioExp->render();
        $form['wrapper']['anioExp']['#prefix'] = '<div class=row><div class="col-md-3">';
        $form['wrapper']['anioExp']['#suffix'] = '</div>';
        $form['wrapper']['anioExp']['#rules'] = array('numeric', 'length[4]', 'notOnlySpaces');
        $form['wrapper']['anioExp']['#theme'] = 'form_element_addon';
        $form['wrapper']['anioExp']['#attributes']['data-input-group-addon-left-text'] = 'EX-';


        $numero = new FieldNumeric('Número');
        $numero->set_required($required);
        $form['wrapper']['numero'] = $numero->render();
        $form['wrapper']['numero']['#prefix'] = '<div class="col-md-3">';
        $form['wrapper']['numero']['#suffix'] = '</div>';
        $form['wrapper']['numero']['#rules'] = array('numeric', 'length[3, 16]', 'notOnlySpaces');
        $form['wrapper']['numero']['#theme'] = 'form_element_addon';
        $form['wrapper']['numero']['#attributes']['data-input-group-addon-left-text'] = '-';

        $codRepA = new FieldSelect('');
        $codRepA->set_options($options);
        $form['wrapper']['codRepA'] = $codRepA->render();
        $form['wrapper']['codRepA']['#prefix'] = '<div class="col-md-2">';
        $form['wrapper']['codRepA']['#suffix'] = '</div>';
        $form['wrapper']['codRepA']['#default_value'] = 'APN';

        $codRepB = new FieldTextfield('Código de repartición');
        $codRepB->set_required($required);
        $form['wrapper']['codRepB'] = $codRepB->render();
        $form['wrapper']['codRepB']['#prefix'] = '<div class="col-md-4">';
        $form['wrapper']['codRepB']['#suffix'] = '</div>';
        $form['wrapper']['codRepB']['#rules'] = array('length[3, 20]', 'notOnlySpaces');

        $submitButton = new FieldSubmitAJAX();
        $submitButton->addClass('btn-success');
        $submitButton->addClass('btn-block');
        $submitButton->setValue("Enviar");
        $submitButton->addClass('m-t-2');

        $form['wrapper']['submit'] = $submitButton->render();
        $form['wrapper']['submit']['#prefix'] = '<div class="col-md-8 col-md-offset-2">';
        $form['wrapper']['submit']['#suffix'] = '</div>';

        # serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
        $form_state['handler']['class'] = serialize($this);

        return $form;
    }

    function get_params()
    {
      global $value;
      $value = null;

      switch ($this->values['codRepA']) {
        case '0':
          $value = 'APN';
          break;
        case '1':
          $value = 'INSSJP';
          break;
      }

      $params = array(
        'tipo_actuacion' => 'EX-',
        'year' => $this->values['anioExp'].'-',
        'numero_expediente' => $this->values['numero'].'--',
        'codigo_reparticion_actuacion' => $value.'-',
        'codigo_reparticion_usuario' => mb_strtoupper($this->values['codRepB']),
      );

      return http_build_query($params);

    }

    function get_endpoint()
    {
      return variable_get('consulta_pami_endpoint', NULL);
    }

    function get_request_url()
    {
      $endpoint = $this->get_endpoint();
      $params = $this->get_params();

      if (!isset($endpoint)) {
        throw new EndpointNuloException("Falta endpoint para Consulta Exp/PAMI", 1);
      }

        $urlconsulta = $endpoint.'?'.$params.'/';

      return $urlconsulta;
    }


    function get_request()
    {
      $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());

      return $request;
    }

    function get_response($request)
    {
      $response = NULL;
      $data = NULL;

      global $value;
      $var_error = array(
        'tipo_actuacion' => 'EX',
        'year' => $this->values['anioExp'],
        'numero_expediente' => $this->values['numero'],
        'codigo_reparticion_actuacion' => $value,
        'codigo_reparticion_usuario' => $this->values['codRepB'],
      );

      if(empty($request) || !isset($request) || $request->error == 'missing schema'){
        $response = theme('expedientes_error');
      }

      if($request->code == 401)
      {
        $this->api_gateway_auth->refresh_token();
        $this->consultar();
      }

      if ($request->code == 500 || $request->code == 503) {

        //throw new ConsultaException('El servicio de Expedientes no esta funcionando', 1);
        $response = theme('expedientes_error');

      }

      if ($request->code == 400 || $request->code == 404) {
        $response = theme('expedientes_no_se_encontro', $var_error);
      }

      if($request->code == 200){

        $data = drupal_json_decode($request->data);

          if($data != null ){
            $theme = 'expedientes_ok';
            $response = theme('expedientes_ok', array(
              'data' => $data,
            ));
          }else {
            $response = theme('expedientes_no_se_encontro', $var_error);
          }
      }

      return $response;

    }
  }
