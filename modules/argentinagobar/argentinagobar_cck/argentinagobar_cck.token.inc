<?php


/**
 * Implements hook_token_info().
 */
function argentinagobar_cck_token_info() {
  $info['tokens']['node']['parent-alias-url'] = array(
    'name' => t('Parent Alias URL'),
    'description' => t("The source node for this current node's translation set."),
    'type' => 'node',
  );
  return $info;
}

/**
 * Implements hook_tokens().
 */
function argentinagobar_cck_tokens($type, $tokens, array $data = array(), array $options = array()){
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];
    $parent_node = NULL;
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'parent-alias-url':
          if (!empty($node->og_group_ref)) {
            $parent_node = node_load($node->og_group_ref['und'][0]['target_id']);
            $replacements[$original] = drupal_get_path_alias('node/' . $parent_node->nid);
          }
          break;
      }
    }
  }

  return $replacements;
}