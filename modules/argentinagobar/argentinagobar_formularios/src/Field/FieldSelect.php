<?php
  class FieldSelect extends Field
  {
      protected $options;

    function __construct($title = 'Radios', $options = [] ){
      $this->set_title($title);
      $this->set_options($options);
    }

    function get_type(){
      return 'select';
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
