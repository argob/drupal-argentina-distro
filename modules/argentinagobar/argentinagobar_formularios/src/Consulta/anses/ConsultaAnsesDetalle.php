<?php
  
  class ConsultaAnsesDetalle extends ConsultaAnses {
  
    function get_endpoint()
    {
      return variable_get('beneficio', null);
    }
  
    function get_params()
    {
    
      return http_build_query([
      
        'beneficio' => $this->values['BeneficioNro'],
    
      ]);
    
    }
  
  
    function get_request_url()
    {
      $endpoint = $this->get_endpoint();
      $params = $this->get_params();
    
    
      if (is_null($endpoint) || $enpoint = '') {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }
    
      return $endpoint . '?' . $params;
    }
  
    function get_request()
    {
      $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
      return $request;
    }
  
    function get_response($request)
    {
      
      
      $beneficios = [];
      
      
      $data = drupal_json_decode($request->data);
      
        if ($request->code == 200 ){
    
          $beneficios['apellidoYNombre'] = $data['rub']['apellidoYnombre'];
          $beneficios['cuil'] = $data['fechaPago'][0]['cuil'];
          $beneficios['nombreBeneficio'] = $this->getDescripcionAmigable($data['fechaPago'][0]['cSistema']);
          $beneficios['lugarDeCobro'] = $data['fechaPago'][0]['cBco'];
          $beneficios['lugarDeCobro'] .= ' ' . $data['fechaPago'][0]['cAge'];
          $beneficios['lugarDeCobro'] .= ' ' . $data['fechaPago'][0]['bcoCalle'];
          $beneficios['lugarDeCobro'] .= ' ' . $data['fechaPago'][0]['localidad'];
          $beneficios['periodo'] = $data['fechaPago'][0]['periodo'];
          $beneficios['pagoActual']['pagoDesde'] = $this->formatDates($data['fechaPago'][0]['pagoDesde']);
          $beneficios['pagoActual']['pagoHasta'] = date('d/m', strtotime($data['fechaPago'][0]['pagoHasta']));
          $beneficios['pagoActual']['proxPagoDesde'] = $this->formatDates($data['fechaPago'][0]['proxPagoDesde']);
          $beneficios['pagoAnterior']['pagoDesde'] = $this->formatDates($data['fechaPago'][1]['pagoDesde']);
          $beneficios['pagoAnterior']['pagoHasta'] = date('d/m', strtotime($data['fechaPago'][1]['pagoHasta']));
        }
  
        if($request->code == 500){
          $beneficios = '500';
        }
        
      
      
      return $beneficios;
    }
  
    function formatDates($date = [])
    {
      $date = date('Y-F-d', strtotime($date));
      $date = explode('-', $date);
      
      return $date;
    }
  
    function getDescripcionAmigable($id)
    {
      $json = array(
        '7' => 'Prestación por desempleo',
        '9' => 'Previsionales',
        '11' =>' Pago único de prestación (matrimonio, nacimiento, adopción',
        '12' => 'Depósito Judicial - Tutor o Curador',
        '13' => 'Deposito Judicial - Embargo sobre Prestación',
        '14' => 'SUAF - Sistema Único de Asignaciones Familiares',
        '15' => 'Depósito judicial - Sucesión',
        '17' => 'Pagos Retroactivos originados en Bonos Previsionales',
        '18' => 'Programa Nacional de Empleo',
        '21' => 'Liquidacion de Prestaciones del Sistema de Capitalizacion (AFJP',
        '22' => 'Programas privados de Empleo',
        '23' => 'Programas del Ministerio de Trabajo',
        '24' => 'Sentencias judiciales',
        '25' => 'Derecho Familiar de Inclusion Social - Plan Mayores',
        '27' => 'Pensiones No Contributivas',
        '32' => 'Subsidio de Contención Familiar',
        '35' => 'Suplemento Excepcional',
        '36' => 'Ayuda económica - Hospital Francés',
        '37' => 'Programa Familias por la Inclusión Social,',
        '50' => 'AFJP',
        '52' =>' Programa Desnutricion Infantil - Primeros años',
        '58' => 'Rentas Vitalicias - Compañias de Seguro',
        '60' => 'Asignación Universal por Hijo',
        '70' => 'Leyes especiales previsionales',
        '90' => 'DGI',
        '39' => 'Programa Hogares con Garrafa',
        '216' => 'Reparación Histórica',
        '62' => 'PROGRESAR - Programa de Respaldo a estudiantes argentinos',
        '64' => 'Programa Ingreso social',
      );
    
      return $json[$id];
    
    }
    
  }
  
