<h2 class="h3 section-title"><?php print t('Páginas relacionadas'); ?></h2>
<?php foreach (array_chunk($campo, 4) as $key => $row) { ?>
  <div class="row">
  <?php foreach ($row as $item) { ?>
    <div class="col-xs-6 col-sm-3">
      <?php
      echo l(
	    theme(
	      'argentinagobar_bloques_listado_tarjeta_simple_horizontal_item',
	      array(
	        'titulo' => $item['entity']->title,
	      )
	    ),
	    'node/' . $item['entity']->nid,
	    array(
	      'html' => TRUE,
	      'attributes' => array(
	        'class' => array('panel panel-default'),
	      )
	    )
	  );
  	?>
    </div>
  <?php } ?>
  </div>
  <?php } ?>