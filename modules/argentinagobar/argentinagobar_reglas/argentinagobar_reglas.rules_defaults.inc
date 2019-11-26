<?php
/**
 * @file
 * argentinagobar_reglas.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function argentinagobar_reglas_default_rules_configuration() {
  $items = array();
  $items['rules_user_tfa_'] = entity_import('rules_config', '{ "rules_user_tfa_" : {
      "LABEL" : "User TFA ",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [
        "rules",
        "tfa_rules",
        "comment",
        "field_collection",
        "node_access_rules",
        "og"
      ],
      "ON" : {
        "user_login" : [],
        "node_delete" : [],
        "node_insert" : [],
        "node_view" : [],
        "node_update" : [],
        "node_presave" : [],
        "comment_view" : [],
        "comment_update" : [],
        "comment_presave" : [],
        "comment_delete" : [],
        "comment_insert" : [],
        "field_collection_item_delete" : [],
        "field_collection_item_insert" : [],
        "field_collection_item_update" : [],
        "field_collection_item_presave" : [],
        "field_collection_item_view" : [],
        "node_access_rules_edit" : [],
        "node_access_rules_view" : [],
        "node_access_rules_delete" : [],
        "og_membership_delete" : []
      },
      "IF" : [
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "18" : "18" } }
              }
            },
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "4" : "4" } }
              }
            },
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "34" : "34" } }
              }
            },
            { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "21" : "21" } } } }
          ]
        },
        { "NOT tfa_rules_user_has_tfa" : { "account" : [ "site:current-user" ] } }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "\\u003Cstrong\\u003ENo se encuentra habilitada la autenticaci\\u00f3n de dos factores (TFA). \\u003C\\/strong\\u003E\\u003Cbr\\u003E\\r\\n\\u003Cp\\u003EPor favor inicie sesi\\u00f3n con un c\\u00f3digo de verificaci\\u00f3n adem\\u00e1s de su nombre de usuario y contrase\\u00f1a. \\u003Cbr\\u003E\\r\\n\\u00a1 Esto impedir\\u00e1 que sea redireccionado constantemente a esta p\\u00e1gina ! \\u003Cbr\\u003E\\r\\n\\u003Cstrong\\u003ESeleccionar: --\\u003E Set up application -\\u003E ingrese su contrase\\u00f1a -\\u003E ingrese la autenticaci\\u00f3n de dos factores (TFA)\\u003C\\/strong\\u003E\\u003C\\/p\\u003E",
            "type" : "warning",
            "repeat" : "0"
          }
        },
        { "redirect" : { "url" : "\\/user\\/[site:current-user:uid]\\/security\\/tfa" } }
      ]
    }
  }');
  return $items;
}