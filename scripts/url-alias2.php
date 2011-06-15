<?php
echo "success";
$username="root";
$password="kanpur@2011";
$host="localhost";
$db="divine_wellness_training";

$link=(mysql_connect($host,$username,$password));

mysql_select_db($db);

$query="select * from url_alias";

$res=mysql_query($query);

while($row=mysql_fetch_assoc($res)) {
  $dst=$row['dst'];
  $id=$row['pid'];
  $update_dst=str_replace(' ','-',$dst);
  $update_dst=str_replace('&','',$update_dst);
  $update_dst=str_replace('--','-',$update_dst);
  $update_dst=strtolower($update_dst);
  $q="update url_alias set dst='$update_dst' where pid=$id";
  mysql_query($q) or die(mysql_error());
  echo $update_dst."<br/>";
}
