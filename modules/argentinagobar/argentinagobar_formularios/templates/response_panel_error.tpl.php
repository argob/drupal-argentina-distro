<?php if(isset($titulo)): ?>
	<h2>
		<h1 class="text-center m-b-2"><?=$titulo?></h1>
	</h2>
<?php endif ?>

<?php if(isset($subtitulo)): ?>
	<p class="text-center"><small> <?=$subtitulo?></small></p>
<?php endif ?>

<?php if(isset($alerta)): ?>
	<div class="alert alert-warning">
		<p><?=$alerta?></p>
	</div>
<?php endif ?>

<?php if (isset($paneles)):?>
	<?php foreach ($paneles as $panel): ?>
		<?= $panel ?>
	<?php endforeach ?>
<?php endif ?>

<p class="text-center m-t-3 m-b-1 hidden-print">&nbsp;
	<a href="<?php drupal_lookup_path('alias', current_path()); ?>" class="btn  use-ajax btn-primary">Hacer otra consulta</a>
</p>

<?php if(isset($footer)): ?>
	<div class="pane-content">
		<div class="">
			<p class="text-center text-muted"><?=$footer?></p>
		</div>
	</div>
<?php endif ?>
