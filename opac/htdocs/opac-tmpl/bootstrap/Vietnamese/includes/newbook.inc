<div class="row-fluid">
	[% IF ( tong_sach ) %]
		<div id="sachmoi">
		<h3 class="title">Sách mới</h3>
		<div id="owl-sachmoi" class="owl-carousel">
		[% FOREACH sach IN sach_moi %]
						<div class="item">
						<div class="img-book">
						<a class="lbook" href="/cgi-bin/koha/opac-detail.pl?biblionumber=[% sach.biblionumber |url %]" title="sách">
						<img src="/cgi-bin/koha/opac-image.pl?thumbnail=1&amp;biblionumber= [% sach.biblionumber %]" alt="Owl Image" title="[% sach.title %]">
						</a>
						</div>
						<div class="title-book" style="position: absolute;">
							<a href="/cgi-bin/koha/opac-detail.pl?biblionumber=[% sach.biblionumber |url %]" title="[% sach.title %]">[% sach.title %]</a>
						</div>
						</div>
		[% END %]
						
		</div>
		</div>
		<script>
			$(document).ready(function() {
			  $("#owl-sachmoi").owlCarousel({
				autoPlay: 3000,
				itemsCustom : [
				[0, 3],
				[450, 3],
				[600, 4],
				[700, 5],
				[1000, 5],
				[1200, 5],
				[1400, 5],
				[1600, 5]
			  ],
			  navigation : true,
			  pagination : false,
			  
			  });
			});
		</script>
		[% END %]
</div>
<style>
	.title-book a{
		color:white;
	}
	
	
</style>