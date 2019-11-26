<?php ($pane_prefix) ? $pane_prefix : null ?>
<?php ($admin_links) ? $admin_links : null ?>


<div class="panel panel-default panel-disabled">
    <?php foreach ($content['#items'] as $key => $accion):?>
        <?php
                $accion = field_collection_item_load($accion['value'], $reset = FALSE);
                if(count(translateActions($accion->field_accion['und'][0]['value']))>0 && count($accion->field_url['und'][0]['title'])){
        ?>
            <div class="panel-body text-center">
                <?php 
                $classes = ($key > 0) ? '' : 'btn btn-success btn-block';
                $texto = isset($accion->field_accion['und']) ?  translateActions($accion->field_accion['und'][0]['value']) : null;
                $link  = isset($accion->field_url['und']) ? l($texto, $accion->field_url['und'][0]['title'], array('attributes' => array('class' => $classes))) : null;
                ?>

                <?php if($link && $texto): ?>
                    <p><?= $link ?></p>
                <?php endif ?>
            </div>
        <?php }?>
    <?php endforeach ?>
</div>