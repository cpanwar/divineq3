<?php 
	//echo "<pre>";print_r($form['locations']['0']);exit;
?>
<div class="form_container">
	<div class="page_title_container">
		<h1>Sign up for Expert</h1>
		<h2>Get exclusive updates on new services, offers, and promotions from Divine Wellness.</h2>
	</div>
<!-- row begins -->
	<div class="form_element_row">
		<div class="orange_label">User info</div>
		<div class="username">
		<div class="fl">
			<label for="l_name">Email Address</label>
			<input type="<?php print $form['account']['mail']['#type'] ?>" name="<?php print $form['account']['mail']['#name'] ?>" id="<?php print $form['account']['mail']['#id'] ?>" value="<?php print $form['account']['mail']['#value'] ?>"/>
		</div>
		<div class="cb"></div>
		</div>
	</div>	
<!-- row ends -->	
<!-- row begins -->
	<div class="form_element_row">
		<div class="orange_label">Salutation</div>
		<div class="salutation">
			<?php print  drupal_render($form['instructor_info']['Instructor information']['profile_inst_salutation'])?>
		</div>
	</div>
<!-- row ends -->
<!-- row begins -->
	<div class="form_element_row">
		<div class="orange_label">Name</div>
		<div class="name">
		<div class="fl">
			<label for="f_name">First Name</label>
			<input type="<?php print $form['instructor_info']['Instructor information']['profile_inst_fname']['#type'] ?>" name="<?php print $form['instructor_info']['Instructor information']['profile_inst_fname']['#name'] ?>" id="<?php print $form['instructor_info']['Instructor information']['profile_inst_fname']['#id'] ?>" value="<?php print $form['instructor_info']['Instructor information']['profile_inst_fname']['#value'] ?>"/>
		</div>
		<div class="fl">
			<label for="l_name">Last Name</label>
			<input type="<?php print $form['instructor_info']['Instructor information']['profile_inst_lname']['#type'] ?>" name="<?php print $form['instructor_info']['Instructor information']['profile_inst_lname']['#name'] ?>" id="<?php print $form['instructor_info']['Instructor information']['profile_inst_lname']['#id'] ?>" value="<?php print $form['instructor_info']['Instructor information']['profile_inst_lname']['#value'] ?>"/>
		</div>
		<div class="cb"></div>
	</div>
	</div>
<!-- row ends -->
<!-- row begins -->
	<div class="form_element_row">
		<div class="orange_label">Address</div>
		<div class="address">
			<div class="address_input">
				<input type="<?php print $form['locations']['0']['street']['#type'];?>" name="<?php print $form['locations']['0']['street']['#name'];?>" id="<?php print $form['locations']['0']['street']['#id'];?>" class="address_input" value="<?php print $form['locations']['0']['street']['#value'];?>"/>
			</div>
			<div class="city_country">
				<div class="fl">
					<label for="add_city">City</label>
					<input type="<?php print $form['locations']['0']['city']['#type'];?>" name="<?php print $form['locations']['0']['city']['#name'];?>" id="<?php print $form['locations']['0']['city']['#id'];?>" value="<?php print $form['locations']['0']['city']['#value'];?>"/>
				</div>
				<div class="fl">
					<label for="add_state">State/Province</label>
					<input type="<?php print $form['locations']['0']['province']['#type'];?>" name="<?php print $form['locations']['0']['province']['#name'];?>" id="<?php print $form['locations']['0']['province']['#id'];?>" value="<?php print $form['locations']['0']['province']['#value'];?>"/>
				</div>
				<div class="fl">
					<label for="add_zip">Zip/Postal</label>
					<input type="<?php print $form['locations']['0']['postal_code']['#type'];?>" name="<?php print $form['locations']['0']['postal_code']['#name'];?>" id="<?php print $form['locations']['0']['postal_code']['#id'];?>" value="<?php print $form['locations']['0']['postal_code']['#value'];?>"/>
				</div>
				<div class="cb"></div>
				<div class="country">
					<?php print drupal_render($form['locations']['0']['country'])?>
				</div>
				<div style="display:none">
					<?php print drupal_render($form['locations']);?>
				</div>
			</div>
		</div>
	</div>
<!-- row ends -->
<!-- row begins -->
<div class="form_element_row">
	<div class="certification">
		<div class="fl">
			<table width="650px" border="0" cellspacing="0" cellpadding="0">
			<tr>  
			<td width="539" valign="top">
				<table width="100%" border="0" cellspacing="0" cellpadding="0">
					<tr>
						<td>
							<?php print drupal_render($form['instructor_info']['Instructor information']['profile_inst_certification'])?>
						</td>
						<td>
							<?php print drupal_render($form['instructor_info']['Instructor information']['profile_inst_institute'])?>
						</td>
					</tr>
				</table>
			</td>
			<td width="111" valign="top">&nbsp;</td>
			</tr>
			</table>
		</div>
		<div class="cb"></div>
	</div>
</div>
<!-- row ends -->
<!-- row begins -->
<div class="form_element_row">
<div class="orange_label">Yoga Style</div>
<div class="yoga_style">
	<div class="fl">
		<?php print drupal_render($form['instructor_info']['Instructor information']['profile_inst_yoga_style'])?>
	</div>
  <div class="fl">
	<div class="practice_years">
		<?php print drupal_render($form['instructor_info']['Instructor information']['profile_inst_teaching_exp'])?>
    </div>
  </div>
  <div class="cb"></div>
</div>

</div>
<!-- row ends -->
<!-- row begins -->
<div class="form_element_row">
	<div class="orange_label">General Information</div>
		<div class="gen_info">
			<?php print drupal_render($form['instructor_info']['Instructor information']['profile_find_site'])?>
		</div>
</div>
<!-- row ends -->

<!-- row begins -->
<div class="form_element_row">
	<div class="terms_condition">
		<?php print drupal_render($form['term']['term_desc'])?>		
		<table width="84%" border="0" cellspacing="0" cellpadding="0" class="agreed">
			<tr>
				<td width="100%" valign="top" colspan="2">
					<?php print drupal_render($form['term']['term_check'])?>
				</td>
			</tr>
		</table>
  </div>
</div>
<!-- row ends -->
<!-- row begins -->
<div class="form_element_row">
	<div class="action-btn">
		<input type="image" src="<?php print base_path().path_to_theme()?>/images/submit-btn.gif" id="<?=$form['buttons']['submit']['#id']?>" name="<?=$form['buttons']['submit']['#name']?>"/>
		<input type="hidden" class="form-submit" value="Next" id="<?=$form['buttons']['submit']['#id']?>" name="<?=$form['buttons']['submit']['#name']?>" />		
	</div>
</div>
<!-- row ends -->
</div>
<?php
	//print drupal_render($form);
	print drupal_render($form['form_build_id']);
	print drupal_render($form['changed']);
	print drupal_render($form['form_token']);
	print drupal_render($form['form_id']);
?>