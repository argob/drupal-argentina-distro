<?php

class ConsultaIncucaiMedula extends ConsultaIncucai
{

  function get_endpoint()
  {
      return variable_get('consulta_incucai_medula_endpoint', NULL);
  }

  function get_response($request)
  {
    $response = null;

    //si el status code es 404 significa que la persona no expresó su voluntad
    if ($request->code == 404) {

     if ($this->mayorDeEdad($this->values['fecha_nacimiento'])) {
        $response = theme('response_incucai_menor_edad');
      } else {
        $data = drupal_json_decode($request->data);
        $response = theme('response_incucai_medula_no_expreso', array());
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
      //dejo sólo la fecha y saco la hora
      $fecha_registro = substr($data['fecha_registro'], 0, 10);

      //convierto fecha de YYYY-MM-DD a DD-MM-YYYY
      $fecha_registro = date("d-m-Y", strtotime($fecha_registro));

      //convierto el documento a id para crear la credencial
      switch ($data['doctipo']) {
        case 'DNI':
          $doctipo = 1;
          break;
        case 'CI':
          $doctipo = 2;
          break;
        case 'LC':
          $doctipo = 3;
          break;
        case 'LE':
          $doctipo = 4;
          break;
        case 'PAS':
          $doctipo = 5;
          break;
        case 'SD':
          $doctipo = 6;
          break;
        default:
          break;
      }

      $credencial = 'https://sintra.incucai.gov.ar/donarweb/donar-medula-consulta/?action=credencial_img&id_tipo_documento=' . $doctipo . '&docnro=' . $data['docnro'];

      $response = theme('response_incucai_medula_donante', array(
            'nombre' => $data['nombre'],
            'apellido' => $data['apellido'],
            'doctipo' => $data['doctipo'],
            'docnro' => $data['docnro'],
            'voluntad' => $data['donante'],
            'fecha_registro' => $fecha_registro,
            'credencial' => $credencial,
          )
        );
    }
    return $response;
  }
}
