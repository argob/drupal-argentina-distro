<?php
/**
 * @file
 * ar_api.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function ar_api_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'ar_api';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/v1.0';
  $endpoint->authentication = array(
    'oauth2_server' => array(
      'server' => 'ar_oauth2',
    ),
  );
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'noticia' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'scope' => '',
              'require_authentication' => NULL,
            ),
          ),
        ),
        'index' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'scope' => '',
              'require_authentication' => NULL,
            ),
          ),
        ),
      ),
    ),
    'servicio' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'scope' => '',
              'require_authentication' => NULL,
            ),
          ),
        ),
        'index' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'scope' => '',
              'require_authentication' => NULL,
            ),
          ),
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['ar_api'] = $endpoint;

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'ar_api_v2';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/v2.0';
  $endpoint->authentication = array(
    'oauth2_server' => array(
      'server' => 'ar_oauth2',
    ),
  );
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'servicio_v2' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'scope' => '',
              'require_authentication' => NULL,
            ),
          ),
        ),
        'index' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'scope' => '',
              'require_authentication' => NULL,
            ),
          ),
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['ar_api_v2'] = $endpoint;

  return $export;
}
