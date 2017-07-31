<style>
#qrcodeimg{
	width:99%;
	background:rgb(243,243,243);
	margin-top:5px;
	border:1px solid rgb(208,208,208);
}
#imgcd{
	margin-top:20px;
	margin-bottom:20px;
	width:70%;
	height:70%;
}
#h1cd{
	margin-top:0px;
	background:rgb(217,217,217);
	border-bottom:1px solid rgb(208,208,208);
	font-size:13px;
	padding-top:10px;
	padding-bottom:10px;
	padding-left:25px;
	color:rgb(0, 102, 153);
}
</style>
<div id="qrcodeimg">
<h1 id="h1cd">QRcode</h1>
<center>
<script type=text/javascript>
//var title = document.getElementsByClassName("title");
//var a = title[0].innerHTML;
var a = document.getElementById("kohabooktitle").innerHTML;
a = a.replace("&amp;"," và");
a = a.replace("/","");
a = a.replace(/(<([^>]+)>)|\n/gi,"");
a = a.replace("'","");
var inra = "Nhan đề: "+ a;

if($('.author').length){
	var author = $('.author');
	var b = author[0].innerHTML;
	
}else {var b="Author: Null";}

b = b.replace("by","Author: ");
b = b.replace(/(<([^>]+)>)|\n/gi,"");
b = b.replace("                    "," ");

inra = inra+"\n"+b+"\n\n";

if($('.location').length || $('.call_no').length || $('.barcode').length || $('.status').length ){
	
	var n = 0;
	if($('.location').length){
		var location1 = $('.location');
		var loca = "";
		n = location1.length;
		
		if(n>5){
			n = 5;
		}
	}

	if($('.call_no').length){
		var call_no = $('.call_no');
		var cal = "";
		n = call_no.length;
		
		if(n>5){
			n = 5;
		}
	}
	if($('.barcode').length){
		var barcode = $('.barcode');
		var bar = "";
		n = barcode.length;
		if(n>5){
			n = 5;
		}
	}
	
	if($('.status').length){
		var status1 = $('.status');
		var sta = "";
		n = status1.length;
		if(n>5){
			n = 5;
		}
	}
	
	for(var i = 1; i < n; i++){
		
		if($('.location').length){
			loca = location1[i-1].innerHTML;
			loca = loca.replace(/(<([^>]+)>)|\n/gi,"");
			//loca = loca.replace("/&amp;","");
			var s = loca.match(/[a-z]/gi);
			var ktudau = s[0];
			loca = loca.slice(loca.indexOf(ktudau));
			var k = s.length;
			var ktketthuc = s[k-1];
			var kt = loca.lastIndexOf(ktketthuc);
			loca = loca.substr(0,kt+1);

			if(location.length == 0){
				loca = "Null";
			}
			inra = inra + loca+"\n";
		}
		if($('.call_no').length){
			cal = $(call_no[i]).html();
			cal = cal.replace(/(<([^>]+)>)|\n/gi,"");
			if(cal.length == 0){
				cal="Null";
			}
			inra = inra + "Call No: "+ cal+"\n";
		}

		if($('.barcode').length){
			bar = $(barcode[i]).html();
			bar = bar.replace(/(<([^>]+)>)|\n/gi,"");
			if(bar.length == 0){
				bar="Null";
			}
			inra = inra + "Barcode: "+ bar+ "\n";
		}
		if($('.status').length){
		
			sta = $(status1[i]).html();
			sta = sta.replace(/(<([^>]+)>)|\n/gi,"");
			var s = sta.match(/[a-z]/gi);
			var ktudau = s[0];
			sta = sta.slice(sta.indexOf(ktudau));
			var k = s.length;
			var ktketthuc = s[k-1];
			var kt = sta.lastIndexOf(ktketthuc);
			sta = sta.substr(0,kt+1);
			if(status1.length == 0){
				sta = "Null";
			}
			inra = inra + "Trạng thái: "+ sta + "\n\n";
		}
	}
	
	
}
inra = inra + "\n" + "URL: " + document.URL;

document.write("<img id='imgcd' src='http://api.qrserver.com/v1/create-qr-code/?data="+encodeURI(inra)+"'/>");
</script>
</center>
</div>




