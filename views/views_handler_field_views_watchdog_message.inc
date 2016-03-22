<?php

/**
 * @file
 * Definition of views_handler_field_views_watchdog_message.
 */


/**
 * Field handler to display the message of a log entry.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_watchdog_message extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();

    $options['replace_variables'] = array('default' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['replace_variables'] = array(
      '#type' => 'checkbox',
      '#title' => t('Replace variables'),
      '#description' => t('If checked, the message will be displayed with replaced variables.'),
      '#default_value' => $this->options['replace_variables'],
    );
  }

  public function init(&$view, &$options) {
    parent::init($view, $options);

    if ($this->options['replace_variables']) {
      $this->additional_fields['variables'] = 'variables';
    }
  }

  function render($values) {
    $value = $values->{$this->field_alias};

    if ($this->options['replace_variables']) {

      $variables = $values->{$this->aliases['variables']};
      if ($variables === 'N;') {
        return $this->sanitize_value($value);
      }

      return t($value, unserialize($variables));
    }
    else {
      return $this->sanitize_value($value);
    }
  }
}
