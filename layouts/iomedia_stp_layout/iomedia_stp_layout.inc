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
      'left' => t('Left'),
      'center-left' => t('Center Left'),
      'center-right' => t('Center Right'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ),
  );
  return $items;
}

