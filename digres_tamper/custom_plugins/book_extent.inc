<?php

$plugin = array(
  'form' => 'digres_tamper_book_extent_form',
  'callback' => 'digres_tamper_book_extent_callback',
  'name' => 'Book extent',
);

function digres_tamper_book_extent_form($importer, $element_key, $settings) {
  $form = array();
  /*
   $form['length'] = array(
    '#type' => 'textfield',
    '#title' => t('Length'),
    '#description' => t('If the value of length is negative, less than, or equal to the length of the input string, no padding takes place.'),
    '#default_value' => isset($settings['length']) ? $settings['length'] : '',
    '#size' => 4,
    '#required' => TRUE,
  );
  $form['string'] = array(
    '#type' => 'textfield',
    '#title' => t('String'),
    '#size' => 10,
    '#description' => t('The string may be truncated if the required number of padding characters can\'t be evenly divided by the string\'s length.'),
    '#default_value' => isset($settings['string']) ? $settings['string'] : ' ',
  );*/
  $form['type'] = array(
    '#type' => 'radios',
    '#title' => t('Type'),
    '#options' => array('copac' => t('Copac'), 'marc' => t('Marc'), 'voyager' => t('Voyager')),
    '#default_value' => isset($settings['type']) ? $settings['type'] : STR_PAD_RIGHT,
  );
  return $form;
  
}

function digres_tamper_book_extent_callback($result, $item_key, $element_key, &$field, $settings) {
  $type = isset($settings['type']) ? $settings['type'] : 'copac';
  switch ($type) {
    case 'copac':
      //$regex = '([0-9]+)';
      $regex = '([a-zA-Z., :;-]+)';
      $numeric_values = preg_split($regex, $field);
      $field = $numeric_values[1];
      break;
  }
}
