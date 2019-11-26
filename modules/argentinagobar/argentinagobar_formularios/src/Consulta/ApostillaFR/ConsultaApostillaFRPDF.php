<?php

  class ConsultaApostillaPdfFr extends ConsultaDescargarPdfFr
  {
    function get_endpoint()
    {
      return variable_get('consulta_apostilla_pdf');
    }

  }
