<?php

/**
 * Implements hook_permission().
 */
function argentinagobar_formularios_permission() {
  return array(
    'administrar formularios' => array(
      'title' => t('Administrar formularios'),
      'description' => t('Permite configurar formularios de argentina.gob.ar'),
    ),
  );
}
