<h2 class="h3 m-b-2">
    <?php echo $titulo; ?>
</h2>

<div class="row row-flex">
    
    <?php foreach ($links as $link): ?>
    
        <div class="col-xs-12 col-sm-6 col-lg-4 m-b-2">
        
            <?= $link; ?>
            
            <?php if(isset($texto)): ?>
            
                <p class="text-muted">
                    <?= $texto; ?>
                </p>
            
            <?php endif ?>
        
        </div>
    
    <?php endforeach ?>
    
</div>

<?php if($paginador): ?>
    
    <?= theme('pager'); ?>

<?php endif ?>
