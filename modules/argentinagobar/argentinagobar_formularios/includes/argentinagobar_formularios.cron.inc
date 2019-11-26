<?php

/*
* Implements hook_cron().
*/
function argentinagobar_formularios_cron() {
  _consultaRegistroObsequiosViajes();
  _consultaPasosFronterizos();

  $opciones = variable_get('DC_opciones', null);

  if(!empty($opciones['queue'])){
    $opciones['queue'] = [];
    variable_set('DC_opciones', $opciones);
  }
}

function _consultaRegistroObsequiosViajes(){
  $consulta = new ConsultaRegistroObsequiosViajes(ApiGatewayAuth::getInstance());
  return $consulta->consultar();

}
 function _consultaPasosFronterizos(){
   $consulta = new ConsultaListadoFronteras(ApiGatewayAuth::getInstance());
   return $consulta->consultar();
 }