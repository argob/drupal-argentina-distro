<div class="row panels-row">
	<?php foreach ($items as $key => $item): ?>
    <?php if ($key < $items_per_page): ?>

			<div class="col-xs-12 col-sm-6 col-md-4">
            <a class="panel panel-default" href="<?= $item['alias'] ?>">
              <div style="background-image:url(<?= $item['imagen'] ?>);" class="panel-heading">
    
              </div>
              <div class="panel-body">
                <div><?= $item['rubro']['nombre'] ?></div>
                <h3 class="nombre-obra m-t-0"><?= $item['nombre'] ?></h3>
                <p><?= mb_substr($item['descripcion'], 0, 150) ?> ... </p>
                <hr>  
               
                <p class="text-muted m-b-0" title="Productor"><span class="fa fa-user fa-1x fa-fw" aria-hidden="true"></span> <?= $item['productor']['nombre'] ?></p> 

                <p class="text-muted m-b-0" title="Ubicación"><span class="fa fa-map-marker fa-1x fa-fw" aria-hidden="true"></span> <?= $item['productor']['provincia_nombre'] ?></p> 
    
              </div>
            </a>
          </div>

	 <?php endif; ?>
  <?php endforeach; ?>
</div>

<?= $paginador ?>