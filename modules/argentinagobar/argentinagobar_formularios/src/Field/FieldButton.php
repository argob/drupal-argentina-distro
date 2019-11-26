<?php

class FieldButton extends Field
{
  function get_type()
  {
    return 'button';
  }

  function get_title()
  {
    return t('Enviar');
  }

  function __construct()
  {
    parent::__construct();
    $this->value = t('Enviar');

    $this->class = array(
      'btn'
    );
  }

}