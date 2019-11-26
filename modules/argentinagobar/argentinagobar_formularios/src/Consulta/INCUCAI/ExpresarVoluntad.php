<?php

class ExpresarVoluntad extends ConsultaPOST
{
    function get_form($form, &$form_state, $consulta)
    {

        $required = true;

        $manifestacion = array(
            'si' => 'Quiero ser donante',
            'no' => 'No quiero ser donante',
        );

        $sexos = array(
            'm' => 'Masculino',
            'f' => 'Femenino',
        );

        $partidos = [];
        $partido_disabled = true;

        if(
            isset($form_state['values']['provincia']) &&
            $form_state['values']['provincia'] != ''
        ) {

          $consulta = new ConsultaIncucaiPartidos(ApiGatewayAuth::getInstance());

          $consulta->set_values($form_state['values']);

          $partidoRes = $consulta->consultar()['results'];

          $partidos = array();

          foreach ($partidoRes as $partido)
          {
            $partidos[$partido['id']] = $partido['descripcion'];
          }

          $partido_disabled = FALSE;

          if($form_state['storage']['provincia'] != $form_state['values']['provincia']){
            $form_state['values']['partido'] = null;
          }

          $localidades = array();
          $localidades_disabled = TRUE;

        }

        $form_state['storage']['provincia'] = $form_state['values']['provincia'];

        if(
            isset($form_state['values']['partido']) &&
            $form_state['values']['partido'] != ''
        ) {

          $consulta = new ConsultaIncucaiLocalidades(ApiGatewayAuth::getInstance());

          $consulta->set_values($form_state['values']);

          $localRes = $consulta->consultar()['results'];
          $localidades = array();
          foreach ($localRes as $localidad)
          {
            $localidades[$localidad['id']] = $localidad['descripcion'];
          }
          $localidad_disabled = FALSE;

        }
        else
        {

          $localidades = array();

          $localidad_disabled = TRUE;

        }


        $form = array();

        $wrapper = new FieldContainer('wrapper');
        $form['wrapper'] = $wrapper->render();

        $form['wrapper']['manifestacion_voluntad'] = array(
            '#markup' => '<div class="row"><div class="col-md-12 form-group">
              <h3 class="m-b-1">Manifestación de voluntad expresa</h3>
              <hr class="m-b-0 m-t-0">
              </div></div>'
        );

        $voluntad = new FieldRadios('Manifestación');

        $form['wrapper']['voluntad'] = $voluntad->render();
        $form['wrapper']['voluntad']['#attributes']['data-description-si'] = t('Manifestación afirmativa a la donación de órganos y tejidos');
        $form['wrapper']['voluntad']['#attributes']['data-description-no'] = t('Manifestación negativa a la donación de órganos y tejidos');
        $form['wrapper']['voluntad']['#theme'] = 'radios_manifestacion';


        $form['wrapper']['datos_personales'] = array(
            '#markup' => '<div class="row"><div class="col-md-12 form-group">
            <h3 class="m-b-1">Datos Personales</h3>
            <hr class="m-b-0 m-t-0">
            </div></div>'
        );

        $tipoDocumento = new FieldSelect('Tipo de Documento', $this->tipo_documento());
        $tipoDocumento->set_required($required);
        $form['wrapper']['tipo_doc'] = $tipoDocumento->render();
        $form['wrapper']['tipo_doc']['#prefix'] = '<div class="row"><div class="col-md-5">';
        $form['wrapper']['tipo_doc']['#suffix'] = '</div>';

        $dni = new FieldDNI('Número de documento');
        $dni->set_required($required);
        $dni->set_maxlength(12);
        $form['wrapper']['num_doc'] = $dni->render();
        $form['wrapper']['num_doc']['#prefix'] = '<div class="col-md-7">';
        $form['wrapper']['num_doc']['#suffix'] = '</div></div>';

        $apellido = new FieldApellido('Apellido');
        $apellido->set_maxlength(40);
        $apellido->set_required($required);
        $form['wrapper']['apellido'] = $apellido->render();

        $nombre = new FieldNombre('Nombre');
        $nombre->set_maxlength(40);
        $nombre->set_required($required);
        $form['wrapper']['nombre'] = $nombre->render();

        $form['wrapper']['fecha_nacimiento'] = array(
          '#type' => 'date_popup',
          '#title' => t('Fecha de nacimiento'),
          '#date_format' => 'd-m-Y',
          '#required' => $required,
          '#default_value' =>  time(),
          '#date_year_range' => '-200:+0',
          '#theme' => array('form_element_date_no_calendar'),
          '#title_display' => 'invisible',
        );

        $sexo = new FieldRadios('Sexo');
        $sexo->set_options($sexos);
        $sexo->set_required($required);
        $form['wrapper']['sexo'] = $sexo->render();
        $form['wrapper']['sexo']['#default_value'] = $form_state['values']['sexo'];
        // $form['wrapper']['sexo']['#theme'] = 'form_element_radios_inline';

        $estado_civil = new FieldSelect('Estado civil', $this->consulta_estados_civiles());
        $form['wrapper']['estado_civil'] = $estado_civil->render();
        $form['wrapper']['estado_civil']['#empty_value'] = '';
        $form['wrapper']['estado_civil']['#default_value'] = isset($form_state['values']['estado_civil']) ? $form_state['values']['estado_civil'] : '';

        $form['wrapper']['datos_contacto'] = array(
            '#markup' => '<div class="row"><div class="col-md-12 form-group">
            <h3 class="m-b-1">Datos de contacto</h3>
            <hr class="m-b-0 m-t-0">
            </div></div>'
        );

        $email = new FieldEmail('Correo electrónico');
        $email->set_required($required);
        $form['wrapper']['email'] = $email->render();

        $prefijo = new FieldNumeric('Prefijo');
        $prefijo->set_maxlength(4);
        $prefijo->set_required($required);
        $form['wrapper']['prefijo'] = $prefijo->render();
        $form['wrapper']['prefijo']['#theme'] = 'form_element_prefijo';
        $form['wrapper']['prefijo']['#prefix'] = '<div class="row"><div class="col-md-6">';
        $form['wrapper']['prefijo']['#suffix'] = '</div>';

        $telefono = new FieldNumeric('Teléfono Móvil');
        $telefono->set_required($required);
        $telefono->set_maxlength(15);
        $form['wrapper']['telefono'] = $telefono->render();
        $form['wrapper']['telefono']['#theme'] = 'form_element_telefono_movil';
        $form['wrapper']['telefono']['#prefix'] = '<div class="col-md-6">';
        $form['wrapper']['telefono']['#suffix'] = '</div></div>';

        $provincia = new FieldSelect('Provincia',  $this->consulta_provincias());
        $provincia->set_required($required);
        $form['wrapper']['provincia'] = $provincia->render();
        $form['wrapper']['provincia']['#empty_value'] = '';
        $form['wrapper']['provincia']['#ajax'] = array(
            'callback' => 'return_form',
            'event' => 'change',
            'wrapper' => 'wrapper',
            'method' => 'replace',
            'effect' => 'none',
            'progress' => FALSE
        );

        $partido = new FieldSelect('Partido', $partidos);
        $partido->set_required($required);
        $form['wrapper']['partido'] = $partido->render();
        $form['wrapper']['partido']['#disabled'] = false;
        $form['wrapper']['partido']['#empty_value'] = '';
        $form['wrapper']['partido']['#default_value'] = isset($form_state['values']['partido']) ? $form_state['values']['partido'] : '';
        $form['wrapper']['partido']['#ajax'] = array(
            'callback' => 'return_form',
            'event' => 'change',
            'wrapper' => 'wrapper',
            'method' => 'replace',
            'effect' => 'none',
            'progress' => FALSE
        );

        $localidad = new FieldSelect('Localidad', $localidades);
        $localidad->set_required($required);
        $form['wrapper']['localidad'] = $localidad->render();
        $form['wrapper']['localidad']['#disabled'] = false;
        $form['wrapper']['localidad']['#default_value'] = isset($form_state['values']['localidad']) ? $form_state['values']['localidad'] : '';
        $form['wrapper']['localidad']['#empty_value'] = '';

        $calle = new FieldTextfield('Calle');
        $calle->set_maxlength(50);
        $calle->set_required($required);
        $form['wrapper']['calle'] = $calle->render();
        $form['wrapper']['calle']['#prefix'] = '<div class="row"><div class="col-md-6">';
        $form['wrapper']['calle']['#suffix'] = '</div>';

        $numero = new FieldNumeric('Número');
        $numero->set_maxlength(6);
        $numero->set_required($required);
        $form['wrapper']['numero'] = $numero->render();
        $form['wrapper']['numero']['#prefix'] = '<div class="col-md-6">';
        $form['wrapper']['numero']['#suffix'] = '</div></div>';

        $piso = new FieldNumeric('Piso');
        $piso->set_maxlength(2);
        $form['wrapper']['piso'] = $piso->render();
        $form['wrapper']['piso']['#prefix'] = '<div class="row"><div class="col-md-6">';
        $form['wrapper']['piso']['#suffix'] = '</div>';

        $departamento = new FieldTextfield('Departamento');
        $departamento->set_maxlength(4);
        $form['wrapper']['departamento'] = $departamento->render();
        $form['wrapper']['departamento']['#prefix'] = '<div class="col-md-6">';
        $form['wrapper']['departamento']['#suffix'] = '</div></div>';


        $form['wrapper']['familiar'] = array(
            '#markup' => '<div class="row"><div class="col-md-12 form-group">
          <h3 class="m-b-1">Datos del familiar o amigo a quién comunico mi decisión (opcional)</h3>
          <hr class="m-b-0 m-t-0">
          </div></div>'
        );

        $nombre_familiar = new FieldNombre('Nombre');
        $nombre_familiar->set_maxlength(40);
        $form['wrapper']['nombre_familiar'] = $nombre_familiar->render();

        $apellido_familiar = new FieldNombre('Apellido');
        $apellido_familiar->set_maxlength(40);
        $form['wrapper']['apellido_familiar'] = $apellido_familiar->render();

        $vinculo = new FieldTextfield('Vínculo');
        $vinculo->set_maxlength(10);
        $form['wrapper']['vinculo'] = $vinculo->render();

        $prefijo_familiar = new FieldNumeric('Prefijo');
        $prefijo_familiar->set_maxlength(4);
        $form['wrapper']['prefijo_familiar'] = $prefijo_familiar->render();
        // $form['wrapper']['prefijo_familiar']['#title_display'] = 'invisible';
        $form['wrapper']['prefijo_familiar']['#theme'] = 'form_element_prefijo';
        $form['wrapper']['prefijo_familiar']['#prefix'] = '<div class="row"><div class="col-md-6">';
        $form['wrapper']['prefijo_familiar']['#suffix'] = '</div>';

        $telefono_familiar = new FieldNumeric('Teléfono Móvil');
        $telefono_familiar->set_maxlength(15);
        $form['wrapper']['telefono_familiar'] = $telefono_familiar->render();
        $form['wrapper']['telefono_familiar']['#theme'] = 'form_element_telefono_movil';
        $form['wrapper']['telefono_familiar']['#prefix'] = '<div class="col-md-6">';
        $form['wrapper']['telefono_familiar']['#suffix'] = '</div></div>';

        $email_familiar = new FieldEmail('Correo electrónico ');
        $form['wrapper']['email_familiar'] = $email_familiar->render();

        $submit = new FieldSubmitAJAX('Continuar');
        $submit->addClass('btn-block');
        $submit->addClass('btn-success');
        $submit->addClass('btn-lg');
        $form['wrapper']['submit'] = $submit->render();

        $response = new FieldContainer('response');
        $form['wrapper']['response'] = $response->render();

        $form_state['handler']['class'] = serialize($this);


        if ($this->hayParametros()) {

          $this->setValues($this->getParametros());

          $response = $this->consultar();
          $form['response'] = array(
            '#type' => 'markup',
            '#markup' => $this->renderResponse($form, $form_state, $response),
          );

      } else {
                $form['response'] = array(
                    '#type' => 'container',
                    '#attributes' => array(
                        'id' => 'response'
                    ),
                );
            }

            $consultas = array(
                'ConsultaIncucaiTipoDocumento',
                'ConsultaIncucaiEstadoCivil',
                'ConsultaIncucaiProvincias',
                'ConsultaIncucaiPartidos',
                'ConsultaIncucaiLocalidades',
            );

            $apiAuth = ApiGatewayAuth::getInstance();

            $verif = $this->salud_general($consultas,$apiAuth);

            if (!$verif) {
                $form['wrapper'] = array(
                    '#type' => 'container',
                    '#attributes' => array(
                        'id' => 'contenedor',
                    ),
                );

                $form['wrapper']['response'] = array(
                    '#type' => 'markup',
                    '#markup' => theme('incucai_respuesta_error')
                );
            }

        return $form;
    }

    function tipo_documento()
    {
        $consulta_tipo_documento = new ConsultaIncucaiTipoDocumento(ApiGatewayAuth::getInstance());
        $res = $consulta_tipo_documento->consultar()['results'];
        $tipos = array();

        foreach ($res as $tipo) {
            $tipos[$tipo['id_tipo_documento']] = $tipo['descripcion'];

        }

        return $tipos;
    }

    function consulta_estados_civiles()
    {
        $consultaEstados = new ConsultaIncucaiEstadoCivil(ApiGatewayAuth::getInstance());

        $estados = $consultaEstados->consultar()['results'];
        $estadosRes = array();

        foreach ($estados as $estado) {
            $estadosRes[$estado['id']] = $estado['descripcion'];

        }

        return $estadosRes;
    }

    function consulta_provincias()
    {
        $consultaProvincias = new ConsultaIncucaiProvincias(ApiGatewayAuth::getInstance());

        $provincias = $consultaProvincias->consultar();
        $provRes = array();

        foreach ($provincias['results'] as $provincia) {
            $provRes[$provincia['id']] = $provincia['descripcion'];

        }

        return $provRes;

    }

    function get_headers()
    {
      return array(
        'Authorization' => 'Bearer ' . $this->api_gateway_auth->getAccessToken(),
        'Content-Type' => 'application/x-www-form-urlencoded',
        'Accept' => 'application/json',
      );
    }



    function get_params()
    {
        $pref = !empty($this->values['prefijo']) ? 0 : '';
        $tel = !empty($this->values['telefono']) ? 15 : '';

        $pref_fam = !empty($this->values['prefijo_familiar']) ? 0 : '';
        $tel_fam = !empty($this->values['telefono_familiar']) ? 15 : '';

        $telefono = $pref . $this->values['prefijo'] . $tel . $this->values['telefono'];
        $telefono_familiar = $pref_fam . $this->values['prefijo_familiar'] . $tel_fam . $this->values['telefono_familiar'];

        $data = array(
            'id_tipo_documento' => $this->values['tipo_doc'],
            'docnro' => $this->values['num_doc'],
            'fecha_nacimiento' => $this->values['fecha_nacimiento'],
        );

        global $base_url;
        $url = $base_url . '/donar-organos/confirmacion/';

      return http_build_query([
          'id_tipo_documento' => isset($this->values['tipo_doc']) ? $this->values['tipo_doc'] : '',
          'nro_documento' => isset($this->values['num_doc']) ? $this->values['num_doc'] : '',
          'apellido' => isset($this->values['apellido']) ? $this->values['apellido'] : '',
          'nombre' => isset($this->values['nombre']) ? $this->values['nombre'] : '' ,
          'sexo' => isset($this->values['sexo']) ? strtoupper($this->values['sexo']) : '',
          'mail' => isset($this->values['email']) ? $this->values['email'] : '',
          'fecha_nacimiento' => isset($this->values['fecha_nacimiento']) ? $this->values['fecha_nacimiento'] : '',
          'calle' => isset($this->values['calle']) ? $this->values['calle'] : '',
          'numero' => isset($this->values['numero']) ? $this->values['numero'] : '',
          'telefono' => isset($telefono) ? $telefono : '',
          'id_provincia' => isset($this->values['provincia']) ? $this->values['provincia'] : '',
          'id_partido' => isset($this->values['partido']) ? $this->values['partido'] : '',
          'id_localidad' => isset($this->values['localidad']) ? $this->values['localidad'] : '',
          'id_estado_civil' => isset($this->values['estado_civil']) ? $this->values['estado_civil'] : '',
          'donante' => isset($this->values['voluntad']) ? strtoupper($this->values['voluntad']) : '',
          'confirmado' => 'NO',
          'nombre_familiar' => isset($this->values['nombre_familiar']) ? $this->values['nombre_familiar'] : '',
          'apellido_familiar' => isset($this->values['apellido_familiar']) ? $this->values['apellido_familiar'] : '',
          'vinculo' => isset($this->values['vinculo']) ? $this->values['vinculo'] : '',
          'telefono_familiar' => isset($this->values['telefono_familiar']) ? $this->values['telefono_familiar'] : '',
          'mail_familiar' => isset($this->values['email_familiar']) ? $this->values['email_familiar'] : '',
          'piso' => isset($this->values['piso']) ? $this->values['piso'] : '',
          'departamento' => isset($this->values['departamento']) ? $this->values['departamento'] : '',
          'url_validacion' => $url . encode_parameters($data),
      ]);
    }

    function handleError($request)
    {
        if($request->code == 500){
            throw new ConsultaErrorException($request->error);
        }
    }

    function get_endpoint()
    {
      return variable_get('donante', NULL);
    }

    function get_response($request)
    {
      $response = NULL;
      $data = drupal_json_decode($request->data);

      if($request->code == 401){

          $this->api_gateway_auth->refresh_token();
          $this->consultar();
      }

      if($request->code != 200) {

          $data = drupal_json_decode($request->data);

          $status = $data['status'];
          $userMessage = $data['userMessage'];
          $developerMessage = $data['developerMessage'];
          $errorCode = $data['errorCode'];

        switch ($errorCode) {
            case '002':
                $texto = 'Ya existe en la Base de Datos de SINTRA un registro de donante con el Número de Documento enviado.';
            break;

            case '003':
                $texto = 'El usuario ingresó una Fecha de nacimiento que indica que es menor de edad.';
            break;

            case '010':
                $texto = 'Ocurrió un error de datos al intentar dar de alta el registro. Intenta mas tarde';
           break;

           default:
                $texto = 'En este momento el servicio no responde. Por favor, intentalo más tarde';
            break;
       }

          watchdog('AR Formularios', '<p>Error code: ' . $errorCode .' Status: '. $status .'<br> Mensaje: ' . $userMessage  . '/' . $developerMessage . '</p>' . '<pre>' . '</pre>', $variables = array(), $severity = WATCHDOG_ERROR, $link = NULL);

          $response = theme('incucai_respuesta_error', array(
              'texto' => $texto,
          ));

      }

      if($request->code == 200){

          $response = theme('incucai_respuesta_voluntad');
      }

      $form['contenedor'] = array(
          '#type' => 'container',
          '#attributes' => array(
              'id' => 'contenedor',
          ),
      );

      $form['contenedor']['response'] = array(
          '#type' => 'markup',
          '#markup' => $response,
      );
      return $form;
  }
}

function return_form($form, &$form_state)
{
  return $form;
}
