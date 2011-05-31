<?php
// $Id: upload_element.pages.inc,v 1.1.2.3 2009/03/25 14:04:23 aland Exp $

/**
 * @file
 * Handles image previews from both temperary and perminant file directories.
 */

/**
 * Generates a temp image for image preview.
 *
 * This uses core Drupal image processing.
 */
function image_upload_element_thumb() {
  $GLOBALS['devel_shutdown'] = FALSE;
  list($form_build_id, $name, $fid) = func_get_args();
  // Load the element and pull out the defaults.
  $form_state = array('submitted' => FALSE);
  if($form = form_get_cache($form_build_id, $form_state)) {
    $form += array('#post' => array(), '#programmed' => TRUE);
    // calling form_builder would trigger the session to be cleared
    $element = locate_upload_element($form, $name);
    if ($element && $image = image_upload_element_preview_path($form_build_id, $name, $element['#image_preview_default_image'])) {
      $info = image_get_info($image->filepath);
      if ($info) {
        // create temp file, minimise conflicts by instant touch
        $tmp_file = file_destination(file_directory_temp() .'/upload_element_'. $fid .'.'. $info['extension'], FILE_EXISTS_RENAME);

        $width = 100;
        $height = 100;
        if ($element['#image_preview_size'] && preg_match('/^\d+x\d+$/', $element['#image_preview_size'])) {
          list($width, $height) = explode('x', $element['#image_preview_size'], 2);
        }

        if (!image_scale($image->filepath, $tmp_file, $width, $height)) {
          $tmp_file = $image->filepath;
        }
        $tmp_info = image_get_info($tmp_file);
        if ($tmp_info) {
          $headers = array(
            'Content-type: '. $tmp_info['mime_type'],
            'Content-Length: '. $tmp_info['file_size'],
            'Cache-Control: max-age=0, no-cache',
            'Expires: '. gmdate('D, d M Y H:i:s', time()) .' GMT',
            'Last-Modified: '. time(),
          );
          ob_end_clean();
          foreach ($headers as $header) {
            $header = preg_replace('/\r?\n(?!\t| )/', '', $header);
            drupal_set_header($header);
          }

          // Transfer file in 1024 byte chunks to save memory usage.
          if ($fd = fopen($tmp_file, 'rb')) {
            while (!feof($fd)) {
              print fread($fd, 1024);
            }
            fclose($fd);
          }
          else {
            watchdog('Upload element', 'Error generating the image thumbnail.', array(), WATCHDOG_ERROR);
          }
        }
        else {
          watchdog('Upload element', 'Error generating the image thumbnail.', array(), WATCHDOG_ERROR);
        }

        // We're using the original if it is too small - do not delete!
        if ($image->filepath != $tmp_file) {
          @unlink($tmp_file);
        }
      }
      else {
        watchdog('Upload element', 'No image information could be parsed from the upload.', array(), WATCHDOG_ERROR);
      }
    }
    else {
      watchdog('Upload element', 'No preview path was created.', array(), WATCHDOG_ERROR);
    }
  }
  else {
    watchdog('Upload element', 'Form element was not found. This form may not be compatible with this module.', array(), WATCHDOG_ERROR);
  }
  if (!headers_sent()) {
    drupal_set_header('HTTP/1.1 404 Not Found');
  }
  exit;
}

/**
 * This parses the session to pull out the filepath of the image.
 *
 * @param string $form_build_id The build id of the current form.
 * @param string $name The key of the element.
 * @param string $default A default image path to override the modules default image.
 * @return object A file object, though the only property may be the filepath.
 */
function image_upload_element_preview_path($form_build_id, $name, $default = FALSE) {
  if (is_array($_SESSION['files']['upload_element'][$form_build_id])) {
    $files = $_SESSION['files']['upload_element'][$form_build_id];
    $file = (isset($files[$name]) && is_object($files[$name])) ? $files[$name] : $files[$name . '_default'];
    if (is_object($file)) {
      if (!(isset($file->submit_action) && $file->submit_action == UPLOAD_ELEMENT_DELETE)) {
        return $file;
      }
    }
  }
  // This allows you to overwrite the default image
  $image= new stdClass();
  if ($default && image_get_info($default)) {
    $image->filepath = $default;
  }
  else {
    $image->filepath = drupal_get_path('module', 'upload_element') .'/no_image.gif';
  }
  return $image;
}

/**
 * Handles the AHAH upload request.
 *
 * @param string $name The elements name.
 */
function upload_element_js($form_build_id, $form_id, $name) {
  $GLOBALS['devel_shutdown'] = FALSE;
  $form_state = array('submitted' => FALSE);
  if ($form = form_get_cache($form_build_id, $form_state)) {
    $form += array('#post' => $_POST);
    if ($element = locate_upload_element($form, $name, array('#is_ahah' => TRUE))) {
      $form = form_builder($form_id, $form, $form_state);
      $element = locate_upload_element($form, $name);
      // The only way to detect if the max post size was exceeded is to check the $_POST
      if (empty($_POST)) {
        form_set_error($name, t("The file %file could not be saved, because it exceeds this form's size limit %size for file uploads.", array('%file' => $_FILES['files']['name'][$name], '%size' => format_size(file_upload_max_size()))), 'error');
      }
      $element['#messages'] = theme('status_messages');
      $output = drupal_render($element);
      print drupal_to_js(array('data' => $output));
      exit();
    }
  }

  form_set_error('form_token', t('Validation error, please try again. If this error persists, please contact the site administrator.'));
  $output = theme('status_messages');
  print drupal_to_js(array('status' => TRUE, 'data' => $output));
  exit();
}


/**
 * This does a recursive check on the cached form
 * to locate a given element.
 *
 * @param array $form The form.
 * @param string $name The element name.
 * @return mixed Either the found element or FALSE.
 */
function locate_upload_element(&$form, $name, $extras = array()) {
  foreach (element_children($form) as $key) {
    // Various modules were causing false positives & errors
    if (isset($form[$key]) && is_array($form[$key])) {
      if ($key == $name && isset($form[$key]['#type'])
          && ($form[$key]['#type'] == 'upload_element' || $form[$key]['#type'] == 'image_upload_element')) {
        $form[$key] += $extras;
        return $form[$key];
      }
      else {
        if ($element = locate_upload_element($form[$key], $name, $extras)) {
          return $element;
        }
      }
    }
  }
  return FALSE;
}
