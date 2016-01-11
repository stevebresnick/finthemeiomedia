<?php

/**
 * Implements hook_panels_layouts()
 */
function fin_bayside_3col_stacked_panels_layouts() {
  $items['bayside_3col_stacked'] = array(
    'title' => t('Bayside: stacked 3 column row'),
    'category' => t('Bayside'),
    'icon' => 'foundation_3col_stacked.png',
    'theme' => 'bayside_3col_stacked',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'top' => t('Top'),
      'secondary' => t('secondary'),
      'left' => t('Left'),
      'center' => t('Center'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

