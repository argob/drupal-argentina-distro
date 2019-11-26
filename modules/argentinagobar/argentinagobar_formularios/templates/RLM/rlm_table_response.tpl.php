<div class="text-center m-t-4" id="rlm_nuevabusqueda">
  <a href="<?php print url('/' . drupal_get_path_alias()); ?>" class="btn btn-primary">Nueva búsqueda</a>
</div>
<div class="table-responsive col-md-12">
  <table class="table table-spaced table-hover" id="pagina_vacia_error_warning">
    <thead>
    <tr>
      <th>CUIT / CUIL</th>
      <th>Nombre o Razón social</th>
      <th>Código de responsable</th>
      <th></th>
    </tr>
    </thead>
    <tbody class="list" id="show-data">
    <?php foreach ($items as $item) :?>
    <tr>
      <td>
        <p><?= $item['cuit']?></p>
      </td>
      <td>
        <p><?= $item['name']?></p>
      </td>
      <td>
        <p><?= $item['ref_number']?></p>
      </td>
      <td>
        <a class="btn btn-primary" href="<?= $item['link']?>"> VER </a>
      </td>
    </tr>
    <?php endforeach;?>
    </tbody>
  </table>
</div>
<div class="text-center m-t-4" id="rlm_nuevapagina">
  <a class="btn btn-primary" id="rlm_pagina_anterior">Página Anterior</a>
  <a class="btn btn-primary" id="rlm_pagina_siguiente">Página Siguiente</a>
</div>

<div class="text-center m-t-4" id="rlm_nuevapagina_captcha">
  <span id="texto_nuevapagina_captcha"><span>
</div>
