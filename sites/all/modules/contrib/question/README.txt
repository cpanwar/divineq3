------------------------------------------------------------------------------
  Question Module for Drupal
  maintained by: Alastair Aitchison | tanoshimi | alastair (att) a3uk (d0t) com
     created by: Jeff Robbins | jjeff | robbins (att) jjeff (d0t) com
------------------------------------------------------------------------------

This module was developed as a solution for a site that wanted to post "question of the week" type nodes where users could submit questions and one would be selected and answered each week.

However, it was developed to be slightly more generic allowing for use anywhere question/answer -type nodes are needed.  A common use might be frequently asked question (FAQ) listings or knowledge base repositories.

Here are the important things to know about question.module:

Question.module basically has two parts:

1) The question form, which gets submitted into a queue viewable by administrators.

2) The question node-type, which can be created either manually (from 'node/add/question') or by selecting a question from the queue. This way the question and user information gets automatically populated into the question node where it can be edited (if necessary) and an answer can be entered.

The question form can be brought into a node by either:
  - Creating a php node containing the following line:
    <?php question_print_form() ?>
  - Using macrotags.module and simply adding the tag:
    [qform]
  - Or just linking to 'www.example.com/question' (or 'www.example.com/?q=question')
  
Submitted questions will end up in the question queue at 'admin/question'