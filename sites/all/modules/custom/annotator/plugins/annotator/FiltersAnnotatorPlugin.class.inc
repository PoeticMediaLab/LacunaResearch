<?php

/*
  Tell Drupal about our Annotation Filters
  Generate settings to pass in
  Include necessary CSS and JS files

  Mike Widner <mikewidner@stanford.edu>
 */

class FiltersAnnotatorPlugin extends AnnotatorPlugin {
  public function settings($defaults = array()) {
    global $user;
    $default = array();
    $default['current_user'] = format_username($user); // current logged in user
    $default['filters'] = array('tags', 'category', 'user');
    return parent::settings($default);
  }

  public function setup() {
    global $user;
    $settings = $this->settings();
    // TODO: check for existing Filters block
    // If not present, create it? (or maybe too many hits every time?)
    drupal_add_js(array('annotator_filters' => (array) $settings), 'setting');
    drupal_add_library('system', 'ui.autocomplete', TRUE);
    drupal_add_css('//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css', $type='external');
    $filter_rids = variable_get('annotator_filters'); // Set in the admin form
    $user_rids = array_keys($user->roles);
    if (count(array_intersect($filter_rids, $user_rids)) == 0) {
      return; // No access, don't enable
    }
    drupal_add_js(drupal_get_path('module', 'annotator') . '/js/annotator_filters.js');
    drupal_add_js(drupal_get_path('module', 'annotator') . '/js/filters.js');
  }
}
