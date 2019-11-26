<?php
/**
 * @file
 * argentinagobar_userblocked.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function argentinagobar_userblocked_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_cancel_method';
  $strongarm->value = 'user_cancel_block';
  $export['user_prune_cancel_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_cron_checkbox';
  $strongarm->value = 1;
  $export['user_prune_cron_checkbox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_cron_checkbox_preview';
  $strongarm->value = 1;
  $export['user_prune_cron_checkbox_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_never_logged_in';
  $strongarm->value = 0;
  $export['user_prune_never_logged_in'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_never_logged_in_preview';
  $strongarm->value = 0;
  $export['user_prune_never_logged_in_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_prune_per_run';
  $strongarm->value = '200';
  $export['user_prune_prune_per_run'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_prune_per_run_preview';
  $strongarm->value = '200';
  $export['user_prune_prune_per_run_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_time_month';
  $strongarm->value = '15778458';
  $export['user_prune_time_month'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_time_month_preview';
  $strongarm->value = '15778458';
  $export['user_prune_time_month_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_time_year';
  $strongarm->value = '0';
  $export['user_prune_time_year'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_time_year_preview';
  $strongarm->value = '0';
  $export['user_prune_time_year_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_user_status';
  $strongarm->value = 'active';
  $export['user_prune_user_status'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_prune_user_status_preview';
  $strongarm->value = 'active';
  $export['user_prune_user_status_preview'] = $strongarm;

  return $export;
}
