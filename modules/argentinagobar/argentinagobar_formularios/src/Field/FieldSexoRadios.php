<?php
  class FieldSexoRadios extends FieldRadios
  {
    function __construct($title = 'Sexo')
    {
      $this->set_title($title);
    }

    function set_options($options = "")
    {
      return array(
        'f' => 'Femenino',
        'm' => 'Masculino',
      );
    }

  }
