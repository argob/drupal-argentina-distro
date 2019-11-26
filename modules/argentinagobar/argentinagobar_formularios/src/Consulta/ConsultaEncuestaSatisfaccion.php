<?php

class ConsultaEncuestaSatisfaccion extends ConsultaPOST
{
  
  function get_endpoint()
  {    
    return variable_get('consulta_consulta_encuesta_satisfaccion_endpoint', NULL);
  }
  
  function get_params(){
    
    $survey_response = array(
      'name' => 'Encuesta de atención',
      'respondent' => '',
      'dni' => $this->values['dni'],
      'organismo' => $this->values['organismo'],
      'categoriaservicio' => $this->values['tramite'],
      'provincia' => $this->values['provincia'],
      'localidad' => $this->values['localidad'],
      'canal' => 2,
    );
    
    $questionresponses = array(
       array(
        'questionId' => 'F72DE9A6-2282-E711-8100-70106FA70181',
        'answerId' => $this->values['calidad_atencion'],
        'valueAsString' => NULL,
       ),
       array(
        'questionId' => '4204B465-2182-E711-8100-70106FA70181',
        'answerId' => $this->values['modalidad'],
        'valueAsString' => NULL,
       ),
       array(
        'questionId' => '0267C72C-2682-E711-8100-70106FA70181',
        'answerId' => $this->values['tiempo_espera'],
        'valueAsString' => NULL,
       ),
       array(
        'questionId' => '4F1CFF65-6B78-E711-80F1-E0071B6E8DC1',
        'answerId' => $this->values['utilidad'],
        'valueAsString' => NULL,
       ),
       array(
        'questionId' => '78F8EA7C-2682-E711-8100-70106FA70181',
        'answerId' => $this->values['tiempo_espera_tramite'],
        'valueAsString' => NULL,
       ),
       array(
        'questionId' => 'A44643D2-2682-E711-8100-70106FA70181',
        'answerId' => NULL,
        'valueAsString' => $this->values['comentario'],
       ),
    );
    
    return json_encode(array(
        'surveyresponse' => $survey_response,
        'questionresponses' => $questionresponses,
      )
    );
  }
  
  function get_response($request)
  {
        
    $response = NULL;
    				
    if($request->code == 401)
    {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }
    
    if($request->code == 404)
    {
      
      $data = drupal_json_decode($request->data);

      $response = theme('encuesta_satisfaccion_error');
      
    }
    		
    if($request->code == 200)
    {
      
      $data = drupal_json_decode($request->data);
      
      $sign_up_link = variable_get('argentinagobar_ciudadano_digital_profile_link', NULL);
      $file_public_path = variable_get('file_public_path', conf_path() . '/files');

      $response = theme(
        'encuesta_satisfaccion_ok', 
        array(
            'sign_up_link' => $sign_up_link,
            'file_public_path' => $file_public_path
          
        )
      );
      
    }
    else
    {
      
      drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = FALSE);
      
      watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = NULL);
      
      $response = theme('encuesta_satisfaccion_error');
      
    }
    
    return $response;
    
  }
  
}