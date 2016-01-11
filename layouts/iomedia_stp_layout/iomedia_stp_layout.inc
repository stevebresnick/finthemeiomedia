<?php

/**
 * Implements hook_panels_layouts()
 */
function fin_iomedia_stp_layout_panels_layouts() {
  $items['iomedia_stp_layout'] = array(
    'title' => t('IOMEDIA STP Layout 1'),
    'category' => t('IOMEDIA'),
    'icon' => 'iomedia_stp_layout.png',
    'theme' => 'iomedia_stp_layout',
    //'admin css' => '../foundation_panels_admin.css',
    'regions' => array(
      'top' => t('Top'),
      'secondary' => t('secondary'),
      'left' => t('First Block'),
      'center-left' => t('Second Block'),
      'center-right' => t('Third Block'),
      'right' => t('Fourth Block'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

