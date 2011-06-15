<?php

if ((!empty($_SERVER['argv'][1])) && (!empty($_SERVER['argv'][2]))) {
  if (!file_exists($_SERVER['argv'][1] .'/index.php')) {
    print("invalid drupal path\n");
    exit;
  }
}
else {
  print("This script rebuilds the complete Bookings API Free Cache of a single installation\n");
  print("Usage: php rebuild.cache.php [Absolute Path to Drupal] [Hostname]\n");
  exit;
}


$sapi_type = php_sapi_name();
if ($sapi_type!='cli')  die('only executable from command line!');

// Drupal Bootstrap laden
chdir($_SERVER['argv'][1]);
$_SERVER['REMOTE_ADDR'] = '127.0.0.1';
$_SERVER['HTTP_HOST'] = $_SERVER['argv'][2];
$_SERVER['PHP_SELF'] = $_SERVER['SCRIPT_NAME'] = '/index.php';
require_once('includes/bootstrap.inc');

drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

module_load_include('module','bookingsapi');
module_load_include('module','bookingsapi_free_cache');

print("Starting to rebuild cache\n");
bookingsapi_free_cache_recalculate();
print("Done\n");
exit;

?>
