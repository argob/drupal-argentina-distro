<?php

class ConsultaGeoRefLocalidades
{

  private function getLocalidadJson($nombreLocalidadJson=FALSE){
      return file_get_contents(dirname(dirname(dirname(__FILE__))).'/json/localidades/'.$nombreLocalidadJson.'.json');
    }

  public function get_select_options($provincia)
  {

    $options = array();

    switch ($provincia) {

      case 14:
        $jsonLocalidad = $this->getLocalidadJson('cordoba');
        break;

      case 30:
        $jsonLocalidad = $this->getLocalidadJson('entre_rios');
        break;

      case 54:
        $jsonLocalidad = $this->getLocalidadJson('misiones');
        break;

      case 50:
        $jsonLocalidad = $this->getLocalidadJson('mendoza');
        break;

      case 58:
        $jsonLocalidad = $this->getLocalidadJson('neuquen');
        break;

      case 06:
        $jsonLocalidad = $this->getLocalidadJson('buenos_aires');
        break;

      case 66:
        $jsonLocalidad = $this->getLocalidadJson('salta');
        break;

      case 42:
        $jsonLocalidad = $this->getLocalidadJson('la_pampa');
        break;

      case 26:
        $jsonLocalidad = $this->getLocalidadJson('chubut');
        break;

      case 78:
        $jsonLocalidad = $this->getLocalidadJson('santa_cruz');
        break;

      case 74:
        $jsonLocalidad = $this->getLocalidadJson('san_luis');
        break;

      case 90:
        $jsonLocalidad = $this->getLocalidadJson('tucuman');
        break;

      case 18:
        $jsonLocalidad = $this->getLocalidadJson('corrientes');
        break;

      case 02:
        $jsonLocalidad = $this->getLocalidadJson('ciudad_autonoma_de_buenos_aires');
        break;

      case 70:
        $jsonLocalidad = $this->getLocalidadJson('san_juan');
        break;

      case 82:
        $jsonLocalidad = $this->getLocalidadJson('santa_fe');
        break;

      case 38:
        $jsonLocalidad = $this->getLocalidadJson('jujuy');
        break;

      case 86:
        $jsonLocalidad = $this->getLocalidadJson('santiago_del_estero');
        break;

      case 10:
        $jsonLocalidad = $this->getLocalidadJson('catamarca');
        break;

      case 62:
        $jsonLocalidad = $this->getLocalidadJson('rio_negro');
        break;

      case 46:
        $jsonLocalidad = $this->getLocalidadJson('la_rioja');
        break;

      case 94:
        $jsonLocalidad = $this->getLocalidadJson('tierra_del_fuego');
        break;

      case 34:
        $jsonLocalidad = $this->getLocalidadJson('formosa');
        break;

      case 22:
        $jsonLocalidad = $this->getLocalidadJson('chaco');
        break;
    }

    if(isset($jsonLocalidad)){
      $localidades = drupal_json_decode($jsonLocalidad);

      foreach ($localidades["results"] as $localidad) {

        $nombreLocalidad = $localidad['nombre'].', '.$localidad['departamento']['nombre'];
        $options[$nombreLocalidad] = $nombreLocalidad;
      }
    }

    return $options;
  }
}
