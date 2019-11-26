<div class="container">

  <div class="panel-pane pane-page-breadcrumb">

    <div class="pane-content">

      <?= $breadcrumb ?>

    </div>

  </div>

</div>

<section>

  <article class="container content_format">

    <div class="col-md-8 col-md-offset-2">

      <h1>Formulario de expresión de voluntad de donación de órganos y tejidos</h1>

      <hr class="m-y-1">

       <div>

        <i class="fa fa-check fa-4x text-success" style="color:#72bb53"></i>

      </div>

      <h2 class="m-t-2 font-weight-bold">Gracias por expresar tu voluntad</h2>

      <div class="panel panel-default">

        <div class="panel-body">

          <a href="<?= $credencial ?>" class="btn btn-success btn-block m-t-2"> DESCARGÁ TU CREDENCIAL</a>

          <hr>

          <h2 class="m-t-2 m-b-2 font-weight-bold">Tus datos:  </h2>

          <div class="row">

            <div class="col-md-6 m-b-1">

              <label class="control-label">Nombre</label>

                <p><?= $nombre ?></p>

            </div>

            <div class="col-md-6 m-b-1">

              <label class="control-label">Apellido</label>

              <p><?= $apellido ?></p>

            </div>

            <div class="col-md-6 m-b-1">

              <label class="control-label">Documento</label>

                <p><?= $documento ?></p>

            </div>

            <div class="col-md-6 m-b-1">

              <label class="control-label">Fecha de nacimiento</label>

              <p><?= $fecha_nacimiento?></p>

            </div>

            <div class="col-md-6 m-b-1">

              <label class="control-label">Donante</label>

              <p><?= $donante ?></p>

            </div>

            <div class="col-md-6">

              <label class="control-label">Fecha de expresión</label>

              <p><?= $fecha_registro?></p>

            </div>

          </div>

        </div>

      </div>

      <hr>

      <p class="pull-right">

        <img src="<?= $logo ?>" class="img-responsive m-b-2" alt="logo incucai" width="150">

      </p>

    </div>

  </article>

</section>



