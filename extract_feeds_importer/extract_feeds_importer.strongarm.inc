<?php

/**
 * Implementation of hook_strongarm().
 */
function extract_feeds_importer_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'error_level';
  $strongarm->value = '1';

  $export['error_level'] = $strongarm;
  return $export;
}
