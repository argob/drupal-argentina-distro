<?php

  class ConsultaDescargarPdf extends Consulta
  {

    function get_request_url()
    {
      $endpoint = $this->get_endpoint();
      if(is_null($endpoint) || $enpoint = '') {
        throw new EndpointNuloException("Falta endpoint para Consulta", 1);
      }
      $urlconsulta = $endpoint . '&numero_documento=' . str_replace(' ', '+', $_GET['numerodocumento'].'-APN-'.str_replace('#', '%23',$_GET['filtroc']));

      return $urlconsulta;
    }

    function getStringBetween($str,$from,$to){
      $sub = substr($str, strpos($str,$from)+strlen($from),strlen($str));
      return substr($sub,0,strpos($sub,$to));
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
        $theme = 'apostillaes_error';
      }

      if ($request->code == 200) {

        $theme = 'apostillaes_ok';
        $rq = $request->request;
        $str = $rq;
        $from = "o=";
        $to = " HTTP/1.0";

        $nombrepdf = $this->getStringBetween($str, $from, $to);
        $nombrepdffinal = str_replace('%23','-',$nombrepdf);
        $data =  $request->data;
        if(!empty($data)){

          $file = file_save_data(base64_decode($data),'public://apostilla/'.$nombrepdffinal.'.pdf',FILE_EXISTS_REPLACE);
          $path = file_create_url($file->uri);
          $file->status = 0;
          file_save($file);
          global $base_url;
          $pdf = $file->filename;

          return $archivoPasar = '<a href="' . $path . '" target="_blank" class="btn btn-success btn-block m-t-2" download="' .$pdf. '" > DESCARGAR DOCUMENTO</a>';

        }else{
          $theme = 'apostillaes_error';
        }
      }

      return theme($theme, [
        'pdf' => $pdf,
        'url' => $url,
        'archivo' => $archivo,
        ]
      );
    }
  }
