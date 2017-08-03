<style>

.center { margin:0px; padding:0px}

</style>

<div class="row-fluid bst" style=" margin-left:0px">
		<h3 class="title">Bộ sưu tập nổi bật</h3>
		
		<ul class="row">
		<li class="col-xs-3">
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
		<li class="col-xs-3">
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