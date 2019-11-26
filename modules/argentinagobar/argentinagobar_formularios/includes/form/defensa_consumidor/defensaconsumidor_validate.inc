<?php
function _validarFechaNacimiento($fecha){

	if(!empty($fecha)){

		$nacimiento = strtotime(_fecha_redapi($fecha));

		$hace1decada = strtotime(date("Y-m-d", time()) . " - 6570 day"); // 18 años

		if ($hace1decada < $nacimiento) {
			form_set_error("personales][fechaNacimiento", "Debe tener al menos 18 años para realizar la denuncia");
		}

	}

}

function _validarComprobanteDC($previo, $donde){

	if(empty($donde) and $previo=='Si'){

		form_set_error("reclamo][dondeorganismo", "Ingrese el organismo dónde realizó el reclamo");

	}

}

function _validarAlmenosUnDatoDeContacto($contacto ) {

	if(empty($contacto['telefono_prefijo']) && empty($contacto['telefono']) && empty($contacto['email'])){
		form_set_error("contacto][telefono_prefijo", "");
		form_set_error("contacto][telefono", "Ingrese al menos un dato de contacto, no se ingresó teléfono");
		form_set_error("contacto][email", "Ingrese al menos un dato de contacto, no se ingresó email");
	}

}