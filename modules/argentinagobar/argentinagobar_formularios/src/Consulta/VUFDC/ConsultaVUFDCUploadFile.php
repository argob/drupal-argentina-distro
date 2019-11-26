<?php

class ConsultaVUFDCUploadFile extends ConsultaPOST
{

  function get_params()
  {
    return $this->prepare_files($this->values['documento']);
  }

  function prepare_files($fid)
  {

    $file = file_load($fid);
    $file->filepath = drupal_realpath($file->uri);

    $this->boundary = md5(uniqid());

    $params = array(
      'file' => $file->filepath,
    );

    return $this->multipart_encode($this->boundary, $params);
  }

  // base function to encode a data array.
  function multipart_encode($boundary, $params)
  {
    $output = "";

    foreach ($params as $key => $value):

      $output .= "--$boundary\r\n";

      if ($key == 'file'):

        $output .= $this->multipart_enc_file($value);

      else:

        $output .= $this->multipart_enc_text($key, $value);

      endif;

    endforeach;

    $output .= "--$boundary--";

    return $output;
  }

  // Function to encode text data.
  function multipart_enc_text($name, $value)
  {
    return "Content-Disposition: form-data; name=\"$name\"\r\n\r\n$value\r\n";
  }

  // Function to multipart encode a file from a give path.
  function multipart_enc_file($path)
  {
    if (substr($path, 0, 1) == "@") $path = substr($path, 1);
    $filename = basename($path);
    $mimetype = "application/octet-stream";
    $data = "Content-Disposition: form-data; name=\"file\"; filename=\"$filename\"\r\n"; // "file" key.
    $data .= "Content-Transfer-Encoding: binary\r\n";
    $data .= "Content-Type: $mimetype\r\n\r\n";
    $data .= file_get_contents($path) . "\r\n";
    return $data;
  }

  function get_endpoint(){
    $opciones = variable_get('DC_opciones');
    return $opciones['destination'] . '/api/v1.0/defensa-consumidor/upload-file';
  }

  function get_response($request)
  {

    $response = NULL;

    if($request->code == 401){
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if($request->code == 200)
    {
      $data = drupal_json_decode($request->data);
      $response = $data['id'];
    }
    else
    {

      drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
      watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);

    }

    return $response;
  }

  function get_headers()
  {
    return array(
      'Content-Type' => "multipart/form-data; boundary=$this->boundary",
      'Authorization' => 'Bearer ' . $this->api_gateway_auth->getAccessToken(),
    );
  }

  function get_request()
  {
    $request = drupal_http_request($this->get_request_url(), $this->get_request_headers());

    if(isset($request->error))
    {
      throw new ConsultaErrorException($request->error);
    }

    return $request;
  }

}
