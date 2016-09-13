<?php

$plugin = array(
  'label' => "Textfield",
  'default_widget' => 'eck_textfield_property_widget',
  'entity_view' => 'eck_textfield_property_entity_view',
  'entity_info' => 'eck_textfield_property_entity_info',
  'default_formatter' => 'eck_textfield_property_formatter',
);

/**
 * How to input a textfield.
 */
function eck_textfield_property_widget($property, $vars) {
  $entity = $vars['entity'];
  return array(
    '#type' => 'textfield',
    '#title' => $vars['properties'][$property]['label'],
    '#default_value' => isset($entity->$property) ? $entity->$property : '',
    //'#required' => TRUE,
  );
}

/**
 * When we are viewing the entity.
 */
function eck_textfield_property_entity_view($property, $vars) {
  $entity = $vars['entity'];
}

/**
 * Make whatever property is using the textfield behavior, the label.
 */
function eck_textfield_property_entity_info($property, $var) {
  $info = $var;

  return $info;
}

/**
 * Display the title as an h1.
 */
function eck_textfield_property_formatter($property, $vars) {
  $entity = $vars['entity'];
  return array('#markup' => isset($entity->$property) ? '<div class="field field-name-' . $property . ' field-type-text">' . $entity->$property . '</div>' : '');
}