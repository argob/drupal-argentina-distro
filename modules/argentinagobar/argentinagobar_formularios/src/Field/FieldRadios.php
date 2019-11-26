<?php
  class FieldRadios extends Field
  {

    function __construct($title = 'Radios')
    {
      $this->set_title($title);
    }

    function get_type(){
      return 'radios';
    }

    function get_title(){
      return $this->title;
    }

    function set_title($title){
      $this->title = t($title);
    }

    function set_options($options = [])
    {
      $this->options = $options;
    }

    function get_options()
    {
        return $this->options;
    }


    function render(){
      return array(
        '#type' => $this->get_type(),
        '#title' => $this->get_title(),
        '#options' => $this->get_options(),
        '#required' => $this->is_required(),
      );
    }
  }
