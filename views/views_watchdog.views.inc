<?php

/**
 * @file
 * Provide views data and handlers for the views_watchdog module.
 */


/**
 * Implements of hook_views_data().
 */
function views_watchdog_views_data() {

  $data['watchdog']['table']['group'] = t('Watchdog');
  $data['watchdog']['table']['base'] = array(
    'field' => 'wid',
    'title' => t('Log entries'),
    'help' => t('Contains a list of log entries.'),
  );

  $data['watchdog']['wid'] = array(
    'title' => t('WID'),
    'help' => t('Unique watchdog event ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'wid',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['uid'] = array(
    'title' => t('UID'),
    'help' => t('The user ID of the user on which the log entry was written.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'uid',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('User'),
      'help' => t('The user on which the log entry as written.'),
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
    ),
  );

  $data['watchdog']['type'] = array(
    'title' => t('Type'),
    'help' => t('The type of the log entry, for example "user" or "page not found".'),
    'field' => array(
      'handler' => 'views_handler_field_views_watchdog_type',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'views_watchdog_get_type_list',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'type',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['message'] = array(
    'title' => t('Message'),
    'help' => t('The actual message of the log entry.'),
    'field' => array(
      'handler' => 'views_handler_field_views_watchdog_message',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'message',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['variables'] = array(
    'title' => t('Variables'),
    'help' => t('The variables of the log entry in a serialized format.'),
    'field' => array(
      'handler' => 'views_handler_field_serialized',
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'variables',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['severity'] = array(
    'title' => t('Severity level'),
    'help' => t('The severity level of the event; ranges from 0 (Emergency) to 7 (Debug).'),
    'field' => array(
      'handler' => 'views_handler_field_views_watchdog_severity',
      'options callback' => 'views_watchdog_get_severity_list',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'views_watchdog_get_severity_list',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'severity',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['link'] = array(
    'title' => t('Operations'),
    'help' => t('Operation links for the event.'),
    'field' => array(
      'handler' => 'views_handler_field_xss',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'link',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['location'] = array(
    'title' => t('Location'),
    'help' => t('URL of the origin of the event.'),
    'field' => array(
      'handler' => 'views_handler_field_url',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'location',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['referer'] = array(
    'title' => t('Referer'),
    'help' => t('URL of the previous page.'),
    'field' => array(
      'handler' => 'views_handler_field_url',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'referer',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['hostname'] = array(
    'title' => t('Hostname'),
    'help' => t('Hostname of the user who triggered the event.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'hostname',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['watchdog']['timestamp'] = array(
    'title' => t('Timestamp'),
    'help' => t('Date when the event occurred.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'name field' => 'timestamp',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  return $data;
}
