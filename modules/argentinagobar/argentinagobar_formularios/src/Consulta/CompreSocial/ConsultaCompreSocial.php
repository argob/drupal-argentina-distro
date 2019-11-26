<?php

class ConsultaCompreSocial extends Consulta
{
    public $items;
    protected $fields = array();

    // Crear la configuración del endpoint
    public function get_endpoint()
    {
        $config = variable_get('compre_social_config');
        return $config['endpoint'] . '/productos';
    }

    // Form API para los filtros de compre social
    public function get_form($form, &$form_state, $consulta)
    {
        // Verifico si hay parámetros para colocarlos o no en la consulta
        if ($this->hayParametros()) {
            $this->setValues($this->getParametros());
            $response = $this->consultar();
        } else {
            $this->set_values([
                'page' => 1,
                'limit' => $this->get_values()['limit'] 
            ]);
            $response = $this->consultar();
        }

        // Verifico la salud del servicio con el endpoint de productos que si o si se necesita para este formulario
        if ($response == false) {
            $form = array();

            $form['response'] = array(
              '#type' => 'markup',
              '#markup' => 'El servicio no esta funcionando en estos momentos',
            );
        } else {
            $form = array();

            $form['#attached']['css'][] = drupal_get_path('module', 'argentinagobar_formularios') . '/css/compreSocial.css';

            // Consulta las provincias a GeoRef

            $provincias = new ConsultaGeoRefProvincias(ApiGatewayAuth::getInstance());

            $form['title'] = array(
                '#type' => 'markup',
                '#markup' => '<h4>Búsqueda de productos/servicios</h4><p class="text-muted">'.variable_get('compresocial_disclaimer').'</p>',
            );

            // Campo buscar le puse nombre para respetar el mismo wording del servicio
            $form['nombre'] = array(
                '#type' => 'textfield',
                '#title' => t('Producto / Servicio'),
                '#prefix' => '<div class="row"><div class="col-xs-12 col-md-9">',
                '#suffix' => '</div>',
                '#default_value' => isset($_GET['nombre']) ? $_GET['nombre'] : null,
            );

            $submit = new FieldSubmit();
            $form['boton_buscar'] = $submit->render();
            $form['boton_buscar']['#value'] = t('Buscar');
            $form['boton_buscar']['#attributes'] = array('class' => array('form-control'));
            $form['boton_buscar']['#prefix'] = '<div class="col-xs-12 col-md-3"><div class="form-item form-item-buscar form-type-textfield form-group"><label class="control-label" for="edit-buscar">&nbsp</label>';
            $form['boton_buscar']['#suffix'] = '</div></div></div>';

            $form['boton_buscar']['#submit']['callback'] = 'compre_social_submit';

            $form['filtros'] = array(
                '#type' => 'container',
                '#attributes' => array(
                    'class' => array(
                        'row'
                    )
                ),
            );

            $form['filtros']['provincia'] = array(
                '#type' => 'select',
                '#title' => 'Provincia',
                '#options' => $provincias->get_select_options(),
                '#prefix' => '<div class="col-xs-12 col-md-3">',
                '#suffix' => '</div>',
            );

            // Consulta los rubros
            $rubros = new ConsultaCompreSocialRubros(ApiGatewayAuth::getInstance());

            $form['filtros']['rubro'] = array(
                '#type' => 'select',
                '#title' => 'Rubro',
                '#options' => $rubros->get_select_options(),
                '#prefix' => '<div class="col-xs-12 col-md-3">',
                '#suffix' => '</div>',
            );

            // Unidad productiva y tipo de elaboración son sólo estos por lo tanto no son dinámicos
            $form['filtros']['unidad_productiva'] = array(
                '#type' => 'select',
                '#title' => 'Unidad productiva',
                '#options' => [
                    'Emprendimiento' => 'Emprendimiento',
                    'Cooperativa' => 'Cooperativa',
                    'Comercializadora' => 'Mercado solidario'
                    ],
                '#prefix' => '<div class="col-xs-12 col-md-3">',
                '#suffix' => '</div>',
            );

            // Unidad productiva y tipo de elaboración son sólo estos por lo tanto no son dinámicos
            $form['filtros']['elaboracion'] = array(
                '#type' => 'select',
                '#title' => 'Tipo de elaboración',
                '#options' => [
                    'Artesanal' => 'Artesanal',
                    'Industrial'=> 'Industrial',
                ],
                '#prefix' => '<div class="col-xs-12 col-md-3">',
                '#suffix' => '</div>',
            );

            $form['response'] = array(
                  '#type' => 'markup',
                  '#markup' => $this->renderResponse($form, $form_state, $response),
            );

            // Defino las propiedades iguales para todos los filtros

            foreach ($form['filtros'] as $key => $filtro) {
                if(isset($filtro['#type']) && $filtro['#type']=='select'){
                    $form['filtros'][$key]['#empty_option'] = '- Todos -';
                    $form['filtros'][$key]['#default_value'] = isset($_GET[$key]) ? $_GET[$key] : null;
                }
            }

            // REEMPLACÉ LA FUNCIÓN DE AJAX porque hay un problema difícil de debuggear de ajax en QA, quiero saber si reemplazando por esto puedo tener solucionado el asunto porque lo único que se necesita es construir el query string.

            drupal_add_js('jQuery(document).ready(function () {
                jQuery(".form-control.form-select").each(function(){
                    jQuery(this).change(function(){
                        var parameter = jQuery(this).attr("name");
                        var optionSelected = jQuery("option:selected", this);
                        var parameterValue = this.value;
                        if( window.location.search.indexOf(parameter) >= 0){
                            var query = window.location.search.replace(new RegExp("(" + parameter + "=)(.*?)(&|$)", "i"), "$1" + parameterValue + "$3");
                        } else {
                            if( window.location.search.length == 0){
                                var query = "?" + parameter + "=" + parameterValue;
                            }else{
                                var query = window.location.search + "&" + parameter + "=" + parameterValue;
                            }
                        }
                        query = query.replace(/page=.*?(&|$)/i, "page=1$1")
                        window.location = window.location.pathname + query;
                    });
                });
            });', array(
              'type' => 'inline',
              'scope' => 'footer',
              'weight' => 5,
            ));

            # serializa la class para tenerla disponible en el submit y ejecutar $this::consultar()
            $form_state['handler']['class'] = serialize($this);
        }

        return $form;
    }

    public function renderResponse($form, &$form_state, $data)
    {

        if (isset($data['data']) && count($data['data']) > 0) {
            $response = 'lista';

            foreach ($data['data'] as $key => $result) {
                // CON EL ID DE FIRST IMAGE CONSULTO ENDPOINT Y QUE ME DE LA IMAGEN POSTA EN BINARY LA RETORNO
                if (isset($result['imagenes'][0]['id'])) {
                    global $base_url;
                    $img_64 = new ConsultaCompreSocialArchivo(ApiGatewayAuth::getInstance());
                    $img_64->set_values([
                        'id' => $result['imagenes'][0]['id'],
                        'mimetype' => $result['imagenes'][0]['mimetype']
                    ]);
                    $data['data'][$key]['imagen'] = $img_64->consultar();
                    $data['data'][$key]['alias'] = $base_url.'/'.drupal_get_path_alias('node/'.arg(1)).'/producto/'.$result['slugs'][0]['slug'].'/detalle';
                }
            }

            $currentPage = $data['meta']['current_page'];
            $lastPage = $data['meta']['last_page'];


            $response = theme(
                'compre_social_listado',
                [
                'items' => $data['data'],
                'items_per_page' => $this->get_values()['limit'],
                'paginador' => theme(
                    'compre_social_paginador',
                    [
                    'start' => ($currentPage > 2) ? ((($currentPage + 2) > $lastPage) ? $currentPage - (4 - ($lastPage-$currentPage)) : $currentPage - 2) : 1,
                    'end' =>   ($currentPage < 3) ? 5 : ((($currentPage + 2) > $lastPage) ? $lastPage : $currentPage + 2),
                    'total' => $data['meta']['total'],
                    'per_page' => $data['meta']['per_page'],
                    'current_page' => $currentPage,
                    'last_page' => $lastPage,
                    'current_url' => '?' . http_build_query($this->get_params_wo_offset())
                    ]
                    )
                ]
                );
        } else {
            $response = '<div class="col-md-12 alert alert-warning">
            <h5>No hay productos con ese criterio de búsqueda</h5>
            <p>Por favor realice una nueva</p>
            </div>';

        }

        return $response;
    }

    public function isValidParam($param)
    {
        return in_array($param, $this->validParams());
    }

    public function validParams()
    {
        return array(
          'nombre',
          'rubro',
          'provincia',
          'unidad_productiva',
          'elaboracion',
          'limit',
          'page'
        );
    }

    public function hayParametros()
    {
        return count($this->getParametros()) > 0;
    }

    public function get_request_url()
    {
        $endpoint = $this->get_endpoint();

        if (is_null($endpoint) || $enpoint = '') {
            throw new EndpointNuloException("Falta endpoint para Consulta", 1);
        }
        // Chequeo el vacío para no enviar parametros vacíos
        if (!empty($this->get_params())) {
            foreach ($this->get_params() as $key => $param) {
                if (!empty($param)) {
                    $params[$key] = $param;
                }
            }
        }
        return $endpoint . '?' . http_build_query($params);
    }

    public function get_params()
    {
        return $this->get_values();
    }

    // Necesito quitar el offset para las nuevas búsquedas
    public function get_params_wo_offset()
    {
        // Chequeo el vacío para no enviar parametros vacíos
        $params = [];
        if (!empty($this->get_params())) {
            foreach ($this->get_params() as $key => $param) {
                if (!empty($param) && !in_array($key, ['limit','page'])) {
                    $params[$key] = $param;
                }
            }
        }
        return $params;
    }

    public function getParametros()
    {
        return drupal_get_query_parameters($query = null, $exclude = array('q'), $parent = '');
    }

    public function get_response($request)
    {
        $response = null;

        if ($request->code == 401) {
            $this->api_gateway_auth->refresh_token();
            $this->consultar();
        }

        if ($request->code == 200) {
            $response = drupal_json_decode($request->data);
        } else {
            $response = false;
            drupal_set_message('Ha ocurrido un error', $type = 'error', $repeat = false);
            watchdog('Formularios', 'Request code: ' . $request->code, $variables = array(), WATCHDOG_ERROR, $link = null);
        }

        return $response;
    }
}

function compre_social_submit($form, &$form_state)
{
  
  $consulta = unserialize($form_state['handler']['class']);

  $consulta->setValues($form_state['values']);

  global $base_url;

  // Para que todas las búsquedas vayan a la página 1
  $params = $consulta->get_params();
  $params['page'] = 1;

  $form_state['redirect'] = array(
    $base_url . '/' . drupal_get_path_alias(),
    array('query' => $params),
  );
}