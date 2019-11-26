<?php
  class FieldNombre extends FieldTextfield
  {
    function get_rules(){
  		return array(
  			'texto_con_espacios',
      );
  	}
  }
