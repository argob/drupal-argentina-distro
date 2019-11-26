
<p class="text-center visible-xs">
	<img src="<?php print $campos['icono']; ?>" width="120">
</p>
<div class="media">
	<div class="media-left media-middle hidden-xs">
    	<img src="<?php print $campos['icono']; ?>" width="120" style="margin-right: 10px;">
	</div>
    <div class="media-body">
        <h1 class="margin-0"><?php print $campos['titulo']; ?></h1>
        <div class="row">
        <?php
			$block = module_invoke('argentinagobar_bloques', 'block_view', 'redes_sociales_generico');
			print render($block['content']);
		?>
		</div>
	</div>
</div>
<hr>
<?php if ($campos['imagen_destacada']) {?>
	<figure>
		<img class="img-responsive img-full" src="<?php print $campos['imagen_destacada']; ?>">
	</figure>
<?php } ?>
