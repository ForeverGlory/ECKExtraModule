<?php

$plugin = array(
  'label' => "User",
  'entity_view' => 'eck_user_property_entity_view',
  'entity_info' => 'eck_user_property_entity_info',
  'default_widget' => 'eck_user_property_widget',
  'default_formatter' => 'eck_user_property_formatter',
);

/**
 */
function eck_user_property_widget($property, $vars) {
  $entity = $vars['entity'];
  return array(
    '#type' => 'textfield',
    '#title' => $vars['properties'][$property]['label'],
    '#default_value' => isset($entity->$property) ? $entity->$property : '',
    '#required' => TRUE,
  );
}

/**
 */
function eck_user_property_formatter($property, $vars) {
  $entity = $vars['entity'];
  return array('#markup' => isset($entity->$property) ? '<div class="field field-name-' . $property . ' field-type-user">' . $entity->$property . '</div>' : '');
}

/**
 */
function eck_user_property_entity_view($property, $vars) {
  $entity = $vars['entity'];
}

/**
 * Make whatever property is using the title behavior, the label.
 */
function eck_user_property_entity_info($property, $var) {
  $info = $var;

  return $info;
}
