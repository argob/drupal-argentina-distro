<?php

class FieldSubmit extends FieldButton
{
  function get_type()
  {
    return 'submit';
  }

  function get_title()
  {
    return t('Consultar');
  }

  function setValue($value)
  {
    $this->value = $value;
  }

  function getValue()
  {
    return $this->value;
  }

  function getAttributes()
  {
    return array(
      'class' => $this->getClass(),
    );
  }

  function getSubmitCallback()
  {
    return array(
      'callback' => 'argobar_consulta_submit',
    );
  }

  function render()
  {
    return array(
      '#type' => $this->get_type(),
      '#value' => $this->getValue(),
      '#attributes' => $this->getAttributes(),
      '#submit' => $this->getSubmitCallback(),
    );
  }
}
