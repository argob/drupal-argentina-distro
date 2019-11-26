<div class="text-center m-t-4" id="rlm_nuevabusqueda">
	<?php
		if(isset($nuevo_path)): ?>
  		<a href="<?= url($nuevo_path) ?>" class="btn btn-primary">Nueva búsqueda</a>
	<?php else: ?>
			<a href="<?= url($base_url . '/' . drupal_get_path_alias()); ?>" class="btn btn-primary">Nueva búsqueda</a>
	<?php endif; ?>

</div>
<div class="container-fluid">
  <p><i class="fa fa-warning m-t-0 m-b-1 fa-3x text-warning"></i></p>
  <h2 class="m-t-2 font-weight-bold">Momentáneamente el servicio no está disponible, por favor intente más tarde.</h2>
</div>
