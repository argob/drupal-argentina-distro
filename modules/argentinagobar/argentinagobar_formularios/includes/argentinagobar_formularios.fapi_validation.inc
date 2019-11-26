<?php

function argentinagobar_formularios_fapi_validation_rules() {
  return array(
    'texto_con_espacios' => array(
      'callback' => 'argentinagobar_formularios_validation_texto_con_espacios',
      'error_msg' => t('Solo se pueden ingresar letras y espacios en el campo %field.'),
    ),
    'textNumberSpaces' => array(
      'callback' => 'argentinagobar_formularios_validation_textNumberSpaces',
      'error_msg' => t('Solo se pueden ingresar letras, y espacios en el campo %field.'),
    ),
    'notOnlySpaces' => array(
      'callback' => 'argentinagobar_formularios_validation_notOnlySpaces',
      'error_msg' => t('Ingrese al menos dos caracteres')
    ),
    'validaCuit' => array(
      'callback' => 'argentinagobar_formularios_validation_validaCuit',
      'error_msg' => t('El cuit ingresado no es valido')
    )
  );
}

function argentinagobar_formularios_validation_texto_con_espacios($value){
    return (bool) preg_match("/^[\pL\pM\p{Zs}.-]+$/u",$value);
#     preg_match("|^[a-zA-Z]+(\s*[a-zA-Z]*)*[a-zA-Z]+$|",$value);
}

function argentinagobar_formularios_validation_textNumberSpaces($value)
{
  return (bool) preg_match('/^[\\w ]+$/', $value);
}

function argentinagobar_formularios_validation_notOnlySpaces($value)
{
  return !ctype_space($value);
}

//Valida que el cuit sea valido
//Fuente: https://www.phpclasses.org/package/10879-PHP-Validate-the-CUIT-or-CUIL-numbers-of-Argentina.html
function argentinagobar_formularios_validation_validaCuit($value)
{
  $valid = false;
  $cuit = str_replace('_', '', str_replace('-', '', $value));
  $aMult = [5,4,3,2,7,6,5,4,3,2];

  if ($cuit && strlen($cuit)== 11) {
      $aCUIT = str_split($cuit);
      $iResult = 0;
      for($i = 0; $i <= 9; $i++)
      {
          $iResult += $aCUIT[$i] * $aMult[$i];
      }
      $iResult = ($iResult % 11);
      $iResult = 11 - $iResult;

      if ($iResult == 11) $iResult = 0;
      if ($iResult == 10) $iResult = 9;

      if ($iResult == $aCUIT[10])
      {
          $valid = true;
      }
  }
  return $valid;
}
