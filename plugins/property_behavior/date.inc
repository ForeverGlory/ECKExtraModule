<?php

/**
 * @file
 */
$plugin = array(
  'label' => "Date",
  'default_widget' => 'eck_date_property_widget',
  'entity_info' => 'eck_date_property_entity_info',
  'entity_view' => 'eck_date_property_entity_view',
  'pre_set' => 'eck_date_property_pre_set',
  //'default_formatter' => 'eck_date_property_formatter',
);

function eck_date_property_widget($property, $vars) {
  $entity = $vars['entity'];
  return array(
    '#title' => $vars['properties'][$property]['label'],
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d',
    '#default_value' => !empty($entity->$property) ? date('Y-m-d', $entity->$property) : '',
  );
}

function eck_date_property_pre_set($property, $vars) {
  return !empty($vars['data']) ? strtotime($vars['data']) : 0;
}

function eck_date_property_formatter($property, $vars) {
  $entity = $vars['entity'];
  return array('#markup' => theme('field', array(
      'element' => array(
        '#label_display' => 'inline',
        '#title' => $vars['properties'][$property]['label'],
        '#items' => array(0),
        '#field_name' => $property,
        '#field_type' => 'textfield',
        '#bundle' => $entity->bundle,
        array('#markup' => date('Y-m-d', $entity->$property))
      )
  )));
}

/**
 * When we are viewing the entity, set the pages title.
 */
function eck_date_property_entity_view($property, $vars) {
  $entity = $vars['entity'];
}

/**
 * Make whatever property is using the title behavior, the label.
 */
function eck_date_property_entity_info($property, $var) {
  $info = $var;

  return $info;
}
