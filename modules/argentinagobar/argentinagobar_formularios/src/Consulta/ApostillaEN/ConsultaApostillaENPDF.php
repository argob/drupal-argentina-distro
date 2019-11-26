<?php

  class ConsultaApostillaPdfEn extends ConsultaDescargarPdfEn
  {
    function get_endpoint()
    {
      return variable_get('consulta_apostilla_pdf');
    }

  }
