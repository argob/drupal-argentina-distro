<?php
  class ConsultaAnses extends Consulta
  {

    function get_form($form, &$form_state, $consulta)
    {

      $form = [];
      $options = array(
        'cuil' => 'CUIL',
        'beneficio-anses' => 'Beneficio',
      );

      $wrapper = new FieldContainer('wrapper');
      $form['wrapper'] = $wrapper->render();

      $response = new FieldContainer('response');
      $form['wrapper']['response'] = $response->render();

      $option = new FieldRadios('Opciones');
      $option->set_required(true);
      $option->set_options($options);

      $form['wrapper']['options'] = $option->render();
      $form['wrapper']['options']['#theme'] = 'form_element_radios_inline';

      $cuil = new FieldNumeric('Número');
      $form['wrapper']['cuil'] = $cuil->render();
      $form['wrapper']['cuil']['#rules'] = array('validCuit');
      $form['wrapper']['cuil']['#states'] = array(
        'visible' => array(
          ':input[name="options"]' => array('value' => 'cuil'),
        ),
      );

      $benef = new FieldNumeric('Beneficio');
      $form['wrapper']['benef'] = $benef->render();
      $form['wrapper']['benef']['#states'] = array(
        'invisible' => array(
          ':input[name="options"]' => array('value' => 'cuil'),
        ),
      );

      $submitButton = new FieldSubmitAJAX();
      $submitButton->addClass('btn-success');
      $submitButton->addClass('btn-block');
      $submitButton->setValue("Consulta");

      $form['wrapper']['submit'] = $submitButton->render();
      $form_state['handler']['class'] = serialize($this);

      return $form;

    }

    function get_params()
    {
      $value = null;

      if(isset($this->values['options']) && $this->values['options'] == 'cuil') {
        $value = $this->values['cuil'];
      }
      else {
        $value = isset($this->values['benef']) ? $this->values['benef'] : null ;
      }


      return http_build_query([

        'cuil' => $value,

      ]);

    }

    function get_endpoint()
    {
      return variable_get('cuil', NULL);
    }


    function get_request_url()
    {
      $endpoint = $this->get_endpoint();
      $params = $this->get_params();


      if (is_null($endpoint) || $enpoint = '') {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }

      return $endpoint . '?' . $params;
    }

    function get_request()
    {
      $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
      return $request;
    }

    function get_response($request)
    {

      if ($request->code == 200 ){



        $data = drupal_json_decode($request->data);

        if(!empty($data['results'])) {

          foreach ($data['results'] as $result){

            $respuesta = $this->getBeneficios($result);

              if(empty($respuesta)) {

                $response ='404';
              }else{

                $response[] = $respuesta;
              }

          }
        }
        else{
          $response = '404';
        }
      }

      return $response;

    }
    function getBeneficios($num)
    {
      $benef =  new ConsultaAnsesDetalle(ApiGatewayAuth::getInstance(),$num);
      return  $benef->consultar();
    }

    function renderResponse($form, &$form_state, $response)
    {
      switch ($response) {
        case '500':
          $theme = 'cuando_cobro_error';
          break;
        case '404':
          $theme = 'cuando_cobro_no_se_encontro';
          break;
        default:
          $theme = 'cuando_cobro';

      }
      if ($response[0] == []){
        $theme = 'cuando_cobro_no_se_encontro';
      }
//
      return theme($theme, ['beneficios' => $response,]);
    }
  }
