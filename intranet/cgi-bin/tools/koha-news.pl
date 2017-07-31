#!/usr/bin/perl

# This file is part of Koha.
#
# Script to manage the opac news.
# written 11/04
# Casta�eda, Carlos Sebastian - seba3c@yahoo.com.ar - Physics Library UNLP Argentina
# Modified to include news to KOHA intranet - tgarip@neu.edu.tr NEU library -Cyprus
# Copyright 2000-2002 Katipo Communications
# Copyright (C) 2013    Mark Tompsett
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

use strict;
# use warnings; FIXME - Bug 2505
use CGI;
use C4::Auth;
use C4::Koha;
use C4::Context;
use C4::Dates qw(format_date_in_iso);
use C4::Output;
use C4::NewsChannels;
use C4::Languages qw(getTranslatedLanguages);
use Date::Calc qw/Date_to_Days Today/;
use C4::Branch qw/GetBranches/;
use CGI::Carp qw/fatalsToBrowser/;
use File::Basename;
 
$CGI::POST_MAX = 1024 * 5000; #adjust as needed (1024 * 5000 = 5MB)
$CGI::DISABLE_UPLOADS = 0; #1 disables uploads, 0 enables uploads

my $cgi = new CGI;

my $id             = $cgi->param('id');
my $idgroup		   = $cgi->param('idgroup');
my $title          = $cgi->param('title');
my $sub 		   = $cgi->param('sub');
my $new            = $cgi->param('new');
my $expirationdate = format_date_in_iso($cgi->param('expirationdate'));
my $timestamp      = format_date_in_iso($cgi->param('timestamp'));
my $number         = $cgi->param('number');
my $lang           = $cgi->param('lang');
my $branchcode     = $cgi->param('branch');
my $img	= $cgi->param('img') or "huythuandeptrai";
my $upload_dir = '../../../opac/htdocs/opac-tmpl/bootstrap/images/news';
my $filename_characters = 'a-zA-Z0-9_.-';
my $upload_filehandle = $cgi->upload("img");
# Foreign Key constraints work with NULL, not ''
# NULL = All branches.
$branchcode = undef if (defined($branchcode) && $branchcode eq '');
my $new_detail = get_opac_new($id);

my ( $template, $borrowernumber, $cookie ) = get_template_and_user(
    {
        template_name   => "tools/koha-news.tt",
        query           => $cgi,
        type            => "intranet",
        authnotrequired => 0,
        flagsrequired   => { tools => 'edit_news' },
        debug           => 1,
    }
);

# get lang list
my @lang_list;
my $tlangs = getTranslatedLanguages() ;
foreach my $language ( @$tlangs ) {
    push @lang_list,
      {
        language => $language->{'rfc4646_subtag'},
        selected => ( $new_detail->{lang} eq $language->{'rfc4646_subtag'} ? 1 : 0 ),
      };
}
#doan them boi vohuythuan
sub LoadNewsGroup{
		my $dbh = C4::Context->dbh;
		my $query = "Select * from newsgroup";
		my $sth = $dbh->prepare($query);
		$sth->execute();
		my @results;
		while ( my $row = $sth->fetchrow_hashref )
		{
			push @results, $row;
		}
		return \@results;
	}
my @newsgroup_list;
my $newsgroup = LoadNewsGroup();

foreach my $group ( @$newsgroup ){
	push @newsgroup_list,
		{
			idgroup => $group->{idgroup},
			namegroup => $group->{namegroup},
			selected => ( $new_detail->{idgroup} eq $group->{idgroup} ? 1 : 0 ),
		};
}
$template->param(
        newsgroup_list => \@newsgroup_list,
		);
#ket thuc them boi vohuythuan


my $branches = GetBranches;

$template->param( lang_list   => \@lang_list,
                  branch_list => $branches,
                  branchcode  => $branchcode );

my $op = $cgi->param('op') // '';

sub uploadimg {
	my $upload_dir = shift;
	my $filename = shift;
	my $upload_filehandle = shift;
	open (UPLOADFILE, ">$upload_dir/$filename");
	binmode UPLOADFILE;
	while ( <$upload_filehandle> ) {
		print UPLOADFILE;
	}
	close UPLOADFILE;
}

if ( $op eq 'add_form' ) {
    $template->param( add_form => 1 );
    if ($id) {
        if($new_detail->{lang} eq "slip"){ $template->param( slip => 1); }
        $template->param( 
            op => 'edit',
            id => $new_detail->{'idnew'}
        );
        $template->{VARS}->{'new_detail'} = $new_detail;
    }
    else {
        $template->param( op => 'add' );
    }
}
elsif ( $op eq 'add' ) {

	my ($filename,undef,$ext) = fileparse($img,qr{\..*});
	#them phan mo rong vao tep tin
	$filename .= $ext;
	#chuyen doi dau cach bang dau gach duoi
	$filename =~ tr/ /_/;
	#loai bo ky hieu ko dung dinh dang

	$filename =~ s/[^$filename_characters]//g;

	#loại bỏ vết nhơ (éo hiểu dich thế eo nào)
	if ($filename =~ /^([$filename_characters]+)$/) {
		$filename = $1;
	}
	else{
		$filename = "huythuandeptrai";
	}

	#ham kiem tra ngon ngu cua tin tuc hien tai
	if ( $filename eq 'huythuandeptrai' ){
		$filename = 'null111';
	}else {
		uploadimg($upload_dir, $filename, $upload_filehandle);
	}
    add_opac_new(
        {
			idgroup		   => $idgroup,
            title          => $title,
			sub 		   => $sub,
            new            => $new,
            lang           => $lang,
            expirationdate => $expirationdate,
            timestamp      => $timestamp,
            number         => $number,
            branchcode     => $branchcode,
			img			   => '/opac-tmpl/bootstrap/images/news/'.$filename,
        }
    );
    print $cgi->redirect("/cgi-bin/koha/tools/koha-news.pl");
}
elsif ( $op eq 'edit' ) {

	my ($filename,undef,$ext) = fileparse($img,qr{\..*});
	#them phan mo rong vao tep tin
	$filename .= $ext;
	#chuyen doi dau cach bang dau gach duoi
	$filename =~ tr/ /_/;
	#loai bo ky hieu ko dung dinh dang

	$filename =~ s/[^$filename_characters]//g;

	#loại bỏ vết nhơ (éo hiểu dich thế eo nào)
	if ($filename =~ /^([$filename_characters]+)$/) {
		$filename = $1;
	}
	else{
		$filename = "huythuandeptrai";
	}

	#ham kiem tra ngon ngu cua tin tuc hien tai
	if ( $filename eq 'huythuandeptrai' ){
		upd_opac_new(
        {
            idnew          => $id,
			idgroup		   => $idgroup,
            title          => $title,
			sub 		   => $sub,
            new            => $new,
            lang           => $lang,
            expirationdate => $expirationdate,
            timestamp      => $timestamp,
            number         => $number,
            branchcode     => $branchcode,
        }
		);
	}else {
		upd_opac_new(
        {
            idnew          => $id,
			idgroup		   => $idgroup,
            title          => $title,
			sub 		   => $sub,
            new            => $new,
            lang           => $lang,
            expirationdate => $expirationdate,
            timestamp      => $timestamp,
            number         => $number,
            branchcode     => $branchcode,
			img			   => '/opac-tmpl/bootstrap/images/news/'.$filename,
        }
		);
		uploadimg($upload_dir, $filename, $upload_filehandle);
	}

    print $cgi->redirect("/cgi-bin/koha/tools/koha-news.pl?idgroup=$idgroup");
}
elsif ( $op eq 'del' ) {
    my @ids = $cgi->param('ids');
    del_opac_new( join ",", @ids );
    print $cgi->redirect("/cgi-bin/koha/tools/koha-news.pl?idgroup=$idgroup");
}

else {

    my ( $opac_news_count, $opac_news ) = &get_opac_news( undef, $lang, $branchcode,$idgroup );
    
    foreach my $new ( @$opac_news ) {
        next unless $new->{'expirationdate'};
       	#$new->{'expirationdate'}=format_date_in_iso($new->{'expirationdate'});
        my @date = split (/-/,$new->{'expirationdate'});
        if ($date[0]*$date[1]*$date[2]>0 && Date_to_Days( @date ) < Date_to_Days(&Today) ){
			$new->{'expired'} = 1;
        }
    }
    
    $template->param(
        opac_news       => $opac_news,
        opac_news_count => $opac_news_count,
		idgroup => $idgroup,
		);
}
$template->param( lang => $lang );
output_html_with_http_headers $cgi, $cookie, $template->output;
