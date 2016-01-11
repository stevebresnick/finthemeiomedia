<?php

/**
 * Implements hook_panels_layouts()
 */
function fin_bayside_2col_stacked_panels_layouts() {
  $items['bayside_2col_stacked'] = array(
    'title' => t('Bayside: stacked 2 column row'),
    'category' => t('Bayside'),
    'icon' => 'foundation_2col_stacked.png',
    'theme' => 'bayside_2col_stacked',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'top' => t('Top'),
      'secondary' => t('secondary'),
      'left' => t('Left'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

