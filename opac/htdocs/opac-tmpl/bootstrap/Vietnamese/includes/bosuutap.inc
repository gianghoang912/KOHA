<style>
.hover-circle {
	margin-right: 5px;
	position: relative;
}

.hover-circle, .hover-circle img {
	width: 107px;
	height: 107px;
}

.hover-circle img {
	position: absolute;
	width: 100%;
	height: 100%;
	left:0px;
}

.anhdung p {

 
	color:#fff;
	text-align:center;
	font-site:12px;
	}
.anhdung a { text-decoration:none}
.anhdung #ad {
	
	font-size: 12px;
	letter-spacing: 0px;
	font-weight:bold
}

.effect1 .overlay {
	background-color: rgba(120, 55, 18, 0.102);
	
	box-shadow: 0px 0px 0px 20px rgba(242, 242, 242, 0.196) inset, 0px 0px 3px rgba(100, 100, 100, 0.600), 0px 0px 0px 0px rgba(250, 86, 9, 0.9) inset;
	-webkit-box-shadow: 0px 0px 0px 20px rgba(242, 242, 242, 0.196) inset, 0px 0px 3px rgba(100, 100, 100, 0.600), 0px 0px 0px 0px rgba(231, 144, 50, 0.9) inset;
	position: absolute;
	transition: box-shadow 0.3s linear;
	-webkit-transition: box-shadow 0.3s linear;
	width: 100%;
	height: 100%;
	z-index: 1;
	color: #fff;
}


.effect1 .overlay .anhdung {
	font-family: "Tahoma";
	width: 100%;
	height: 100%;
	display: block;
	transform: scale(0);
	transition: all 0.3s linear;
	-webkit-transform: scale(0);
	-webkit-transition: all 0.3s linear;
	
}

.effect1:hover .overlay .anhdung {
	transform: scale(1);
	-webkit-transform: scale(1);
}

.effect1:hover .overlay {
	box-shadow: 0px 0px 0px 20px rgba(242, 242, 242, 0.196) inset, 0px 0px 3px rgba(100, 100, 100, 0.600), 0px 0px 0px 140px rgba(250, 86, 9, 0.9) inset;
	-webkit-box-shadow: 0px 0px 0px 20px rgba(242, 242, 242, 0.196) inset, 0px 0px 3px rgba(100, 100, 100, 0.600), 0px 0px 0px 140px rgba(250, 86, 9, 0.9) inset;
}

.bst ul li { list-style:none; float:left; margin-top:5px}
.center { margin:0px; padding:0px}

</style>




<div class="span6 bst" style=" margin-left:0px">
		<h3>Bộ sưu tập nổi bật</h3>
		
		<ul class="center">
		<li>
		<div class="hover-circle effect1">			
			<div class="overlay">
			<div class="anhdung">
				<a href="/cgi-bin/koha/opac-chuyenmuc.pl">					
					<p id="ad"><br>Bộ sưu tập tổng hợp<br></p></a>
				</div>
			</div>
			<a href="/cgi-bin/koha/opac-chuyenmuc.pl"><img src="../../opac-tmpl/bootstrap/images/bosuutap/thumucchuyende.jpg" /></a>
		</div>					
		</li>
				
		[% FOREACH bst IN bosuutap %]
		<li>
		<div class="hover-circle effect1">			
			<div class="overlay">
			<div class="anhdung">
				<a href="/cgi-bin/koha/opac-shelves.pl?viewshelf=[% bst.shelfnumber %]">					
					<p id="ad"><br>[% bst.shelfname %]<br></p></a>
				</div>
			</div>
			<a href="/cgi-bin/koha/opac-shelves.pl?viewshelf=[% bst.shelfnumber %]"><img src="../../opac-tmpl/bootstrap/images/bosuutap/[% bst.img %]" /></a>
		</div>
		</li>
		[% END %]
		</ul>
		
		
		

	 
</div>