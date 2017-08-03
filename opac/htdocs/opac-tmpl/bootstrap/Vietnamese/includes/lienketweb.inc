<select class="lienketweb" style="width:100%;margin-top:20px; color:#333333;">
	<option value="">---------- Liên kết Website ----------</option>
	<option value="#">Link 01</option>
	<option value="#">Link 02</option>
	<option value="#">Link 03</option>
	<option value="#">Link 04</option>
	<option value="#">Link 05</option>
	<option></option>
</select>
<script>
	$(document).ready(function(){
		$(".lienketweb").change(function(){
			if($(".lienketweb").val()){
				window.open($(".lienketweb").val());
			}			
		})
	})
</script>
<div class="counter">
	<p>0000999999</p>
</div>
