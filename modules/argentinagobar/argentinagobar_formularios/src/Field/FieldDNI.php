<?php

class FieldDNI extends FieldTextfield{

    function __construct($title = 'DNI'){
        parent::__construct();
        $this->set_title($title);
        $this->maxlength = 8;
    }

    function get_rules(){
        return array(
            'numeric',
            array('rule' => 'length[4, 8]', 'error' => '%field no válido'),
        );

    }
}
