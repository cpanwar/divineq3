<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function block_settings_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'askanexpert_static_block';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'askanexpert_feature';
  $fe_block_boxes->body = '<a href="mailto:care@divinewellness.com"><div class="expert_block">
<strong><h3>
Ask An Expert</h3><strong>
Submit a question to<br>
one of our Qualified<br> 
Yoga Instructor.
</div></a>';

  $export['askanexpert_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'List of Booked Classes';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'bookedclass_feature';
  $fe_block_boxes->body = '<?php
Global $user;
		$query = db_query("SELECT * from booked_sessions");
		if ($user->uid ==1) {			
			$header=array(\'User Email\',\'Package name\',\'Yoga Guru\',\'Time Slot\',\'Booking Time\');
			while ($result = db_fetch_array($query)) {
				$uid = $result[\'uid\'];
				$uname_query=db_query("Select mail from users where uid=$uid");
				$uname_result_array = db_fetch_array($uname_query);
				$uname = $uname_result_array[\'mail\'];
				$resid=$result[\'resource_id\'];
				$pid=$result[\'package_id\'];
				$timeslot=$result[\'time_slot\'];
				$created=$result[\'created\'];
				$query1=db_query("Select title from node where nid=$resid");
				$res_array=db_fetch_array($query1);
				$res_name=$res_array[\'title\'];    
				$query2=db_query("Select title from node where nid=$pid");
				$res_array=db_fetch_array($query2);
				$pack_name=$res_array[\'title\'];    
				$rows[]=array(l($uname,\'user/\'.$uid),l($pack_name,\'node/\'.$pid),l($res_name,\'node/\'.$resid),$timeslot,format_date($created,\'small\',\'\'));    
			}
			if (count($rows)) {
				$output = theme(\'table\', $header, $rows);
			}
			else {
				$output = "<p>" . t(\'You have not scheduled any classes yet.\') . "</p>";
			}
		}
		else {			
			$header=array(\'Package name\',\'Yoga Guru\',\'Time Slot\',\'Booking Time\');
			while ($result = db_fetch_array($query)) {
				$resid=$result[\'resource_id\'];
				$pid=$result[\'package_id\'];
				$timeslot=$result[\'time_slot\'];
				$created=$result[\'created\'];
				$query1=db_query("Select title from node where nid=$resid");
				$res_array=db_fetch_array($query1);
				$res_name=$res_array[\'title\'];    
				$query2=db_query("Select title from node where nid=$pid");
				$res_array=db_fetch_array($query2);
				$pack_name=$res_array[\'title\'];    
				$rows[]=array(l($pack_name,\'node/\'.$pid),l($res_name,\'node/\'.$resid),$timeslot,format_date($created,\'small\',\'\'));    
			}
			if (count($rows)) {
				$output = theme(\'table\', $header, $rows);
			}
			else {
				$output = "<p>" . t(\'You have not scheduled any classes yet.\') . "</p>";
			}
		}
print $output;
?>';

  $export['bookedclass_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'CorporateWellness';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'corporatewellness_feature';
  $fe_block_boxes->body = '<div class="CorporateWellness">
<h2>Corporate Wellness</h2>
<h5>SUSPENDISSE SED CONGUE MAURIS.</h5>
<div class="default_width">
<div class="content_area">Rotating wellness Tips from the Yoga and other Gurus.&nbsp; Rotating wellness Tips from the Yoga and other Gurus.</div>
<div class="btn"><button class="orange_btn3"></button></div>
</div>
</div>';

  $export['corporatewellness_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Explore our programs';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'explore_feature';
  $fe_block_boxes->body = '<ul class="menu"><li class="leaf first active-trail"><a href="<?php print base_path();?>weight-loss" title="Weight Loss" class="active">Weight Loss</a></li>
<li class="leaf"><a href="<?php print base_path();?>Cleanse" title="Cleanse" class="active">Cleanse</a></li>
<li class="leaf"><a href="<?php print base_path();?>anti-aging" title="Anti-Aging" class="active">Anti-aging</a></li>
<li class="leaf"><a href="<?php print base_path();?>joint-care" title="Joint Care" class="active">Joint Care</a></li>
<li class="leaf"><a href="<?php print base_path();?>stress-relief" title="Stress Relief" class="active">Stress Relief</a></li>
<li class="leaf last"><a href="<?php print base_path();?>pregnancy" title="Post-Natal" class="active">Pregnancy</a></li>
</ul>
';

  $export['explore_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'how_itworks_block';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'howitworks_static';
  $fe_block_boxes->body = '<div class="how_itworks_block">
<div class="ho_block_list">
<ul>
  <li>1) Sign up</li>
  <li>2) Choose your program</li>
  <li>3) Schedule a class</li>
  <li>4) Take your class</li>
</ul>
</div>
<div class="butn">
<a href="<?php print base_path();?>trial-form">FREE Trial</a>
</div>

</div>';

  $export['howitworks_static'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'LiveConsultations';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'liveconsultation_feature';
  $fe_block_boxes->body = '<div class="LiveConsultations">
<h2>Live Consultations</h2>
<h5>SUSPENDISSE SED CONGUE MAURIS.</h5>
<div class="default_width">
<div class="content_area">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer et metus sed mi fermentum lobortis.</div>
<div class="btn"><button class="orange_btn2"></button></div>
</div>
</div>';

  $export['liveconsultation_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'live_sessions';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'livesession_feature';
  $fe_block_boxes->body = '<!-- <p><img width="237" height="223" src="/divinewellness-theme/sites/default/files/userfiles/live_sessions.png" alt=""></p> -->
<div class="live_sessions">
<div class=wc1"><h1>LIVE</h1> <h3>sessions with yoga instructors around the world</h3><br/><br/></div>
<div class="btn"><a href="<?php print base_path();?>packages"><button class="orange_butn">Buy Now</button></a></div>
</div>
';

  $export['livesession_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'MeettheGurus';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'meetguru_feature';
  $fe_block_boxes->body = '<div class="MeettheGurus">
<h2>Meet the Gurus</h2>
<h5>SOMETHING ABOUT THIS</h5>
<div class="default_width">
<div class="image_box"><img width="98" height="155" src="<?php print base_path();?>sites/default/files/userfiles/Meet.png" alt=""></div>
<div class="content_right">
<h4>From Our Gurus</h4>
<p>Rotating wellness Tips from the Yoga and other Gurus.</p></div>
<p><button class="orange_btn"></button></p></div>
</div>';

  $export['meetguru_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'List of packages bought by a user';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'mypackage_feature';
  $fe_block_boxes->body = '<?php
Global $user;
$uid =$user->uid;
$admin = FALSE;
  if (user_access(\'modify yoga booking instances\'))
    $admin = TRUE;
  if ($admin)
    $header = array(\'Package\',\'Status\', \'Book Now\', \'Admin\');
  else
    $header = array(\'Package\', \'Status\', \'Book Now\');
  $rows = array();
  if(!$admin) { 
  $query = db_query("SELECT dws.instance_id, node.nid, node.title, product.field_live_sessions_value, dws.sessions, dws.expiry, dws.status FROM {dw_yoga_sessions} AS dws INNER JOIN {node} AS node ON dws.product_id = node.nid INNER JOIN {content_type_product} AS product ON node.nid = product.nid WHERE dws.uid = %d limit 0,5", $uid) ;
  $i = 0;
  
  while ($result = db_fetch_array($query)) {
  	$i++;
  
  	$sessions_bought = $result[\'field_live_sessions_value\'];

  	$sessions_available = $result[\'sessions\'];
  	$expiry_date = ($result[\'expiry\'] == 0) ? \'Not Active\' : date(\'j M Y\', $result[\'expiry\']);
  	$activate_now_form = drupal_get_form(\'divine_bookings_activate_form_\' . $i, $result[\'instance_id\']);
  	if ($result[\'status\'] == 0 && $result[\'expiry\'] == 0) {
  	  $status = $activate_now_form;
  	}
  	else if ($result[\'expiry\'] < time()) {
  	  $status = \'Expired\';
  	}
  	else {
  	  $status = \'Active\';
  	}
  
  	$instance = $result[\'instance_id\'];
  	if ($admin) {
  	  if ($result[\'status\'] == 1 && $sessions_available > 0)
  	    $rows[] = array($package_url, $status, l(\'Book Now\', \'booking\', array(\'query\' => array(\'package\' => $result[\'nid\'],\'instance_id\' => $result[\'instance_id\']))), l(\'Edit\', \'user/\' . $uid . \'/instance/\' . $instance . \'/edit\'));
  	  else
  	    $rows[] = array($package_url, $status, \'Cannot Book\', l(\'Edit\', \'user/\' . $uid . \'/instance/\' . $instance . \'/edit\'));
  	}
  	else {
  	  if ($result[\'status\'] == 1 && $sessions_available > 0)
  	    $rows[] = array($package_url, $status, l(\'Book Now\', \'booking\', array(\'query\' => array(\'package\' => $result[\'nid\'],\'instance_id\' => $result[\'instance_id\']))));
  	  else
  	    $rows[] = array($package_url, $status, \'Cannot Book\');
  	}
  }
}
else {
 $query = db_query("SELECT dws.instance_id, node.nid, node.title, product.field_live_sessions_value, dws.sessions, dws.expiry, dws.status FROM {dw_yoga_sessions} AS dws INNER JOIN {node} AS node ON dws.product_id = node.nid INNER JOIN {content_type_product} AS product ON node.nid = product.nid limit 0,5");
  $i = 0;
  
  while ($result = db_fetch_array($query)) {
  	$i++;
    $qty=$result[\'qty\'];   
  	$package_url = l($result[\'title\'], \'node/\' . $result[\'nid\']);
  
  	$sessions_bought = $result[\'field_live_sessions_value\'];

  	$sessions_available = $result[\'sessions\'];
  	$expiry_date = ($result[\'expiry\'] == 0) ? \'Not Active\' : date(\'j M Y\', $result[\'expiry\']);
  	$activate_now_form = drupal_get_form(\'divine_bookings_activate_form_\' . $i, $result[\'instance_id\']);
  	if ($result[\'status\'] == 0 && $result[\'expiry\'] == 0) {
  	  $status = $activate_now_form;
  	}
  	else if ($result[\'expiry\'] < time()) {
  	  $status = \'Expired\';
  	}
  	else {
  	  $status = \'Active\';
  	}
  
  	$instance = $result[\'instance_id\'];
      if ($sessions_available == 0)
        $rows[] = array($package_url, $status, \'No Sessions\', l(\'Edit\', \'user/\' . $uid . \'/instance/\' . $instance . \'/edit\'));
      else {
      if ($status==\'Expired\') 
        $rows[] = array($package_url, $status, \'Expired\', l(\'Edit\', \'user/\' . $uid . \'/instance/\' . $instance . \'/edit\'));      
      else {
  	  if ($result[\'status\'] == 1 && $sessions_available > 0)
  	    $rows[] = array($package_url, $status, l(\'Book Now\', \'booking\', array(\'query\' => array(\'package\' => $result[\'nid\'],\'instance_id\' => $result[\'instance_id\']))), l(\'Edit\', \'user/\' . $uid . \'/instance/\' . $instance . \'/edit\'));
  	  else
  	    $rows[] = array($package_url, $status, \'Cannot Book\', l(\'Edit\', \'user/\' . $uid . \'/instance/\' . $instance . \'/edit\'));
      }
    }
  }
}
  if (count($rows)) {
    $output = theme(\'table\', $header, $rows);
  }
  else {
    $output = "<p>" . t(\'You have not bought any packages yet.\') . "</p>";
  }
  print $output;
	print l(\'List of all the Packages\',\'user/\'.$uid.\'/packages\');
  ?>  ';

  $export['mypackage_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'newspaper letter';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'newspaper_feature';
  $fe_block_boxes->body = '<div class="newsletter_title"><a href="<?php print base_path();?>page-under-construction">SIGN UP FOR OUR NEWSLETTER</a></div>';

  $export['newspaper_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'recentpost_static_block';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'recentpost_static';
  $fe_block_boxes->body = '<div class="recent_post_block">
<strong><h3>
Recent Posts</h3><strong>
Submit a question to<br>
one of our Qualified<br> 
Yoga Instructor.
</div>
';

  $export['recentpost_static'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'user_prof_community';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'userprofile_community_feature';
  $fe_block_boxes->body = '<div class="user_prof_community">
<ul>
<li><a href="<?php print base_path();?>node">My Posts</a></li>
<li><a href="<?php print base_path();?>node">My Pics</a></li>
<li><a href="<?php print base_path();?>node">My Stories</a></li>
<li><a href="<?php print base_path();?>node">My Friends</a></li>
<li><a href="<?php print base_path();?>node">My Videos</a></li>
<li><a href="<?php print base_path();?>node">My Questions</a></li>
</ul>

</div>';

  $export['userprofile_community_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'user_prof_favourites';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'userprofile_fav_feature';
  $fe_block_boxes->body = '<div class="user_prof_favourites">
<ul>
<li><a href="<?php print base_path();?>packages">Packages</a></li>
<li><a href="<?php print base_path();?>yoga_resource">Gurus</a></li>
<li><a href="<?php print base_path();?>yoga_sequence">Yoga Sequences</a></li>
<li><a href="<?php print base_path();?>content/video-demos">Videos</a></li>
<li><a href="<?php print base_path();?>node">Articles</a></li>
</ul>
</div>
<div class="ext_link">
<a href="<?php print base_path();?>node">See all favourites >></a>
</div>';

  $export['userprofile_fav_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'FreeWellnessConsultation';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'wellness_feature';
  $fe_block_boxes->body = '<div class="FreeWellnessConsultation">
<!-- <img width="237" height="108" src="/divinewellness-theme/sites/default/files/userfiles/right_banner-02.jpg" alt=""> -->
<div class="wc1"><strong><h2>FREE</h2></strong><b><h3>Wellness Consultation</h3></b></div>
<div class="oc1">With a purchase of 4 class package</div>
</div>';

  $export['wellness_feature'] = $fe_block_boxes;

  return $export;
}
