<?php

class ConsultaCompreSocialArchivo extends Consulta
{
    
    public function get_endpoint()
    {
        $config = variable_get('compre_social_config');
        return $config['endpoint'] . '/archivos/' . $this->get_values()['id'];
    }

    function get_response($request)
    {
    $data = null;

    if ($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if ($request->code == 404) {
      global $base_url;
      $data = $base_url.'/'.drupal_get_path('module', 'ar_compre_social').'/img/image_placeholder.jpg';
    }
    

    if ($request->code == 200) {
      $data = 'data:' . $this->get_values()['mimetype'] . ';base64,' . base64_encode($request->data);
    }

    return $data;
  }

  public function handleError($request){

    if($request->code == 404) {

      return $request;

    }

    throw new ConsultaErrorException($request->error);

  }

}
