<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function extract_feeds_importer_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'copac';
  $feeds_importer->config = array(
    'name' => 'Copac',
    'description' => 'Import node from Copac',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(),
        'rawXML' => array(),
        'context' => '',
        'exp' => array(
          'errors' => FALSE,
          'tidy' => FALSE,
          'debug' => array(),
          'tidy_encoding' => 'UTF8',
        ),
        'allow_override' => TRUE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsSelfNodeProcessor',
      'config' => array(
        'content_type' => 'extract',
        'input_format' => 0,
        'update_existing' => 0,
        'expire' => -1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_pubtitle',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'authorize' => 0,
      ),
    ),
    'content_type' => 'extract',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['copac'] = $feeds_importer;
  return $export;
}
