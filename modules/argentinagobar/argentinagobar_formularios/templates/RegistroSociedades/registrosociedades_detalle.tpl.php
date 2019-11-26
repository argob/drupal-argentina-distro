<style>
@media screen and (max-width: 768px){
.table-sociedad thead{display: none;}
.table-sociedad td{display: block;width: initial;border-top:none!important;}
.table-sociedad tr td:last-child{border-bottom:1px solid #ddd!important;}
}
</style>
    <div class="text-center m-t-4" id="reg_soc_nuevabusqueda">
      <a href="<?= url($base_url . '/' . drupal_get_path_alias()); ?>" class="btn btn-primary">Nueva búsqueda</a>
    </div>
<div class="col-md-12">
  <table class="table table-spaced table-hover table-sociedad">
    <thead>
    <tr>
      <th width=25%>Sociedad</th>
      <th width=30%>Domicilio fiscal</th>
      <th width=30%>Domicilio legal</th>
      <th width=15%>Fecha de actualizacion <a href="#fecha_act" style="position: relative;bottom: 26px;color: #1B5388;">*</a></th>
    </thead>
    <tbody class="list" id="show-data">
    <?php foreach ($items as $item):?>
    <tr>
      <td width=25%>
        <strong>Razón social</strong>
        <p><?= $item['razon_social']?></p>
        <strong>CUIT / CDI</strong>
        <p><?= $item['cuit']?></p>
        <strong>Tipo societario</strong>
				<p><?= $item['tipo_societario']?></p>
				<strong>Fecha de contrato</strong>
				<p><?= $item['fecha_contrato_social']?></p>
				<strong>Número en registro local</strong>
				<p><?= $item['numero_inscripcion']?></p>
      </td>
      <td width=30%>
        <strong>Provincia</strong>
        	<p><?= $item['df_provincia']?></p>
        <strong>Localidad</strong>
        	<p><?= $item['df_localidad']?></p>
        <strong>Domicilio</strong>
        	<p><?= $item['df_domicilio']?></p>
        <strong>Código postal</strong>
        	<p><?= $item['df_cp']?></p>
        <strong>Estado de domicilio <a href="#estado_dom" style="color: #1B5388">**</a></strong>
        	<p><?= $item['df_estado_domicilio']?></p>
        <strong>Correo</strong>
        <p><?= $item['correo']?></p>
      </td>
      <td width=30%>
        <strong>Provincia</strong>
        <p><?= $item['dl_provincia']?></p>
        <strong>Localidad</strong>
        <p><?= $item['dl_localidad']?></p>
        <strong>Domicilio</strong>
        <p><?= $item['dl_domicilio']?></p>
        <strong>Código postal</strong>
        <p><?= $item['df_provincia']?></p>
        <strong>Estado de domicilio</strong>
        <p><?= $item['dl_estado_domicilio']?></p>
      </td>
      <td width=15%>
        <p><?= $item['fecha_actualizacion']?></p>
      </td>
    </tr>
    <?php endforeach;?>

    </tbody>
  </table>
  <label><b>Información fuente AFIP</b></label>
  <label id="fecha_act"><b>* La Fecha de Actualización</b> indica la fecha en que los datos del CUIT fueron modificados respecto de la base de datos que fue elaborada el 13/11/2018.  De existir modificaciones al CUIT anteriores al 13/11/2018, no surgirán de esta consulta.</label>
  <label id="estado_dom"><b>** <a href="https://www.argentina.gob.ar/justicia/registro-nacional-sociedades/referencias"  target="_blank">El Estado de Domicilio</a></b> indica la condición que éste tiene para AFIP y describe el criterio que sigue AFIP para las distintas categorías que usted puede encontrar en este campo.</label>
</div>
