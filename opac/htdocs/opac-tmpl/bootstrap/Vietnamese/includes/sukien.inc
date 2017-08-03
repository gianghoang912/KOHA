<div class="sk">
	[% FOREACH koha_new1 IN koha_news %]
	<div class="preview-img">
		<a href="/cgi-bin/koha/opac-ctnews.pl?idnew=[% koha_new1.idnew %]&idgroup=[% koha_new1.idgroup %]">
			<img src="[% IF koha_new1.img != "/opac-tmpl/bootstrap/images/news/null111" %][% koha_new1.img %][% ELSE %]/opac-tmpl/bootstrap/images/news/default.jpg[% END %]">
		</a>
	</div>
	[% END %]
</div>