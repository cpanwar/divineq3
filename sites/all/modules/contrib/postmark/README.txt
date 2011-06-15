Module description
------------------

The Postmark module allows the administrator to switch the standard SMTP 
library over to use the third party Postmark library. An account with 
Postmark is required to use this module.

The recommended third party library for this module is the latest version
of the Postmark PHP class v0.4.4 by Markus Hedlund et al.
http://github.com/Znarkus/postmark-php

Note: The module uses the REST API to connect to Postmark.

Installation
------------

Installing the Postmark module requires a few steps :

1) Copy the postmark folder to the modules folder in your installation 
   This is usually sites/all/modules.

2) Obtain the Postmark PHP library from http://github.com/Znarkus/postmark-php.

3) Copy the files to the includes directory in the module folder
   /modules/postmark/includes.

4) You must ensure you get the Certificate folder too as this is now implemented
   within the PHP class.

4) Enable the module using Administer > Modules (/admin/build/modules).

5) Go to Site configuration > Postmark (/admin/settings/postmark)
   
6) Enable Postmark functionality and add your API key from your Postmark account.

7) The test functionality enables you to test the integration is working, this 
   will use a credit by default each time you submit an email address.

8) The email address that emails are sent from on your site must have a valid 
   Sender Signature set up in your Postmark account. Different modules use 
   different settings for the "From" address. One important place to check is 
   the address on Administer > Site configuration > Site information.

Support and bugs
----------------

If you have any problems using the module, please submit an issue in the 
Postmark queue (http://drupal.org/project/issues/postmark).

That's also a good place to check for known problems and "todos".

Credit
------

The Postmark module was developed by
 * Luke Simmons (luketsimmons)
 * Allister Price (alli.price)
from Deeson Online (http://www.deeson.co.uk/online).

Credit also goes to the phpmailer (http://drupal.org/project/phpmailer) module on 
which this module is heavily based.
