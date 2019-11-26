<?php

class ConsultaConvocatorias extends Consulta {

  function get_request_url() {
    $endpoint = $this->get_endpoint();
    if (empty($_GET['offset'])) {
      $urlconsulta = $endpoint ."?ordering=-evento__fecha_fin&limit=20&offset=0";
    } else {
      $urlconsulta = $endpoint ."?limit=20&offset=". $_GET['offset'];
    }
    return $urlconsulta;
  }

  function get_endpoint() {
    $endpoint = variable_get('cultura_convocatorias', NULL);
    return $endpoint;
  }

  function get_request() {
    $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
    return $request;

  }

  function get_response($request){
    $data = NULL;

    if($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if ($request->code == 500 || $request->code == 503) {
      throw new ConsultaException('Convocatorias Cultura no esta funcionando', 1);
    }

    if ($request->code == 400 || $request->code == 404) {
      $theme = 'convocatorias_cultura_error';
    }

    if($request->code == 200){
      $theme = "convocatorias_cultura_ok";
      $data = drupal_json_decode($request->data);

      $count_total = intval(round($data['metadata']['total'] / 20));
      $offset = $data['metadata']['resultset']['offset'];

      if ($offset == 0) {
        $currentPage = 1;
      } else {
        $currentPage = ($offset / 20) + 1;
      }
    }

    $response = theme($theme,[
          'data' => $data,
          'currentPage' => $currentPage,
          'count_total' => $count_total,
      ]);

    return $response;
  }
}
