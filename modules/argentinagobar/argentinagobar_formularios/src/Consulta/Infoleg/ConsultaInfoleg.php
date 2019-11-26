<?php

abstract class ConsultaInfoleg extends Consulta
{

  public function __construct(
    ConsultaInfolegProvincias $consultaProvincias,
    IConsultaInfolegTipoNorma $consultaTipoNorma,
    ApiGatewayAuth $api_gateway_auth,
    array $values = array()
  ) {

    parent::__construct($api_gateway_auth, $values);

    $this->consultaProvincias = $consultaProvincias;
    $this->consultaTipoNorma = $consultaTipoNorma;

  }

  public $items;
  protected $fields = array();
  protected $consultaProvincias;


  function get_form($form, &$form_state, $consulta)
  {
    $form = array();

    $form['#attached']['css'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/css/Infoleg/estilosInfoleg.css',
    );

    $form['messages'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'messages'
      ),
    );

    $form['contenedor'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'wrapper',
        'class' => [
          'row',
          'm-b-0'
        ],
      ),
      '#prefix' => '<div class="row">',
      '#suffix' => '</div>',
    );

    $form['contenedor']['links'] = [

      '#type' => 'markup',
      '#markup' => '<div class="col-md-12 m-b-2">
                    <ul class="nav nav-pills">' .
                        $this::createPillTab("nacional") .
                            '<a href="'. $this::createPath(['jurisdiccion' => 'nacional']) . '">Búsqueda Nacional</a>
                        </li>' .
                        $this::createPillTab("provincial") .
                            '<a href="'. $this::createPath(['jurisdiccion' => 'provincial']) . '">Búsqueda Provincial</a>
                        </li>
                    </ul>
                  </div>'

    ];

    $form['contenedor']['jurisdiccion'] = $this->getFieldJurisdiccion();

    if ($this->hayParametros()) {

      $this->setValues($this->getParametros());

      $response = $this->consultar();

      $form['response'] = array(
        '#type' => 'markup',
        '#markup' => $this->renderResponse($form, $form_state, $response),
      );

      $form['#attached']['js'][] = array(
        'type' => 'external',
        'data' => '//cdnjs.cloudflare.com/ajax/libs/list.js/1.5.0/list.min.js',
      );

      $form['#attached']['js'][] = array(
        'type' => 'file',
        'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/infoleg/infolegSort.js',
      );

    } else {

      $form['response'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'response'
        ),
      );
    }

    $form['#attached']['js'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/infoleg/unSetCampoEnOtroTab.js',
      'type' => 'file',
      'data' => drupal_get_path('module', 'argentinagobar_formularios') . '/js/infoleg/unsetProvincia.js',
    );

    $form['#attached']['js'][] = array(
      'type' => 'setting',
      'data' => array('infoleg' => array('itemsPerPage' => $this->getItemsPerPage())),
    );

    //Deshabilito la antigua validacion del formulario
    //$form['#validate'] = array(array($this, 'validar_busqueda'));

    return $form;
  }

  protected static function createPath($queryString = []) {

    return url(current_path(), ['query' => $queryString]);

  }

  protected function getItemsPerPage()
  {
    return 50;
  }

  protected function getFieldSubmit()
  {
    $submitButton = new FieldSubmit();
    $submitButton->addClass('btn-primary');
    $submitButton->addClass('btn-block');
    $submitButton->setValue("Buscar");

    return $submitButton;
  }

  protected static function createPillTab($jurisdiccion) {

    if(static::getJurisdiccion() == $jurisdiccion) {

      $tab = '<li role="presentation" class="active">';

    } else {

      $tab = '<li role="presentation">';

    }

    return $tab;

  }

  protected function getFieldJurisdiccion() {

    return [
      '#type' => 'radios',
      '#title' => t('Jurisdicción'),
      '#title_display' => 'invisible',
      '#options' => [
        'nacional' => t('Nacional'),
        'provincial' => t('Provincial')
      ],
      '#attributes' => [
        'name' => 'jurisdiccion',
        'class' => [
          'hidden'
        ],
      ],
      '#default_value' => isset($_GET['jurisdiccion']) ? check_plain($_GET['jurisdiccion']) : 'nacional',
    ];

  }

  protected function getFieldProvincias() {

    return [
      '#type' => 'select',
      '#title' => t('Provincia'),
      '#options' => $this->getProvincias(),
      '#attributes' => array(
        'name' => 'provincia',
        'class' => [
          'col-md-3',
        ]
      ),
      '#empty_option' => t('Todas las provincias'),
      '#empty_value' => t(''),
      '#default_value' => isset($_GET['provincia']) ? check_plain($_GET['provincia']) : '',
      '#states' => array(
        'visible' => array(
          ':input[name="jurisdiccion"]' => array('value' => 'provincial')
        ),
      )
    ];

  }

  protected function getFieldNumero()
  {
    return array(
      '#type' => 'textfield',
      '#title' => t('Número (sin puntos)'),
      '#attributes' => array(
        'name' => 'numero',
      ),
      '#rules' => array('numeric',array(
        'rule' => "digit",
        'error' => t('No se pueden ingresar numeros negativos en %field'),
      )),
      '#default_value' => isset($_GET['numero']) ? check_plain($_GET['numero']) : '',
    );
  }

  protected function getFieldTiposNormas()
  {
    return array(
      '#type' => 'select',
      '#title' => t('Tipo de norma'),
      '#options' => $this->getTiposNormas(),
      '#attributes' => array(
        'name' => 'tipo_norma'
      ),
      '#empty_option' => t('Todas'),
      '#empty_value' => t('legislaciones'),
      '#prefix' => '<div class="col-md-4">',
      '#suffix' => '</div>',
      '#default_value' => isset($_GET['tipo_norma']) ? check_plain($_GET['tipo_norma']) : '',
      '#attached' => array(
        'js' => array(
          drupal_get_path('module', 'argentinagobar_formularios') . '/js/infoleg/unsetSancionEnTipoNormaLey.js',
        )
      ),
    );
  }

  protected function getFieldSancion()
  {
    return array(
      '#type' => 'textfield',
      '#title' => t('Año'),
      '#attributes' => array(
        'name' => 'sancion',
      ),
      '#prefix' => '<div class="col-md-2">',
      '#suffix' => '</div>',
      '#states' => array(
        'disabled' => array(
          ':input[name="tipo_norma"]' => array('value' => 'leyes')
        ),
      ),
      '#default_value' => isset($_GET['sancion']) ? check_plain($_GET['sancion']) : '',
      '#maxlength' => 4,
      '#rules' => array('numeric', 'length[4]',array(
        'rule' => "digit",
        'error' => t('No se pueden ingresar numeros negativos en %field'),
      )),
    );
  }

  abstract function validParams();

  function isValidParam($param)
  {
    return in_array($param, $this->validParams());
  }

  function get_params()
  {

    if(!empty($this->values['tipo_norma']) && $this->values['tipo_norma'] == 'ley') {

      unset($this->values['sancion']);

    }

    if(!empty($this->values['texto'])) {

      $this->values['texto'] = filter_var(htmlspecialchars_decode($this->values['texto'], ENT_QUOTES), FILTER_SANITIZE_STRING, FILTER_FLAG_NO_ENCODE_QUOTES);

    }

    if(!isset($this->values['limit'])) {

      $this->values['limit'] = 50;

    }

    if(!isset($this->values['offset'])) {

      $this->values['offset'] = 1;

    }

    return $this->values;
  }

  function get_request_url()
  {
    $endpoint = $this->get_endpoint();

    if(is_null($endpoint) || $enpoint = '') {
      throw new EndpointNuloException("Falta endpoint para Consulta", 1);
    }

    $params = $this->values;

    $tipoNorma = isset($params['tipo_norma']) ? $params['tipo_norma'] : 'legislaciones';
    $tipoNorma = isset($params['tipo_norma']) &&  $params['tipo_norma'] == 'Ley'? 'leyes' : $params['tipo_norma'];

    unset($params['tipo_norma']);
    unset($params['jurisdiccion']);

    return $endpoint. "/". $tipoNorma . '?' . http_build_query($params);
  }

  function get_response($request)
  {
    $data = null;

    if ($request->code == 401) {
      $this->api_gateway_auth->refresh_token();
      $this->consultar();
    }

    if ($request->code == 200) {
      $data = drupal_json_decode($request->data);

      $items = array();

      foreach ($data['results'] as $norma) {

        static::crearNorma($norma);

        $items[] = $norma;
      }

      $data['results'] = $items;
    }
    return $data;
  }

  static public function crearNorma(&$norma) {

    if(! empty($norma)) {

      static::setNormaURL($norma);
      static::setNormaTitulo($norma);
      static::setNormaBreadcrumb($norma);
      static::setComplementarias($norma);
      static::setJurisdiccion($norma);

    }

  }

  protected static function getJurisdiccion() {

    $q = drupal_get_query_parameters();

    return array_key_exists("jurisdiccion", $q) ? $q['jurisdiccion'] : 'nacional';

  }

  function get_endpoint()
  {

    $variable = $this::getJurisdiccion() == 'nacional' ? 'consulta_infoleg_endpoint' : 'consulta_infoleg_provinciales_endpoint';

    return variable_get($variable, null);

  }

  function handleError($request)
  {
    if($request->code == 409) {

      $data = drupal_json_decode($request->data);

      throw new ConsultaInfolegException($request->error, $data['userMessage'], $data['errorCode']);
    }

    parent::handleError($request);
  }

  function renderResponse($form, &$form_state, $data)
  {
    if (isset($data['results']) && count($data['results']) > 0) {

      $cantidad = $data['metadata']['resultset']['count'];

      $response = theme('listado_infoleg', array(
          'items' => $data['results'],
          'cantidad' => $cantidad,
          'paginas' => ceil($cantidad / $this->getItemsPerPage()),
          'offset' => $data['metadata']['resultset']['offset'],
        )
      );

    } else {
      $response = theme('infoleg_no_se_encontro_norma');
    }

    return $response;
  }

  function getTiposNormas()
  {

    $cid = 'infoleg_tipos_normas_' . $this::getJurisdiccion();
    $cache = cache_get($cid);

    if (false) {

      $tiposNorma = $cache->data;

    } else {

      $tiposNorma = array();

      foreach ($this->consultaTipoNorma->consultar() as $tipoNorma) {

        $tiposNorma[$tipoNorma['route']] = $tipoNorma['detalle'];

      }

      cache_set($cid, $tiposNorma);
    }

    return $tiposNorma;
  }

  function getTiposNormasProvinciales()
  {
    $cid = 'infoleg_tipos_normas_provinciales';
    $cache = cache_get($cid);

    if (false) {

      $tiposNorma = $cache->data;

    } else {

      $tiposNorma = array();

      foreach ($this->consultaTipoNormaProvincial->consultar() as $tipoNorma) {

        $tiposNorma[$tipoNorma['route']] = $tipoNorma['detalle'];

      }

      cache_set($cid, $tiposNorma);
    }

    return $tiposNorma;
  }

  function getProvincias()
  {

    $cid = 'infoleg_provincias';
    $cache = cache_get($cid);

    if ($cache) {

      $items = $cache->data;

    } else {

      $items = [];


      foreach ($this->consultaProvincias->consultar() as $key => $value) {

        $items[$value] = $value;

      }

      cache_set($cid, $items);
    }

    return $items;

  }

  function getDependencias()
  {
    $cid = 'infoleg_dependencias';
    $cache = cache_get($cid);

    if ($cache) {
      $dependencias = $cache->data;
    } else {

      $consultaDependencias = new ConsultaDependencias(ApiGatewayAuth::getInstance());

      $dependencias = array();

      foreach ($consultaDependencias->consultar() as $key => $value) {
        $dependencias[$value] = $value;
      }

      cache_set($cid, $dependencias);
    }
    return $dependencias;
  }


  function getYears() {
    $years = array();
    $starting_year = 1900;
    $ending_year = (int) date("Y");

    for($starting_year; $starting_year <= $ending_year; $starting_year++) {
      $years[$starting_year] = $starting_year;
    }

      return $years;
  }

  static function setNormaURL(&$norma)
  {

    // Minúsculas y reemplaza espacios con guiones bajos
    $normaTipo = strtolower(str_replace([" ", "/"],"_", $norma['tipoNorma']));
    $normaNumero = $norma['idNormas'][0]['numero'];
    $normaSancion = date('Y', strtotime($norma['sancion']));
    $normaID = $norma['id'];

    $norma['url'] = '/normativa';

    $norma['url'] .= isset($norma['jurisdiccion']) && $norma['jurisdiccion'] == 'Local' ? '/provincial' : '/nacional';

    $norma['url'] .= '/' . $normaTipo . '-' . $normaNumero;

    $norma['url'] .= $norma['tipoNorma'] == "Ley" || $norma['tipoNorma'] == "Decreto Ley" ? '-' . $normaID  : '-' . $normaSancion . '-' . $normaID;

  }

  static function setJurisdiccion(&$norma) {

    if(isset($norma['jurisdiccion'])) {

      switch ($norma['jurisdiccion']) {

        case 'Local':

          $norma['jurisdiccion'] = 'provincial';
          break;

        case 'Nacional':

          $norma['jurisdiccion'] = 'nacional';
          break;

        default:
          $norma['jurisdiccion'] = 'nacional';
          break;
      }

    }

  }

  static function setNormaBreadcrumb(&$norma)
  {

      $claseNorma = isset($norma['claseNorma']) ? $norma['claseNorma'] : null;
      $norma['breadcrumb']['titulo'] = $norma['tipoNorma'] . ' ' .$claseNorma. ' ' . $norma['idNormas'][0]['numero'] .'/' . date('Y', strtotime($norma['sancion']));
      $norma['breadcrumb']['url'] = $norma['url'];

  }

  static function setNormaTitulo(&$norma)
  {
    $claseNorma = isset($norma['claseNorma']) ? $norma['claseNorma'] : "";
    foreach ($norma['idNormas'] as $i =>$conjunta) {
      $titulo = $norma['tipoNorma'] . ' ' . $claseNorma . ' ' . $norma['idNormas'][$i]['numero'];

      if ($norma['tipoNorma'] != "Ley") {
        $titulo = $titulo . ' / ' . date('Y', strtotime($norma['sancion']));
      }

      $norma['idNormas'][$i]['titulo'] = $titulo;
    }

  }

  static function extraerID($path)
  {

    $id = explode('-', $path);

    /**
     * El id de las normas provinciales son por ej: 123456789-0abc-defg-590-0100fvorpyel
     * Para identificarlos
     */
    if(sizeof($id) > 4) {

      unset($id[1], $id[0]);

      $id = [implode('-', $id)];

    }

    return end($id);

  }

  static function flatNormasComplementarias($carry, $normas)
  {

    if(is_array($normas)) {

      foreach ($normas as $norma) {

        if(isset($norma['ref'])) {

          $carry[] = mb_substr($norma['ref'], 0, 23);

          }

      }

    } else {

      $carry[] = $normas;

    }

    return $carry;

  }

  static function setComplementarias(&$norma)
  {

    // #Normas para el listado
    // $norma['listaNormasQueComplementaCompleta'] = $norma['listaNormasQueComplementa'];
    // $norma['listaNormasQueLaComplementanCompleta'] = $norma['listaNormasQueLaComplementan'];

    #Normas para el listado
    $norma['listaNormasQueComplementaCompleta'] = isset($norma['listaNormasQueComplementa']) ? $norma['listaNormasQueComplementa'] : null;
    $norma['listaNormasQueLaComplementanCompleta'] = isset($norma['listaNormasQueLaComplementan']) ? $norma['listaNormasQueLaComplementan'] : null;

    #normas para el contador
    //$norma['listaNormasQueComplementaCount'] =  array_unique(array_reduce(array_values($norma['listaNormasQueComplementa']), array('ConsultaInfoleg', 'flatNormasComplementarias'), array()));
    //$norma['listaNormasQueLaComplementanCount'] =  array_unique(array_reduce(array_values($norma['listaNormasQueLaComplementan']), array('ConsultaInfoleg', 'flatNormasComplementarias'), array()));

    #normas para el contador
    $norma['listaNormasQueComplementaCount'] =  isset($norma['listaNormasQueComplementa']) ? array_unique(array_reduce(array_values($norma['listaNormasQueComplementa']), array('ConsultaInfoleg', 'flatNormasComplementarias'), array())) : null;
    $norma['listaNormasQueLaComplementanCount'] = isset($norma['listaNormasQueLaComplementan']) ? array_unique(array_reduce(array_values($norma['listaNormasQueLaComplementan']), array('ConsultaInfoleg', 'flatNormasComplementarias'), array())): null;

  }

  function parametrosValidos($v, $k)
  {
    return in_array($k, [
        'sancion',
        'tipo_norma',
        'numero',
        'limit',
        'offset',
        'jurisdiccion',
        'provincia'
      ]) && $v != null;
  }

  function filtrarParametros($parametros) {

    // Retorna parámetros permitidos y no nulos

    return array_filter(array_filter($parametros, [$this, 'isValidParam'], ARRAY_FILTER_USE_KEY));

  }

}
