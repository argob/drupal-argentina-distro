<?php

$hay_atajo_activo = false;

$plugin = array(
  'single' => true,
  'title' => t('Grupo de Atajos'),
  'description' => t('Los atajos se utilizan para enlazar cualquier tipo de contenido, tanto interno como externo, y con diferentes tipos de jerarquías.'),
  'category' => t('Drupar'),
  'render callback' => 'drupar_componentes_atajos_render',
  'edit form' => 'drupar_componentes_atajos_edit_form',
  'admin info' => 'drupar_componentes_atajos_admin_info',
  'defaults' => array(
    'atajos' => array(),
    'cantidadAtajos' => 1,
    'opciones' => array(
      'formato' => 'FormatoAtajoSimple',
      'columnas' => 1,
    ),
  )
);

/**
* 'admin info' callback for panel pane.
*/
function drupar_componentes_atajos_admin_info($subtype, $conf, $contexts)
{
    foreach ($conf['atajos'] as $key => $item) {
        $atajo = array();
        $formato_de_texto = strip_tags($conf['atajos'][$key]['texto']['format']);
        $atajo['titulo'] = $item['titulo'];
        $atajo['texto_descriptivo'] = strip_tags($item['texto']['value']);
        $atajo['formato_de_texto'] = ucfirst(str_replace("_", " ", $formato_de_texto));
        $atajo['enlace_interno'] = $item['link_interno']['entity_label'];
        $atajo['enlace_externo'] = $item['link_externo'];
        $atajo['imagen'] = $item['imagen'];
        $atajo['color_del_boton'] = $item['color_boton'];
        $atajo['tipo_de_icono'] = $item['icono'];
        $atajo['color_del_icono'] = $item['color_icono'];
        $atajo['color_de_fondo'] = $item['color_fondo'];
        $campos['listado_de_atajos']['atajo_' . $key] = $atajo;
    }

    if (!empty($conf)) {
        $block = new stdClass;
        $block->title = propertyExists($conf, 'override_title') ? $conf['override_title_text'] : "Cantidad de atajos: ". $conf['cantidadAtajos'];
        $block->content = theme('argentinagobar_bloques_admin_info', array('campos' => $campos));

        return $block;
    }
}

/**
* 'Edit form' callback for the content type.
*/
function drupar_componentes_atajos_edit_form($form, &$form_state)
{
    form_load_include($form_state, 'inc', 'argentinagobar_bloques', 'plugins/content_types/atajos');

    // La propiedad #tree asegura que cada elemento HTML sean nombrados distintivamente ej: name=[container][123][name]
    $form['#tree'] = true;

    $form['cantidadAtajos'] = array(
    '#type' => 'hidden',
    '#value' => $form_state['conf']['cantidadAtajos'],
  );

    $form['opciones'] = array(
    '#type' => 'fieldset',
    '#title' => t('Opciones de visualización'),
    '#weight' => 5,
    '#collapsible' => true,
    '#collapsed' => false,
  );

    $form['atajos'] = array(
    '#type' => 'fieldset',
    '#title' => t('Atajos'),
    '#collapsible' => true,
    '#collapsed' => false,
  );

    $form['agregarAtajo'] = array(
    '#type' => 'fieldset',
    '#title' => t(' '),
  );

    if ($form_state['conf']['cantidadAtajos'] > 1) {
        $form['borrarAtajo'] = array(
            '#type' => 'fieldset',
            '#title' => t('Borrar Atajos'),
            '#collapsible' => true,
            '#collapsed'   => true,
        );

        /*
         * Hotfix 42.3 - Borrar Ultimo Atajo
        */
        $form['borrarUltimoAtajo'] = array(
            '#type' => 'fieldset',
            '#title' => t('Borrar Ultimo Atajo'),
            '#collapsible' => true,
            '#collapsed'   => true
        );

        $form['ordenarAtajo'] = array(
            '#type' => 'fieldset',
            '#title' => t('Ordenar Atajos'),
            '#collapsible' => true,
            '#collapsed'   => true,
        );
    }

    $form['opciones']['formato'] = array(
    '#type' => 'select',
    '#title' => t('Formato'),
    '#options' => array(
      'FormatoAtajoBoton' => t('Botón'),
      'FormatoAtajoSimple' => t('Simple'),
      'FormatoAtajoDestacadoIcono' => t('Destacado con ícono'),
      'FormatoAtajoDestacadoImagen' => t('Destacado con imagen'),
      'FormatoAtajoCircular' => t('Circular'),
    ),
    '#default_value' => $form_state['conf']['opciones']['formato'],
    '#description' => t('Define el estilo visual de los atajos'),
  );

    $form['opciones']['columnas'] = array(
    '#type' => 'select',
    '#title' => t('Columnas'),
    '#default_value' => $form_state['conf']['opciones']['columnas'],
    '#description' => t("Cantidad de atajos por fila"),
    '#element_validate' => array('drupar_componentes_validar_cantidad_columnas'),
    '#options' => array(
      1 => 1,
      2 => 2,
      3 => 3,
      4 => 4,
    ),
    '#required' => true,
    '#states' => array(
      'invisible' => array(
        array(
          array(':input[name="opciones[formato]"]' => array('value' => 'FormatoAtajoBoton')),
          'OR',
          array(':input[name="opciones[formato]"]' => array('value' => 'FormatoAtajoCircular')),
        ),
      ),
    ),
  );

    $form['opciones']['destacar'] = array(
    '#type' => 'checkbox',
    '#title' => t('Destacar'),
    '#default_value' => propertyExists($form_state['conf']['opciones'], 'destacar') ? $form_state['conf']['opciones']['destacar'] : null,
    '#description' => t("Crea botones más grandes"),
    '#states' => array(
      'visible' => array(
        array(
          array(':input[name="opciones[formato]"]' => array('value' => 'FormatoAtajoBoton')),
        ),
      ),
    ),
  );

    $cantidadAtajos = $form_state['conf']['cantidadAtajos'];

    for ($i = 1; $i <= $cantidadAtajos; $i++) {
        $confAtajo = isset($form_state['conf']['atajos'][$i]) ? $form_state['conf']['atajos'][$i] : null;

        $form['atajos'][$i] = array(
      '#type' => 'fieldset',
      '#title' => 'Atajo ' . $i . ' -'.$confAtajo['titulo'],
      '#collapsible' => true,
      '#collapsed' => true,
    );

        $form['atajos'][$i]['titulo'] = array(
      '#title' => t('Título'),
      '#type' => 'textfield',
      '#default_value' => $confAtajo['titulo'],
      '#required' => true,
    );

        $form['atajos'][$i]['texto'] = array(
      '#title' => t('Texto descriptivo'),
      '#type' => 'text_format',
      '#format' => 'filtered_html',
      '#default_value' => $confAtajo['texto']['value'],
      '#required' => false,
      '#maxlength' => 500,
      '#states' => array(
        'invisible' => array(
          array(
            array(':input[name="opciones[formato]"]' => array('value' => 'FormatoAtajoBoton')),
            array(':input[name="opciones[formato]"]' => array('value' => 'FormatoAtajoCircular')),
          ),
        ),
      ),
    );

        $form['atajos'][$i]['link_interno'] = array(
      '#type' => 'entityreference',
      '#title' => t('Enlace interno'),
      '#default_value' => $confAtajo['link_interno'],
      '#required' => false,
      '#era_entity_type' => 'node',
      '#era_bundles' => array(),
      '#era_cardinality' => 1,
      '#states' => array(
        'invisible' => array(
          ':input[name="link_externo"]' => array('filled' => true),
        ),
      ),
      '#description' => t('Usá este campo para hacer enlaces a contenido de Argentina.gob.ar'),
    );

        $form['atajos'][$i]['link_externo'] = array(
      '#type' => 'textfield',
      '#title' => t('Enlace externo'),
      '#default_value' => $confAtajo['link_externo'],
      '#rules' => array('url'),
      '#maxlength' => 255,
      '#states' => array(
        'invisible' => array(
          ':input[name="link_interno"]' => array('filled' => true),
        ),
      ),
      '#element_validate' => array('drupar_componentes_atajos_validar_link_externo'),
      '#description' => t('Usá este campo para hacer enlaces a contenido externo a Argentina.gob.ar'),
    );

        $form['atajos'][$i]['imagen'] = array(
      '#type' => 'managed_file',
      '#title' => t('Subir imagen'),
      '#default_value' => $confAtajo['imagen']['fid'],
      '#description' => t('Upload a file, allowed extensions: jpg, jpeg, png, gif'),
      '#upload_location' => 'public://imagenAtajo/',
      '#progress_indicator' => 'bar',
      '#progress_message' => t('Subiendo archivo ...'),
      '#upload_validators' => array(
        'file_validate_extensions' => array('jpg jpeg png gif'),
      ),
      '#element_validate' => array('drupar_componentes_atajos_validar_imagen'),
      '#states' => array(
        'visible' => array(
          array(
            array(':input[name="opciones[formato]"]' => array(
              'value' => 'FormatoAtajoDestacadoImagen'
            )),
          ),
        ),
      ),
    );

        $form['atajos'][$i]['icono'] = array(
      '#title' => t('Elegir ícono'),
      '#type' => 'select',
      '#default_value' => $confAtajo['icono'],
      '#empty_option' => t('Sin ícono'),
      '#empty_value' => 'sin_icono',
      '#options' => variable_get('iconos', $default = null),
      '#element_validate' => array('drupar_componentes_atajos_validar_icono'),
      '#states' => array(
        'invisible' => array(
          array(
            array(':input[name="opciones[formato]"]' => array('value' => 'FormatoAtajoBoton')),
            array(':input[name="opciones[formato]"]' => array('value' => 'FormatoAtajoDestacadoImagen')),
          ),
        ),
      ),
    );

        $form['atajos'][$i]['color_icono'] = array(
      '#title' => t('Color de ícono'),
      '#type' => 'select',
      '#default_value' => $confAtajo['color_icono'],
      '#options' => array(
        'text-primary' => t('Azul'),
        'text-secondary' => t('Celeste'),
        'text-success' => t('Verde'),
        'text-warning' => t('Amarillo'),
        'text-danger' => t('Rojo'),
        'text-muted' => t('Gris claro'),
        'text-gray' => t('Gris oscuro'),
        'text-default' => t('Negro'),
        'text-fucsia' => t('Fucsia'),
        'text-arandano' => t('Arándano'),
        'text-uva' => t('Uva'),
        'text-cielo' => t('Cielo'),
        'text-verdin' => t('Verdin'),
        'text-lima' => t('Lima'),
        'text-maiz' => t('Maiz'),
        'text-tomate' => t('Tomate'),
        'text-verde-azulado' => t('Verde Azulado'),
        'text-naranja' => t('Naranja Oscuro'),
      ),
      '#states' => array(
        'visible' => array(
          ':input[name="opciones[formato]"]' => array(
            'value' => "FormatoAtajoSimple"
          ),
        ),
      ),
    );

        $form['atajos'][$i]['color_fondo'] = array(
      '#title' => t('Color de fondo'),
      '#type' => 'select',
      '#default_value' => str_replace("bg-", "panel-", $confAtajo['color_fondo']),
      '#options' => array(
        'panel-primary' => t('Azul'),
        'panel-info' => t('Celeste'),
        'panel-success' => t('Verde'),
        'panel-warning' => t('Amarillo'),
        'panel-muted' => t('Gris oscuro'),
        'panel-gray' => t('Gris claro'),
        'panel-danger' => t('Rojo'),
        'panel-fucsia' => t('Fucsia'),
        'panel-arandano' => t('Arandano'),
        'panel-uva' => t('Uva'),
        'panel-cielo' => t('Cielo'),
        'panel-verdin' => t('Verdin'),
        'panel-lima' => t('Lima'),
        'panel-maiz' => t('Maiz'),
        'panel-tomate' => t('Tomate'),
        'panel-verde-azulado' => t('Verde Azulado'),
        'panel-naranja' => t('Naranja Oscuro'),
      ),
      '#states' => array(
        'visible' => array(
          array(
            array(':input[name="opciones[formato]"]' => array(
              'value' => "FormatoAtajoDestacado"
            )),
            array(':input[name="opciones[formato]"]' => array(
              'value' => "FormatoAtajoDestacadoIcono"
            )),
            array(':input[name="opciones[formato]"]' => array(
              'value' => "FormatoAtajoCircular"
            )),
          )
        ),
      ),
    );

        $form['atajos'][$i]['color_boton'] = array(
      '#title' => t('Color de botón'),
      '#type' => 'select',
      '#default_value' => $confAtajo['color_boton'],
      '#options' => array(
        'btn-default' => t('Gris'),
        'btn-primary' => t('Azul'),
        'btn-success' => t('Verde'),
        'btn-danger' => t('Rojo'),
        'btn-link' => t('Link'),
      ),
      '#states' => array(
        'visible' => array(
          ':input[name="opciones[formato]"]' => array(
            'value' => "FormatoAtajoBoton"
          ),
        ),
      ),
    );

        $atajosBorrar[$i] = 'Atajo: '.$i. ' - '.$confAtajo['titulo'];
        $ordenTotal[$i]   = $i;
    }

    $form['agregarAtajo']['agregar_otro_atajo'] = array(
    '#type' => 'submit',
    '#value' => t('Agregar otro atajo'),
    '#submit' => array('drupar_componentes_atajos_agregar_otro_atajo'),
  );

    if ($form_state['conf']['cantidadAtajos'] > 1) {
        $form['borrarAtajo']['borrar_select'] = array(
      '#type' => 'select',
      '#options' => $atajosBorrar,
      '#default_value' => t('Seleccione un atajo')
    );

        $form['borrarAtajo']['borrar_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Borrar atajo seleccionado'),
      '#submit' => array('drupar_componentes_atajo_seleccionado'),
      '#limit_validation_errors' => array()
    );

        $form['borrarUltimoAtajo']['borrarUltimoAtajo'] = array(
      '#type' => 'submit',
      '#value' => t('Borrar ultimo atajo'),
      '#submit' => array('drupar_componentes_borrar_ultimo_atajo'),
      '#limit_validation_errors' => array()
    );


        for ($iOrden=1; $iOrden <= $cantidadAtajos; $iOrden++) {
            $confAtajo = isset($form_state['conf']['atajos'][$iOrden]) ? $form_state['conf']['atajos'][$iOrden]['titulo'] : null;

            $nombreSelect = 'orden_select_'.$iOrden;
            $titleSelect  = 'Atajo '.$iOrden.' - '.$confAtajo.': ';

            $form['ordenarAtajo'][$nombreSelect] = array(
        '#type'     => 'select',
        '#title'    => $titleSelect,
        '#default_value' => $iOrden,
        '#options'  => $ordenTotal,
      );
        }

        $form['ordenarAtajo']['orden_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Guardar Orden'),
      '#submit' => array('drupar_componentes_guardar_orden'),
      '#limit_validation_errors' => array(),
    );
    }

    // boton de finish, se le cambia el texto
    $form['buttons']['return']['#value'] = 'Guardar';

    return $form;
}

function drupar_componentes_guardar_orden($form, &$form_state)
{
    $hayError = false;
    // simepre va a haber al menos 1
    $opcionesTotales = count($form['ordenarAtajo']['orden_select_1']['#options']);
    $mensaje = "";
    $ordenSeleccionado = array();

    for ($j=1; $j <= $opcionesTotales; $j++) {
        $nombreSelect = 'orden_select_'.$j;
        $ordenSeleccionado[$nombreSelect] = $form['ordenarAtajo'][$nombreSelect]['#value'];
    }

    $countValues = array_count_values($ordenSeleccionado);

    if (count($countValues) != $opcionesTotales) {
        $hayError = true;
        $mensaje .= 'No puede haber 2 atajos con el mismo numero de orden.';
    }

    if ($opcionesTotales != count($form_state['conf']['atajos'])) {
        $hayError = true;
        $mensaje .= 'Primero tiene que guardar los cambios para poder ordenar los atajos';
    }

    if ($hayError) {
        drupal_set_message($mensaje, 'error');
    } else {
        // a este punto ya estoy seguro que los 2 array son del mismo largo
        $ordenNuevo = array();
        $ordenAnterior = $form_state['conf']['atajos'];

        for ($iOrden=1; $iOrden <= $opcionesTotales; $iOrden++) {
            $nombreSelect = 'orden_select_'.$iOrden;
            $ordenNuevo[$iOrden] = $ordenAnterior[$ordenSeleccionado[$nombreSelect]];
        }

        $form_state['conf']['atajos'] = $ordenNuevo;
        $form_state['input']['atajos'] = $ordenNuevo;
        $form['atajos'] = $ordenNuevo;

        foreach ($form_state['input']['atajos'] as $key => $atajo) {
            if ($atajo['link_interno'] != array()) {
                $label  = $atajo['link_interno']['entity_label'];
                $id     = $atajo['link_interno']['entity_id'];

                $nuevoLinkInterno = '"'.$label.' ('.$id.')"';

                $form_state['input']['atajos'][$key]['link_interno'] = $nuevoLinkInterno;
            }
        }

        $form_state['rebuild'] = true;
    }
}

function drupar_componentes_atajos_agregar_otro_atajo($form, &$form_state)
{
    // All we need is to increase the number used in our for loop above ...
    $form_state['conf']['cantidadAtajos']++;
    // ... and rebuild our form.
    $form_state['rebuild'] = true;
}


/*
 * Hotfix 42.3 - Borrar ultimo atajo
*/
function drupar_componentes_borrar_ultimo_atajo($form, &$form_state)
{
    $form_state['conf']['cantidadAtajos']--;
    $form_state['rebuild'] = true;
}


function drupar_componentes_atajo_seleccionado($form, &$form_state)
{
    $opcionSeleccionada = $form['borrarAtajo']['borrar_select']['#value'];
    $atajos             = $form_state['conf']['atajos'];
    $atajoSeleccionado  = $atajos[$opcionSeleccionada];

    $nuevosAtajos = array();
    $i = 1;

    foreach ($atajos as $atajo) {
        if ($atajo['titulo'] != $atajoSeleccionado['titulo']) {
            $nuevosAtajos[$i] = $atajo;
            $i++;
        }
    }

    $form_state['conf']['atajos'] = $nuevosAtajos;
    $form_state['input']['atajos'] = $nuevosAtajos;
    $form['atajos'] = $nuevosAtajos;


    foreach ($form_state['input']['atajos'] as $key => $atajo) {
        if ($atajo['link_interno'] != array()) {
            $label  = $atajo['link_interno']['entity_label'];
            $id     = $atajo['link_interno']['entity_id'];

            $nuevoLinkInterno = '"'.$label.' ('.$id.')"';

            $form_state['input']['atajos'][$key]['link_interno'] = $nuevoLinkInterno;
        }
    }

    $form_state['rebuild'] = true;
    $form_state['conf']['cantidadAtajos']--;
    $form_state['rebuild'] = true;
}

/**
* The submit form stores the data in $conf.
*/
function drupar_componentes_atajos_edit_form_submit($form, &$form_state)
{
    foreach ($form_state['values']['atajos'] as $key => $atajo) {
        if ($atajo['imagen']['fid'] != 0) {
            $imagen = file_load($atajo['imagen']['fid']);
            $imagen->status = FILE_STATUS_PERMANENT;
            file_usage_add($imagen, 'argentinagobar_bloques', $type = 'atajo', $imagen->fid, $count = 1);
            file_save($imagen);
        }
    }
    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (isset($form_state['values'][$key])) {
            $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
}

function drupar_componentes_atajos_render($subtype, $conf, $panel_args, $context = null)
{
    $conf['opciones']['formato'] = $conf['opciones']['formato'] == 'FormatoAtajoDestacado' ? 'FormatoAtajoDestacadoIcono' : $conf['opciones']['formato'];

    $formato = new $conf['opciones']['formato'];
    $grupo_atajos = new GrupoAtajos($formato);

    $block = new stdClass();
    $block->title = '';
    $block->content = $grupo_atajos->render($conf['atajos'], $conf['opciones']);

    return $block;
}

function drupar_componentes_atajos_edit_form_validate(&$form_state, $form)
{
    $hayError = false;
    foreach ($form['values']['atajos'] as $key => $atajo) {
        if (empty($atajo['link_interno']) && empty($atajo['link_externo'])) {
            $hayError = true;
            $atajoKey = $key;
        }
    }
    if ($hayError) {
        form_set_error("atajos[1]['link_interno']", t('Debe indicar algún enlace'));
    }
}

function drupar_componentes_validar_cantidad_columnas($element, &$form_state, $form)
{
    if ($element['#value'] < 0 && $element['#value'] > 5) {
        form_error($element, t('Cantidad de columnas no permitida. Elegí entre 1 y 4'));
    }
}

function drupar_componentes_atajos_validar_imagen($element, &$form_state, $form)
{
    if ($form_state['values']['opciones']['formato'] == 'FormatoAtajoDestacadoImagen' && $element['#value']['fid'] == 0) {
        form_error($element, t('Debe elegir una imagen'));
    }
}

function drupar_componentes_atajos_validar_icono($element, &$form_state, $form)
{
    if ($form_state['values']['opciones']['formato'] == 'FormatoAtajoDestacadoIcono' && $element['#value'] == 'sin_icono' || $form_state['values']['opciones']['formato'] == 'FormatoAtajoCircular' && $element['#value'] == 'sin_icono') {
        form_error($element, t('Debe elegir un ícono'));
    }
}

function drupar_componentes_atajos_validar_link_externo($element, &$form_state, $form)
{
    if (!empty($element['#value']) && !valid_url($element['#value'], $absolute = true)) {
        form_error($element, t('Verificar link externo. Debe comenzar con el protocolo, por ejemplo \'https://\''));
    }
}

function drupar_componentes_atajos_validar_link_interno($element, &$form_state, $form)
{
    if (!empty($element['#value']) && valid_url($element['#value'], $absolute = false) && url_is_external($element['#value'], $absolute = true)) {
        form_error($element, t('Verificar link interno.'));
    }
}
