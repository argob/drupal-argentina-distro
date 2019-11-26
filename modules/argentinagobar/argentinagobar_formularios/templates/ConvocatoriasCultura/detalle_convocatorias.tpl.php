<?php

	$id = drupal_get_path_alias();
	$id = substr($id, -4);

	for ($i=0; $i < 20; $i++) {
		if($items->data[$i]['id'] == $id){
			$pos = $i;
		}
	}
    setlocale (LC_TIME, "es_AR.utf8");
    $fe_inicio = strftime("%d de %B de %Y", strtotime($items->data[$pos]['fecha_inicio']));
    $fe_fin = strftime("%d de %B de %Y", strtotime($items->data[$pos]['fecha_fin']));
?>

<div class="col-md-12">
<ol class="breadcrumb pull-left">
	<?php foreach($breadcrumb as $crumb): ?>
	<?= !is_array($crumb) ? '<li>'.$crumb.'</li>' : '' ?>
	<?php endforeach; ?>
	<li class="active"><span><?= $items->data[$pos]['titulo']?></span></li>
</ol>
</div>


<div class="article-wrap row">
	<header class="col-md-12">
		<h2><?php echo $items->data[$pos]['titulo']; ?></h2>
		<p><?php echo $items->data[$pos]['bajada']; ?></p>
		<div class="section-actions col-md-12 social-share" style="margin-bottom: 40px;">
			<p>Compartir en<br>redes sociales</p>
			<ul class="list-inline">
				<li><a href="<?php echo"http://www.facebook.com/sharer/sharer.php?u=".url(current_path(), array('absolute' => TRUE))."&amp;title=".$node->title."" ?>" target="_blank"><span class="sr-only">Compartir en Facebook</span><i class="fa fa-facebook" aria-hidden="true"></i></a></li>
				<li><a href="https://twitter.com/share" target="_blank"><span class="sr-only">Compartir en Twitter</span><i class="fa fa-twitter" aria-hidden="true"></i></a></li>
			</ul>
		</div>
		<hr>
	</header>

	<!-- Article body goes here -->
	<div class="content col-12">
		<div class="label label-success abierta">
			<span><?php echo $items->data[$pos]['estado']; ?></span>
		</div>
		&nbsp;Del <strong><?php echo $fe_inicio; ?></strong> al <strong><?php echo $fe_fin; ?></strong>.
		<hr>
		<br>
		<p><?php echo $items->data[$pos]['cuerpo']; ?></p>

	</div>
</div>