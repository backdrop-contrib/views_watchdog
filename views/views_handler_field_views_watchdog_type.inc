<?php

/**
 * @file
 * Definition of views_handler_field_views_watchdog_type.
 */


/**
 * Field handler to display the type of a log entry.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_watchdog_type extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();

    $options['alter']['contains']['make_class_name'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['alter']['make_link']['#states'] = array(
      'visible' => array(
        ':input[name="options[alter][make_class_name]"]' => array('checked' => FALSE),
      ),
    );
    $form['alter']['make_class_name'] = array(
      '#type' => 'checkbox',
      '#title' => t('Output this field as a CSS class'),
      '#description' => t('If checked, this field will be made into a CSS class name. Space characters will be replaced with dashes.'),
      '#default_value' => $this->options['alter']['make_class_name'],
      '#states' => array(
        'visible' => array(
          ':input[name="options[alter][make_link]"]' => array('checked' => FALSE),
        ),
      ),
    );
  }

  function render($values) {
    $value = $this->get_value($values);

    if (!empty($this->options['alter']['make_class_name'])) {
      $value = str_replace(' ', '-', $value);
    }

    return $this->sanitize_value($value);
  }
}
