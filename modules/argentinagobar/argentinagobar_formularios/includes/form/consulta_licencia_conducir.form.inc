<?php

function consulta_licencia_conducir($form, &$form_state) {

  $form = array();

  $form['contenedor'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contenedor',
      ),
  );

  $form['contenedor']['titulo'] = array(
    '#type' => 'markup',
    '#markup' => "<h3>".t('Completá los datos del formulario:')."</h3>" ,
  );

  $form['contenedor']['alerta'] = array(
    '#type' => 'markup',
    '#markup' => '<div class="alert alert-warning">
          <div class="media">
            <div class="media-left media-middle">
              <i class="fa fa-warning fa-fw fa-4x"></i>
            </div>
          <div class="media-body">
            <p class="m-b-0"> Esta consulta funciona solamente con Licencias Nacionales, no con licencias municipales o provinciales. Estos son los modelos de licencias. Seleccioná una imagen para agrandarla.</p>
          </div>
          </div>
        </div>',
  );

  $form['contenedor']['licencia_imagen'] = array(
    '#type' => 'markup',
    '#markup' =>"<div class=\"row\">
  <div class=\"col-sm-8 col-sm-offset-2 col-md-4 col-md-offset-0\">
    <a href=\"#modeloLicencia\" data-toggle=\"modal\">
      <img src=\"" . base_path() . "sites/default/files/licencia-anterior.jpg\" class=\"img-responsive m-b-1\"  alt=\"Responsive image\">
    </a>
  </div>
  <div class=\"col-sm-8 col-sm-offset-2 col-md-4 col-md-offset-0\">
    <a href=\"#modeloLicencia\" data-toggle=\"modal\">
      <img src=\"" . base_path() . "sites/default/files/licencia.jpg\" class=\"img-responsive m-b-1\"  alt=\"Responsive image\">
    </a>
  </div>
  <div class=\"col-sm-8 col-sm-offset-2 col-md-4 col-md-offset-0\">
    <a href=\"#modeloLicencia\" data-toggle=\"modal\">
      <img src=\"" . base_path() . "sites/default/files/licencia-nueva.jpg\" class=\"img-responsive m-b-1\"  alt=\"Responsive image\">
    </a>
  </div>
</div>


<div id=\"modeloLicencia\" class=\"modal fade\" tabindex=\"-1\" role=\"dialog\">
  <div class=\"modal-dialog\">
    <div class=\"modal-content\">
      <div class=\"modal-header\">
        <button type=\"button\" class=\"close\" data-dismiss=\"modal\" aria-label=\"Close\">
          <span aria-hidden=\"true\">×</span>
        </button>
      </div>
      <div class=\"modal-body p-x-2\">
        <div class=\"row numbers p-b-1 text-center\">
          <div class=\"col-md-12\">
            <img src=\"" . base_path() . "sites/default/files/licencia.jpg\" class=\"img-responsive m-b-1 center-block\" alt=\"Responsive image\">
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
<script type=\"text/javascript\">
(function($) {
  $('[data-toggle=\"modal\"]').click( function() {
    var src = $(this).find(\"img\").attr(\"src\");
    $(\".modal\").find(\"img\").attr(\"src\", src);
  });
 })(jQuery);
</script>
",
  );

  $form['contenedor']['document'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('row'),
    ),
  );

  $form['contenedor']['document']['document_type'] = array(
    '#type' => 'select',
    '#title' => t('Tipo de documento'),
    '#required' => TRUE,
    '#empty_option' => t('Seleccioná'),
    '#prefix' => '<div class="col-xs-4">',
    '#suffix' => '</div>',
    '#options' => array(
      '1' => t('DNI'),
      '2' => t('Libreta Cívica'),
      '3' => t('Libreta de Enrolamiento'),
      '4' => t('Pasaporte'),
      '5' => t('Cédula de Identidad Extranjera'),
      ),
  );

  $form['contenedor']['document']['document_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Número de Documento'),
    '#prefix' => '<div class="col-xs-8">',
    '#suffix' => '</div>',
    '#size' => 60,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#rules' => array('numeric', 'length[6, 8]'),
  );

  $form['contenedor']['gender'] = array(
    '#type' => 'radios',
    '#title' => 'Sexo',
    '#required' => TRUE,
    '#options' => array(
      'F' => t('Femenino'),
      'M' => t('Masculino'),
    ),
    '#theme' => array('form_element_radios_btn'),
  );

  $form['contenedor']['boton_consultar_ll_conducir'] = array(
    '#prefix' => '<div class="text-center">',
    '#suffix' => '</div>',
    '#type' => 'submit',
    '#ajax' => array(
      'callback' => 'consulta_licencia_conducir_submit_ajax',
      'wrapper' => 'contenedor',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#value' => t('Consultar'),
      '#attributes' => array(
        'class' => array(
        'btn',
        'btn-success',
        'btn-block',
        'btn-lg',
        ),
      ),
  );

  return $form;
}



function consulta_licencia_conducir_submit_ajax($form, $form_state) {

  $form_id = $form_state['build_info']['form_id'];

  drupal_validate_form($form_id, $form, $form_state);

  if (form_get_errors()) {
    $form_state['rebuild'] = TRUE;
    return $form;
  }

  $consulta = new ConsultaLicenciaConducir(ApiGatewayAuth::getInstance(), $form_state['values']);

  return $consulta->consultar();
}
