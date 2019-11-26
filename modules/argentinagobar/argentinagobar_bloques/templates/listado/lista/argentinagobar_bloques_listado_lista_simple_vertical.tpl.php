<h2 class="h3 m-b-2"><?php echo $titulo; ?></h2>

<div class="row row-flex">
<?php foreach ($links as $link) { ?>
  <div class="col-xs-12 col-sm-12 col-lg-12 m-b-2">
  <?php echo $link; ?> 
  <p class="text-muted"><?php echo $texto; ?></p>
  </div>
<?php } ?>
</div>