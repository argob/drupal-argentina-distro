<?php
/**
* Implements hook_block_info().
*/
function argentinagobar_bloques_block_info() {
  $blocks = array();
  $blocks['redes_sociales_generico'] = array(
    'info' => t('Redes sociales reutilizable'),
  );
  return $blocks;
}
/**
* Implements hook_block_view().
*/
function argentinagobar_bloques_block_view($delta = '') {
  $node = node_load(arg(1));
  $block = array();
  switch ($delta) {
    case 'redes_sociales_generico':
      $block['subject'] = '';
      $block['content'] = _argentinagobar_bloques_BLOCK_ABC_CONTENT($node);
      break;
  }
  return $block;
}


function _argentinagobar_bloques_BLOCK_ABC_CONTENT($node) {
  $output = '<div class="section-actions col-md-6 social-share">
      <p>Compartir en<br>redes sociales</p>
      <ul class="list-inline">
        <li><a href="http://www.facebook.com/sharer/sharer.php?u='.url(current_path(), array('absolute' => TRUE)).'&amp;title='.$node->title.'" target="_blank"><span class="sr-only">Compartir en Facebook</span><i class="fa fa-facebook" aria-hidden="true"></i></a></li>
        <li><a href="https://twitter.com/share" target="_blank"><span class="sr-only">Compartir en Twitter</span><i class="fa fa-twitter" aria-hidden="true"></i></a></li>
        <li><a href="https://www.linkedin.com/shareArticle?mini=true&url='.url(current_path(), array('absolute' => TRUE)).'" target="_blank"><span class="sr-only">Compartir en Linkedin</span><i class="fa fa-linkedin" aria-hidden="true"></i></a></li>
      </ul>
    </div>';
  return $output;
}
