<?php

class ConsultaException extends Exception
{
  function __construct($exceptionMessage, $userMessage = 'Servicio momentáneamente no disponible', $errorCode = 0)
  {
    parent::__construct($exceptionMessage, $errorCode);

    $this->userMessage = $userMessage;
  }

  function getUserMessage()
  {
    return $this->userMessage;
  }
}
