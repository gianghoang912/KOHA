 <div class="container-fluid footer">
     <div class="footer-NCB">
         <div class="container">
             <div class="main-footer">
                 <div class="col-xs-8 info-dl">
                     <div id="logo-bottom">
                         <h3>Thư viện Ngân hàng TMCP Quốc Dân - NCB</h3>
                     </div>
                     <div id="content-bottom">
                         <p>Thư viện Ngân hàng TMCP Quốc Dân – NCB hiện tại có hơn 10.000 đầu sách về nhiều lĩnh vực khác nhau như: Kinh tế - tài chính, chính trị, khoa học tự nhiên, xã hội học..</p>
                     </div>
                 </div>
                 <div class="col-xs-4 menu-bottom">
                     <div class="menu-bt1">
                         <a href="/cgi-bin/koha/opac-tangsach.pl?op=add">Tặng sách</a>
                         <a href="/cgi-bin/koha/opac-dv.pl">Dịch vụ</a>
                         <a href="https://www.ncb-bank.vn/vi/tin-tuc">Tin tức</a>
                     </div>
                     <div class="menu-bt2">
                         <a href="/cgi-bin/koha/opac-ctnews.pl?idnew=6&idgroup=4">Giới thiệu</a>
                         <a href="/cgi-bin/koha/opac-faq.pl">Hỏi đáp</a>
                         <a href="/cgi-bin/koha/opac-ctnews.pl?idnew=7&idgroup=4">Liên hệ</a>
                     </div>
                     <div class="menu-bt3">
                         <a href="#" target="_blank"><img src="../../opac-tmpl/bootstrap/images/dl/logoface.png"></a>
                         <a href="#"><img src="../../opac-tmpl/bootstrap/images/dl/logotwitter.png"></a>
                     </div>

                 </div>

             </div>
         </div>
     </div>
     <div class="footer-dl">
         <span style="color:white">© Bản quyền 2017 thuộc về Ngân Hàng Quốc Dân (NCB)</span>
     </div>
 </div>

[% UNLESS ( is_popup ) %]
 [% IF ( opaccredits ) %]
 <div class="container-fluid">
 <div class="row-fluid">
 <div class="span12">
 <div id="opaccredits">
 [% opaccredits %]
 </div>
 </div>
 </div>
 </div>
 [% END #/ opaccredits %]

 [% IF ( !OpacKohaUrl ) %]
 <div class="container-fluid">
 <div class="row-fluid">
 <div class="span12">
 <div id="koha_url" class="clearfix">
 <p>Được phát triển bởi [% IF template.name.match('opac-main.tt') %] <a class="koha_url" href="http://dlcorp.com.vn">D&L </a>
 [% ELSE %]
 <a class="koha_url" rel="nofollow" href="http://dlcorp.com.vn">D&L </a>
 [% END %]</p>
 </div>
 </div> <!-- /.span12 -->
 </div> <!-- /.row-fluid -->
 </div> <!-- /.container-fluid -->
 [% END # / OpacKohaUrl %]

</div> <!-- / #wrap in masthead.inc -->

 [% IF ( !opaclanguagesdisplay ) %]
 [% IF ( languages_loop && opaclanguagesdisplay ) %]
 [% UNLESS ( one_language_enabled ) %]
 <div id="changelanguage" class="navbar navbar-fixed-bottom navbar-static-bottom">
 <div class="navbar-inner">
 <ul id="i18nMenu" class="nav">
 <li><p class="lang navbar-text"><strong>Ngôn ngữ:&nbsp;</strong></p></li>
 [% FOREACH languages_loo IN languages_loop %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.plural ) %]
 <li class="dropdown">
 <a data-toggle="dropdown" class="dropdown-toggle sublangs" id="show[% languages_loo.rfc4646_subtag %]" href="#">[% IF ( languages_loo.native_description ) %][% languages_loo.native_description %][% ELSE %][% languages_loo.rfc4646_subtag %][% END %] <b class="caret"></b></a>
 <ul id="sub[% languages_loo.rfc4646_subtag %]" class="dropdown-menu">
 [% FOREACH sublanguages_loo IN languages_loo.sublanguages_loop %]
 [% IF ( sublanguages_loo.enabled ) %]
 [% IF ( sublanguages_loo.sublanguage_current ) %]
 <li> <p>[% sublanguages_loo.native_description %] [% sublanguages_loo.script_description %] [% sublanguages_loo.region_description %] [% sublanguages_loo.variant_description %] ([% sublanguages_loo.rfc4646_subtag %])</p></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/opac-changelanguage.pl?language=[% sublanguages_loo.rfc4646_subtag %]"> [% sublanguages_loo.native_description %] [% sublanguages_loo.script_description %] [% sublanguages_loo.region_description %] [% sublanguages_loo.variant_description %] ([% sublanguages_loo.rfc4646_subtag %])</a></li>
 [% END %]
 [% END # / IF sublanguages_loo.enabled %]
 [% END # / FOREACH sublanguages_loo %]
 </ul>
 </li> <!-- / .more -->
 [% ELSE %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.current ) %]
 <li class="active"><p class="navbar-text">[% IF ( languages_loo.native_description ) %][% languages_loo.native_description %][% ELSE %][% languages_loo.rfc4646_subtag %][% END %]</p></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/opac-changelanguage.pl?language=[% languages_loo.rfc4646_subtag %]">[% IF ( languages_loo.native_description ) %][% languages_loo.native_description %][% ELSE %][% languages_loo.rfc4646_subtag %][% END %]</a></li>
 [% END %]
 [% END # / IF languages_loo.current %]
 [% END # / IF ( languages_loo.plural ) %]
 [% END # / IF ( languages_loo.group_enabled ) %]
 [% END # / FOREACH languages_loo IN languages_loop %]
 </ul> <!-- / #i18menu -->
 </div> <!-- / .navbar-inner -->
 </div> <!-- / #changelanguage -->
 [% END # / UNLESS ( one_language_enabled ) %]
 [% END # / IF ( languages_loop && opaclanguagesdisplay ) %]
 [% END # / IF opaclanguagesdisplay %]
[% END # / UNLESS is_popup %]


<!-- JavaScript includes -->

<script type="text/javascript" src="[% interface %]/[% theme %]/lib/jquery/jquery-ui.js"></script>
<script type="text/javascript">
// Resolve name collision between jQuery UI and Twitter Bootstrap
$.widget.bridge('uitooltip', $.ui.tooltip);
</script>
<script type="text/javascript" src="[% interface %]/[% theme %]/lib/bootstrap/js/bootstrap.min.js"></script>
<script type="text/javascript" src="[% interface %]/[% theme %]/js/global.js"></script>
<script type="text/javascript">
    Modernizr.load([
        // Test need for polyfill
        {
            test: window.matchMedia,
            nope: "[% interface %]/[% theme %]/lib/media.match.min.js"
        },
        // and then load enquire
        "[% interface %]/[% theme %]/lib/enquire.min.js",
        "[% interface %]/[% theme %]/js/script.js"
    ]);
</script>
[% IF ( OPACAmazonCoverImages || SyndeticsCoverImages ) %]
<script type="text/javascript">//<![CDATA[
        var NO_AMAZON_IMAGE = _("Tài liệu không có ảnh bìa");
    //]]>
</script>
<script type="text/javascript" src="[% interface %]/[% theme %]/js/amazonimages.js"></script>
[% END %]

[% IF Koha.Preference( 'opacbookbag' ) == 1 %]<script type="text/javascript" src="[% interface %]/[% theme %]/js/basket.js">
[% ELSIF ( Koha.Preference( 'virtualshelves' ) == 1 ) %]<script type="text/javascript" src="[% interface %]/[% theme %]/js/basket.js">
[% ELSE %]<script type="text/javascript"> var readCookie;[% END %]
</script>

<script type="text/javascript">
    //<![CDATA[
    var MSG_CONFIRM_AGAIN = _("Cảnh báo: Hành động này không thể khôi phục lại. Xin xác nhận lại một lần nữa")
    var MSG_DELETE_SEARCH_HISTORY = _("Bạn chắc chắn muốn xóa lịch sử tìm kiếm của mình?");
    var MSG_NO_SUGGESTION_SELECTED = _("Bạn chưa chọn đề xuất mua");
    [% IF Koha.Preference( 'opacbookbag' ) == 1 or Koha.Preference( 'virtualshelves' ) == 1 %]
        var MSG_BASKET_EMPTY = _("Giỏ tài liệu đang trống");
        var MSG_RECORD_IN_BASKET = _("Tài liệu đã có trong giỏ tài liệu của bạn");
        var MSG_RECORD_ADDED = _("Tài liệu được thêm vào giỏ tài liệu của bạn");
        var MSG_RECORD_REMOVED = _("Tài liệu bị loại khỏi giỏ tài liệu của bạn");
        var MSG_NRECORDS_ADDED = _(" tài liệu đã được thêm vào giỏ tài liệu của bạn");
        var MSG_NRECORDS_IN_BASKET = _("đã có trong giỏ tài liệu của bạn");
        var MSG_NO_RECORD_SELECTED = _("Bạn chưa chọn bản tài liệu");
        var MSG_NO_RECORD_ADDED = _("Không có tài liệu được thêm vào giỏ tài liệu của bạn");
        var MSG_CONFIRM_DEL_BASKET = _("Bạn chắc chắn muốn xóa thông tin trong giỏ tài liệu?");
        var MSG_CONFIRM_DEL_RECORDS = _("Bạn chắc chắn muốn loại bỏ các tài liệu đã chọn?");
        var MSG_ITEM_IN_CART = _("Trong giỏ tài liệu");
        var MSG_IN_YOUR_CART = _("Tài liệu trong giỏ tài liệu của bạn: ");
        var MSG_ITEM_NOT_IN_CART = _("Thêm vào giỏ tài liệu");
        var MSG_NO_RECORD_SELECTED = _("Bạn chưa chọn bản tài liệu");
    [% END %]
    [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 ) && ( Koha.Preference( 'TagsEnabled' ) == 1 ) %]
        var MSG_TAGS_DISABLED = _("Xin lỗi, các từ khóa không được kích hoạt trong hệ thống của bạn.");
        var MSG_TAG_ALL_BAD = _("Lỗi! Từ khóa của bạn chứa ký tự không phù hợp. Bạn không thể tạo từ khóa  này. Bạn vui lòng thử lại với từ khóa khác.");
        var MSG_ILLEGAL_PARAMETER = _("Lỗi! Thông số không phù hợp");
        var MSG_TAG_SCRUBBED = _("Ghi chú: Từ khóa của bạn có chứa ký tự không phù hợp nên đã bị loại bỏ. Từ khóa đã được thêm như là ");
        var MSG_ADD_TAG_FAILED = _("Lỗi! Không thể tạo mới từ khóa");
        var MSG_ADD_TAG_FAILED_NOTE = _("Lưu ý: Bạn chỉ có thể thêm một từ khóa cho một tài liệu. Bạn vui lòng kiểm tra 'Từ khóa' để xem các từ khóa hiện tại của bạn.");
        var MSG_DELETE_TAG_FAILED = _("Lỗi! Bạn không thể xóa từ khóa");
        var MSG_DELETE_TAG_FAILED_NOTE = _("Lưu ý: Bạn chỉ được phép xóa các từ khóa bạn tạo ra.")
        var MSG_LOGIN_REQUIRED = _("Bạn phải đăng nhập để thêm từ khóa.");
        var MSG_TAGS_ADDED = _("Từ khóa đã nhập: ");
        var MSG_TAGS_DELETED = _("Từ khóa đã nhập: ");
        var MSG_TAGS_ERRORS = _("Lỗi: ");
        var MSG_MULTI_ADD_TAG_FAILED = _("Không thể thêm từ khóa nữa.");
        var MSG_NO_TAG_SPECIFIED = _("Không có từ khóa nào được khai báo.");
    [% END %]
    [% IF ( OPACAmazonCoverImages || SyndeticsCoverImages ) %]
        $(window).load(function() {
            verify_images();
         });
    [% END %]
    [% IF ( opacuserjs ) %][% opacuserjs %][% END %]
    //]]>
</script>
[% IF Koha.Preference( 'opacbookbag' ) == 1 %]
 <script type="text/javascript" src="[% interface %]/[% theme %]/js/basket.js"></script>
[% ELSIF ( Koha.Preference( 'virtualshelves' ) == 1 ) %]
 <script type="text/javascript" src="[% interface %]/[% theme %]/js/basket.js"></script>
[% ELSE %]
 <script type="text/javascript">var readCookie;</script>
[% END %]
[% IF Koha.Preference( 'opacuserlogin' ) == 1 %][% IF Koha.Preference( 'TagsEnabled' ) == 1 %]<script type="text/javascript" src="[% interface %]/[% theme %]/js/tags.js"></script>[% END %][% ELSE %][% END %]
[% IF ( GoogleJackets ) %]
 <script type="text/javascript" src="[% interface %]/[% theme %]/js/google-jackets.js"></script>
 <script type="text/javascript">
        //<![CDATA[
        var NO_GOOGLE_JACKET = _("Tài liệu không có ảnh bìa");
        //]]>
    </script>
[% END %]
[% IF OpenLibraryCovers %]
 <script type="text/javascript" src="[% interface %]/[% theme %]/js/openlibrary.js"></script>
 <script type="text/javascript">
    //<![CDATA[
    var NO_OL_JACKET = _("Tài liệu không có ảnh bìa");
    //]]>
    </script>
[% END %]

[% IF OPACLocalCoverImages %]
 <script type="text/javascript" src="[% interface %]/[% theme %]/js/localcovers.js"></script>
 <script type="text/javascript">
    //<![CDATA[
    var NO_LOCAL_JACKET = _("Tài liệu không có ảnh bìa");
    //]]>
    </script>
[% END %]

[% IF ( BakerTaylorEnabled ) %]
 <script type="text/javascript" src="[% interface %]/[% theme %]/js/bakertaylorimages.js"></script>
 <script type="text/javascript">
        //<![CDATA[
        var NO_BAKERTAYLOR_IMAGE = _("Tài liệu không có ảnh bìa");
        $(window).load(function(){
            bt_verify_images();
        });
        //]]>
    </script>
[% END %]
[% IF ( GoogleIndicTransliteration ) %]
 <script type="text/javascript" src="http://www.google.com/jsapi"></script>
 <script type="text/javascript" src="[% interface %]/[% theme %]/js/googleindictransliteration.js"></script>
[% END %]
[% IF persona %]
 <script src="https://login.persona.org/include.js"></script>
 <script type="text/javascript">

    navigator.id.watch({
        loggedInUser: [% IF emailaddress && loggedinpersona %]'[% emailaddress %]'[% ELSE %]null[% END %],
        onlogin: function (assertion) {
            $.post('/cgi-bin/koha/svc/login',
                { assertion: assertion },
                function (data) {
                    window.location = '/cgi-bin/koha/opac-user.pl';
                }
            )
            .fail(function() { var errstr = _("Không thể đăng nhập, có thể tài khoản Persona của bạn không được phép truy cập vào Koha");
                alert(errstr);
            });
        },
        onlogout: function () {
            window.location = '/cgi-bin/koha/opac-main.pl?logout.x=1';
        }
    });

    var signinLink = document.getElementById('browserid');

    if (signinLink) {
        signinLink.onclick = function(evt) {
            // Requests a signed identity assertion from the user.
            navigator.id.request({
                siteName: "[% LibraryName | html %]",
                returnTo: '/cgi-bin/koha/opac-user.pl',
                oncancel: function() { alert('user refuses to share identity.'); }
                });
            };
    }

    </script>
[% END #  / IF persona %]
[% PROCESS jsinclude %]
<script text="javascript">

		$(document).ready(function(){
			$("#clsss1").addClass("collapsed");
			$("#clsss2").addClass("collapsed");
			$("#clsss3").addClass("collapsed");
			$(".btn.btn-navbar.btn-nav1").click(function(){
				if($(".btn.btn-navbar.btn-user.collapsed").length){
					
				}else{
					$("#clsss2").click();
				}
				
				if($(".btn.btn-navbar.btn-cart.collapsed").length){
					
				}else{
					$("#clsss3").click();
				}
			});
			
			$(".btn.btn-navbar.btn-user").click(function(){
				if($(".btn.btn-navbar.btn-nav1.collapsed").length){
					
				}else{
					$("#clsss1").click();
				}
				
				if($(".btn.btn-navbar.btn-cart.collapsed").length){
					
				}else{
					$("#clsss3").click();
				}
			});
			$(".btn.btn-navbar.btn-cart").click(function(){
				if($(".btn.btn-navbar.btn-nav1.collapsed").length){
					
				}else{
					$("#clsss1").click();
				}
				
				if($(".btn.btn-navbar.btn-user.collapsed").length){
					
				}else{
					$("#clsss2").click();
				}
			});
		})
							
</script>
</body>
</html>
