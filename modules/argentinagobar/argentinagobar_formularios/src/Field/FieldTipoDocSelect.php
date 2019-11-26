<?php
class FieldTipoDocSelect extends FieldSelect
{
  function __construct($title = 'Tipo de Documento')
  {
    $this->set_title($title);
  }

  function set_options($options = "")
  {
    return array(
      '29' => 'DNI',
      '25' => 'Libreta de Enrolamiento',
      '26' => 'Libreta Cívica',
      '00' => 'Otros',
    );
  }
}
