<?php
/**
 * @file
 * argentinagobar_configuracion.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function argentinagobar_configuracion_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
