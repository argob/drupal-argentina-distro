<div>
	<h1 class="text-center"><i class="fa <?php print $icon ?> fa-3x"></i></h1>
	<h1 class="text-center margin-40"><?php print $title; ?></h1>
	<p class="text-center lead"><?php print $message; ?></p>
	<?php if($response_id == 3){ ?>
	<div class="text-center m-t-4">
    	<a href="<?php print url('node/12614' ); ?>" class="btn btn-primary">Solicitar el relevamiento de mi barrio</a>
    </div>
    <hr class="m-t-4">
    <p class="lead text-center">También podés consultar el <a href="<?php print url('node/26569'); ?>">mapa de Barrios Populares</a> para buscar si está tu barrio o no.</p>
	<?php } else { ?>
	<div class="text-center m-t-4">
		<a href="<?php print url('http://www.anses.gob.ar/oficina'); ?>" class="btn btn-primary">Buscar oficinas</a>
	</div>
	<div class="text-center m-t-2">
		<a href="<?php drupal_lookup_path('alias', current_path()); ?>" class="btn btn-link">Hacer otra consulta</a>
	</div>
	<?php } ?>
</div>