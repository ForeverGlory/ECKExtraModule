<?php

/**
 */
$plugin = array(
  'label' => "Select",
  //'default_widget' => 'eck_select_property_widget',
  'entity_view' => 'eck_select_property_entity_view',
  'entity_info' => 'eck_select_property_entity_info',
  'default_formatter' => 'eck_select_property_formatter',
);

/**
 * How to select.
 */
function eck_select_property_widget($property, $vars) {
  $entity = $vars['entity'];
  $options = array();
  //black code
  //$options = array('male' => '男', 'female' => '女');
  return isset($options) ? array(
    '#type' => 'select',
    '#title' => $vars['properties'][$property]['label'],
    '#default_value' => isset($entity->$property) ? $entity->$property : 0,
    '#options' => $options,
          ) : array();
}

/**
 * Display the title as an h1.
 */
function eck_select_property_formatter($property, $vars) {
  $entity = $vars['entity'];
  return array('#markup' => isset($entity->$property) ? '<div class="field field-name-' . $property . ' field-type-select">' . $entity->$property . '</div>' : '');
}

/**
 * When we are viewing the entity, set the pages title.
 */
function eck_select_property_entity_view($property, $vars) {
  $entity = $vars['entity'];
}

/**
 * Make whatever property is using the title behavior, the label.
 */
function eck_select_property_entity_info($property, $var) {
  $info = $var;

  return $info;
}
