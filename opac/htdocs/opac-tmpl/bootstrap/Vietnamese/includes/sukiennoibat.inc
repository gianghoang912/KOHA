<div class="span6 sk" style="float: right;">
		<h3>Sự kiện</h3>
		[% FOREACH koha_new IN kohanew_thuan %]
		<div class="sk-ct">
			<div class="imgcl">
				<div class="img-sk">
					<h2 class="month">[% koha_new.month %]
					</h1>
					<h2 class="day">[% koha_new.day %]
					</h1>
				</div>
			</div>
			<div class="sk-item">
				<h5><a style="color:black;" href="/cgi-bin/koha/opac-ctnews.pl?idnew=[% koha_new.idnew %]&idgroup=[% koha_new.idgroup %]">[% koha_new.title %]</a></h5>
				<div class="sk-tt">
					[% koha_new.sub %]
					
				</div>
			</div>
		</div>
		[% END %]
		
	</div>