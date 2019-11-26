<div class="text-center m-t-4" id="rlm_nuevabusqueda">
  <a href="<?php print url('/' . drupal_get_path_alias()); ?>" class="btn btn-primary">Nueva búsqueda</a>
</div>
<div class="alert alert-warning">
  <div class="media">
    <div class="media-left">
    <i class="fa fa-warning fa-fw fa-2x"></i>
    </div>
    <div class="media-body">
      <p class="m-b-0">Los datos enviados no concuerdan o tu registro se encuentra en proceso.</p>
    </div>
  </div>
</div>
<script type="text/javascript">
  document.getElementById("wrapp").childNodes[0].childNodes[0].style.display = 'none';
</script>