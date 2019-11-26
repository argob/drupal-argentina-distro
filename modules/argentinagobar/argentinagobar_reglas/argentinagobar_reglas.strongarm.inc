<?php
/**
 * @file
 * argentinagobar_reglas.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function argentinagobar_reglas_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tfa_basic_cookie_domain';
  $strongarm->value = '.argentina.gob.ar';
  $export['tfa_basic_cookie_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tfa_basic_help_text';
  $strongarm->value = 'Contactar con soporte para resetear el acceso';
  $export['tfa_basic_help_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tfa_basic_roles_require';
  $strongarm->value = array(
    2 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    14 => 0,
  );
  $export['tfa_basic_roles_require'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tfa_enabled';
  $strongarm->value = 1;
  $export['tfa_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tfa_fallback_plugins';
  $strongarm->value = array(
    -999 => 'tfa_basic_totp',
    0 => 'tfa_basic_recovery_code',
    10 => 'tfa_basic_help',
  );
  $export['tfa_fallback_plugins'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tfa_login_plugins';
  $strongarm->value = array();
  $export['tfa_login_plugins'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tfa_validate_plugin';
  $strongarm->value = 'tfa_basic_totp';
  $export['tfa_validate_plugin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_defaults';
  $strongarm->value = array(
    'taxonomy_term' => FALSE,
  );
  $export['views_defaults'] = $strongarm;

  return $export;
}
