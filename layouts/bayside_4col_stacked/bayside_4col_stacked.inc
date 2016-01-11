<?php

/**
 * Implements hook_panels_layouts()
 */
function fin_bayside_4col_stacked_panels_layouts() {
  $items['bayside_4col_stacked'] = array(
    'title' => t('Bayside: stacked 4 column row'),
    'category' => t('Bayside'),
    'icon' => 'foundation_4col_stacked.png',
    'theme' => 'bayside_4col_stacked',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'top' => t('Top'),
      'secondary' => t('secondary'),
      'left' => t('Left'),
      'center-left' => t('Center Left'),
      'center-right' => t('Center Right'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

