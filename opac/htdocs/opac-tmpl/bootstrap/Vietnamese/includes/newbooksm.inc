
	[% IF ( tong_sach ) %]
		<h4>Sách mới</h4>
		<div id="owl-sachmoi" class="owl-carousel" style="border:10px solid #f1f2f4; border-radius:5px; padding:10px;float:left">
		[% FOREACH sach IN sach_moi %]
						<div class="item">
						<div class="img-book">
						<a class="lbook" href="/cgi-bin/koha/opac-detail.pl?biblionumber=[% sach.biblionumber |url %]" title="sách">
						<img src="/cgi-bin/koha/opac-image.pl?thumbnail=1&amp;biblionumber= [% sach.biblionumber %]" alt="Owl Image" title="[% sach.title %]">
						</a>
						</div>
						<div class="title-book" style="position: absolute; top: 113px;">
							<a href="/cgi-bin/koha/opac-detail.pl?biblionumber=[% sach.biblionumber |url %]" title="[% sach.title %]">[% sach.title %]</a>
						</div>
						</div>
		[% END %]
						
		</div>
		<script>
			$(document).ready(function() {
			  $("#owl-sachmoi").owlCarousel({
				autoPlay: 3000,
				itemsCustom : [
				[0, 2],
				[450, 3],
				[600, 3],
				[767, 4],
				[1000, 1],
				[1200, 1],
				[1400, 1],
				[1600, 1]
			  ],
			  navigation : true,
			  pagination : false
			  });
			});
		</script>
		[% END %]
		
		<style>
			@media (min-width: 768px){
				.item .img-book{
					margin-left:40px;
				}
				.item .title-book{
					margin-left:40px;
				}
			}
			#owl-sachmoi{
				width:194px !important;
			}
			.owl-theme .owl-controls .owl-buttons div.owl-next{
				right:0;
			}
			.title-book a{
				font-size:12px;
				color:white;
				lin
			}
		</style>