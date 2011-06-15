
        TELL A FRIEND NODE MODULE - README
______________________________________________________________________________

NAME:       Tell A Friend Node
AUTHORS:    Glenn Gaetz (glenngaetz@gmail.com)
______________________________________________________________________________


DESCRIPTION

Tell A Friend node type for creating tell a friend pages

INSTALLATION

Step 1) Download latest release from http://drupal.org/project/tellafriend_node

Step 2)
  Extract the package into your 'modules' directory.


Step 3)
  Enable the Tell A Friend Node module.

  Go to "administer >> build >> modules" and put a checkmark in the 'status' column next
  to 'Tell A Friend Node'.


Step 4)
  Enable permissions appropriate to your site.

  The Tell A Friend Node module provides two permissions:
   - 'access tellafriend nodes': allow user to access and use Tell A Friend Nodes.
   - 'administer tellafriend nodes': allow user to configure Tell A Friend Nodes.

  Note: There are no global settings for this module at this time.
  

Step 5)

Go to "administer >> Content Management >> Content Types >> Tell A Friend Page" to configure the node default settings (enable or disable comments, attachments, publishing options, etc).

If you are using a WYSIWYG editor you will probably want to make sure that it does not replace the following textareas:
- Recipients field (field id: edit-recipients)
- Email wrapper field (field id: edit-tellafriend-node-html-mail-wrapper)

- The WYSIWYG settings for both Message field should probably match. This means that if you are using the WYSIWYG when editing the node, you should also have the WYSIWYG show for the users to edit the message when they use the Tell a Friend page. Otherwise all the HTML markup will be displayed to them. 


Step 6)
  Go to "/node/add/tellafriend-node" to create a new Tell A Friend Page.


CREDITS & SUPPORT

Development of this module sponsored by Ecojustice (ecojustice.ca) and Harvey McKinnon Associates (harveymckinnon.com)

All issues with this module should be reported via the following form:
http://drupal.org/node/add/project_issue/tellafriend_node
