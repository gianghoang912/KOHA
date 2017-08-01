[% USE Koha %]
<style>

	
</style>
<div id="wrap">
	<div class="navbar container">
	 <div class="navbar-inner">
		<ul class="nav">
            <li>
                <a href="#" id="cartmenuitem" class="cart-message" tabindex="-1" role="menuitem">Giỏ tài liệu của bạn trống</a>
            </li>
			<!--<li><a style="color:#15a1b1;" href="http://lirc.cep.edu.vn/" target="_blank">TRANG THÔNG TIN THƯ VIỆN</a></li>
			<li><a style="color:#15a1b1;" href="http://dlib.cep.edu.vn/" target="_blank">THƯ VIỆN SỐ</a></li>
			<li><a style="color:#15a1b1;" href="http://vufind.cep.edu.vn/" target="_blank">VUFIND</a></li>-->
		</ul>

		<ul class="nav pull-right">
[% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
		[% UNLESS ( loggedinusername ) %]
			[% IF Koha.Preference('casAuthentication') %]
				[%# CAS authentication is too complicated for modal window %]
					<li><a href="/cgi-bin/koha/opac-user.pl" style="margin-top:0px;"> Đăng nhập</a></li>
            [% ELSE %]
                    <li><a href="/cgi-bin/koha/opac-user.pl" style="margin-top:0px;  color:#15a1b1;" class="btn btn-thuan loginModal-trigger" role="button" data-toggle="modal"><i class="icon-user"></i> Đăng nhập</a></li>
            [% END %]
									
		[% END %]
									
		[% IF ( loggedinusername ) %]
            <li class="dropdown"><a style="color:#15a1b1;"  class="dropdown-toggle" data-toggle="dropdown" href="/cgi-bin/koha/opac-user.pl"><i class="icon-user"></i> [% FOREACH USER_INF IN USER_INFO %][% USER_INF.title %] [% USER_INF.surname %] [% USER_INF.firstname %] [% END %] <b class="caret"></b></a>
			<ul class="dropdown-menu">
										
		[% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
            [% UNLESS ( loggedinusername ) %]
                [% IF Koha.Preference('casAuthentication') %]
                [%# CAS authentication is too complicated for modal window %]
                    <li><a href="/cgi-bin/koha/opac-user.pl"> Đăng nhập</a></li>
                [% ELSE %]
                    <li><a href="/cgi-bin/koha/opac-user.pl" class="loginModal-trigger" role="button" data-toggle="modal"> Đăng nhập</a></li>
                [% END %]
            [% END %]
            [% IF ( loggedinusername ) %]
                    <li><a style="color:#15a1b1;" href="/cgi-bin/koha/opac-user.pl">Thông tin tài khoản</a></li>
            [% END %]
        [% END %]
        [% IF EnableOpacSearchHistory %]
                    <li><a style="color:#15a1b1;" href="/cgi-bin/koha/opac-search-history.pl" title="View your search history"> Lịch sử tìm kiếm</a></li>
        [% END %]
            [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
                [% IF ( loggedinusername ) %]
                    <li>
                       [% IF persona %]
                       <a class="logout" id="logout" href="/cgi-bin/koha/opac-main.pl?logout.x=1" onclick='navigator.id.logout();'>
                       [% ELSE %]
                        <a style="color:#15a1b1;" class="logout" id="logout" href="/cgi-bin/koha/opac-main.pl?logout.x=1">
                       [% END %]Đăng xuất</a>
                    </li>
                 [% END %]
            [% END %]			
			</ul>								
		</li>
                               
	[% END %]
							
[% END %]
            <li><a style="padding-left:0px ; padding-right:0px ; color:#15a1b1" href="/cgi-bin/koha/opac-changelanguage.pl?language=en">EN</a></li>
            <li><a style="padding-left:3px ; padding-right:3px ; color:#15a1b1 ">|</a></li>
            <li><a style="padding-left:0px; padding-right:20px; color:#15a1b1 " href="/cgi-bin/koha/opac-changelanguage.pl?language=Vietnamese">VN</a></li>

        </ul>
		</div>	
	</div> <!-- end intersite-nav -->


	<div class="header-banner">
		<div class="header-main">
			<div class="navbar navbar-inverse navbar-static-top container">
				<div class="navbar-inner">
					<div class="header-content row">

						<div class="col-xs-2">
						<a id="clsss1"  class="btn btn-navbar btn-nav1" data-toggle="collapse" data-target=".navbar-responsive-collapse"></a>
						<a id="clsss2"  class="btn btn-navbar btn-user" data-toggle="collapse" data-target=".navbar-responsive-user"></a>
						<!--<a class="btn btn-list" ></a>-->
						<a id="clsss3" id="cartmenulink"  class="btn btn-navbar btn-cart"  data-toggle="collapse" data-target=".navbar-responsive-cast"></a>


						<h1 id="logo">
							<a class="brand" href="/cgi-bin/koha/opac-main.pl"></a>
						</h1>
						</div>
						<div class="col-xs-10">
						   [% IF ( Koha.Preference( 'opacbookbag' ) == 1 ) %]
                        <div id="cartDetails" class="cart-message">Giỏ tài liệu của bạn trống.</div>
                    [% END %]
<!--						<div class="nav-collapse collapse navbar-responsive-user">-->
<!--							<ul class="nav  pull-right">-->
<!--							[% IF Koha.Preference( 'opacuserlogin' ) == 1 %]-->
<!--                                    [% UNLESS ( loggedinusername ) %]-->
<!--                                        [% IF Koha.Preference('casAuthentication') %]-->
<!--                                            [%# CAS authentication is too complicated for modal window %]-->
<!--                                            <li><a href="/cgi-bin/koha/opac-user.pl"> Đăng nhập</a></li>-->
<!--                                        [% ELSE %]-->
<!--                                            <li><a href="/cgi-bin/koha/opac-user.pl" class="loginModal-trigger" role="button" data-toggle="modal"> Đăng nhập</a></li>-->
<!--                                        [% END %]-->
<!--                                    [% END %]-->
<!--                                    [% IF ( loggedinusername ) %]-->
<!--                                        <li> <a href="/cgi-bin/koha/opac-user.pl">Xin chào: <span class="loggedinusername">[% FOREACH USER_INF IN USER_INFO %][% USER_INF.title %] [% USER_INF.surname %] [% USER_INF.firstname %] [% END %]</span></a></li>-->
<!--                                    -->
<!--                                    [% END %]-->
<!--                                [% END %]-->
<!--							[% IF EnableOpacSearchHistory %]-->
<!--								<li><a href="/cgi-bin/koha/opac-search-history.pl" title="View your search history"> Lịch sử tìm kiếm</a> </li>-->
<!--								<li>-->
<!--								<a class="logout" href="/cgi-bin/koha/opac-search-history.pl?action=delete" title="Delete your search history" onclick="return confirm(MSG_DELETE_SEARCH_HISTORY);">Xóa lịch sử tìm kiếm</a></li>-->
<!--							[% END %]-->
<!--							</ul>-->
<!--						</div>-->

						<div class="nav-collapse collapse navbar-responsive-collapse">
							<ul class="nav  pull-right">

								  <li>
								  <a href="/cgi-bin/koha/opac-tangsach.pl?op=add">
									<center>
										<div class="links-menu pull-left">
											<img src="../../opac-tmpl/bootstrap/images/dl/icon_menu/tangsach.png" title="Tặng sách" alt="Tặng sách">
										</div>
										<div class="title pull-right">Tặng sách</div>
									</center>
								  </a>
								  </li>

								  <li>
								  <a href="/cgi-bin/koha/opac-dv.pl">
									<center>
										<div class="links-menu pull-left">
											<img src="../../opac-tmpl/bootstrap/images/dl/icon_menu/dichvu.png" title="Dịch vụ" alt="Dịch vụ">
										</div>
										<div class="title pull-right">Dịch vụ</div>
									</center>
								  </a>
								</li>

								  <li>
								  <a href="https://www.ncb-bank.vn/vi/tin-tuc" target="_blank" >
									<center>
										<div class="links-menu pull-left">
											<img src="../../opac-tmpl/bootstrap/images/dl/icon_menu/tintuc.png" title="Tin tức" alt="Tin tức">
										</div>
										<div class="title pull-right">Tin tức</div>
									</center>
								  </a>
								  </li>

								  <li>
								  <a href="/cgi-bin/koha/opac-faq.pl">
									<center>
										<div class="links-menu pull-left">
											<img src="../../opac-tmpl/bootstrap/images/dl/icon_menu/faq.png" title="Hỏi đáp" alt="Hỏi đáp">
										</div>
										<div class="title pull-right">Hỏi đáp</div>
									</center>
								  </a>
								  </li>

								   <li>
								  <a href="/cgi-bin/koha/opac-ctnews.pl?idnew=7&idgroup=4">
									<center>
										<div class="links-menu pull-left">
											<img src="../../opac-tmpl/bootstrap/images/dl/icon_menu/lienhe.png" title="Liên hệ" alt="Liên hệ">
										</div>
										<div class="title pull-right">Liên hệ</div>
									</center>
								  </a>
								  </li>

							</ul>

							<ul class="nav pull-right cls-mobi" style="display:none">

								<li><a href="/cgi-bin/koha/opac-shelves.pl"> Giá sách ảo</a></li>
								<!--<li><a href="/cgi-bin/koha/opac-z3950.pl"> Tìm kiếm Z39.50</a></li>-->
								<li><a href="/cgi-bin/koha/opac-search.pl"> Tìm kiếm nâng cao</a></li>
                                    [% IF ( Koha.Preference( 'UseCourseReserves' ) == 1 ) %]<li><a href="/cgi-bin/koha/opac-course-reserves.pl"> CSDL Khóa học</a></li>[% END %]
                                    [% IF Koha.Preference( 'OpacBrowser' ) == 1 %]<li><a href="/cgi-bin/koha/opac-browser.pl">Tìm kiếm phân cấp</a></li>[% END %]
                                    [% IF Koha.Preference( 'OpacAuthorities' ) == 1 %]<li><a href="/cgi-bin/koha/opac-authorities-home.pl"> Tìm dữ liệu kiểm soát</a></li>[% END %]
                                    [% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && ( Koha.Preference( 'reviewson' ) == 1 ) && ( Koha.Preference( 'OpacShowRecentComments' ) == 1 ) ) %]<li><a href="/cgi-bin/koha/opac-showreviews.pl"> Bình luận mới nhất</a></li>[% END %]
                                    [% IF Koha.Preference( 'TagsEnabled' ) == 1 %]<li><a href="/cgi-bin/koha/opac-tags.pl"> Mây Tag</a></li>[% END %]
                                    [% IF Koha.Preference( 'OpacCloud' ) == 1 %]<li><a href="/cgi-bin/koha/opac-tags_subject.pl"> Mây chủ đề</a></li>[% END %]
                                    [% IF Koha.Preference( 'OpacTopissue' ) == 1 %]<li><a href="/cgi-bin/koha/opac-topissues.pl"> Mượn nhiều nhất</a></li>[% END %]
                                    [% IF Koha.Preference( 'suggestion' ) == 1 %]
                                        [% IF Koha.Preference( 'AnonSuggestions' ) == 1 %]
                                            <li><a href="/cgi-bin/koha/opac-suggestions.pl"> Đề xuất mua</a></li>
                                        [% ELSIF ( ( Koha.Preference( 'OPACViewOthersSuggestions' ) == 1 ) ) %]
                                            <li><a href="/cgi-bin/koha/opac-suggestions.pl"> Đề xuất mua</a></li>
                                        [% END %]
                                    [% END %]
							</ul>
						</div> <!-- end nav-collapse -->
						</div><!-- end span7-->
					</div>
				</div><!-- end navbar-inner-->
			</div><!-- end navbar-->
		</div>
        <div class="main-search-menu header-search">
            <div class="main-search container">
                <div class="row">
                    <form name="searchform" method="get" action="/cgi-bin/koha/opac-search.pl" id="searchform" class="form-inline">

                        [% UNLESS ( Koha.Preference( 'OpacAddMastheadLibraryPulldown' ) == 1 ) %]
                        <div class="input-append ">
                            <select class="col-xs-3" name="idx" id="masthead_search">
                                [% IF ( ms_kw ) %]
                                <option selected="selected" value="">Từ khóa bất kỳ</option>
                                [% ELSE %]
                                <option value="">Tìm kiếm chung</option>
                                [% END # /ms_kw %]
                                [% IF ( ms_ti ) %]
                                <option selected="selected" value="ti">Nhan đề</option>
                                [% ELSE %]
                                <option value="ti">Nhan đề</option>
                                [% END # /ms_ti %]
                                [% IF ( ms_au ) %]
                                <option selected="selected" value="au">Tác giả</option>
                                [% ELSE %]
                                <option value="au">Tác giả</option>
                                [% END # /ms_au%]
                                [% IF ( ms_su ) %]
                                <option selected="selected" value="su">Chủ đề</option>
                                [% ELSE %]
                                <option value="su"> Chủ đề</option>
                                [% END # /ms_su %]
                                [% IF ( ms_nb ) %]
                                <option selected="selected" value="nb"> Số ISBN</option>
                                [% ELSE %]
                                <option value="nb"> Số ISBN</option>
                                [% END # /ms_nb%]
                                [% IF ( ms_se ) %]
                                <option selected="selected" value="se"> Tùng thư</option>
                                [% ELSE %]
                                <option value="se"> Tùng thư</option>
                                [% END # /ms_se %]
                                [% IF ( numbersphr ) %]
                                [% IF ( ms_callnum ) %]
                                <option selected="selected" value="callnum,phr"> Ký hiệu phân loại</option>
                                [% ELSE %]
                                <option value="callnum,phr"> Ký hiệu phân loại</option>
                                [% END #/ms_callnum %]
                                [% ELSE %]
                                [% IF ( ms_callnum ) %]
                                <option selected="selected" value="callnum">Ký hiệu phân loại</option>
                                [% ELSE %]
                                <option value="callnum">Ký hiệu phân loại</option>
                                [% END # /ms_callnum %]
                                [% END # /numbersphr %]
                            </select>
                            [% END %]
                            [% IF ( ms_value ) %]
                            <input class="col-xs-7" type="text" title="Nhập thuật ngữ tìm kiếm" class="transl1" id = "translControl1" name="q" value="[% ms_value |html %]" /><span id="translControl"></span>
                            [% ELSE %]
                            <input class="col-xs-7" type="text" title="Nhập thuật ngữ tìm kiếm" class="transl1" id = "translControl1" name="q" /><span id="translControl"></span>
                            [% END # /ms_value %]

                            [% UNLESS ( Koha.Preference( 'OpacAddMastheadLibraryPulldown' ) == 1 ) %]
                            <button type="submit" id="searchsubmit" class="">Tìm kiếm</button>
                            <ul class="ul1">
                                <li class="li1"><a class="menu-duoi" href=""></a>
                                    <ul>
                                        <li><a href="/cgi-bin/koha/opac-shelves.pl"> Giá sách ảo</a></li>
                                        <!--<li><a href="/cgi-bin/koha/opac-z3950.pl"> Tìm kiếm Z39.50</a></li>-->
                                        <li><a href="/cgi-bin/koha/opac-search.pl"> Tìm kiếm nâng cao</a></li>
                                        [% IF ( Koha.Preference( 'UseCourseReserves' ) == 1 ) %]<li><a href="/cgi-bin/koha/opac-course-reserves.pl"> CSDL Khóa học</a></li>[% END %]
                                        [% IF Koha.Preference( 'OpacBrowser' ) == 1 %]<li><a href="/cgi-bin/koha/opac-browser.pl">Tìm kiếm phân cấp</a></li>[% END %]
                                        [% IF Koha.Preference( 'OpacAuthorities' ) == 1 %]<li><a href="/cgi-bin/koha/opac-authorities-home.pl"> Tìm dữ liệu kiểm soát</a></li>[% END %]
                                        [% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && ( Koha.Preference( 'reviewson' ) == 1 ) && ( Koha.Preference( 'OpacShowRecentComments' ) == 1 ) ) %]<li><a href="/cgi-bin/koha/opac-showreviews.pl"> Bình luận mới nhất</a></li>[% END %]
                                        [% IF Koha.Preference( 'TagsEnabled' ) == 1 %]<li><a href="/cgi-bin/koha/opac-tags.pl"> Mây Tag</a></li>[% END %]
                                        [% IF Koha.Preference( 'OpacCloud' ) == 1 %]<li><a href="/cgi-bin/koha/opac-tags_subject.pl"> Mây chủ đề</a></li>[% END %]
                                        [% IF Koha.Preference( 'OpacTopissue' ) == 1 %]<li><a href="/cgi-bin/koha/opac-topissues.pl"> Mượn nhiều nhất</a></li>[% END %]
                                        [% IF Koha.Preference( 'suggestion' ) == 1 %]
                                        [% IF Koha.Preference( 'AnonSuggestions' ) == 1 %]
                                        <li><a href="/cgi-bin/koha/opac-suggestions.pl"> Đề xuất mua</a></li>
                                        [% ELSIF ( ( Koha.Preference( 'OPACViewOthersSuggestions' ) == 1 ) ) %]
                                        <li><a href="/cgi-bin/koha/opac-suggestions.pl"> Đề xuất mua</a></li>
                                        [% END %]
                                        [% END %]


                                    </ul>
                                </li>
                                <!--
                                <li class="li1">
                                    <a href="" class="menu-cart" id="cartmenulink"><span id="basketcount"></span></a>
                                    <ul aria-labelledby="cartmenulink" class="cls-cartmenulink">
                                    <li role="presentation">
                                        <a href="#" id="cartmenuitem" class="cart-message" tabindex="-1" role="menuitem">Giỏ tài liệu của bạn trống.</a>
                                    </li>
                                    </ul>

                                </li>
                                -->
                                <!--
                                [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]

                                    [% UNLESS ( loggedinusername ) %]
                                        [% IF Koha.Preference('casAuthentication') %]
                                            [%# CAS authentication is too complicated for modal window %]
                                            <li class="li1 last"><a class="btn btn-thuan" href="/cgi-bin/koha/opac-user.pl"> Đăng nhập</a></li>
                                        [% ELSE %]
                                            <li class="li1 last"><a href="/cgi-bin/koha/opac-user.pl" class="btn btn-thuan loginModal-trigger" role="button" data-toggle="modal"><i class="icon-user"></i> Đăng nhập</a></li>
                                        [% END %]

                                    [% END %]

                                    [% IF ( loggedinusername ) %]
                                        <li class="li1 last"><a class="btn btn-thuan" href="/cgi-bin/koha/opac-user.pl"><i class="icon-user"></i> [% FOREACH USER_INF IN USER_INFO %][% USER_INF.title %] [% USER_INF.surname %] [% USER_INF.firstname %] [% END %]</a>
                                        <ul>

                                        [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
                                    [% UNLESS ( loggedinusername ) %]
                                        [% IF Koha.Preference('casAuthentication') %]
                                            [%# CAS authentication is too complicated for modal window %]
                                            <li><a href="/cgi-bin/koha/opac-user.pl"> Đăng nhập</a></li>
                                        [% ELSE %]
                                            <li><a href="/cgi-bin/koha/opac-user.pl" class="loginModal-trigger" role="button" data-toggle="modal"> Đăng nhập</a></li>
                                        [% END %]
                                    [% END %]
                                    [% IF ( loggedinusername ) %]
                                        <li><p class="members navbar-text">Xin chào, <a href="/cgi-bin/koha/opac-user.pl"><span class="loggedinusername">[% FOREACH USER_INF IN USER_INFO %][% USER_INF.title %] [% USER_INF.surname %] [% USER_INF.firstname %] [% END %]</span></a></p></li>
                                        <li class="divider-vertical"></li>
                                    [% END %]
                                [% END %]
                                [% IF EnableOpacSearchHistory %]
                                    <li><p class="navbar-text"><a href="/cgi-bin/koha/opac-search-history.pl" title="View your search history"> Lịch sử tìm kiếm</a> [<a class="logout" href="/cgi-bin/koha/opac-search-history.pl?action=delete" title="Delete your search history" onclick="return confirm(MSG_DELETE_SEARCH_HISTORY);">x</a>]</p></li>
                                    <li class="divider-vertical"></li>
                                [% END %]
                                [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
                                    [% IF ( loggedinusername ) %]
                                        <li><p class="navbar-text">
                                            [% IF persona %]
                                                <a class="logout" id="logout" href="/cgi-bin/koha/opac-main.pl?logout.x=1" onclick='navigator.id.logout();'>
                                            [% ELSE %]
                                                <a class="logout" id="logout" href="/cgi-bin/koha/opac-main.pl?logout.x=1">
                                            [% END %]
                                            Đăng xuất</a></p></li>
                                    [% END %]
                                [% END %]

                                        </ul>

                                        </li>

                                    [% END %]

                                [% END %]
                                -->
                            </ul>

                        </div>
                        [% END %]

                    </form>
                </div>
            </div>

        </div>
	</div>

	    <div id="loginModal" class="modal hide" tabindex="-1" role="dialog" aria-labelledby="modalLoginLabel" aria-hidden="true">
        <div class="modal-header">
            <button type="button" class="closebtn" data-dismiss="modal" aria-hidden="true">×</button>
            <h3 id="modalLoginLabel" style="color:#a397c5"> Đăng Nhập</h3>
        </div>
        <form action="/cgi-bin/koha/opac-user.pl" method="post" name="auth" id="modalAuth">
            <div class="modal-body">
                    [% IF ( shibbolethAuthentication ) %]
                    [% IF ( invalidShibLogin ) %]
                    <!-- This is what is displayed if shibboleth login has failed to match a koha user -->
                    <div class="alert alert-info">
                        <p> Xin lỗi, tài khoản Shibboleth của bạn không chính xác. Nếu bạn có tài khoản thư viện, bạn có thể sử dụng tài khoản đó.</p>
                    </div>
                    [% ELSE %]
                    <h4>Đăng nhập Shibboleth</h4>
                    <p>Nếu bạn có tài khoản Shibboleth, vui lòng <a href="[% shibbolethLoginUrl %]">click vào đây để đăng nhập</a>.</p>
                    <h4>Tài khoản thư viện</h4>
                    [% END %]
            [% END %]
                    <input type="hidden" name="koha_login_context" value="opac" />
                    <fieldset class="brief" style="width:200px;margin:0px auto;">
                        <label for="muserid">Tên đăng nhập:</label><input type="text" id="muserid" name="userid" />
                        <label for="mpassword"> Mật khẩu:</label><input type="password" id="mpassword"  name="password" />
                    [% IF Koha.Preference( 'NoLoginInstructions' ) %]
                        <div id="nologininstructions-modal">
                            [% Koha.Preference( 'NoLoginInstructions' ) %]
                        </div>
                    [% END %]
                        
                    </fieldset>
            </div>
            <div class="modal-footer">
                <input type="submit" class="btn btn-success" value="Đăng Nhập" />
				[% IF PatronSelfRegistration && PatronSelfRegistrationDefaultCategory %]
				<a href="/cgi-bin/koha/opac-memberentry.pl" style="text-decoration:none;"> Đăng ký.</a>[% END %]
				
				<!--
                <a href="#" data-dismiss="modal" aria-hidden="true" class="cancel"> Hủy bỏ</a>-->
            </div>
        </form> <!-- /#auth -->
    </div>  <!-- /#modalAuth  -->
