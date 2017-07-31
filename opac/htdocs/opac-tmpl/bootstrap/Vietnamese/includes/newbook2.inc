<div class="row-fluid">
	[% IF ( tong_sach ) %]
		<div id="sachmoi">
		<h3 class="bg_title">Sách mới</h3>
		<div id="owl-sachmoi" class="owl-carousel">
		[% FOREACH sach IN sach_moi %]
						<div class="item">
						<div class="img-book">
						<a class="lbook" href="/cgi-bin/koha/opac-detail.pl?biblionumber=[% sach.biblionumber |url %]" title="sách">
						<img src="/cgi-bin/koha/opac-image.pl?thumbnail=1&amp;biblionumber= [% sach.biblionumber %]" alt="Owl Image" title="[% sach.title %]">
						</a>
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
				[0, 2],
				[450, 3],
				[600, 4],
				[700, 5],
				[1000, 5],
				[1200, 5],
				[1400, 5],
				[1600, 5]
			  ],
			  navigation : true,
			  pagination : true
			  });
			});
		</script>
		[% END %]
</div>
<style>
	.title-book a{
		color:white;
		font-weight:bold
		font-size:12px
		
	}
	/*newbook*/
.titlesm, .titlebst, .titledv{
	display:flex;
	margin-left:10px;
	padding-top:10px;	
}
.titlesm h3, .titlebst h3, .titledv h3{
	margin:0px;
	padding:10px;
}
#sachmoi, #bosuutap, #dichvu{

	border-bottom:1px solid #d7d7d7;
}
#owl-sachmoi{

	padding-left:10px;
	padding-right:0px;
}

#owl-sachmoi .owl-wrapper-outer{
	width:100%;
}

#owl-sachmoi .item{
	padding:10px 10px 0px 0px;
	margin-left:10px;
}
#owl-sachmoi .item .img-book{
	width:100px;
	height:145px;
	
}
#owl-sachmoi .item .img-book a img{
	width:100px;
	height:145px;
	background:transparent url(../../images/dl/sachmoi.jpg) no-repeat scroll 0%;
}
#owl-sachmoi .item .title-book{
	height:28px;
	width:90px;
	padding-top:5px;
	padding-bottom:10px;
	background:rgba(93, 101, 184, 0.65);
	padding-left:5px;
	padding-right:5px;
	overflow: hidden;
	
}

#owl-sachmoi .item .title-book a{
	text-decoration:none; text-align:center; font-weight:bold; font-size:11px
}

.owl-buttons{
	position:relative;
	
}
.owl-theme .owl-controls .owl-buttons div.owl-prev{
	position:absolute;
	top:-105px;
	left:-7px;
	width:10px;
	height:25px;
	background:transparent url(../../images/dl/prev.png) no-repeat scroll 0%;
	opacity:0.2;
}
.owl-theme .owl-controls .owl-buttons div.owl-next{
	position:absolute;
	top:-105px;
	right:19px;
	width:10px;
	height:25px;
	background:transparent url(../../images/dl/next.png) no-repeat scroll 0%;
	opacity:0.2;
}	
.owl-item { width:120px}	
</style>