<?php
function argentinagobar_migtram_init(){
    MigrateGroup::deregister('Noticias');
    MigrateGroup::deregister('TramiteViejo');
    MigrateGroup::deregister('TramiteTema');
}

function argentinagobar_migtram_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'noticias' => array(
        'title' => t('Noticias'),
      ),
    ),
  );
  return $api;
}

class Noticias extends Migration{
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Importar noticias');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'id' => array('type' => 'int',
                        'length' => 255,
                        'not null' => TRUE,
                        'description' => 'Title',
                        )),
        MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceCSV($arguments['source_file'], array(), array('header_rows' => TRUE));

    $this->destination = new MigrateDestinationNode('noticia');
    $body_arguments = MigrateTextFieldHandler::arguments(NULL, filter_default_format(), NULL);
    
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'summary');
    $this->addFieldMapping('body:format', 'format')->defaultValue('full_html');

  }

  public function prepare($entity, $row) {

    if(!empty($row->body)){
      $body = '';
      $paragraph = explode('  ', $row->body);
      foreach ($paragraph as $key => $value){
        $body .= '<p>'.$value.'</p>';
      }
      $entity->body['und'][0]['value'] = $body;
    }

    // ACCIONES MANIPULAR FIELD COLLECTION
    if (!empty($row->acciones)){
      preg_match_all("/\[(.*?)\]/", $row->acciones, $matches);
      foreach($matches[1] as $key => $value){
        $items = explode(';;', $value);
        // Crea una field collection programáticamente
        $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_acciones'));
        // Aprovecha esta función que ya tiene el enity formado
        $field_collection_item->setHostEntity('node', $entity);
        $field_collection_item->field_accion['und'][0]['value'] = $items[0];
        $field_collection_item->field_url['und'][0]['url'] = $items[1];
        $field_collection_item->field_detalle['und'][0]['value'] = $items[2];
        $field_collection_item->save();
        // Se guarda el id del item de field collection
        $entity->field_acciones['und'][$key]['value'] = $field_collection_item->item_id;
      }
    }

    // IMAGENES REFERENCIADAS EN PUBLIC DE DRUPAL
    if (!empty($row->imagenes) && $row->imagenes != 'NULL'){
      global $base_url;
      $entity->body['und'][0]['value'] = '<p><img src="'.$base_url.'/sites/default/files/NoticiasTrabajo/'.$row->imagenes.'"></p>'.$entity->body['und'][0]['value'];
    } else {
      $entity->body['und'][0]['value'] = $entity->body['und'][0]['value'];
    }

    // FECHA EN FORMATO ESPAÑOL
    if (!empty($row->fecha)){
      $fecha = explode('/', $row->fecha);
      $entity->created = strtotime($row->fecha);
    }

    if (!empty($row->body)){
      $entity->field_featured_image['und'][0] = array('fid' => variable_get('imagen_migracion_noticias'));
      $entity->og_group_ref['und'][0]['target_id'] = 3679;
    }

  }
}