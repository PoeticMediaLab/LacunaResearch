<?php
/**
 * @file
 * research_study.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function research_study_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function research_study_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function research_study_flag_default_flags() {
  $flags = array();
  // Exported flag: "Demographic Survey Flag".
  $flags['demographic_survey_flag'] = array(
    'entity_type' => 'node',
    'title' => 'Demographic Survey Flag',
    'global' => 1,
    'types' => array(
      0 => 'webform',
    ),
    'flag_short' => 'Make this item the initial survey for this cohort',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item - remove it as the demographic survey',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'workflow_tab' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'research_study',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Post-reading Survey".
  $flags['post_reading_survey'] = array(
    'entity_type' => 'node',
    'title' => 'Post-reading Survey',
    'global' => 1,
    'types' => array(
      0 => 'webform',
    ),
    'flag_short' => 'Make this item the post-reading survey for the given cohort',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item - remove it as the post-reading survey',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'workflow_tab' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'research_study',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "User Has Completed Post-Reading Survey".
  $flags['user_has_completed_post_reading_'] = array(
    'entity_type' => 'user',
    'title' => 'User Has Completed Post-Reading Survey',
    'global' => 1,
    'types' => array(),
    'flag_short' => 'User has completed post-reading survey',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'User has not completed post-reading survey',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'research_study',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function research_study_node_info() {
  $items = array(
    'cohort_instructions' => array(
      'name' => t('Cohort Instructions'),
      'base' => 'node_content',
      'description' => t('Instructions that can be configured to display differently to different cohorts, participants, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This title will not be visible to participants, so you can name the instructions in a way that makes it clear which cohort they are intended for.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
