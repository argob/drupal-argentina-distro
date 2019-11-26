<div class="text-center m-t-4" id="rlm_nuevabusqueda">
  <a href="<?php print url('/' . drupal_get_path_alias()); ?>" class="btn btn-primary">Nueva búsqueda</a>
</div>


<div class="row row-compartir">
  <!-- ========== DESCARGA CERTIFICADO ============= !-->
  <div class="col-md-12">
    <h4>Descargá el certificado</h4>
    <p>Descargá el certificado del Registro Nacional de Bases de Datos con código QR para imprimir.</p>

  </div>
  <div class="col-md-4">
    <a alt="descargar certificado" class="btn btn-primary btn-block "href="https://descarga.aaip.gob.ar/cert/<?= $cuit ?>--<?= $ref_number ?>" id="btn-descargar-qr" target="_blank" title="descargar certificado">Descargar</a>
  </div>

  <!-- ========== INICIO COMPARTIR QR ============= !-->
  <div class="col-md-12">
    <h4>Publicá el QR en tu web</h4>
    <p class="m-t-2">Copiá y pegá el código generado automáticamente con el QR de tu inscripción en el Registro Nacional de Bases de Datos y envíalo al administrador de tu sitio web.</p>
  </div>

  <div class="col-md-8">
    <img alt="Compartí el QR del Registro Nacional de Bases de Datos en tu web" src="https://www.argentina.gob.ar/sites/default/files/aaip-isologo.png" width="150px" />
  </div>
  <div class="col-md-12 m-t-2">
    <textarea id="myText" cols="100" maxlength="280" readonly="readonly">
      <a href="https://www.argentina.gob.ar/aaip/datospersonales/reclama/<?= $cuit ?>--<?= $ref_number ?>">
        <img src="https://www.argentina.gob.ar/sites/default/files/aaip-isologo.png" alt="AAIP RNBD" style="width:55px;height:71px;border:0;"></a>
    </textarea>
  </div>
  <div class="col-md-4 m-t-4">
    <a alt="copiar código html" class="btn btn-primary btn-block" id="btn-copiar-qr" title="copiar código html" onclick="copier()">Copiar código</a>
  </div>
</div>
<!-- ========== FIN COMPARTIR QR ============= !-->

<script type="text/javascript">
  
  function copier(){
    document.getElementById('myText').select();
    document.execCommand('copy');
  }

  document.getElementById("wrapp").childNodes[0].childNodes[0].style.display = 'none';
</script>