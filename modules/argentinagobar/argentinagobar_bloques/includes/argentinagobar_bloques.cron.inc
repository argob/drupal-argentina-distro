<?php
/*
* Implements hook_cron().
*/
function argentinagobar_bloques_cron()
{
    $request = drupal_http_request("https://argob.github.io/iconos/icono-arg.json");

    if ($request->code == 200) {
        $iconos = array();
        $data = drupal_json_decode($request->data);
        foreach ($data['iconos'] as $icono) {
            $iconos[$icono['clase']] = $icono['nombre'];
        }
        variable_set('iconos', $iconos);
    }

    _getIconos();
}

function _getIconos()
{
    try {
        $response = file_get_contents('https://raw.githubusercontent.com/argob/iconos/master/dist/css/icono-arg.css');
    } catch (Exception $e) {
        watchdog('Iconos Poncho', 'No se puede descargar el CSS de iconos poncho');
        watchdog('Iconos Poncho', '<pre>'. print_r($e->getMessage(), true) .'</pre>');
    }

    if (!empty($response)) {
        $new_folder = 'public://updatePoncho/';
        file_prepare_directory($new_folder, FILE_CREATE_DIRECTORY);

        $new_folder = 'public://updatePoncho/css';
        file_prepare_directory($new_folder, FILE_CREATE_DIRECTORY);

        $new_folder = 'public://updatePoncho/fonts';
        file_prepare_directory($new_folder, FILE_CREATE_DIRECTORY);

        global $base_url;

        $file_path = variable_get('file_public_path');

        file_put_contents(drupal_realpath($file_path).'/updatePoncho/icono-arg.css', $response);

        $pattern = '/arg_(.*)\./';
        preg_match($pattern, $response, $matches);

        $hash = str_replace(['arg_', '.'], ['',''], $matches[0]);

        foreach (['eot','svg','ttf','woff'] as $ext) {
            try {
                $font = file_get_contents('https://raw.githubusercontent.com/argob/iconos/master/dist/fonts/icono-arg_' . $hash . '.' . $ext);
            } catch (Exception $e) {
                watchdog('Iconos Poncho', 'No se puede descargar una fuente de poncho');
                watchdog('Iconos Poncho', '<pre>'. print_r($e->getMessage(), true) .'</pre>');
            }
            if (isset($font)) {
                file_put_contents(drupal_realpath($file_path).'/updatePoncho/fonts/icono-arg_'.$hash.'.'.$ext, $font);

                //file_put_contents(drupal_realpath(drupal_get_path('theme', 'poncho')).'/fonts/icono-arg_'.$hash.'.'.$ext, $font);
            }
        }
    }
}
