<?php
/**
 * @file
 * argentinagobar_usuarios.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function argentinagobar_usuarios_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access admin theme'.
  $permissions['access admin theme'] = array(
    'name' => 'access admin theme',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'moderador' => 'moderador',
    ),
    'module' => 'admin_theme',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor servicios' => 'editor servicios',
      'moderador' => 'moderador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access overlay'.
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(),
    'module' => 'overlay',
  );

  // Exported permission: 'access printer-friendly version'.
  $permissions['access printer-friendly version'] = array(
    'name' => 'access printer-friendly version',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
      'moderador' => 'moderador',
    ),
    'module' => 'book',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Admin Usuarios' => 'Admin Usuarios',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add content to books'.
  $permissions['add content to books'] = array(
    'name' => 'add content to books',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
      'moderador' => 'moderador',
    ),
    'module' => 'book',
  );

  // Exported permission: 'admin tfa settings'.
  $permissions['admin tfa settings'] = array(
    'name' => 'admin tfa settings',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'tfa',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Admin Usuarios' => 'Admin Usuarios',
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer book outlines'.
  $permissions['administer book outlines'] = array(
    'name' => 'administer book outlines',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'book',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Admin Usuarios' => 'Admin Usuarios',
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'og',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer manualcrop settings'.
  $permissions['administer manualcrop settings'] = array(
    'name' => 'administer manualcrop settings',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'manualcrop',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Evento_Editor' => 'Evento_Editor',
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'editor servicios' => 'editor servicios',
      'moderador' => 'moderador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panelizer'.
  $permissions['administer panelizer'] = array(
    'name' => 'administer panelizer',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node area content'.
  $permissions['administer panelizer node area content'] = array(
    'name' => 'administer panelizer node area content',
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node area context'.
  $permissions['administer panelizer node area context'] = array(
    'name' => 'administer panelizer node area context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node area defaults'.
  $permissions['administer panelizer node area defaults'] = array(
    'name' => 'administer panelizer node area defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node area layout'.
  $permissions['administer panelizer node area layout'] = array(
    'name' => 'administer panelizer node area layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node area overview'.
  $permissions['administer panelizer node area overview'] = array(
    'name' => 'administer panelizer node area overview',
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node area settings'.
  $permissions['administer panelizer node area settings'] = array(
    'name' => 'administer panelizer node area settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node argentinagobar_migtram content'.
  $permissions['administer panelizer node argentinagobar_migtram content'] = array(
    'name' => 'administer panelizer node argentinagobar_migtram content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node argentinagobar_migtram context'.
  $permissions['administer panelizer node argentinagobar_migtram context'] = array(
    'name' => 'administer panelizer node argentinagobar_migtram context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node argentinagobar_migtram layout'.
  $permissions['administer panelizer node argentinagobar_migtram layout'] = array(
    'name' => 'administer panelizer node argentinagobar_migtram layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node argentinagobar_migtram overview'.
  $permissions['administer panelizer node argentinagobar_migtram overview'] = array(
    'name' => 'administer panelizer node argentinagobar_migtram overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node argentinagobar_migtram settings'.
  $permissions['administer panelizer node argentinagobar_migtram settings'] = array(
    'name' => 'administer panelizer node argentinagobar_migtram settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node noticia content'.
  $permissions['administer panelizer node noticia content'] = array(
    'name' => 'administer panelizer node noticia content',
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node noticia context'.
  $permissions['administer panelizer node noticia context'] = array(
    'name' => 'administer panelizer node noticia context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node noticia defaults'.
  $permissions['administer panelizer node noticia defaults'] = array(
    'name' => 'administer panelizer node noticia defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node noticia layout'.
  $permissions['administer panelizer node noticia layout'] = array(
    'name' => 'administer panelizer node noticia layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node noticia overview'.
  $permissions['administer panelizer node noticia overview'] = array(
    'name' => 'administer panelizer node noticia overview',
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node noticia settings'.
  $permissions['administer panelizer node noticia settings'] = array(
    'name' => 'administer panelizer node noticia settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node page content'.
  $permissions['administer panelizer node page content'] = array(
    'name' => 'administer panelizer node page content',
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node page context'.
  $permissions['administer panelizer node page context'] = array(
    'name' => 'administer panelizer node page context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node page defaults'.
  $permissions['administer panelizer node page defaults'] = array(
    'name' => 'administer panelizer node page defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node page layout'.
  $permissions['administer panelizer node page layout'] = array(
    'name' => 'administer panelizer node page layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node page overview'.
  $permissions['administer panelizer node page overview'] = array(
    'name' => 'administer panelizer node page overview',
    'roles' => array(
      'maquetador' => 'maquetador',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node page settings'.
  $permissions['administer panelizer node page settings'] = array(
    'name' => 'administer panelizer node page settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node tramite defaults'.
  $permissions['administer panelizer node tramite defaults'] = array(
    'name' => 'administer panelizer node tramite defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Admin Usuarios' => 'Admin Usuarios',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer tca_node'.
  $permissions['administer tca_node'] = array(
    'name' => 'administer tca_node',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'moderador' => 'moderador',
    ),
    'module' => 'tca',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Admin Usuarios' => 'Admin Usuarios',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'advanced migration information'.
  $permissions['advanced migration information'] = array(
    'name' => 'advanced migration information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass tca_node'.
  $permissions['bypass tca_node'] = array(
    'name' => 'bypass tca_node',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'moderador' => 'moderador',
    ),
    'module' => 'tca',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Admin Usuarios' => 'Admin Usuarios',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Admin Usuarios' => 'Admin Usuarios',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create aplicacion content'.
  $permissions['create aplicacion content'] = array(
    'name' => 'create aplicacion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create area content'.
  $permissions['create area content'] = array(
    'name' => 'create area content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create argentinagobar_migtram content'.
  $permissions['create argentinagobar_migtram content'] = array(
    'name' => 'create argentinagobar_migtram content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create book content'.
  $permissions['create book content'] = array(
    'name' => 'create book content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create new books'.
  $permissions['create new books'] = array(
    'name' => 'create new books',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
      'moderador' => 'moderador',
    ),
    'module' => 'book',
  );

  // Exported permission: 'create noticia content'.
  $permissions['create noticia content'] = array(
    'name' => 'create noticia content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create tramite content'.
  $permissions['create tramite content'] = array(
    'name' => 'create tramite content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any aplicacion content'.
  $permissions['delete any aplicacion content'] = array(
    'name' => 'delete any aplicacion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any area content'.
  $permissions['delete any area content'] = array(
    'name' => 'delete any area content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any argentinagobar_migtram content'.
  $permissions['delete any argentinagobar_migtram content'] = array(
    'name' => 'delete any argentinagobar_migtram content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any book content'.
  $permissions['delete any book content'] = array(
    'name' => 'delete any book content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any noticia content'.
  $permissions['delete any noticia content'] = array(
    'name' => 'delete any noticia content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tramite content'.
  $permissions['delete any tramite content'] = array(
    'name' => 'delete any tramite content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own aplicacion content'.
  $permissions['delete own aplicacion content'] = array(
    'name' => 'delete own aplicacion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own area content'.
  $permissions['delete own area content'] = array(
    'name' => 'delete own area content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own argentinagobar_migtram content'.
  $permissions['delete own argentinagobar_migtram content'] = array(
    'name' => 'delete own argentinagobar_migtram content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own book content'.
  $permissions['delete own book content'] = array(
    'name' => 'delete own book content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own noticia content'.
  $permissions['delete own noticia content'] = array(
    'name' => 'delete own noticia content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tramite content'.
  $permissions['delete own tramite content'] = array(
    'name' => 'delete own tramite content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in migtram_hecho_vital'.
  $permissions['delete terms in migtram_hecho_vital'] = array(
    'name' => 'delete terms in migtram_hecho_vital',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in migtram_perfil'.
  $permissions['delete terms in migtram_perfil'] = array(
    'name' => 'delete terms in migtram_perfil',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in noticias'.
  $permissions['delete terms in noticias'] = array(
    'name' => 'delete terms in noticias',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tema'.
  $permissions['delete terms in tema'] = array(
    'name' => 'delete terms in tema',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tramites'.
  $permissions['delete terms in tramites'] = array(
    'name' => 'delete terms in tramites',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any aplicacion content'.
  $permissions['edit any aplicacion content'] = array(
    'name' => 'edit any aplicacion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any area content'.
  $permissions['edit any area content'] = array(
    'name' => 'edit any area content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any argentinagobar_migtram content'.
  $permissions['edit any argentinagobar_migtram content'] = array(
    'name' => 'edit any argentinagobar_migtram content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'editor servicios' => 'editor servicios',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any book content'.
  $permissions['edit any book content'] = array(
    'name' => 'edit any book content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any noticia content'.
  $permissions['edit any noticia content'] = array(
    'name' => 'edit any noticia content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tramite content'.
  $permissions['edit any tramite content'] = array(
    'name' => 'edit any tramite content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'editor servicios' => 'editor servicios',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own aplicacion content'.
  $permissions['edit own aplicacion content'] = array(
    'name' => 'edit own aplicacion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own area content'.
  $permissions['edit own area content'] = array(
    'name' => 'edit own area content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'moderador' => 'moderador',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own argentinagobar_migtram content'.
  $permissions['edit own argentinagobar_migtram content'] = array(
    'name' => 'edit own argentinagobar_migtram content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own book content'.
  $permissions['edit own book content'] = array(
    'name' => 'edit own book content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own noticia content'.
  $permissions['edit own noticia content'] = array(
    'name' => 'edit own noticia content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tramite content'.
  $permissions['edit own tramite content'] = array(
    'name' => 'edit own tramite content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'relevador servicios' => 'relevador servicios',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit terms in migtram_hecho_vital'.
  $permissions['edit terms in migtram_hecho_vital'] = array(
    'name' => 'edit terms in migtram_hecho_vital',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in migtram_perfil'.
  $permissions['edit terms in migtram_perfil'] = array(
    'name' => 'edit terms in migtram_perfil',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in noticias'.
  $permissions['edit terms in noticias'] = array(
    'name' => 'edit terms in noticias',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tema'.
  $permissions['edit terms in tema'] = array(
    'name' => 'edit terms in tema',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tramites'.
  $permissions['edit terms in tramites'] = array(
    'name' => 'edit terms in tramites',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'field hidden administer'.
  $permissions['field hidden administer'] = array(
    'name' => 'field hidden administer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_hidden',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'merge tema terms'.
  $permissions['merge tema terms'] = array(
    'name' => 'merge tema terms',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'migration information'.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'editor servicios' => 'editor servicios',
    ),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Admin Usuarios' => 'Admin Usuarios',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use manualcrop'.
  $permissions['use manualcrop'] = array(
    'name' => 'use manualcrop',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'manualcrop',
  );

  // Exported permission: 'use media wysiwyg'.
  $permissions['use media wysiwyg'] = array(
    'name' => 'use media wysiwyg',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media_wysiwyg',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'maquetador' => 'maquetador',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'ver reportes nodo'.
  $permissions['ver reportes nodo'] = array(
    'name' => 'ver reportes nodo',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'argentinagobar_bloques_reportes',
  );

  // Exported permission: 'view any unpublished aplicacion content'.
  $permissions['view any unpublished aplicacion content'] = array(
    'name' => 'view any unpublished aplicacion content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished area content'.
  $permissions['view any unpublished area content'] = array(
    'name' => 'view any unpublished area content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished argentinagobar_migtram content'.
  $permissions['view any unpublished argentinagobar_migtram content'] = array(
    'name' => 'view any unpublished argentinagobar_migtram content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderador' => 'moderador',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished noticia content'.
  $permissions['view any unpublished noticia content'] = array(
    'name' => 'view any unpublished noticia content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished page content'.
  $permissions['view any unpublished page content'] = array(
    'name' => 'view any unpublished page content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished tramite content'.
  $permissions['view any unpublished tramite content'] = array(
    'name' => 'view any unpublished tramite content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'editor servicios' => 'editor servicios',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrador drupal' => 'administrador drupal',
      'administrator' => 'administrator',
      'editor servicios' => 'editor servicios',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'system',
  );

  return $permissions;
}
