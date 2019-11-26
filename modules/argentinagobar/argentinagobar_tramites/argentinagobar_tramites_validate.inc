<?php

function _validarDNI($dni){
	if(empty($dni)){
		form_set_error("dni", "Ingrese un dni");
	}

	$min=1000000; $max=119999999;
	if ((trim($dni) < $min) || (trim($dni) > $max)) {
		form_set_error("dni", "El dni debe ser un número sin comas ni puntos entre ".$min.' y '.$max);
	}
}

function _validarSexo($sexo){
	if($sexo == null){
		form_set_error("sexo", "Seleccione su sexo");
	}
}

function _validarBoleta($boleta){
	if(empty($boleta)){
		form_set_error("boleta", "Ingrese el número de boleta");
	}
}