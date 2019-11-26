<?php

class FieldSubmitAJAX extends FieldSubmit
{
  function getAJAX()
  {
    return array(
      'callback' => 'argobar_consulta_ajax_submit',
      'effect' => 'fade',
      'wrapper' => 'wrapper',
      'method' => 'replace',
    );
  }

  function render()
  {
    return array(
      '#type' => $this->get_type(),
      '#value' => $this->getValue(),
      '#attributes' => $this->getAttributes(),
      '#ajax' => $this->getAJAX(),
      '#submit' => false,
    );
  }
}
