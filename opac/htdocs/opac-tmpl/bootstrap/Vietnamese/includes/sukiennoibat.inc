<div class="sk">
	<h3 class="title">Sự kiện</h3>
	<div class="row">
		[% FOREACH koha_new IN kohanew_thuan %]
		<div class="sk-ct col-xs-12 col-sm-6">
			<div class="imgcl">
				<div class="img-sk">
					<h2 class="month">[% koha_new.month %]
					</h2>
					<h2 class="day">[% koha_new.day %]
					</h2>
				</div>
			</div>
			<div class="sk-item">
				<h5><a class="sk-title" href="/cgi-bin/koha/opac-ctnews.pl?idnew=[% koha_new.idnew %]&idgroup=[% koha_new.idgroup %]">[% koha_new.title %]</a></h5>
				<div class="sk-tt">
					<p>[% koha_new.sub %]</p>
				</div>
			</div>
		</div>
		[% END %]
	</div>
</div>
<script>
	$(".sk-item a.sk-title").each(function(i) {
		var len = $(this).text().length;
		if (len > 75) {
			var str = $(this).text().substr(0, 75);
			var lastIndex = str.lastIndexOf(" ");
			str = str.substring(0, lastIndex);
			$(this).html("<span>" + str + "</span>");
			var link = $("<span>...</span>");
			$(this).append(link);
		}
	});

	$(".sk-item div.sk-tt p").each(function(i) {
		var len = $(this).text().length;
		if (len > 150) {
			var str = $(this).text().substr(0, 150);
			var lastIndex = str.lastIndexOf(" ");
			str = str.substring(0, lastIndex);
			$(this).html("<span>" + str + "</span>");
			var link = $("<span>...</span>");
			$(this).append(link);
		}
	});
</script>