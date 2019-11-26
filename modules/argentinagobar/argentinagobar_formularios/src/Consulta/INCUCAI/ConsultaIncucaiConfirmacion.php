<?php
class ConsultaIncucaiConfirmacion extends ConsultaPost
{
    function get_endpoint()
    {
        return variable_get('consulta_incucai_organos_confirmacion_endpoint', null);
    }

    function get_params()
    {
      return http_build_query(
        array(
          'id_tipo_documento' => $this->values['id_tipo_documento'],
          'fecha_nacimiento' => $this->values['fecha_nacimiento'],
        )
      );
    }

    function get_headers()
    {
      return array(
        'Authorization' => 'Bearer ' . $this->api_gateway_auth->getAccessToken(),
        'Content-Type' => 'application/x-www-form-urlencoded',
        'Accept' => 'application/json',
      );
    }

    function get_request_url()
    {

      $endpoint = $this->get_endpoint();

      $dni = $this->values['docnro'];


      if (is_null($endpoint) || $enpoint = '') {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }

      return $endpoint . '/' . $dni .  '?' . $this->get_params() ;
    }

    function get_request()
    {
      $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());

      return $request;
    }

    function get_response($request)
    {
        $data = drupal_json_decode($request->data);

        if ($request->code == 401) {
        $this->api_gateway_auth->refresh_token();
        $this->consultar();
      }

      if ($request->code != 200){
          $response = array();
      }
      if ($request->code == 200) {

        $time = isset($data['fecha_registro']) ? strtotime($data['fecha_registro']) : '';
        $apellido = isset($data['apellido']) ? $data['apellido'] : '';
        $nombre = isset($data['nombre']) ? $data['nombre'] : '';
        $fecha_registro = date('d/m/Y',$time);
        $nro_documento = isset($data['nro_documento']) ? number_format($data['nro_documento'], 0, '.', '.') : '';
        $tipo_documento = isset($data['tipo_documento']) ? $data['tipo_documento'] : '';
        $donante = isset($data['donante']) ? $data['donante'] : '';
        $credencial = isset($data['credencial']) ? $data['credencial'] : '';
        $fecha_nacimiento = isset( $this->values['fecha_nacimiento']) ?  $this->values['fecha_nacimiento'] : '';

        $response = array(
            'nombre' => $nombre,
            'apellido' => $apellido,
            'fecha_registro' => $fecha_registro,
            'documento' => $tipo_documento . ' ' . $nro_documento,
            'fecha_nacimiento' => date('d/m/Y', strtotime($fecha_nacimiento)),
            'donante' => $donante,
            'credencial' => $credencial,
        );
      }
      return $response;
    }
}
