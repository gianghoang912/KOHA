package C4::NewsChannels;

# This file is part of Koha.
#
# Copyright (C) 2000-2002  Katipo Communications
# Copyright (C) 2013       Mark Tompsett
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
use C4::Context;
use C4::Dates qw(format_date);

use vars qw($VERSION @ISA @EXPORT);

BEGIN { 
    $VERSION = 3.07.00.049;    # set the version for version checking
    @ISA = qw(Exporter);
    @EXPORT = qw(
        &GetNewsToDisplay &GetNewsToDisplay1 &ViewVirtualShelves &ViewBookNew &getTinTuc
        &add_opac_new &upd_opac_new &del_opac_new &get_opac_new &get_opac_news
    );
}

=head1 NAME

C4::NewsChannels - Functions to manage OPAC and intranet news

=head1 DESCRIPTION

This module provides the functions needed to mange OPAC and intranet news.

=head1 FUNCTIONS

=cut

=head2 add_opac_new

    $retval = add_opac_new($hashref);

    $hashref should contains all the fields found in opac_news,
    except idnew. The idnew field is auto-generated.

=cut

sub add_opac_new {
    my ($href_entry) = @_;
    my $retval = 0;

    if ($href_entry) {
        my @fields = keys %{$href_entry};
        my @values = values %{$href_entry};
        my $field_string = join ',', @fields;
        $field_string = $field_string // q{};
        my $values_string = join(',', map { '?' } @fields);
        my $dbh = C4::Context->dbh;
        my $sth = $dbh->prepare("INSERT INTO opac_news ( $field_string ) VALUES ( $values_string )");
        $sth->execute(@values);
        $retval = 1;
    }
    return $retval;
}

=head2 upd_opac_new

    $retval = upd_opac_new($hashref);

    $hashref should contains all the fields found in opac_news,
    including idnew, since it is the key for the SQL UPDATE.

=cut

sub upd_opac_new {
    my ($href_entry) = @_;
    my $retval = 0;

    if ($href_entry) {
        # take the keys of hash entry and make a list, but...
        my @fields = keys %{$href_entry};
        my @values;
        $#values = -1;
        my $field_string = q{};
        foreach my $field_name (@fields) {
            # exclude idnew
            if ( $field_name ne 'idnew' ) {
                $field_string = $field_string . "$field_name = ?,";
                push @values,$href_entry->{$field_name};
            }
        }
        # put idnew at the end, so we know which record to update
        push @values,$href_entry->{'idnew'};
        chop $field_string; # remove that excess ,

        my $dbh = C4::Context->dbh;
        my $sth = $dbh->prepare("UPDATE opac_news SET $field_string WHERE idnew = ?;");
        $sth->execute(@values);
        $retval = 1;
    }
    return $retval;
}

sub del_opac_new {
    my ($ids) = @_;
    if ($ids) {
        my $dbh = C4::Context->dbh;
        my $sth = $dbh->prepare("DELETE FROM opac_news WHERE idnew IN ($ids)");
        $sth->execute();
        return 1;
    } else {
        return 0;
    }
}

sub get_opac_new {
    my ($idnew) = @_;
    my $dbh = C4::Context->dbh;
    my $query = q{
                  SELECT opac_news.*,branches.branchname, newsgroup.namegroup
                  FROM newsgroup,  opac_news LEFT JOIN branches
                      ON opac_news.branchcode=branches.branchcode 
                  WHERE opac_news.idnew = ? and opac_news.idgroup = newsgroup.idgroup;
                };
    my $sth = $dbh->prepare($query);
    $sth->execute($idnew);
    my $data = $sth->fetchrow_hashref;
    $data->{$data->{'lang'}} = 1 if defined $data->{lang};
    $data->{expirationdate} = format_date($data->{expirationdate});
    $data->{timestamp}      = format_date($data->{timestamp});
    return $data;
}


sub get_opac_news {
    my ($limit, $lang, $branchcode, $idgroup) = @_;
    my @values;
    my $dbh = C4::Context->dbh;
    my $query = q{
                  SELECT opac_news.*, branches.branchname,
                         timestamp AS newdate, newsgroup.namegroup
                  FROM newsgroup, opac_news LEFT JOIN branches
                      ON opac_news.branchcode = branches.branchcode
                };
    $query .= ' WHERE 1';
    $query .= ' AND opac_news.idgroup = newsgroup.idgroup';
    if ($lang) {
        $query .= " AND (opac_news.lang='' OR opac_news.lang=?)";
        push @values,$lang;
    }
    if ($branchcode) {
        $query .= ' AND (opac_news.branchcode IS NULL OR opac_news.branchcode=?)';
        push @values,$branchcode;
    }
    if ($idgroup) {
        $query .= ' AND (opac_news.idgroup=?)';
        push @values,$idgroup;
    }
    $query.= ' ORDER BY timestamp DESC ';
    #if ($limit) {
    #    $query.= 'LIMIT 0, ' . $limit;
    #}
    my $sth = $dbh->prepare($query);
    $sth->execute(@values);
    my @opac_news;
    my $count = 0;
    while (my $row = $sth->fetchrow_hashref) {
        if ((($limit) && ($count < $limit)) || (!$limit)) {
            push @opac_news, $row;
        }
        $count++;
    }
    return ($count, \@opac_news);
}

=head2 GetNewsToDisplay

    $news = &GetNewsToDisplay($lang,$branch);
    C<$news> is a ref to an array which containts
    all news with expirationdate > today or expirationdate is null
    that is applicable for a given branch.

=cut

sub GetNewsToDisplay {
    my ($lang,$branch,$idgroup) = @_;
    my $dbh = C4::Context->dbh;
    # SELECT *,DATE_FORMAT(timestamp, '%d/%m/%Y') AS newdate
    my $query = q{
     SELECT *,timestamp AS newdate
     FROM   opac_news
     WHERE   (
        expirationdate >= CURRENT_DATE()
        OR    expirationdate IS NULL
        OR    expirationdate = '00-00-0000'
     )
     AND   (lang = '' OR lang = ?)
     AND   (branchcode IS NULL OR branchcode = ?)
	 AND   (idgroup = ?)
     ORDER BY newdate desc 
    }; # expirationdate field is NOT in ISO format?
       # timestamp has HH:mm:ss, CURRENT_DATE generates 00:00:00
       #           by adding 1, that captures today correctly.
    my $sth = $dbh->prepare($query);
    $lang = $lang // q{};
    $sth->execute($lang,$branch,$idgroup);
    my @results;
    while ( my $row = $sth->fetchrow_hashref ){
        $row->{newdate} = format_date($row->{newdate});
        push @results, $row;
    }
    return \@results;
}


=head2 GetNewsToDisplay1

    $news = &GetNewsToDisplay1($lang,$branch);
    C<$news> is a ref to an array which containts
    all news with expirationdate > today or expirationdate is null
    that is applicable for a given branch.

=cut

sub GetNewsToDisplay1 {
    my ($lang,$branch,$idgroup) = @_;
    my $dbh = C4::Context->dbh;
    # SELECT *,DATE_FORMAT(timestamp, '%d/%m/%Y') AS newdate
    my $query = q{
     SELECT *,timestamp AS newdate
     FROM   opac_news
     WHERE   (
        expirationdate >= CURRENT_DATE()
        OR    expirationdate IS NULL
        OR    expirationdate = '00-00-0000'
     )
     AND   (lang = '' OR lang = ?)
     AND   (branchcode IS NULL OR branchcode = ?)
	 AND   (idgroup = ?)
     ORDER BY newdate desc limit 5 
    }; # expirationdate field is NOT in ISO format?
       # timestamp has HH:mm:ss, CURRENT_DATE generates 00:00:00
       #           by adding 1, that captures today correctly.
    my $sth = $dbh->prepare($query);
    $lang = $lang // q{};
    $sth->execute($lang,$branch,$idgroup);
    my @results;
    while ( my $row = $sth->fetchrow_hashref ){
        $row->{newdate} = format_date($row->{newdate});
        push @results, $row;
    }
    return \@results;
}

sub ViewVirtualShelves {
		my $dbh = C4::Context->dbh;
		my $query = "Select * from virtualshelves where owner = 1 and shelfnumber > 1 limit 3";
		my $sth = $dbh->prepare($query);
		$sth->execute();
		my @results1;
		while ( my $row = $sth->fetchrow_hashref ){
			push @results1, $row;
		}
    return \@results1;
}

sub ViewBookNew {
		my $dbh = C4::Context->dbh;
		my $query = "Select biblio.biblionumber, biblio.title from biblio, virtualshelfcontents where biblio.biblionumber = virtualshelfcontents.biblionumber and virtualshelfcontents.shelfnumber = 1";
		my $sth = $dbh->prepare($query);
		$sth->execute();
		my @results1;
		while ( my $row = $sth->fetchrow_hashref ){
		$row->{timestamp} = format_date($row->{timestamp});
        push @results1, $row;
    }
    return \@results1;
}

sub getTinTuc {
    my ($lang,$branch,$idgroup,$limit) = @_;
    my $dbh = C4::Context->dbh;
    # SELECT *,DATE_FORMAT(timestamp, '%d/%m/%Y') AS newdate
    my $query = q{
     SELECT *,timestamp AS newdate
     FROM   opac_news
     WHERE   (
        expirationdate >= CURRENT_DATE()
        OR    expirationdate IS NULL
        OR    expirationdate = '00-00-0000'
     )
     AND   (lang = '' OR lang = ?)
     AND   (branchcode IS NULL OR branchcode = ?)
	 AND   (idgroup = ?)
     ORDER BY newdate desc limit ?
    }; # expirationdate field is NOT in ISO format?
       # timestamp has HH:mm:ss, CURRENT_DATE generates 00:00:00
       #           by adding 1, that captures today correctly.
    my $sth = $dbh->prepare($query);
    $lang = $lang // q{};
    $sth->execute($lang,$branch,$idgroup,$limit);
    my @results;
    while ( my $row = $sth->fetchrow_hashref ){
        $row->{newdate} = format_date($row->{newdate});
        push @results, $row;
    }
    return \@results;
}
1;
__END__

=head1 AUTHOR

TG

=cut
