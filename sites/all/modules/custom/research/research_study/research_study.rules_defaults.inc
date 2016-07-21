<?php
/**
 * @file
 * research_study.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function research_study_default_rules_configuration() {
  $items = array();
  $items['lacuna_stories_irb_form_send_user_to_study'] = entity_import('rules_config', '{ "lacuna_stories_irb_form_send_user_to_study" : {
      "LABEL" : "Send User to Study",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "NOT text_matches" : {
            "text" : [ "site:current-page:path" ],
            "match" : "^user\\/reset\\/",
            "operation" : "regex"
          }
        },
        { "flag_flagged_user" : {
            "flag" : "irb_form_completed",
            "user" : [ "account" ],
            "flagging_user" : [ "account" ]
          }
        },
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "8" : "8" } } } }
      ],
      "DO" : [
        { "redirect" : { "url" : "study-readings" } },
        { "drupal_message" : { "message" : "Thanks for resuming the study. You can continue where you left off with the reading below." } }
      ]
    }
  }');
  $items['rules_block_accounts_of_users_who_have_completed_survey'] = entity_import('rules_config', '{ "rules_block_accounts_of_users_who_have_completed_survey" : {
      "LABEL" : "Block Accounts of Users Who Have Completed Survey",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "user_logout" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "8" : "8" } } } },
        { "flag_flagged_user" : {
            "flag" : "user_has_completed_post_reading_",
            "user" : [ "account" ],
            "flagging_user" : [ "account" ]
          }
        }
      ],
      "DO" : [ { "user_block" : { "account" : [ "account" ] } } ]
    }
  }');
  $items['rules_flag_user_after_post_reading_survey'] = entity_import('rules_config', '{ "rules_flag_user_after_post_reading_survey" : {
      "LABEL" : "Flag User After Post-reading Survey",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "webform_rules" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "flag_flagged_node" : {
            "flag" : "post_reading_survey",
            "node" : [ "node" ],
            "flagging_user" : [ "user" ]
          }
        }
      ],
      "DO" : [
        { "flag_flaguser" : {
            "flag" : "user_has_completed_post_reading_",
            "user" : [ "user" ],
            "flagging_user" : [ "user" ],
            "permission_check" : "1"
          }
        }
      ]
    }
  }');
  $items['rules_prompt_user_to_logout'] = entity_import('rules_config', '{ "rules_prompt_user_to_logout" : {
      "LABEL" : "Prompt User to Logout",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "rules", "webform_rules" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "flag_flagged_node" : {
            "flag" : "post_reading_survey",
            "node" : [ "node" ],
            "flagging_user" : [ "user" ]
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Thank you for participating in our study. You may log out \\u003Ca href=\\u0022..\\/..\\/user\\/logout\\u0022\\u003EHere\\u003C\\/a\\u003E" } }
      ]
    }
  }');
  return $items;
}
