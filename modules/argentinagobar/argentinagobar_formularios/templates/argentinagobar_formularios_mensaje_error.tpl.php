<div class="alert alert-block alert-danger messages error">
  <a class="close" data-dismiss="alert" href="#">×</a>
  <h4 class="element-invisible">Mensaje de error</h4>
  <ul>
   <?php foreach ($errores as $error) { ?>
     <li>El campo Año de Expediente es obligatorio.</li>
   <?php } ?>
  </ul>
</div>
