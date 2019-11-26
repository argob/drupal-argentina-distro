<?php
    class FieldDate extends FieldTextfield{

        public $title;

        function __construct($title = 'Fecha'){
            $this->set_title($title);
            $this->set_maxlength(10);
        }

        function get_type(){
            return 'date_popup';
        }

        function get_title(){
            return $this->title;
        }

        function set_title($title){
            $this->title = t($title);
        }

        function get_format(){
            return 'd/m/Y';
        }

        function render(){
            return array(
                '#type' => $this->get_type(),
                '#title' => $this->get_title(),
                '#required' => $this->is_required(),
                '#date_format' => $this->get_format(),
                '#maxlength' => $this->get_maxlength(),
                '#date_year_range' => '-200:+0',
                '#size' => 60,
                '#date_label_position' => 'within',
                '#attributes' => array(
                    'placeholder' => '01/01/2017'
                ),
            );
        }
    }
