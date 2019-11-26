<?php

  class ConsultaDescargarPdfFr extends Consulta
  {

    function get_request_url()
    {
      $endpoint = $this->get_endpoint();
      if(is_null($endpoint) || $enpoint = '') {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }
      //$urlconsulta = $endpoint . '&numero_documento=' . str_replace(' ', '+', $_GET['numerodocumento']).'-APN-DNGT%23JGM' ;
      $urlconsulta = $endpoint . '&numero_documento=' . str_replace(' ', '+', $_GET['numerodocumento'].'-APN-'.str_replace('#', '%23',$_GET['filtroc']));

      //var_dump('URL CONSULTA API PDF CLASS ConsultaDescargarPdf',$urlconsulta);
      return $urlconsulta;
    }

    function get_response($request) {
      $response = NULL;
      $data = NULL;
      if ($request->code == 401) {
        $this->api_gateway_auth->refresh_token();
        $this->consultar();
      }

      if ($request->code == 503 || $request->code == 500) {
        throw new ConsultaSinServicioException('El servicio de Apostilla No esta respondiendo', 4);
      }

      if ($request->code == 400 || $request->code == 404) {
        $theme = 'apostillafr_error';
      }

      if ($request->code == 200) {
        $theme = 'apostillafr_ok';

        $rq = $request->request;
        //var_dump('RQ',$rq);

          $str = $rq;
          $from = "o=";
          $to = " HTTP/1.0";
          //Function for extract subtring between two strings
          function getStringBetween($str,$from,$to)
          {
              $sub = substr($str, strpos($str,$from)+strlen($from),strlen($str));
              return substr($sub,0,strpos($sub,$to));
          }

            $nombrepdf = getStringBetween($str,$from,$to);
            $nombrepdffinal = str_replace('%23','-',$nombrepdf);
            //var_dump($nombrepdf);
            //var_dump($nombrepdffinal);
        //$data =  base64_encode($request->data);

        $data =  $request->data;
        if(!empty($data)){

          //$file = file_save_data(base64_decode(str_replace($base, '', $data)),'public://infoleg/'.$consulta->values['filename'].'.'.$consulta->values['extension'],FILE_EXISTS_REPLACE);
          $file = file_save_data(base64_decode($data),'public://apostilla/'.$nombrepdffinal.'.pdf',FILE_EXISTS_REPLACE);
          $path = file_create_url($file->uri);
          $file->status = 0;
          file_save($file);
          global $base_url;
          $pdf = $file->filename;

          //FUNCION saber real path de public://
          // if ($wrapper = file_stream_wrapper_get_instance_by_uri('public://')) {
          //   $realpath = $wrapper->realpath();
          //   var_dump($realpath);
          // }


          // var_dump(drupal_goto(file_create_url($file->uri)));

          // watchdog('Apostilla', 'el path del file es '.$path, WATCHDOG_NOTICE);
          // watchdog('Apostilla', 'el nombre del file '.$pdf, WATCHDOG_NOTICE);

          //return $archivoPasar = '<a href="' . $archivo . '" target="_blank" class="btn btn-success btn-block m-t-2" download="' .$pdf. '" > DESCARGAR DOCUMENTO</a>';
          return $archivoPasar = '<a href="' . $path . '" target="_blank" class="btn btn-success btn-block m-t-2" download="' .$pdf. '" > DESCARGAR DOCUMENTO</a>';


        }else{

          $theme = 'apostillafr_error';

        }
      }

      return theme($theme, [
          'pdf' => $pdf,
          'url' => $url,
          'archivo' => $archivo,
          //'pdf' => drupal_goto(file_create_url($file->uri)),
          // 'data'=> $data,
          // 'nombrepdffinal' => $nombrepdffinal,
        ]
      );

    }

  }
