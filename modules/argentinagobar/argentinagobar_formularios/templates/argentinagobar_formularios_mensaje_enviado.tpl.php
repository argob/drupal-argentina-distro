<?php
  $text = "Volver a Argentina.gob.ar";
  $options = array(
    'attributes' => array(
      'class' => array(
        'btn btn-primary btn-lg"y'
      ),
    ),
    'html' => TRUE
  );
?>
<div class="row">
  <div class="col-md-8 col-md-offset-2">
    <div>
    <h1 class="text-success text-center"><i class="fa fa-check-circle fa-5x"></i></h1>
    <h1 class="text-center margin-40">¡Tus comentarios se enviaron con éxito!</h1>
    <p class="text-center">Muchas gracias por ayudarnos a mejorar este sitio.</p>
      <div class="text-center padding-20 margin-60">
        <?php print l($text,base_path(),$options); ?>
      </div>
    </div>
  </div>
</div>
