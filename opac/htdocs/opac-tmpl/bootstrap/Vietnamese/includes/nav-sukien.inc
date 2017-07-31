<h4 >Sự kiện</h4>
<div class="giomocua" style="border:10px solid #f1f2f4; border-radius:5px; padding:10px;float:left">

		<ul style="padding:0px;margin:0px;width:100%; float:left">
		[% FOREACH koha_new IN kohanew_thuan %]
			<li style="list-style:none; width:100%; float:left;margin-bottom:5px;">
			<div class="thoigian" style="width:15%;float:left;">
				<h5 class="thang" style="text-align:center; width:100%;color:white; background:#e77052;margin:0px">[% koha_new.month %]</h5>
				<h5 class="ngay" style="text-align:center; width:100%;margin:0px">[% koha_new.day %]</h5>
			</div>
			<div class="tieudesk" style="width:70%;float:right; padding-right:10px;height:45px;overflow:hidden;">
				<a href="/cgi-bin/koha/opac-ctnews.pl?idnew=[% koha_new.idnew %]&idgroup=[% koha_new.idgroup %]">[% koha_new.title %]</a>
			</div>
				
			</li>
		[% END %]	
		</ul>
		
</div>