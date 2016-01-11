<?php

/**
 * Implements template_preprocess_html().
 */
function fin_preprocess_html(&$variables) {
}

/**
 * Implements template_preprocess_page.
 */
function fin_preprocess_page(&$variables) {
  if (!((module_exists('page_manager') && page_manager_get_current_page()))) {
    $variables['not_panels'] = 'row';
  }
}

/**
 * Implements template_preprocess_node.
 */
function fin_preprocess_node(&$variables) {
}


function fin_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['#form_id']) && ($form['#form_id'] == 'search_block_form')) {
    $form['search_block_form']['#prefix'] = '<div class="collapse">';
    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
    $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
    // Prevent user from searching the default text
    $form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";
    // Alternative (HTML5) placeholder attribute instead of using the javascript
    $form['search_block_form']['#attributes']['placeholder'] = t('Search');
    $form['actions']['submit']['#prefix'] = '<div class="">';
    $form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/search-button.png');
  }
}

/**
 * Implements theme_links() targeting the main menu topbar.
 */
function fin_links__topbar_main_menu($variables) {
  // We need to fetch the links ourselves because we need the entire tree.
  $links = menu_tree_output(menu_tree_all_data(variable_get('menu_main_links_source', 'main-menu')));
  $output = _zurb_foundation_links($links);
  $variables['attributes']['class'][] = 'right';

  return '<ul' . drupal_attributes($variables['attributes']) . '>' . $output . '</ul>';
}