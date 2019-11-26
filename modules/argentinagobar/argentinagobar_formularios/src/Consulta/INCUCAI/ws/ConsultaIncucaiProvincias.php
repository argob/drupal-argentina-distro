<?php

class ConsultaIncucaiProvincias extends Consulta
{
    const ENDPOINT = 'incucai_provincias';


    function get_endpoint()
    {
      return variable_get('incucai_provincias', null);
    }


}
