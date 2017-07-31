#!/usr/bin/perl

# This file is part of Koha.
#
# Parts Copyright (C) 2013  Mark Tompsett
#
# Koha is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Koha is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Koha; if not, see <http://www.gnu.org/licenses>.


use Modern::Perl;
use CGI;
use C4::Auth;    # get_template_and_user
use C4::Output;
use C4::NewsChannels; # GetNewsToDisplay
use C4::Languages qw(getTranslatedLanguages accept_language);
use C4::Koha qw( GetDailyQuote );
use C4::Dates qw(format_date);
my $input = new CGI;
my $dbh   = C4::Context->dbh;

my ( $template, $borrowernumber, $cookie ) = get_template_and_user(
    {
        template_name   => "opac-chuyenmuc.tt",
        type            => "opac",
        query           => $input,
        authnotrequired => ( C4::Context->preference("OpacPublic") ? 1 : 0 ),
        flagsrequired   => { borrow => 1 },
    }
);

my $casAuthentication = C4::Context->preference('casAuthentication');
$template->param(
    casAuthentication   => $casAuthentication,
);

# display news
# use cookie setting for language, bug default to syspref if it's not set
my ($theme, $news_lang, $availablethemes) = C4::Templates::themelanguage(C4::Context->config('opachtdocs'),'opac-main.tt','opac',$input);

my $homebranch;
if (C4::Context->userenv) {
    $homebranch = C4::Context->userenv->{'branch'};
}

#lấy danh sách tin tức sắp diễn ra :)
my $thumuc   = &getTinTuc($news_lang,$homebranch,6,10);

my $all_koha_news   = &GetNewsToDisplay($news_lang,$homebranch,2);
my $koha_news_count = scalar @$all_koha_news;



my $thumuc_count = scalar @$thumuc;

my $quote = GetDailyQuote();   # other options are to pass in an exact quote id or select a random quote each pass... see perldoc C4::Koha

$template->param(
    koha_news           => $all_koha_news,
    thumucs           => $thumuc,
    thumuc_count     => $thumuc_count,
    display_daily_quote => C4::Context->preference('QuoteOfTheDay'),
    daily_quote         => $quote,
);

my $view_book = &ViewBookNew();
my $book_count = scalar @$view_book;
$template->param(
		sach_moi => $view_book,
		tong_sach => $book_count,
		);

		
#hàm xử lý chuyển chữ thành số
my $all_koha_news1   = &getTinTuc($news_lang,$homebranch,2,4);
my $koha_news_count1 = scalar @$all_koha_news1;



my @kohanew_thuan;
my @months = ("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec");
foreach my $row(@$all_koha_news1){
	my $day = substr($row->{newdate},0,2); # lấy tháng của thơi gian
	my $month= substr($row->{newdate},3,2); # lấy ngày của thời gian
	$month--;
	$month = $months[$month]; # chuyển tháng kiểu số thành kiểu chữ bằng việc lấy số trong mảng mảng ra 

	push @kohanew_thuan, 
	{
		idnew => $row->{idnew},
		title => $row->{title},
		new => $row->{new},
		day => $day,
		month => $month,
		newdate => $row->{newdate},
		idgroup => $row->{idgroup},
	}
}

$template->param(
		kohanew_thuan => \@kohanew_thuan,
		);


# If GoogleIndicTransliteration system preference is On Set paramter to load Google's javascript in OPAC search screens
if (C4::Context->preference('GoogleIndicTransliteration')) {
        $template->param('GoogleIndicTransliteration' => 1);
}

if (C4::Context->preference('OPACNumbersPreferPhrase')) {
        $template->param('numbersphr' => 1);
}

output_html_with_http_headers $input, $cookie, $template->output;
