function checkData(){
		var ele=document.mapping_form.elements;
	var eleLength=ele.length;
	var flag=0;
	for(var i=0; i<eleLength; i++){
		  if(ele[i].type.toUpperCase()=="CHECKBOX" && ele[i].name=="mapping_chk[]" &&  ele[i].checked==true){
		flag=1;
	  }
	}
	if(!flag){
	  if(!confirm("You are de-assigning yourself from all packages.\nAre you sure?")){
		return false;
	  }
	}
	return true;
}

function checkAll(state){
  var ele=document.mapping_form.elements;
  var eleLength=ele.length;
  for(var i=0; i<eleLength; i++){
	  if(ele[i].type.toUpperCase()=="CHECKBOX" && ele[i].name=="mapping_chk[]"){
	ele[i].checked=state;
  }
 }
}