<?php

class ConsultaIncucaiEstadoCivil extends Consulta
{
    const ENDPOINT = 'incucai_estado_civil';

    function get_endpoint()
    {
      return variable_get('incucai_estado_civil', NULL);
    }


}
