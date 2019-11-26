<?php
	$id = drupal_get_path_alias();
	$id = substr($id, -5);
?>

<div class="col-md-12">
	<ol class="breadcrumb pull-left">
		<?php foreach($breadcrumb as $crumb): ?>
		<?= !is_array($crumb) ? '<li>'.$crumb.'</li>' : '' ?>
		<?php endforeach; ?>
		<li class="active"><span><?= $items['Nombre'].' '.$items['Apellido'] ?></span></li>
	</ol>
</div>

<section>
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <h2><?= $items['Nombre'].' '.$items['Apellido'] ?></h2>
            </div>
        </div>
        <hr>
    </div>
</section>

<section class="p-t-0">
  <div class="container">
    <div class="row">
      <div class="col-md-8">

          <div class="media m-t-0">
              <div class="media-left hidden-xs">
                  <i class="text-secondary fa fa-list-ul fa-fw fa-2x" aria-hidden="true"></i>
              </div>
              <div class="media-body">
                  <h3 class="m-t-0 clearfix h4"><i class="text-secondary fa fa-list-ul fa-fw fa-2x visible-xs-inline pull-left" aria-hidden="true"></i> Datos del hecho</h3>
                  <p><strong>Fecha: </strong><?php  setlocale (LC_TIME, "es_AR.utf8"); print strftime(("%d de %B de %Y"), strtotime($items['FechaHecho']))?></p>
                  <p><strong>Circunstancia: </strong><?= $items['CircunstanciaHecho']?></p>
                  <p><strong>Localidad: </strong> <?= $items['LocalidadHecho']?></p>
                  <p><strong>Provincia: </strong> <?= $items['ProvinciaHecho']?></p>
                  <p><strong>País: </strong><?= $items['PaisHecho']?></p>
              </div>
          </div>

          <div class="media m-t-3">
              <div class="media-left hidden-xs">
                  <i class="text-secondary fa fa-list-ul fa-fw fa-2x" aria-hidden="true"></i>
              </div>
              <div class="media-body">
                  <h3 class="m-t-0 clearfix h4"><i class="text-secondary fa fa-list-ul fa-fw fa-2x visible-xs-inline pull-left" aria-hidden="true"></i> Datos de nacimiento</h3>
                  <p><strong>Fecha: </strong><?php  setlocale (LC_TIME, "es_AR.utf8"); print strftime(("%d de %B de %Y"), strtotime($items['FechaNacimiento']))?></p>
                  <p><strong>Localidad: </strong><?= $items['LocalidadNacimiento']?></p>
                  <p><strong>Provincia: </strong><?= $items['ProvinciaNacimiento']?></p>
                  <p><strong>País: </strong><?= $items['PaisNacimiento']?></p>
                  <p><strong>Edad: </strong><?= $items['Edad']?></p>
              </div>
          </div>

          <div class="media m-t-3">
              <div class="media-left hidden-xs">
                  <i class="text-secondary fa fa-list-ul fa-fw fa-2x" aria-hidden="true"></i>
              </div>
              <div class="media-body">
                  <h3 class="m-t-0 clearfix h4"><i class="text-secondary fa fa-list-ul fa-fw fa-2x visible-xs-inline pull-left" aria-hidden="true"></i> Descripción física</h3>
                  <p><strong>Contextura: </strong><?= $items['Contextura']?></p>
                  <p><strong>Color ojos: </strong><?= $items['ColorOjos']?></p>
                  <p><strong>Altura: </strong><?= $items['Altura']?></p>
                  <p><strong>Peso: </strong><?= $items['Peso']?></p>
                  <p><strong>Color cabello: </strong><?= $items['ColorCabello']?></p>
                  <p><strong>Estilo cabello: </strong><?= $items['EstiloCabello']?></p>
                  <p><strong>Señas particulares: </strong><?= $items['SeniaParticular']?></p>
                  <p><strong>Indumentaria: </strong> <?= $items['Indumentaria']?></p>
              </div>
          </div>

          <div class="media m-t-3">
              <div class="media-left hidden-xs">
                  <i class="text-secondary fa fa-list-ul fa-fw fa-2x" aria-hidden="true"></i>
              </div>
              <div class="media-body">
                  <h3 class="m-t-0 clearfix h4"><i class="text-secondary fa fa-list-ul fa-fw fa-2x visible-xs-inline pull-left" aria-hidden="true"></i> Autoridad interviniente</h3>
                      <p><strong>Nombre: </strong><?= $items['AutoridadInterviniente']?></p>
              </div>
          </div>

          <hr>

          <div class="row">
              <div class="col-sm-12">
                 <div class="panel">
                     <div class="panel-body">
                          <h2 class="m-b-1">Línea gratuita 142</h2>
                          <p>Si se extravía un niño, niña o adolescente, realizá la denuncia en forma inmediata en la comisaría de la zona y comunicate con nosotros. Recibimos tu llamado las 24 horas.</p>
                          <div><a class="btn btn-primary m-t-1 m-b-1" href="tel:142">Llamanos</a></div>
                          <div class="m-b-2">También podés comunicarte al <a href="tel:08001222442">0800-122-2442</a> o escribir al correo electrónico <a href="mailto:juschicos@jus.gov.ar">juschicos@jus.gov.ar</a>.</div>
                          <img src="http://www.jus.gob.ar/media/3089468/rnipmextrav.png" alt="Buscar" height="70">
                     </div>
                 </div>
              </div>
          </div>

      </div>

          	<div class="col-md-4">
              <img src="<?= $items['ImagenNormal'] ?>" alt="" class="m-b-2" width="100%">
          </div>

		</div>
  </div>
</section>
