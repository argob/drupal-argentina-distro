
<h2 class="m-t-2 font-weight-bold">Tu constancia fue generada</h2>
  <div class="panel panel-default">
      <div class="panel-body">
            <a href=<?php print $pdf ?> download="constancia-cuil.pdf" target="_blank" id="descarga-cuil-btn" class="btn btn-success btn-block m-t-2"> DESCARGÁ LA CONSTANCIA (PDF)</a>
                <hr>
                <h2 class="m-t-2 font-weight-bold">Cargaste estos datos:  </h2>
                <div class="row">
                  <div class="col-md-12">
                    <label class="control-label">Documento</label>
                    <p><?php print $documento ?></p>
                  </div>
                  <div class="col-md-6">
                    <label class="control-label">Nombre</label>
                    <p><?php print $nombre ?></p>
                  </div>
                  <div class="col-md-6">
                    <label class="control-label">Apellido</label>
                    <p><?php print $apellido ?></p>
                  </div>
                  <div class="col-md-6">
                    <label class="control-label">Sexo</label>
                    <p><?php print $sexo ?></p>
                  </div>
                  <div class="col-md-6">
                    <label class="control-label">Fecha de nacimiento</label>
                    <p><?php print $birthdate ?></p>
                  </div>
                <div class="col-md-12">

                  <div class="m-t-2">
                    <p><a href="" class="btn btn-link btn-block"> Hacé otra consulta</a></p>
                  </div>
                </div>
                  <div class="col-md-12">
                    <div class="text-muted">
                      <p class="small">Los datos son suministrados por el Sistema Único de Registro Laboral, Ministerio de Trabajo, Empleo y Seguridad Social.</p>
                      <p class="small">Esta constancia de CUIL no requiere autenticación con sello y firma de un agente de ANSES (artículo 1° de la Resolución ANSES 76/2009).</p>
                    </div>
                  </div>
              </div>

              </div>
        </div>
