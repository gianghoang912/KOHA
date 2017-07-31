<select class="lienketweb" style="width:100%;margin-top:10px; color:#159eae;">
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
