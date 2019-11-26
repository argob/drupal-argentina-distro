<?php

class ConsultaBeneficios extends Consulta {
    private $consulta_beneficios_endpoint;

  function __construct($api_gateway_auth, $values){
    $this->api_gateway_auth = $api_gateway_auth;
    $this->values = $values;
    $this->consulta_beneficios_endpoint = variable_get('consulta_beneficios_client_endpoint', NULL);
  }
  function consultar(){
    $params = array(
      'cuil' => $this->values['cuil'],
    );

    $access_token = $this->api_gateway_auth->getAccessToken();
    $url = $this->consulta_beneficios_endpoint . '/' . $params['cuil'];
    $options = array(
      'headers' => array('Authorization' => 'Bearer ' . $access_token),
    );

    $request = drupal_http_request($url, $options);

    if($request->code == 401 || $request->code == 400){
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if($request->code == 200){
      $data = drupal_json_decode($request->data);

      $legajo = array();

      switch ($data['estadoExistenciaLegajo']) {
        case 'VERDE':
          $legajo['color'] = 'text-success';
          $legajo['icono'] = 'fa-check-circle fa-3x';
          $legajo['texto'] = 'aplica para los beneficios';
          $legajo['sub_texto'] ="";
          break;
        case 'AMARILLO':
          $legajo['color'] = 'text-warning';
          $legajo['icono'] = 'fa-warning fa-3x';
          $legajo['texto'] = 'no aplica para los beneficios';
          $legajo['sub_texto'] = '"Consultá al responsable de RRHH de tu repartición para conocer como podes cargar todos tus datos en LUE y poder acceder a estos beneficios”';
          break;
        case 'ROJO':
          $legajo['color'] = 'text-danger';
          $legajo['icono'] = 'fa-warning fa-3x';
          $legajo['texto'] = 'no aplica para los beneficios';
          $legajo['sub_texto'] = "";
          break;
      }

      $response = theme('response_beneficios', array(
        'legajo' => $legajo,
        'cuil' => $this->values['cuil'],
        )
      );
    }else
      {
        drupal_set_message('Ha ocurrido un error, vuelva a intentarlo mas tarde', $type = 'error', $repeat = FALSE);
        watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);
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
