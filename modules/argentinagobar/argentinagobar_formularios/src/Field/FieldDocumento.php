<?php

class FieldDocumento extends FieldTextfield{

	function __construct($title = 'Documento'){
		parent::__construct();
		$this->set_title($title);
		$this->maxlength = 10;
	}

	function get_rules(){
		return array(
			'alpha_numeric',
		);
	}
}
