<h1 class="text-center"><?php print variable_get('titulo_buscador'); ?></h1>
<div class="input-group input-group-lg input-group-shadow">
	<?php print render($form['basic']['keys']); ?>
	<?php print render($form['basic']['submit']); ?>
</div>
<?php print drupal_render_children($form); ?>