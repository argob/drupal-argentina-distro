<?php

class ConsultaDefensaDelConsumidor extends ConsultaPOST{
	
	function get_form($form, &$form_state, $consulta){

	}

	private function getProvincia($prov){

       $provs = array(
			'54' => 'Misiones',
			'74' => 'San Luis',
			'86' => 'Santiago del Estero',
			'94' => 'Tierra del Fuego, Antártida e Islas del Atlántico Sur',
			'18' => 'Corrientes',
			'30' => 'Entre Ríos',
			'34' => 'Formosa',
			'38' => 'Jujuy',
			'46' => 'La Rioja',
			'82' => 'Santa Fe',
			'06' => 'Buenos Aires',
			'14' => 'Córdoba',
			'22' => 'Chaco',
			'58' => 'Neuquén',
			'78' => 'Santa Cruz',
			'02' => 'Ciudad Autónoma de Buenos Aires',
			'26' => 'Chubut',
			'50' => 'Mendoza',
			'62' => 'Río Negro',
			'70' => 'San Juan',
			'10' => 'Catamarca',
			'42' => 'La Pampa',
			'66' => 'Salta',
			'90' => 'Tucumán'
       );

       return $provs[$prov];

   }

	private function multipart_encode($boundary, $params){
	  $output = "";
	  foreach ($params as $key => $value){
	    $output .= "--$boundary\r\n";
	    $output .= "Content-Disposition: form-data; name=\"$key\"\r\n\r\n$value\r\n";
	  }
	  $output .="--$boundary--";
	  return $output;
	}

	private function fechaUS($fecha){
		$f = explode('/', $fecha); return $f[2].'-'.$f[1].'-'.$f[0];
	}

	function parse_x_www_form_urlencoded($values, $documents){

		$recl = $values['reclamo'];
		$pers = $values['personales'];
		$cont = $values['contacto'];

		$issue = array(
			'subject' => $pers['doc'],
			'nombre' => $pers['nombre'],
			'apellido' => $pers['apellido'],
			'doc_tipo' => $pers['tipo_doc'],
			'doc_numero' => $pers['doc'],
			'sexo' =>  $pers['genero'],
			'fecha_nacimiento' => $this->fechaUS($pers['fechaNacimiento']),
			'domicilio' => $pers['domicilio'],
			'provincia' => $this->getProvincia($pers['provincia']),
			'localidad' => $_POST['personales']['localidad'],
			'cp' => $pers['cp'],
			'tel_prefijo' => $cont['telefono_prefijo'],
			'tel_numero' => $cont['telefono'],
			'email' => $cont['email'],
			'problema' => $recl['motivo'],
			'reclamo_al_proveedor' => $recl['previoProveedor'],
			'reclamo_numero' => $recl['numeroProveedor'],
			'reclamo_gob' => $recl['previoOrganismo'],
			'organismo_que_reclamo' => $recl['dondeOrganismo'],
			'reclamo_gob_numero' => $recl['numeroOrganismo'],
			'loc_compra' => $_POST['reclamo']['localidad'],
			'localidad_uso' => $_POST['uso']['localidad'],
			'documentacion_probatoria' => $values['archivoscondicional']['tiene_documentacion'],
			'adjunta_documentacion' => $values['archivoscondicional']['pruebas'],
			'estitular' => $recl['esTitular'],
			'titular_nombre' => $recl['nombreTitular'],
			'uso_producto' => $recl['esUsuario'],
			'como_espera_que_se_resuelva' => implode("\n", array_filter($recl['solicito'])),
			'pretensiones' => $recl['otraPretencion'],
			'elige_organismo' => null,
			'loc_provincia' => $this->getProvincia($recl['provincia']),
			'provincia_uso' => $this->getProvincia($values['uso']['provincia']),
			'documents' => $documents,
		);

		for ($c=1; $c<=5 ; $c++) {
			$prov = $_POST['proveedor'.$c];
			$issue['prov_'.$c.'_nombre'] = (!empty($prov['nombre'])) ? $prov['nombre'] : null;
			$issue['prov_'.$c.'_cuit'] = (!empty($prov['cuit'])) ? $prov['cuit'] : null;
			$issue['prov_'.$c.'_domicilio'] = (!empty($prov['direccion'])) ? $prov['direccion'] : null;
			$issue['prov_'.$c.'_localidad'] = (!empty($prov['localidad'])) ? $prov['localidad'] : null;
			$issue['prov_'.$c.'_provincia'] = (!empty($prov['provincia'])) ? $this->getProvincia($prov['provincia']) : null;
		}

		$new_issue = array();

		foreach ($issue as $key => $value) {
			if (!empty($value)){
				$new_issue[$key] = $value;
			} else {
				if(is_numeric($value)){
					$new_issue[$key] = $value;
				}
			}
		}

		$this->set_values($new_issue);

	}

	function get_params() {
		return $this->values;
  	}
	
	function get_endpoint(){
		$opciones = variable_get('DC_opciones');
		return $opciones['destination'] . '/api/v1.0/defensa-consumidor/issues';
	}
	
	function get_response($request){
		if($request->code == 401){
			$this->api_gateway_auth->refresh_token();
			$this->consultar();
		}
		if($request->code == 200){

			$datos 	= array();
			$data 	= drupal_json_decode($request->data);
			$values = $this->get_params();

			// watchdog('values params', '<pre>'. print_r($values, TRUE) .'</pre>');

			if(is_array($values)){

				
				$datos = array(
					'first_name' => $values['nombre'],
					'last_name' => $values['apellido'],
					'gender' => $values['sexo'],
					'birthdate' => $values['fecha_nacimiento'],
					'email' => $values['email']
				);
			}

			$conf = variable_get('openid_connect_client_generic');
			$base_url = str_replace('authorize/', '', $conf['authorization_endpoint']);
			$url = $base_url.'registro/?fields='.str_replace(array('{','"','}'), array('%7B','%22','%7D'), json_encode($datos));

			if (estaLogueado()) {
				$register = array(
					'url' => 'https://mi.argentina.gob.ar',
					'id' => 'Ingresar'
				);
			} else {
				$register = array(
					'url' => $url,
					'id' => 'BOT_loguearse_registrarse'
				);
			}

			//Construye una respuesta para el formato de poncho
			return array(
				'openid' => render($block['content']),
				'id_respuesta' => $data['issue']['id'],
				'respuesta' => theme('defensa_consumidor_issue', array(
					'id_response' => $data['issue']['id'],
					'icono' => 'fa-check-circle text-success',
					'register' => $register, // Boton ID
					)
				),
			);

		}
		return $response;
	}

  function get_request_headers() {
    return array(
      'headers' => array(
        'Authorization' => 'Bearer ' . $this->api_gateway_auth->getAccessToken(),
        'Content-Type' => 'application/x-www-form-urlencoded'
      ),
      'method' => $this->get_request_method(),
      'data' => http_build_query($this->get_params()),
    );
  }
}
