<?php
  class ConsultaRadicacionPorDominio extends Consulta {
    private $consultar_radicacion_por_dominio_endpoint;

    function __construct($api_gateway_auth, $values) {
      $this->api_gateway_auth = $api_gateway_auth;
      $this->values = $values;
      $this->consultar_radicacion_por_dominio_endpoint = variable_get('consulta_radicacion_dominio_client_endpoint', NULL);
    }

    function consultar() {
      $params = array(
        'dominio' => $this->values['patente'],
      );

      $access_token = $this->api_gateway_auth->getAccessToken();

      $data = http_build_query($params);

      $url = $this->consultar_radicacion_por_dominio_endpoint . '?' . $data;
      $options = array(
        'headers' => array('Authorization' => 'Bearer ' . $access_token),
      );

      $request = drupal_http_request($url, $options);

      if($request->code == 401){
        $this->api_gateway_auth->refresh_token();
        $this->consultar();
      }

      $footer = array(
        'titulo' => t('Datos de contacto de DNRPA'),
        'data' => array(
          array(
            'label' => t('Teléfono'),
            'value' => l('0800-122-2227','tel:0800-122-2227') . ' ' . t('(de 07:00hs a 16.00)'),
          ),
          array(
            'label' => t('Mail'),
            'value' => l('asesoramiento@dnrpa.gob.ar','mailto:asesoramiento@dnrpa.gob.ar'),
          ),
          )
        );


      if($request->code == 400) {
        $response = theme('response_panel_completo', array(
          'titulo' => t('@patente no es una patente válida ', array('@patente' => strtoupper($this->values['patente']))),
          'alerta' => 'Por favor revisá que el número de patente sea correcto, y comunicáte con la DNRPA para que te asesoremos.',
          'footer' => $footer,
        ));
      }


      if($request->code == 500){
        $response = theme('response_panel_completo', array(
          'titulo' => t('El vehículo de patente @patente no aparece radicado', array('@patente' => strtoupper($this->values['patente']))),
          'alerta' => 'Por favor revisá que el núme Nro de patente sea correcto, y comunicáte con la DNRPA para que te asesoremos.',
          'footer' => $footer,
        ));
      }
      

      if($request->code == 200){

        $data = drupal_json_decode($request->data);
        
        foreach ($data['results'] as $key => $items) {
        	$array_paneles[] = $this->crear_panel($items);
        }

        $response = theme('response_panel_completo', array(
        'titulo' => t('Información del vehículo de patente @patente', array('@patente' => strtoupper($this->values['patente']))),
          'paneles' => $array_paneles,
        ));
      }


      $form['contenedor'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'contenedor',
        ),
      );

      $form['contenedor']['response'] = array(
        '#type' => 'markup',
        '#markup' => $response
      );
      return $form;
    }

    private function crear_panel($results) {
    $info = array(
      'titulo' => t('Información del Registro Automotor'),
      'data' => array(
        array(
          'label' => t('Registro Seccional'),
          'value' => empty($results['descripcionRegistroSeccional']) ? "-" : t($results['descripcionRegistroSeccional'])
        ),
        array(
          'label' => t('Dirección'),
          'value' => t($results['calle'] . " ". $results['numero'])
        ),
        array(
          'label' => t('Piso'),
          'value' => empty($results['piso']) ? "-" : t($results['piso'])
        ),
        array(
          'label' => t('Departamento'),
          'value' => empty($results['depto']) ? "-" :  t($results['depto'])
        ),
        array(
          'label' => t('Código postal'),
          'value' => empty($results['codigoPostal']) ? "-" : t($results['codigoPostal'])
        ),
        array(
          'label' => t('Localidad'),
          'value' => empty($results['localidad']) ? "-": t($results['localidad'])
        ),
        array(
          'label' => t('Provincia'),
          'value' => empty($results['provincia']) ? "-": t($results['provincia'])
        ),
        array(
          'label' => t('Teléfono'),
          'value' => empty($results['telefono']) ? "-": t($results['telefono'])
        ),
        array(
          'label' => t('Horario'),
          'value' => empty($results['horario']) ? "-": t($results['horario'])
        ),
      )
    );
    return theme('response_panel', $info);
  }
 }
