<?php


function bookingsapi_rules_condition_resource_form($settings, &$form) {
  $form['settings']['resources'] = array(
    '#type'  => 'select',
    '#title' => t('Affected resources'),
    '#options' => bookingsapi_resource_minimal_list(),
    '#multiple' => TRUE,
    '#default_value' => isset($settings['resources']) ? $settings['resources'] : array(),
    '#required' => TRUE,
  );
}

function bookingsapi_rules_condition_status_unchanged_form($settings, &$form) {
  bookingsapi_rules_condition_status_form($settings,$form);
}

function bookingsapi_rules_condition_status_changed_form($settings,&$form) {
  bookingsapi_rules_condition_status_form($settings,$form);
}

function bookingsapi_rules_condition_status_form($settings, &$form) {
  $form['settings']['status'] = array(
    '#type'  => 'select',
    '#title' => t('Searched status'),
    '#options' => bookingsapi_record_status(),
    '#multiple' => TRUE,
    '#default_value' => isset($settings['status']) ? $settings['status'] : array(),
    '#required' => TRUE,
  );
}

function bookingsapi_rules_condition_priority_form($settings, &$form) {
  $form['settings']['priority'] = array(
    '#type'  => 'select',
    '#title' => t('Searched priority'),
    '#options' => bookingsapi_booking_priorities(),
    '#multiple' => TRUE,
    '#default_value' => isset($settings['priority']) ? $settings['priority'] : array(),
    '#required' => TRUE,
  );
}
