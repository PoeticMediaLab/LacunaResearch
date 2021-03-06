<?php
/**
 * @file
 * course.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function course_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_course_image',
      ),
      'left' => array(
        1 => 'field_course_title',
        2 => 'field_name',
        3 => 'body',
      ),
      'right' => array(
        4 => 'field_start_date',
        5 => 'field_end_date',
      ),
    ),
    'fields' => array(
      'field_course_image' => 'header',
      'field_course_title' => 'left',
      'field_name' => 'left',
      'body' => 'left',
      'field_start_date' => 'right',
      'field_end_date' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|course|default'] = $ds_layout;

  return $export;
}
