<div id="calendar">
	<h3 class="title">Lịch sự kiện</h3>
<link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/lib/calendar/css/eventCalendar.css" />
<link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/lib/calendar/css/eventCalendar_theme_responsive.css" />
<link rel="stylesheet" type="text/css" href="[% interface %]/[% theme %]/lib/calendar/css/dl.style.calendar.css" />
	<div id="eventCalendarHumanDate" ></div>
				<script>
					$(document).ready(function() {
						var d = new Date();
						var n = d.getTime();
						//console.log(n);
						var datajson = [  
						[% FOREACH koha_new1 IN koha_news %]
							[% IF loop.last %]
								{ "date": "[% koha_new1.timestamp %]", "type": "meeting", "title": "[% koha_new1.title %]", "description": "", "url": "/cgi-bin/koha/opac-ctnews.pl?idnew=[% koha_new1.idnew %]&idgroup=[% koha_new1.idgroup %]" }
							[% ELSE %]
								{ "date": "[% koha_new1.timestamp %]", "type": "meeting", "title": "[% koha_new1.title %]", "description": "", "url": "/cgi-bin/koha/opac-ctnews.pl?idnew=[% koha_new1.idnew %]&idgroup=[% koha_new1.idgroup %]" },
							[% END %]
						[% END %]
						];
						$("#eventCalendarHumanDate").eventCalendar({
							jsonData: datajson,
							jsonDateFormat: 'human',
							eventsScrollable: true
						});
						
					});
					
					
				</script>

</div>

<script src="[% interface %]/[% theme %]/lib/calendar/js/jquery.eventCalendar.js" type="text/javascript"></script>