<?php
/**
 * @file
 * vocabulary.tramites.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '2',
  'name' => 'Tipo de servicios',
  'machine_name' => 'tramites',
  'description' => '',
  'hierarchy' => '0',
  'module' => 'taxonomy',
  'weight' => '0',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'skos:ConceptScheme',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'description' => array(
      'predicates' => array(
        0 => 'rdfs:comment',
      ),
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'taxonomy',
);
