function checkData(){
	//var ele=document.mapping_form.elements;
	var ele=document.getElementsByTagName('INPUT');
	var eleLength=ele.length;

	var flag=0;
	for(var i=0; i<eleLength; i++){
      try{
	   if(ele[i].type.toUpperCase()=="CHECKBOX" && ele[i].name=="mapping_chk[]" &&  ele[i].checked==true &&  ele[i].disabled==false){
		flag=1;
	   }
	  }
	  catch(e){}
   }
  
   if(!flag){
	  if(!confirm("You are de-assigning yourself from all normal packages.\nAre you sure?")){
		return false;
	  }
   }
  return true;
}

function checkAll(state){
  //var ele=document.mapping_form.elements;
  var ele=document.getElementsByTagName('INPUT');
  var eleLength=ele.length;
  for(var i=0; i<eleLength; i++){
  if(!ele[i].disabled){
   if(ele[i].type.toUpperCase()=="CHECKBOX" && ele[i].name=="mapping_chk[]"){
	ele[i].checked=state;
   }
  }
 }
}