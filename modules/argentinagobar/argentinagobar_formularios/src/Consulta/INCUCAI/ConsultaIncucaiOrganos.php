<?php

class ConsultaIncucaiOrganos extends ConsultaIncucai
{

  function get_endpoint()
  {
    return variable_get('consulta_incucai_organos_endpoint', NULL);
  }

    function get_params()
  {
    $parametros = array();
    $parametros['id_tipo_documento'] =  $this->values['id_tipo_documento'];
    $parametros['docnro'] =  $this->values['docnro'];
    $parametros['fecha_nacimiento'] =  $this->values['fecha_nacimiento'];

    return $parametros;
  }

  function get_request_url()
  {
    $endpoint = $this->get_endpoint();
    $params = $this->get_params();

    //agrego el doc a la URL para que quede el parámetro organos/:documento
    $endpoint = $endpoint . '/' . $params['docnro'];

    //una vez que lo usé arriba lo elimino del query string
    unset($params['docnro']);

    if(is_null($endpoint) || $enpoint = '') {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }

    return $endpoint . '?' . http_build_query($params);
  }

  function get_response($request)
  {
    $response = null;
    //si el status code es 404 significa que la persona no expresó su voluntad
    if ($request->code == 404) {

      //valido que sea mayor de edad
      if ($this->mayorDeEdad($this->values['fecha_nacimiento'])) {
        $response = theme('response_incucai_menor_edad');
      } else {
          global $base_url;
          $url = $base_url . '/donar-organos/formulario';
        $data = drupal_json_decode($request->data);
        $response = theme('response_incucai_no_expreso', array(
            'url' => $url,
        ));
      }
  }

    //si el status code es 401 hay que pedir nuevamente el token
    if ($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    //si el status code es 200 la persona expresó su volutand, ya sea por si o por no
    if ($request->code == 200) {

    $data = drupal_json_decode($request->data);

      $credencial = $data['credencial'];

      //muestro el botón de descarga sólo si me envían una credencial
      if($credencial == null){
        $credencialAPasar = '';
      }else{
        $credencialAPasar = '<a href="' . $credencial . '" class="btn btn-success btn-block m-t-2"> DESCARGÁ TU CREDENCIAL</a>';
      }

      //dejo sólo la fecha y saco la hora que viene de API
      $fecha_registro = substr($data['fecha_registro'], 0, 10);

      //convierto formato fecha de YYYY-MM-DD a DD-MM-YYYY
      $fecha_registro = date("d-m-Y", strtotime($fecha_registro));

      //esto lo hago por si el estado es pendiente (sólo sucede en órganos)
      //en dicho caso debo cambiarle el template por el de sin confirmación
      if ($data['situacion_donante'] != 'PENDIENTE') {

        $response = theme('response_incucai_donante_organos',array(
          'nombre' => $data['nombre'],
          'apellido' => $data['apellido'],
          'doctipo' => $data['doctipo'],
          'docnro' => $data['nro_documento'],
          'voluntad' => $data['donante'],
          'credencial' => $credencialAPasar,
          'fecha_registro' => $fecha_registro,
        ));
      } else {
        $response = theme('response_incucai_donante_sin_confirmacion');
      }
    }

    return $response;
  }
}
