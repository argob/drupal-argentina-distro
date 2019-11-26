<?php if(isset($filtro)): ?>

    <?= drupal_render($filtro); ?>

<?php endif; ?>

<div id="pruebaloca" class="col-md-12 m-t-3 p-x-0">
    
    <?php if (isset($titulo)): ?>

        <h2 class="h3 m-b-2"><?= $titulo; ?></h2>
    
    <?php endif ?>
    
    
    <?php if($destacar_primer_fila): ?>

        <div class="row panels-row">
            
            <?php for ($i=0; $i < 3; $i++): ?>

                <div class="col-xs-12 col-sm-12 col-md-4">
                    <?= array_shift($links); ?>
                </div>
            
            <?php endfor ?>

        </div>
    
    <?php endif ?>
    
    <?php foreach (array_chunk($links, 4) as $key => $row): ?>

        <div class="row panels-row">
            
            <?php foreach ($row as $item): ?>

                <div class="col-xs-12 col-sm-3">
                    <?= $item; ?>
                </div>
            
            <?php endforeach ?>

        </div>
    
    <?php endforeach; ?>
    
    <?php if(isset($boton)): ?>
        <?php 
            if (strpos($boton, 'Ver todos') !== false) {
                $order   = array("Ver todos");
                $replace = 'Ver todo';

                $boton = str_replace($order, $replace, $boton);
            }
        ?>
        <?= $boton ?>
        
    <?php endif ?>
    
    <?php if(isset($paginador)): ?>
        
        <?= theme('pager'); ?>
    
    <?php endif ?>

</div>
