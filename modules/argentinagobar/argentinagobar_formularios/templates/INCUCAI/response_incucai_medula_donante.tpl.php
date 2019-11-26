<div>
	<i class="fa fa-check fa-4x text-success" style="color:#72bb53"></i>
</div>
<h2 class="m-t-2 font-weight-bold">Ya estás inscripto</h2>

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
              <p><?= $docnro ?></p>
            </div>

            <div class="col-md-6 m-b-1">
              <label class="control-label">Donante</label>
              <p><?= $voluntad ?></p>
            </div>

            <div class="col-md-6">
              <label class="control-label">Fecha de expresión</label>
              <p><?= $fecha_registro ?></p>
       		</div>
        </div>
	</div>
</div>