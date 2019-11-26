<?php
/**
 * @file
 * argentinagobar_userblocked.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function argentinagobar_userblocked_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
