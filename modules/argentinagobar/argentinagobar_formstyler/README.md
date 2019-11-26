Argentinagobar Drupal Form Styler
=================

Módulo Drupal para adaptar los formularios con clases añadidas a los elementos


# Listado de funciones

## function argentinagobar_radiostyler($form)

Devuelve form con estilos para mostrar los radio button como botones.


### Parameters

**$form:** El form que utilizas en hook_form.


### Utilización

En el hook_form se debe agregar el estilo radioStyler a los atributos del radio a modificar. Y agregar la funcion argentinagobar_radiostyler al final.

```
function consulta_tramite_pasaporte_form($form, &$form_state) {

	$form['radioSample'] = array(
		'#type' => 'radios',
		'#default_value' => 0,
		'#title' => t('Sexo'),
		'#attributes' => array('class'=>array('radioStyler'))
	);

	argentinagobar_radiostyler($form);

	return $form;
}
```


## function argentinagobar_localidad($form, $form_state, $options)

Devuelve el campo para elegir provincia y localidad consumido de MiArgentina.
Dado que al hacer varias consultas tiene problemas al responder. Obtiene las localidades en un json que se renueva periódicamente.


### Parameters

**$options:** Es un array con las opciones del campo


### Utilización

```
	$options = array(
		'nombre' => 'Elegir provincia',
		'caption' => 'Elegir una provincia',
		'required' => FALSE,
		'fieldset' => 'elegirProv'
	);

	argentinagobar_localidad($form, $form_state, $options);
```


## function argentinagobar_formstyler(&$form, $title, $response)

Devuelve form con estilos para mostrar respuestas.


### Parameters

**$form:** El form que utilizas en hook_form.

**$title:** El titulo del form porque se ve separado.

**$response:** TRUE si habilitas la respuesta o FALSE solo lo utilizas para estilizar un form.


### Utilización

Se debe agregar la funcion argentinagobar_formstyler al final. Por ejemplo.

```
function hook_form($form, &$form_state) {

	$form['consulta'] = array(
		'#type' => 'vertical_tabs',
		'#description' => t('Estado del DNI'),
	);

	$form['tramite'] = array('#type' => 'hidden', '#value' => 'estadoDNI');

	$form['submit']['#type'] = 'submit';
	$form['submit']['#value'] = t('Consultar');

	$options = array (
		'title' => 'Elegí el tipo de consulta', // Titulo formateado
		'subtitle' => '(Los campos marcados con * son obligatorios)', // Subitulo formateado
		'response' => TRUE, // Respuesta de ajax
		'progress' => FALSE, // Usa progress grisando el form
	);

	argentinagobar_formstyler($form, $options);

	return $form;
}
```