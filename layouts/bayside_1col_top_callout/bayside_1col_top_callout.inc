<?php

/**
 * Implements hook_panels_layouts()
 */
function fin_bayside_1col_top_callout_panels_layouts() {
  $items['bayside_1col_top_callout'] = array(
    'title' => t('Bayside: stacked 1 col with top callout'),
    'category' => t('Bayside'),
    'icon' => 'bayside_1col_top_callout.png',
    'theme' => 'bayside_1col_top_callout',
    'regions' => array(
      'top' => t('Top'),
      'main' => t('Main'),
      'left' => t('Left Callout'),
      'right' => t('Right Callout'),
      'secondary' => t('secondary'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

