<?php
global $user;
$arg_user_id = arg(1);
$account = user_load($arg_user_id);
$thisAccountsRole = getUsersUniqueRole($account->uid);	
if($thisAccountsRole=='expert'){
	$expertPackage = expertPackage($account->uid);
}	

// template for expert
$tmplExpert = '<table border="1">
					<tr>
						<td colaspan="2">'.$account->profile_inst_fname.' '.$account->profile_inst_lname.'</td>
					</tr>
					<tr>
						<td><img src='.base_path().$account->picture.'></td>
						<td>
							<table>
								<tr>
									<td>Styles: '.$account->profile_inst_yoga_style.'</td>
								</tr>
								<tr>
									<td>Country: '.$account->location['city'].' '.$account->location['country_name'].'</td>
								</tr>								
								<tr>
									<td>Certification: '.$account->profile_inst_certification.'</td>
								</tr>
								<tr>
									<td>Experience: '.$account->profile_inst_teaching_exp.'</td>
								</tr>								
								<tr>
									<td>Description: '.$account->profile_inst_desc.'</td>
								</tr>
								
							</table>
						</td>
					</tr>
					<tr>		
						<td>
							<table border="0">
								<tr>
									<td>'.theme('imagecache', 'user_pic', $account->profile_inst_image1, $alt, $title,  $attributes).'</td>
									<td>'.theme('imagecache', 'user_pic', $account->profile_inst_image2, $alt, $title,  $attributes).'</td>
									<td>'.theme('imagecache', 'user_pic', $account->profile_inst_image3, $alt, $title,  $attributes).'</td>
								</tr>
							</table>
						</td>
						<td>
							<table>';
								if(!empty($expertPackage)){
									foreach($expertPackage as $key => $value){
										$nodeL = node_load($value);
										//echo "<pre>";print_r($nodeL);exit;
										$tmplExpert .= '<tr>';
											$tmplExpert .= '<td>'.$nodeL->title.' - '.$nodeL->sell_price.'</td>';
										$tmplExpert .= '</tr>';
									}
								}else{
										$tmplExpert .= '<tr>';
											$tmplExpert .= '<td>There are no packages for this  teacher</td>';
										$tmplExpert .= '</tr>';
									
								}
						$tmplExpert .= '</table>
						</td>
					<tr>
				<table>';

// template for member user				
$tmplMember	=  $user_profile;


switch ($thisAccountsRole) {
    case "expert" :
        $profileTpl = $tmplExpert;
        break;
    case "member" :
        $profileTpl = $tmplMember;
        break;
    default:
        $profileTpl = t($tmplMember);
}	
echo $profileTpl;
?>