<div id="pasos-fronterizos-lista">
  <table class="table table-striped table-bordered table-mobile table-spaced">
    <thead>
      <tr>
  		  <th class="estado" data-sort="estado">Estado</span></th>
  		  <th class="" data-sort="nombre">Nombre</span></th>
  		  <th class="provincia" data-sort="provincia">Provincia</span></th>
  		  <th class="paislimitrofe" data-sort="paislimitrofe">País limítrofe </span></th>
  		  <th class="tipo" data-sort="tipo">Tipo</span></th>
      </tr>
    </thead>
    <tbody class="list">
        <tr><?php foreach ($pasos_fronterizos as $paso) {?>
          <?php $clases = $paso['estado']['estado'] == "Abierto" ? " label-success" : " label-danger" ?>
          <?php $tipo = $paso['origen'] == 0 ? "Ruta" : "Río" ?>
          <?php $origen = $paso['origen'] == 0 ? "ruta" : "rio" ?>
          <td>
          	<span class="td-label">Estado</span>
          	<span class="estado label <?php print $clases?>"><?php print $paso['estado']['estado']; ?></span>
          </td>
          <td>
          	<span class="td-label">Nombre</span>
          	<strong><a href="/pasosinternacionales/detalle/<?php print $origen ?>/<?php print $paso['id'];?>/<?php print str_replace('---','-',str_replace(' ', '-', $paso['nombre'])) ?>"> <span class="nombre"><?php print $paso['nombre']; ?></span></a></strong>
          </td>
          <td>
          	<span class="td-label">Provincia</span>
            <span class="provincia">
            <?php print $paso['provincia']['nombre']; ?>
            </span>
          </td>
          <td>
          	<span class="td-label">País limítrofe</span>
            <span class="paislimitrofe">
          	<?php print $paso['pais']['nombre']; ?>
          </span>
          </td>
          <td>
          	<span class="td-label">Tipo</span>
            <span class="tipo">
          	<?php print $tipo; ?>
            </span>
          </td>
        </tr>
    <?php   } ?>
    </tbody>
  </table>
	<nav class="text-center">
  	<ul class="pagination"></ul>
  </nav>
</div>
