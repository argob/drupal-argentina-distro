<?php
class FieldBirthdate extends FieldDate{
		
	function __construct($title = 'Fecha de Nacimiento'){
		$this->set_title($title);
		$this->set_maxlength(10);
	}
}