<?php

  class ConsultaRLMPrivada extends ConsultaRLMDetalle
  {
    function get_endpoint()
    {
      return variable_get('consulta_rlm_74');
    }
  }
