<?php

  class ConsultaApostillaPdf extends ConsultaDescargarPdf
  {
    function get_endpoint()
    {
      return variable_get('consulta_apostilla_pdf');
    }

  }
