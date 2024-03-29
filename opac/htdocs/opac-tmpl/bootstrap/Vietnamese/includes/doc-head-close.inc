</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="generator" content="Koha [% Version %]" /> <!-- leave this for stats -->
<meta name="viewport" content="width=device-width, initial-scale=1" />
<link rel="shortcut icon" href="[% IF ( OpacFavicon ) %][% OpacFavicon %][% ELSE %][% interface %]/[% theme %]/images/favicon.ico[% END %]" type="image/x-icon" />
[% IF ( bidi ) %]
    <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/lib/bootstrap/css/bootstrap-rtl.min.css" />
[% ELSE %]
    <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/lib/bootstrap/css/bootstrap.css" />
[% END %]

[% IF ( bidi ) %]
    <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/lib/jquery/jquery-ui-rtl.css" />
[% ELSE %]
    <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/lib/jquery/jquery-ui.css" />
[% END %]

[% SET opaclayoutstylesheet='opac.css' UNLESS opaclayoutstylesheet %]
[% IF (opaclayoutstylesheet.match('^https?:|^\/')) %]
    <link rel="stylesheet" type="text/css" href="[% opaclayoutstylesheet %]" />
[% ELSE %]
    <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/css/[% opaclayoutstylesheet %]" />
[% END %]
[% IF ( opaccolorstylesheet ) %]
    [% IF (opaccolorstylesheet.match('^https?:|^\/')) %]
        <link rel="stylesheet" type="text/css" href="[% opaccolorstylesheet %]" />
    [% ELSE %]
        <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/css/[% opaccolorstylesheet %]" />
    [% END %]
[% END %]
[% IF ( opac_css_override ) %]
    <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/css/[% opac_css_override %]" />
[% END %]
<link rel="stylesheet" type="text/css" media="print" href="[% interface %]/[% theme %]/css/print.css" />
[% IF persona %]
 <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/css/persona-buttons.css" />
[% END %]
[% IF ( bidi ) %]
    <link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/css/right-to-left.css" />
[% END %]
[% IF ( OPACUserCSS ) %]<style type="text/css">[% OPACUserCSS %]</style>[% END %]
<link rel="unapi-server" type="application/xml" title="unAPI" href="[% OPACBaseURL %]/cgi-bin/koha/unapi" />
[% PROCESS cssinclude %]
<!-- Respond.js brings responsive layout behavior to IE < v.9 -->
<!--[if lt IE 9]>
    <script src="[% interface %]/[% theme %]/lib/respond.min.js"></script>
<![endif]-->
<script type="text/javascript">
    function _(s) { return s } // dummy function for gettext
</script>
<script type="text/javascript" src="[% interface %]/[% theme %]/lib/modernizr.min.js"></script>


<script type="text/javascript" src="[% interface %]/[% theme %]/lib/jquery/jquery.js"></script>


<script type="text/javascript" src="[% themelang %]/lib/owl-carousel/owl.carousel.js"></script>
<link rel="stylesheet" type="text/css" href="[% themelang %]/lib/owl-carousel/owl.theme.css" />
<link rel="stylesheet" type="text/css" href="[% themelang %]/lib/owl-carousel/owl.carousel.css" />


<script type="text/javascript" src="[% themelang %]/lib/owl-carousel/jquery.totemticker.js"></script>

<link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/css/dl/dl.style.css" />
<link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/css/dl/dl.responsive.style.css" />
<link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/css/dl/dl.bootstrapGridSystem.style.css" />
<script type="text/javascript" src="[% interface %]/[% theme %]/lib/jquery/jquery-ui.js"></script>