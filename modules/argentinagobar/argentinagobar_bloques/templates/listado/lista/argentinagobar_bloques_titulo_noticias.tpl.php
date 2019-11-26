<?php
$parts = explode('/', $_SERVER['REQUEST_URI']); 

for($i=0; $i < sizeof($parts); $i++){
    if($parts[$i] != 'argentina.gob.ar' && $parts[$i] != 'noticias'){
       $last_node .= $parts[$i].'/';
    }
}

$last_node = implode("/", array_filter(explode("/", $last_node))); 

$last_conf = end($parts);

if($last_conf == 'noticias'){
    $argN = drupal_get_normal_path($last_node);
    $_GET['q'] = $argN.'/'.$last_conf;
}
  $node = node_load(arg(1));
  //fix: compruebo si el usuario viene del "ver todos" de noticias
  //si es así, el número de nodo es distinto, por ende necesito levantar
  //el título desde el número de nodo que me viene por parámetro.
 
  if (drupal_get_query_parameters() == null) {
 	$node = node_load(arg(1));
  } else {
  	$nid = drupal_get_query_parameters();
  	$node = node_load($nid['nodo']);
  }
 ?>
 
<div id="pruebaloca" class="col-md-12 m-t-3 p-x-0">
<h2 class="h3 m-b-2"><?php print("Noticias de ") . $node->title ; ?></h2>
</div>
