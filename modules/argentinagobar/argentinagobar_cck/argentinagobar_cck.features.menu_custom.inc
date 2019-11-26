<?php
/**
 * @file
 * argentinagobar_cck.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function argentinagobar_cck_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: devel.
  $menus['devel'] = array(
    'menu_name' => 'devel',
    'title' => 'Desarrollo',
    'description' => 'Development link',
  );
  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-footer-1.
  $menus['menu-footer-1'] = array(
    'menu_name' => 'menu-footer-1',
    'title' => 'Footer 1',
    'description' => '',
  );
  // Exported menu: menu-footer-2.
  $menus['menu-footer-2'] = array(
    'menu_name' => 'menu-footer-2',
    'title' => 'Footer 2',
    'description' => '',
  );
  // Exported menu: menu-footer-3.
  $menus['menu-footer-3'] = array(
    'menu_name' => 'menu-footer-3',
    'title' => 'Footer 3',
    'description' => '',
  );
  // Exported menu: menu-footer-4.
  $menus['menu-footer-4'] = array(
    'menu_name' => 'menu-footer-4',
    'title' => 'Footer 4',
    'description' => '',
  );
  // Exported menu: navigation.
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Desarrollo');
  t('Development link');
  t('Footer 1');
  t('Footer 2');
  t('Footer 3');
  t('Footer 4');
  t('Main menu');
  t('Management');
  t('Navigation');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>Management</em> menu contains links for administrative tasks.');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');


  return $menus;
}
