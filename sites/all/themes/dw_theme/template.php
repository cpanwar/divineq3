<?php
// The default function from uc_cart.module.
function dw_theme_uc_cart_block_content() {
  	global $user;
  	if (variable_get('uc_cart_show_help_text', FALSE)) {
    		$output = '<span class="cart-help-text">'. variable_get('uc_cart_help_text', t('Click title to display cart contents.')).'</span>';
  	}
	$output .= '<div id="block-cart-contents"><a href="'.base_path().'cart">';
	$items = uc_cart_get_contents();
 	$item_count = 0;
  	if (!empty($items)) {
    		$output .= '<table class="cart-block-table">'.'<tbody class="cart-block-tbody">';
    		foreach ($items as $item) {
      			$total += ($item->price) * $item->qty;
      			$item_count += $item->qty;
    		}
    		$output .= '<tr><td>'.$item_count. t('items') .'</td><td>'.uc_currency_format($total) .'</td></tr>';
		$output .= '</tbody></table>';
	}
  	else {
    		$output .= '<p>'. t('0 Items')  .'</p>';
  	}
	$output .= '</a></div>';
	return $output;
}

	function dw_theme_preprocess_user_register(&$vars) {
      // That's where $form_markup is created
		variable_set( $vars['form']['name']['#maxlength'],24);
	  $vars['form']['name']['#description']="Your username should be same as your email address.";
    $vars['form_markup'] = drupal_render($vars['form']);
	}
		
	 function divine_preprocess_user_register(&$vars) {
      // That's where $form_markup is created

     variable_set( $vars['form']['name']['#maxlength'],24);
      $vars['form']['name']['#description']="Username can be 6-24 characters long,Spaces are not allowed,Both Uppercase, lowercase, '_','-'&'.' are only allowed";

      $vars['form']['name']['#description']="Username should be atleast 6 characters long,Spaces are not allowed,Both Uppercase, lowercase, '_','-'&'.' are only allowed";

      $vars['form_markup'] = drupal_render($vars['form']);
    }


    function divine_user_login_block($form) {
       $form['name']['#title'] = t('Email'); //wrap any text in a t function
       $form['pass']['#title'] = t('Password');  
       return (drupal_render($form));
    }

    function divine_preprocess_page(&$variables) {

      $path=$variables['node']->path;
      $type=$variables['node']->type;
      
      $temp=array();
      $temp=explode('/',$path);
      if($temp[0]=="diet-nutrition") {
        array_push($variables['template_files'],'page-diet');
      }
      if($type=="static_page") {
        array_push($variables['template_files'],'page-static_page');
      }
		}
		
		
function dw_theme_username($object) {
	if ($object->uid && $object->name) {
	  $thisuser = user_load(array(uid=>$object->uid));
	  $role = db_result(db_query("SELECT r.name FROM users u, role r, users_roles ur WHERE u.uid = ur.uid AND ur.rid = r.rid AND u.uid =%d", $thisuser->uid));

	  if($role=='expert'){
		$fullname = $thisuser->profile_inst_fname;
	  }else{
		$fullname = $thisuser->profile_firstname;
		}	
	  // Shorten the name when it is too long or it will break many tables.
	  if (drupal_strlen($fullname) > 20) {
		$name = drupal_substr($fullname, 0, 15) .'...';
	  }
	  else {
		$name = $fullname;
	  }
	  if (user_access('access user profiles')) {
		$output = l($name, 'user/'. $object->uid, array('title' => t('View my profile.')));
	  }
	  else {
		$output = check_plain($name);
	  }
	}
	else if ($object->name) {

	  // Sometimes modules display content composed by people who are

	  // not registered members of the site (e.g. mailing list or news

	  // aggregator modules). This clause enables modules to display

	  // the true author of the content.
	  if ($object->homepage) {
		//$output = l($object->name, $object->homepage);
		$output = l($object->name, $object->homepage, array('rel' => 'nofollow'));
	  }
	  else {
		$output = check_plain($object->name);
	  }
	  //$output .= ' ('. t('not verified') .')';
	}
	else {
	  $output = variable_get('anonymous', t('Anonymous'));
	}
	return $output;
}	
/*
function dw_theme_theme($existing, $type, $theme, $path) { //echo "hello";exit;
  return array(
    'user_instructor_register_form' => array(
      'arguments' => array('form' => NULL),
      'template' => 'user-instructor-register-form', 
    ),		
  );
}
*/
?>
