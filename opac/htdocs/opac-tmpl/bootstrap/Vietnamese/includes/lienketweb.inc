<div class="lienketweb col-xs-12">
	<select style="width:100%;margin-top:20px; color:#333333;">
		<option value="">--Liên kết Website --</option>
		<option value="#">Link 01</option>
		<option value="#">Link 02</option>
		<option value="#">Link 03</option>
		<option value="#">Link 04</option>
		<option value="#">Link 05</option>
		<option></option>
	</select>
</div>

<script>
	$(document).ready(function(){
		$(".lienketweb").change(function(){
			if($(".lienketweb").val()){
				window.open($(".lienketweb").val());
			}			
		})
	})
</script>
<div class="col-xs-12">
	<div class="counter"><p>999999</p></div>
</div>
