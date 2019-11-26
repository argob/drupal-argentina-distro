<section class="p-t-0">
    <div class="container">
      <div class="row">
          <div class="col-md-12">

              <h3>Chicos extraviados</h3>

              <div class="row panels-row">
                <?php foreach ($items as $item) :?>
                  <div class="col-xs-12 col-sm-6 col-md-3">
                    <a class="panel panel-default panel-icon panel-secondary" href="<?= $item['link']?>">
                          <div style="background-image:url('<?= $item['ImagenNormal'] ?>');" class="panel-heading"></div>
                          <div class="panel-body">
                              <small class="text-muted"><?= $item['ProvinciaHecho']?></small>
                              <h4><?= $item['nombreCompleto']?></h4>
                          </div>
                      </a>
                  </div>
                  <?php endforeach;?>
              </div>
          </div>
      </div>

      <div class="row">
          <div class="col-sm-12">
            <div class="panel">
              <div class="panel-body">
                  <p>El Registro Nacional de Información de Personas Menores Extraviadas (RNIPME) se creó en 2003 por la <a target="_blank" href="http://servicios.infoleg.gob.ar/infolegInternet/verNorma.do?id=86491">Ley 25746</a> y funciona bajo la Dirección Nacional de Grupos en Situación de Vulnerabilidad de la Subsecretaria de Protección de Derechos Humanos, Secretaría de Derechos Humanos y Pluralismo Cultural de la Nación.</p>
              </div>
            </div>
          </div>
      </div>

    </div>
</section>
