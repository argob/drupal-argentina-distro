<?php

/**
 * Class ConsultaLicenciaConducir
 */
class ConsultaLicenciaConducir extends Consulta{

  private $consulta_licencia_conducir_endpoint;

  function __construct($api_gateway_auth, $values){
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consulta_licencia_conducir_endpoint = variable_get('consulta_licencia_conducir_client_endpoint', NULL);
  }

  function consultar(){

    $document_type = array(
      '1' => t('DNI'),
      '2' => t('Libreta Cívica'),
      '3' => t('Libreta de Enrolamiento'),
      '4' => t('Pasaporte'),
      '5' => t('Cédula de Identidad Extranjera'),
    );

    $params = array(
      'document_type' => $this->values['document_type'],
      'document_number' => $this->values['document_number'],
      'gender' => $this->values['gender'],
    );

    $access_token = $this->api_gateway_auth->getAccessToken();

    $data = http_build_query($params);

    $url = $this->consulta_licencia_conducir_endpoint . '?' . $data;

    $options = array(
      'headers' => array('Authorization' => 'Bearer ' . $access_token),
    );

    $request = drupal_http_request($url, $options);

    if($request->code == 401){
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if($request->code == 404 || $request->code == 400){
      $titulo = t('Esta identidad no está asociada a una Licencia Nacional de Conducir');
      $subtitulo = $titulo . '<p>' . t('Puede que sí esté asociada a una licencia Provincial  Municipal') . '</p>';
      $feedback_data = array('titulo' => $titulo,
        'datos_licencia' => array(),
      );

      $response = theme('response_panel_error', array('data' => $feedback_data , 'titulo' => $subtitulo));
    }

    if($request->code == 200){
      
      $data             = drupal_json_decode($request->data);
      $array_paneles[]  = $this->crear_panel($data);

      $response = theme('response_panel_completo', array(
        'titulo' => t('Esta es la información de la licencia'),
        'paneles' => $array_paneles,
        'href' => drupal_lookup_path('alias', current_path()),
        'subtitulo' => t('(Esta información no reemplaza a la licencia, por lo que no es válida para conducir)'),
        'leyenda' => t('<br /> La presente no refleja aptitud para conducir, toda vez que el titular puede encontrarse inhabilitado por decisión judicial y/o administrativa</strong>'),
        'footer'  => theme('response_panel_footer'),
        )
      );
    }

    $form['contenedor'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'contenedor',
      ),
    );

    if(isset($response)){
      $form['contenedor']['response'] = array(
        '#type' => 'markup',
        '#markup' => $response,
      );
    }
    else{
      $form['contenedor']['response'] = array(
        '#type' => 'markup',
      );
    }

    return $form;
  }

  private function crear_panel($data) {

    $tipo_documento ="";

    switch ($data['document_type']){
      case 1:
        $tipo_documento = 'DNI';
        break;
      case 2:
        $tipo_documento = 'Libreta Cívica';
        break;
      case 3:
        $tipo_documento = 'Libreta de Enrolamiento';
        break;
      case 4:
        $tipo_documento = 'Pasaporte';
        break;
      case 5:
        $tipo_documento = 'Cédula de Identidad Extranjera';
        break;
    }

    $info = array(
      'titulo' => t('Datos de la licencia:'),
      'data' => array(
        array(
          'label' => t('Clase'),
          'value' => t(l($data['classes'], 'node/7269'))
        ),
        array(
          'label' => t('Vencimiento'),
          'value' => t($data['expiration_date'])
        ), #queda penediente el caso de que piso y departamento vengan vacios
        array(
          'label' => t('Emitida'),
          'value' => t($data['valid_from'])
        ),
        array(
          'label' => t('Localidad de emisión'),
          'value' => t($data['emission_center'])
        ),
        array(
          'label' => t('Provincia'),
          'value' => t($data['province'])
        ),
        array(
          'label' => t('Nombre y apellido'),
          'value' => t($data['first_name'] . ' ' . $data['last_name'])
        ),
        array(
          'label' => t('Tipo y número de documento'),
          'value' => t( $tipo_documento . ' ' . $data['document_number'])
        ),
      )
    );
    return theme('response_panel', $info);
  }
}
