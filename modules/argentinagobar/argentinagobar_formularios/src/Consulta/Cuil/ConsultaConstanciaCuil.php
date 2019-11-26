<?php
  class ConsultaConstanciaCuil extends Consulta
   {

     protected function getFieldSubmit()
     {

       return $submitButton;
     }

    function get_form($form, &$form_state, $consulta)
    {

        $options = array(
          '29' => 'DNI',
          '25' => 'Libreta de Enrolamiento',
          '26' => 'Libreta Cívica',
          '00' => 'Otros',
        );

        $sexos = array(
            'm' => 'Masculino',
            'f' => 'Femenino',
        );

        $form = array();

        $wrapper = new FieldContainer('wrapper');
        $form['wrapper'] = $wrapper->render();

        $response = new FieldContainer('response');
        $form['wrapper']['response'] = $response->render();

        $tipoDocumento = new FieldSelect('Tipo de Documento');
        $tipoDocumento->set_options($options);
        $form['wrapper']['tipo_doc'] = $tipoDocumento->render();
        $form['wrapper']['tipo_doc']['#prefix'] = '<div class=row><div class="col-md-5">';
        $form['wrapper']['tipo_doc']['#suffix'] = '</div>';

        $dni = new FieldDNI('Número de documento');
        $dni->set_required(TRUE);
        $dni->set_maxlength(12);
        $form['wrapper']['num_doc'] = $dni->render();
        $form['wrapper']['num_doc']['#prefix'] = '<div class="col-md-7">';
        $form['wrapper']['num_doc']['#suffix'] = '</div></div>';

        $nombre = new FieldNombre('Nombre');
        $nombre->set_required(TRUE);
        $form['wrapper']['nombre'] = $nombre->render();

        $apellido = new FieldApellido('Apellido');
        $apellido->set_required(TRUE);
        $form['wrapper']['apellido'] = $apellido->render();

        $sexo = new FieldRadios('Sexo');
        $sexo->set_options($sexos);
        $sexo->set_required(TRUE);
        $form['wrapper']['sexo'] = $sexo->render();
        $form['wrapper']['sexo']['#theme'] = 'form_element_radios_inline';


        $birthdate = new FieldBirthdate();
        $birthdate->set_required(TRUE);
        $form['wrapper']['fecha_nacimiento'] = $birthdate->render();
        $form['wrapper']['fecha_nacimiento']['#theme'] = 'form_element_date';
        $form['wrapper']['fecha_nacimiento']['#title_display'] = 'invisible';


        $submitButton = new FieldSubmitAJAX();
        $submitButton->addClass('btn-success');
        $submitButton->addClass('btn-block');
        $submitButton->setValue("Generá tu Constancia de CUIL");

        $form['wrapper']['submit'] = $submitButton->render();

        # serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
        $form_state['handler']['class'] = serialize($this);

        return $form;
    }

    function get_params()
    {
      return http_build_query(
        array(
          'apellido' => $this->values['apellido'],
          'nombre' => $this->values['nombre'],
          'fecha_nacimiento' => $this->values['fecha_nacimiento'],
          'num_doc' => $this->values['num_doc'],
          'tipo_doc' => $this->values['tipo_doc'],
          'sexo' => $this->values['sexo'],
        )
      );
    }

    function get_endpoint()
    {
      return variable_get('consulta_constancia_cuil_client_endpoint', NULL);
    }

    function handleError($request)
    {
      if($request->code != 404 || $request->code != 400) {
        parent::handleError($request);
      }
    }

    function get_request()
    {
      $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());

      return $request;
    }

    function get_response($request)
    {
      $response = NULL;
      if($request->code == 401)
      {
        $this->api_gateway_auth->refresh_token();
        $this->consultar();
      }

      if ($request->code == 400 || $request->code == 404) {
        $theme = 'response_cuil_error';
      }elseif ($request->code == 200){
        $theme = 'response_cuil_ok';
      }

      global $base_url;

      $data = drupal_json_decode($request->data);

      $nombre = $this->values['nombre'];
      $apellido = $this->values['apellido'];
      $tipo_doc = $this->values['tipo_doc'];
      $sexo = $this->values['sexo'] == 'm'? 'Masculino' : 'Femenino';
      $birthdate = date("d-m-Y", strtotime($this->values['fecha_nacimiento']));
      $num_doc = number_format($this->values['num_doc'], 0, '.', '.');

      switch ($tipo_doc) {
        case '29':
          $tipo_doc = 'DNI';
          break;
        case '25':
          $tipo_doc = 'LE';
          break;
        case '26':
          $tipo_doc = 'LC';
          break;
      }

      $pdf = isset($data['constanciaCodificada']) ? 'data:application/pdf;base64,' . $data['constanciaCodificada'] : null;

      $response = theme($theme,array(
        'nombre' => $nombre,
        'apellido' => $apellido,
        'documento' => $tipo_doc . " " . $num_doc,
        'sexo' => $sexo,
        'birthdate' => $birthdate,
        'pdf' => $pdf,
        'urlCuil' => $base_url . '/obtener-cuil',
        )
      );

      return $response;
    }
  }
