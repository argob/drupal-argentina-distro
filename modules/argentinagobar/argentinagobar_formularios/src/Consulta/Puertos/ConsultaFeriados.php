<?php

  class ConsultaFeriados extends Consulta
  {
    function get_endpoint()
    {
      return variable_get('feriados_endpoint');
    }

  }
