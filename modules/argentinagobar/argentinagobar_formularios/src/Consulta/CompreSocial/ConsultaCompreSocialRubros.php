<?php

class ConsultaCompreSocialRubros extends Consulta
{
  
    public function get_endpoint()
    {
        $config = variable_get('compre_social_config');
        return $config['endpoint'] . '/rubros';
    }

    public function get_select_options()
    {
        $request = $this->get_request();
        $options = array();
        $results = $this->get_response($request);

        foreach ($results as $key => $value) {
            if (!empty($value['hijos'])) {
                foreach ($value['hijos'] as $obj) {
                    $options[$value['nombre']][$obj['id']] = $obj['nombre'];
                }
            }
        }

        return $options;
    }
  
  
    public function get_response($request)
    {
        $response = null;

        if ($request->code == 401) {
            $this->api_gateway_auth->refresh_token();
            $this->consultar();
        }

        if ($request->code == 200) {
            $response = drupal_json_decode($request->data);
        } else {
            drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = false);
            watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = null);
        }

        return $response['data'];
    }
}
