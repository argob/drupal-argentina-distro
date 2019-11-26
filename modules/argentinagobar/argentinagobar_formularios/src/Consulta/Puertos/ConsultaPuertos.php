<?php

class ConsultaPuertos extends Consulta {

      #Funcion que construye la URL de consulta a la API
      function get_request_url() {
        $endpoint = $this->get_endpoint();
          if (is_null($endpoint) || empty($endpoint)) {
            throw new EndpointNuloException("Falta endpoint para Consulta", 1);
          }
        $urlconsulta = $endpoint;

        return $urlconsulta;
      }

      #Funcion que trae el endpoint de conexion a la API
      function get_endpoint() {
        return variable_get('puertos_endpoint');
      }

      #Funcion que hace el request a la api
      function get_request() {
        $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());
        return $request;

      }

      function get_response($request){
        $items = array();
        $response = NULL;
        $data = NULL;

        if($request->code == 401) {
          $this->api_gateway_auth->refresh_token();
          $this->consultar();
        }

        if ($request->code == 500 || $request->code == 503) {
          throw new ConsultaException('Convocatorias Cultura no esta funcionando', 1);
        }

        if ($request->code == 400 || $request->code == 404) {
          $theme = 'puertos_error';
        }

        if ($request->code == 200) {
          $theme = "puertos_ok";
          $data = drupal_json_decode($request->data);
          $items = $this->formatItems($data['results']);

          #CONSULTA FERIADOS
          $consultaFeriados = new ConsultaFeriados(ApiGatewayAuth::getInstance());
          $responseFeriados = $consultaFeriados->consultar();
          }


        $this->esFeriado($responseFeriados);
        $estadoOfrecer = $this->calculoEstadoOfrecer($items);
        $response = $items;
        return $this->renderResponseSinForm($response);
      }

      function formatItems($data)
      {
        $items = array();
        foreach ($data as $data2) {
             $nro_expediente[] = $data2['nro_expediente'];
             $fecha_y_hora_publicacion[] = $data2['fecha_y_hora_publicacion'];
             $tipo_equipo[] = $data2['tipo_equipo'];
             $fecha_inicio_operacion[] = $data2['fecha_inicio_operacion'];
             $fecha_fin_operacion[] = $data2['fecha_fin_operacion'];
             $caracteristicas[] = $data2['caracteristicas'];
             $lugar_operacion[] = $data2['lugar_operacion'];
             $estado[] = $data2['estado'];
        }

          #Ordenamiento de los elementos del Array
          #1ero por estado y luego por fecha de publicacion
           array_multisort($estado, SORT_ASC,
       			$fecha_y_hora_publicacion, SORT_ASC,
       			$data);

            $items = $data;

        return $items;
        }

    #@items, array resultado del formateo de los items que provienen de la API puertos
    #Se cambia el varlor del Array @items por referencia
      function calculoEstadoOfrecer(&$items)
      {
               //Inclucion Clase Carbon
               require_once(realpath(dirname(__FILE__) . '/vendor/autoload.php'));
               //Inclucion Clase Business Days
               set_include_path(get_include_path() . $_SERVER["DOCUMENT_ROOT"] . "/vendor/cmixin/business-day");

               $baseList = 'us-national';
               $arrayFeriados = array(
                'Año nuevo' => '2019-1-1',
                'Carnaval 1' =>  '2019-3-4',
                'Carnaval 2' =>  '2019-3-5',
                'Día Nacional de la Memoria por la Verdad y la Justicia' =>  '2019-3-24',
                'Día del Veterano y de los Caídos en la Guerra de Malvinas' =>  '2019-4-2',
                'Jueves y Viernes Santo 1' =>  '2019-4-18',
                'Jueves y Viernes Santo 2' =>  '2019-4-19',
                'Día del trabajador' =>  '2019-5-1',
                'Día de la Revolución de Mayo' =>  '2019-5-25',
                'Día Paso a la Inmortalidad del General Martín Miguel de Güemes' =>  '2019-6-17',
                'Día Paso a la Inmortalidad del General Manuel Belgrano' =>  '2019-6-20',
                'Día no laboral con fines turísticos 1' =>  '2019-7-8',
                'Día de la Independencia' =>  '2019-7-9',
                'Paso a la Inmortalidad del General José de San Martín' =>  '2019-8-17',
                'Día no laboral con fines turísticos 2' =>  '2019-8-19',
                'Día del Respeto a la Diversidad Cultural' =>  '2019-10-12',
                'Día no laboral con fines turísticos 3' =>  '2019-10-14',
                'Día de la Soberanía Nacional (20/11)' =>  '2019-11-18',
                'Inmaculada Concepción de María' =>  '2019-12-8',
                'Navidad' =>  '2019-12-25'
               );

               #@$feriadosArg contiene el array seteado de los Feriados via API
               global $feriadosArg;
               $carbon = new \Carbon\Carbon();
               $carbonB = new \Carbon\Carbon();
               $BusinessDay = new \Cmixin\BusinessDay();
               $BusinessDay::enable('Carbon\Carbon', $baseList, $arrayFeriados);
               $fechaActual = new \Carbon\Carbon();
               $fechaActual = $fechaActual->now();

               foreach ($items as $index => $data) {
                $fecha_y_hora_pub = $data['fecha_y_hora_publicacion'];
                $fecha_y_hora_pub_orig = $carbon::parse($fecha_y_hora_pub);
                $fecha_y_hora_pub_mod = $carbonB::parse($fecha_y_hora_pub);

                $dias = 0;
                while ($dias < 2){

                  if ($fecha_y_hora_pub_mod->isWeekend() == false && $fecha_y_hora_pub_mod->isHoliday() == false) {
                    $dias++;
                  }

                  $fecha_y_hora_pub_mod->addWeekDays(1);
                }

              $estado_ofrecer = false;
                if((strtotime($fechaActual)<=strtotime($fecha_y_hora_pub_mod) == true) && (strtotime($fechaActual)>=strtotime($fecha_y_hora_pub_orig) == true)){
                   $estado_ofrecer = true;
                }
                $items[$index]['valorOfrecer'] = $estado_ofrecer;

           }
            return $estado_ofrecer;
      }

      #Formatea los valores de los Feriados
      function esFeriado($responseFeriados)
      {
        $meses_NUM = array("1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12");
        $meses_LET = array("Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre");

        global $feriadosArg;
        $feriadosArg = array();
        foreach ($responseFeriados as $var) {
          if ($var['categoria'] == 'No laborable') {
              $feriado['mes'] = $var['mes'];
              $feriado['dia'] = $var['dia'];
              $feriado['nombre'] = $var['feriado'];

              #Convierto los datos del Feriado en Formato Fecha:y-m-d
                 $feriado_fecha = '2019'.'-'.$feriado['mes'].'-'.$feriado['dia'];
              #Reemplazo el nombre de los meses por numeros
                 $numMes = str_replace($meses_LET, $meses_NUM, $feriado_fecha);
              #Creo un array asociativo con los datos: Nombre feriado => fecha
                $feriados_fechas2[] = array($feriado['nombre'] => $numMes,);

              #Convierto el array multidimensional a un array unidimensional
                $feriadosArg= array_reduce($feriados_fechas2, 'array_merge', array()); //funciona, pero cambia 2 fechas
          }

        }
        //return $feriadosArg;
      }


  function renderResponseSinForm($response)
  {
    $theme = count($response) >= 1  ? 'puertos_ok' : 'puertos_error' ;

    return theme($theme, array(
        'items' => $response,
      )
    );
  }

}
