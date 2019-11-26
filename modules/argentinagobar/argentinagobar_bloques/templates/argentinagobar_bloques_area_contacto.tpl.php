<h2 class="h3 section-title"><?php print t('Contacto'); ?></h2>
<p class="margin-40">
  <?php if(isset($contacto->direccion)){ ?><strong><?php print t('Dirección') . ':'; ?></strong> <?php print $contacto->direccion; ?><br><?php } ?>
  <?php if(isset($contacto->codigo_postal)){ ?><strong><?php print t('Código postal') . ':'; ?></strong> <?php print $contacto->codigo_postal; ?><br><?php } ?>
  <?php if(isset($contacto->telefono)){ ?><strong><?php print t('Teléfono') . ':'; ?></strong> <?php print $contacto->telefono; ?><br><?php } ?>
  <?php if(isset($contacto->correo_electronico)){ ?><strong><?php print t('Correo electrónico') . ':'; ?></strong> <?php print l($contacto->correo_electronico, "mailto:" . $contacto->correo_electronico); ?><br><?php } ?>
  <?php if(isset($contacto->whatsapp)){ ?><strong><?php print t('Whatsapp') . ':'; ?></strong> <?php print $contacto->whatsapp; ?><br><?php } ?>
</p>
<?php if(isset($contacto->facebook) || isset($contacto->twitter) || isset($contacto->instagram) || isset($contacto->youtube) || isset($contacto->flickr)) { ?>

  <h5><?php print t('Redes sociales del área'); ?></h5>
  <div class="social-share">
    <ul class="list-inline">
      <?php if(isset($contacto->facebook)){ ?>
        <li><?php print $contacto->facebook; ?></li>
      <?php } ?>
      <?php if(isset($contacto->twitter)){ ?>
        <li><?php print $contacto->twitter; ?></li>
      <?php } ?>
      <?php if(isset($contacto->instagram)){ ?>
        <li><?php print $contacto->instagram; ?></li>
      <?php } ?>
      <?php if(isset($contacto->youtube)){ ?>
        <li><?php print $contacto->youtube; ?></li>
      <?php } ?>
      <?php if(isset($contacto->flickr)){ ?>
        <li><?php print $contacto->flickr; ?></li>
      <?php } ?>
      <?php if(isset($contacto->linkedin)){ ?>
        <li><?php print $contacto->linkedin; ?></li>
      <?php } ?>
    </ul>
  </div>
<?php } ?>
