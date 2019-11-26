<?php

class ConsultaIncucaiTipoDocumento extends Consulta
{
    const ENDPOINT = 'incucai_tipo_documento';

    function get_endpoint()
    {
      return variable_get('incucai_tipo_documento', NULL);
    }


}
