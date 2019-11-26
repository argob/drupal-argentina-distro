<?php

function argentinagobar_formularios_my_file_element_process($element, &$form_state, $form) {

  $element = file_managed_file_process($element, $form, $form_state);
  $element['upload_button']['#access'] = FALSE;

  return $element;
}


function decode_parameters($data)
{
    $decode = rawurldecode($data);
    $decode_64 = base64_decode($decode);
    $decode_gz = gzdecode($decode_64);
    $decode_json = drupal_json_decode($decode_gz);

    return($decode_json);
}

function encode_parameters($data)
{
    $data_json = drupal_json_encode($data);
    $data_jsonz = gzencode($data_json);
    $data_jsonzb64 = base64_encode($data_jsonz);
    $data_jsonzb64url = rawurlencode($data_jsonzb64);

    return($data_jsonzb64url);
}
