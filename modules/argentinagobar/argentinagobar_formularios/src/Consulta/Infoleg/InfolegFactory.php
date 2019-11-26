<?php

class InfolegFactory
{

  public static function crearConsulta(ApiGatewayAuth $api_gateway_auth, $busqueda)
  {

    $consultaProvincias = new ConsultaInfolegProvincias($api_gateway_auth);

    $q = drupal_get_query_parameters();

    if(array_key_exists('jurisdiccion', $q) && $q['jurisdiccion'] == 'provincial') {

      $consultaTipoNorma = new ConsultaInfolegTipoNormaProvincial($api_gateway_auth);

    } else {

      $consultaTipoNorma = new ConsultaInfolegTipoNorma($api_gateway_auth);

    }

    switch ($busqueda) {

      case 'infoleg_consulta_simple':

        $consulta = new ConsultaInfolegSimple(
          $consultaProvincias,
          $consultaTipoNorma,
          $api_gateway_auth
        );

        break;

      case 'infoleg_consulta_avanzada':

        $consulta = new ConsultaInfolegAvanzada(
          $consultaProvincias,
          $consultaTipoNorma,
          $api_gateway_auth
        );

        break;

      case 'infoleg_consulta_boletin':

        $consulta = new ConsultaInfolegBoletin(
          $consultaProvincias,
          $consultaTipoNorma,
          $api_gateway_auth
        );

        break;

    }

    return $consulta;

  }

}