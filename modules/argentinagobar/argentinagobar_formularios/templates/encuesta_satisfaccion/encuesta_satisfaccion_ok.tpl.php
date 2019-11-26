<div class="col-md-8 col-md-offset-2 text-center">
  <img id="mano" src="<?= $file_public_path; ?>/mano.png">
  <p id="gracias" class="m-t-2">¡Muchas gracias por completar la encuesta!</p>
  <p>Registrate en <b>Mi Argentina</b> para seguir tus trámites, recibir notiﬁcaciones de vencimiento y fechas de cobro entre otros servicios.</p>
  <?php if(!is_null($sign_up_link)): ?>
  <?= l('Registrarme', $sign_up_link, array('attributes' => array('class' => array('btn','btn-success', 'btn-lg', 'm-t-2')))); ?>
  <?php endif; ?>
</div>