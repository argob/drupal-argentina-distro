<?php

class ConsultaCompreSocialProducto extends Consulta
{
    
    public function get_endpoint()
    {
        $config = variable_get('compre_social_config');
        return $config['endpoint'] . '/productos/' . $this->get_values()['id'];
    }

    public function handleError($request){

    if($request->code == 404) {

        drupal_not_found();

    }

    throw new ConsultaErrorException($request->error);

  }

}
