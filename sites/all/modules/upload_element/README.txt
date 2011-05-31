// $Id: README.txt,v 1.1.2.2 2008/11/22 04:51:59 aland Exp $

This module provides two new form elements to assist with files that are stored/updated in Drupal's {files} table.

This module was programmed by Alan Davison @ www.caignwebs.com.au


Dependencies
------------
 * none
 
Optimal integration
-------------------
 * Image Cache (http://drupal.org/project/imagecache)
   This module allows integration with Image Cache when saving
   uploaded files.

Install
-------
Installing the Upload Element module is simple:

1) Copy the upload_element folder to the modules folder in your installation.

2) Enable the module using Administer -> Modules (/admin/build/modules)

Configuration for Upload Element
-------------------------------

No configuration is required.

Contributing
------------
All comments and patches welcome. Just visit the issue queue.

Support
-------
If you experience a problem with upload element or have a problem, file a
request or issue on the upload element queue at
http://drupal.org/project/issues/upload_element.

DO NOT POST IN THE FORUMS.

Posting in the issue queues is a direct line of communication with the module authors.

Usage
-----
The base usage can be as simple as:

## To add the element to the form
  $form['image'] = array(
    '#type' => 'image_upload_element',
    '#title' => t('Image'),
    '#default_value' => $node->image, // {files} object
  );

## And to handle the submission

  // in hook_insert or somewhere
  // $node->image is a {files} object
  // If you handle this yourself, make sure that you check
  // the property submit_action to see if the object has
  // been flagged as deleted.
  $image_id = 0;
  if($node->image) {
    $image_id = upload_element_save($node->image, 'dest/directory', FILE_EXISTS_RENAME, 'imagecache_preset');
  }


Configurable settings
---------------------

1) File validators

  These are passed to file_save_upload during "hook_value", form_type_upload_element_value.
  
  The image upload element has 'file_validate_is_image' automatically added.
  
  Both elements get 'file_validate_size' added for theming purposes. This can be overridden
  with a custom theme_upload_element_file_description($element).
  
  This is adjusted to file_upload_max_size() if this is lower than the user defined size.
  
  Even if set to file_upload_max_size(), PHP will drop the file or the entire form submission
  if the upload size is exceeded, so these do not get passed to "hook_value".
  
  While the text must be changed with a custom theme, the message seperator can be set using
  '#file_validator_seperator'. This is defaulted to '<br />'

2) Images

  There are two main settings of interest.
  
  i) Image preview size
  
    This can be used to change the image thumb on the form.
  
    Eg: '#image_preview_size' => '100x100',

  ii) Image preview default image
  
    This replaces the simple "no image" image.
  
    Eg: '#image_preview_default_image' => drupal_get_path('module', 'cw') .'/no_image2.GIF',
  
3) Themes

  There are a number of possible theming functions:
  
  i) Element theming functions
  
    Takes full control of the element theming.
    
    Note that theme_image_upload_element simply calls theme_upload_element
    
  ii) Theming the filename preview
  
    The theme_upload_element_preview themes the filename.
    
    To override just a one off element, pass the theme function name as a '#file_formatter'
    
  iii) Theming the image preview
  
    Override theme_upload_element_image_preview

    To override just a one off element, pass the theme function name as a '#image_formatter'

  iv) Theming the description under the file input control.
  
    Override theme_upload_element_file_description

##############################################################################################################
######   The demo version that is running @ http://www.caignwebs.com.au/contributions/node/2            ######
##############################################################################################################

Adding an image and a file to a node
------------------------------------

1) Create a new module info file: "cw.info"

--------------------------------------------------------------------------------------------------------------
name = Upload example demo
description = A module to demo/test the upload field.
package = Other
core = 6.x
--------------------------------------------------------------------------------------------------------------

2) Create an install file to create a new table to store the information: "cw.install"

--------------------------------------------------------------------------------------------------------------
<?php

function cw_schema() {
  $t = get_t();
  
  // fid1, fid3 are images
  // fid2, fid4 are files
  $schema['cw_node_images'] = array(
    'description' => $t('Additional upload element example fields.'),
    'fields' => array(
      'nid'             => array('type' => 'int',   'unsigned' => TRUE, 'not null' => TRUE, 'default' => 0,  'description' => $t('Primary Key: The {node}.nid of the node.')),
      'fid1'            => array('type' => 'int',   'unsigned' => TRUE, 'not null' => TRUE, 'default' => 0,  'description' => $t('Index: The {files}.fid of the image file.')),
      'fid2'            => array('type' => 'int',   'unsigned' => TRUE, 'not null' => TRUE, 'default' => 0,  'description' => $t('Index: The {files}.fid of the file.')),
      'fid3'            => array('type' => 'int',   'unsigned' => TRUE, 'not null' => TRUE, 'default' => 0,  'description' => $t('Index: The {files}.fid of the image file.')),
      'fid3_alt'        => array('type' => 'varchar', 'length' => 255, 'not null' => TRUE, 'default' => '',  'description' => $t('Custom ALT attribute of the image.')),
      'fid3_title'      => array('type' => 'varchar', 'length' => 255, 'not null' => TRUE, 'default' => '',  'description' => $t('Custom TITLE attribute of the image.')), 
      'fid3_copyright'  => array('type' => 'varchar', 'length' => 255, 'not null' => TRUE, 'default' => '',  'description' => $t('Copyright details of the image.')),
      'fid4'            => array('type' => 'int',   'unsigned' => TRUE, 'not null' => TRUE, 'default' => 0,  'description' => $t('Index: The {files}.fid of the file.')),
      'fid4_title'      => array('type' => 'varchar', 'length' => 255, 'not null' => TRUE, 'default' => '',  'description' => $t('Custom TITLE of the file.')), 
    ),
    'primary key' => array('nid'),
  );
  return $schema;
}

/**
 * Implementation of hook_install().
 */
function cw_install() {
  drupal_install_schema('cw');
}

/**
 * Implementation of hook_uninstall().
 */
function cw_uninstall() {
  drupal_uninstall_schema('cw');
}

--------------------------------------------------------------------------------------------------------------

3) Create the hooks required to hook into a node form: "cw.module"

In this example, we are using a custom 'upload_element_example' content type as the type to add the two fields to.

 a) Using hook_form_alter to add the new fields to the node edit form
 b) Using hook_nodeapi op save to save the data
 c) Also using the hook_nodeapi ops load and view to present the files
 
The example shows how to add new elements into the upload element.
 
--------------------------------------------------------------------------------------------------------------
<?php

/**
 * Implementation of hook_form_alter().
 */
function cw_form_alter(&$form, $form_state, $form_id) {
  // Only do this for node forms
  if (isset($form['#id']) && ($form['#id'] == 'node-form') && arg(0) == 'node') {
    $node = $form['#node'];
    if ($node->type == 'upload_element_example') {
      $form['#attributes'] = array("enctype" => "multipart/form-data");
      $form['fid2'] = array(
        '#type' => 'upload_element',
        '#title' => t('File 1'),
        '#required' => FALSE,
        '#default_value' => $node->fid2,
        '#file_validators' => array('file_validate_size' => array(32768)),
      );
      $form['fid4'] = array(
        '#type' => 'upload_element',
        '#title' => t('File 2'),
        '#required' => FALSE,
        '#default_value' => $node->fid4,
        '#file_validators' => array(
          'file_validate_size' => array(16384),
          'file_validate_extensions' => array('txt gif patch diff jpg jpeg'),
        ),
      );
      $form['fid4']['fid4_info'] = array(
        '#type' => 'markup',
        '#value' => '<div id="edit-fid4-info" class="form-item"><label>Element info: </label><div>This info box and the title field below are child elements added to the upload_element. Two file validators have also been added, size and extension validation.</div></div>',
      );
      $form['fid4']['fid4_title'] = array(
        '#type' => 'textfield',
        '#title' => 'Title',
        '#description' => 'Extra fields can be added as simply as defining them as child elements.',
        '#default_value' => $node->fid4_title,
      );
      $form['fid1'] = array(
        '#type' => 'image_upload_element',
        '#title' => t('Image 1'),
        '#description' => 'Upload an image to demonstrate the usage of the image_upload_field.',
        '#required' => TRUE,
        '#default_value' => $node->fid1,
        '#file_validators' => array('file_validate_size' => array(131072)),
      );
      $form['fid3'] = array(
        '#type' => 'image_upload_element',
        '#title' => t('Image 2'),
        '#description' => 'This example uses element settings to configure the preview size.',
        '#required' => FALSE,
        '#default_value' => $node->fid3,
        '#file_validators' => array('file_validate_size' => array(524288)),
        '#image_preview_size' => '150x150',
      );
      $form['fid3']['fid3_info'] = array(
        '#type' => 'markup',
        '#value' => '<div id="edit-fid4-info" class="form-item"><label>Element info: </label><div>This info box and the following three fields are child elements added to the image_upload_element. A file validators has been added, the image validator is automatically added. Using <i>#image_preview_size</i> we have changed the preview size to fit inside a 150 square box. Save has a distinctive imagecache filter applied to reduce the image size and to convert the image to greyscale.</div></div>',
      );
      $form['fid3']['fid3_alt'] = array(
        '#type' => 'textfield',
        '#title' => 'Alt',
        '#description' => 'Extra fields can be added as simply as defining them as child elements.',
        '#default_value' => $node->fid3_alt,
      );
      $form['fid3']['fid3_title'] = array(
        '#type' => 'textfield',
        '#title' => 'Title',
        '#description' => 'The title attribute of the image.',
        '#default_value' => $node->fid3_title,
      );
      $form['fid3']['fid3_copyright'] = array(
        '#type' => 'textfield',
        '#title' => 'Copyright details',
        '#description' => 'Another example field.',
        '#default_value' => $node->fid3_copyright,
      );
    }
  }
}

function cw_nodeapi(&$node, $op, $a3 = NULL, $a4 = NULL) {
  if ($node->type == 'upload_element_example') {
    switch ($op) {
      case 'load':
        _cw_load($node);
        break;
      case 'insert':
      case 'update':
        _cw_save($node);
        break;
      case 'view':
        $node->content['ue_files'] = array(
          '#value' => 
            '<h3>File 1:</h3><div>'. cw_file($node->fid2) .'</div>' .
            '<h3>File 2:</h3><div>'. cw_file($node->fid4, $node->fid4_title) .'</div>',
          '#weight' => 9,
        );
        $node->content['ue_images'] = array(
          '#value' => 
            '<h3>Image 1:</h3><div>'. cw_image($node->fid1) .'</div>'.
            '<h3>Image 2:</h3><div>'. cw_image($node->fid3, $node->fid3_alt, $node->fid3_title, $node->fid3_copyright) .'</div>',
          '#weight' => 10,
        );
        break;
    }
  }
}

function cw_image($image = FALSE, $alt = FALSE, $title = FALSE, $copy = FALSE) {
  if (is_object($image)) {
    return theme('imagecache', 'upload_element_preview', $image->filepath, $alt, $title) . '<br/><i>' . check_plain($copy) . '</li>';
  }
  return '--';
}

function cw_file($file = FALSE, $title = FALSE) {
  if ($file) {
    $element = array('#value' => $file);
    return '<strong>'. $title .'</strong>' . theme('upload_element_preview', $element);
  }
  return '--';
}

function _cw_load(&$node) {
  if(!$node->nid) return;
  $node->fid1 = FALSE;
  $node->fid2 = FALSE;
  $node->fid3 = FALSE;
  $node->fid4 = FALSE;
  $q1 = db_fetch_object(db_query("SELECT * FROM {cw_node_images} WHERE nid = %d", $node->nid));
  if ($q1) {
    $node->fid1 = ($q1->fid1) ? db_fetch_object(db_query("SELECT * FROM {files} WHERE fid = %d", $q1->fid1)) : FALSE;
    $node->fid2 = ($q1->fid2) ? db_fetch_object(db_query("SELECT * FROM {files} WHERE fid = %d", $q1->fid2)) : FALSE;
    $node->fid3 = ($q1->fid3) ? db_fetch_object(db_query("SELECT * FROM {files} WHERE fid = %d", $q1->fid3)) : FALSE;
    $node->fid4 = ($q1->fid4) ? db_fetch_object(db_query("SELECT * FROM {files} WHERE fid = %d", $q1->fid4)) : FALSE;
    foreach(array('fid3_alt', 'fid3_title', 'fid3_copyright', 'fid4_title') as $prop) {
      $node->$prop = $q1->$prop;
    }
  }
}

function _cw_save(&$node) {
  if(!$node->nid) return;
  

  $fid1 = $fid2 = $fid3 = $fid4 = 0;
  if(is_object($node->fid1)) {
    $fid1 = upload_element_save($node->fid1, 'upload_element', FILE_EXISTS_RENAME);
  }    
  if(is_object($node->fid2)) {
    $fid2 = upload_element_save($node->fid2, 'upload_element', FILE_EXISTS_RENAME);
  }    
  if(is_object($node->fid3)) {
    $fid3 = upload_element_save($node->fid3, 'upload_element', FILE_EXISTS_RENAME, 'upload_element_save_action');
  }    
  if(is_object($node->fid4)) {
    $fid4 = upload_element_save($node->fid4, 'upload_element', FILE_EXISTS_RENAME);
  }    
  db_query("
    INSERT INTO {cw_node_images} (nid, fid1, fid2, fid3, fid4, fid3_alt, fid3_title, fid3_copyright, fid4_title)
    VALUES (%d, %d, %d, %d, %d, '%s', '%s', '%s', '%s')
    ON duplicate KEY
    UPDATE fid1 = %d, fid2 = %d, fid3 = %d, fid4 = %d, fid3_alt = '%s', fid3_title = '%s', fid3_copyright = '%s', fid4_title = '%s'
    ", $node->nid, $fid1, $fid2, $fid3, $fid4, $node->fid3_alt, $node->fid3_title, $node->fid3_copyright, $node->fid4_title,
       $fid1, $fid2, $fid3, $fid4, $node->fid3_alt, $node->fid3_title, $node->fid3_copyright, $node->fid4_title);
}

--------------------------------------------------------------------------------------------------------------
