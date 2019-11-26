<div class="col-md-12">
  <table class="table table-spaced table-hover table-sociedad">
    <thead>
    <tr>
      <th>Nº de expediente</th>
      <th>Hora de publicación</th>
      <th>Tipo de equipo</th>
      <th>Inicio de la operación </th>
      <th>Fin de la operación</th>
      <th>Características requeridas</th>
      <th>Lugar de operación</th>
      <th>Ofrecer buque</th>
    </thead>
    <tbody class="list" id="show-data">
      <?php foreach ($items as $item) :?>
      <tr>
        <td>
          <p><?php print $item['nro_expediente']?></p>
        </td>
        <td>
            <p><?php print $item['fecha_y_hora_publicacion']?></p>
        </td>
        <td>
          <p><?php print $item['tipo_equipo']?></p>
        </td>
        <td>
          <p><?php print $item['fecha_inicio_operacion']?></p>
        </td>
        <td>
          <p><?php print $item['fecha_fin_operacion']?></p>
        </td>
        <td>
            <p><?php print $item['caracteristicas']?></p>
        </td>
        <td>
          <p><?php print $item['lugar_operacion']?></p>
        </td>
        <td>
            <?php if ($item['valorOfrecer'] == true) :?>
              <a href="https://tramitesadistancia.gob.ar/tramitesadistancia/filtro-tramites?id_tipo_tramite=2179" class="btn btn-primary">OFRECER</a>
            <?php else : ?>
                <p><?php print $item['estado']?></p>
            <?php endif ?>
        </td>
      </tr>
      <?php endforeach;?>
    </tbody>
  </table>
</div>
