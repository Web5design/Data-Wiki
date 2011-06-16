<?php
/**
 * @file
 * datawiki_content.features.content.inc
 */

/**
 * Implementation of hook_content_defaults().
 */
function datawiki_content_content_defaults() {
$content = array();
$content['data_page_community_data'] = (object)array(
  'exported_path' => 'community-data-api',
  'title' => 'Community Data & API',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308189616',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'data_page_community_data',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'There is a reason why we do not already have a city-wide groups directory already: it requires the participation of a community to keep the data up to date.

We want this directory to be useful to everyone in the city, so we are working with city staff and community groups to build a community of people who need up-to-date information about groups. We want new residents to be able to find useful groups in their neighborhood, or for a community organizer to be able to invite all the groups along a parade route to participate in the parade.

<h3>Our goals</h3>
<ul>
<li>To make it easy to find groups. <a href="/contact">Not easy? Please contact us to give us your feedback.</a></li>
<li>To keep our service simple. We just list groups by geography & topic. We aim to do that well. We provide an API for everything else.</li>
<li>To be technology agnostic with respect to the technology used by a community group. We aim to list groups from any technology that provides a URL or Email address. These could be Meetup, Facebook pages, or just simply a personal email address for someone who reaches out to communities that are not online.</li>
<li>To make it easy to add data you already have. <a href="/user">Join</a> our community to import <a href="/help/import-csv">CSV</a> data.</li>
<li>To provide structure for describing groups. <a href="/data-standard">See our data standard.</a></li>
<li>To make it easy for community organizers and city employees to keep the information up to date.</li>
<li>To make it easy for community members to add new groups and update out-of-date groups</li>
<li>To make it easy to add helpful information about the groups, like geographic service area (location) and metadata (tags)</li>
<li>To make it easy to get information out of the directory, using a public API (<a href="/groups/all/csv/export">CSV</a> & <a href="/groups/all/export/json">JSON</a>). (Then developers can build new services on top of the group listings, such as a cool map, or an text-message service, or group-to-group notification system.</li>
</ul>',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>There is a reason why we do not already have a city-wide groups directory already: it requires the participation of a community to keep the data up to date.</p>
<p>We want this directory to be useful to everyone in the city, so we are working with city staff and community groups to build a community of people who need up-to-date information about groups. We want new residents to be able to find useful groups in their neighborhood, or for a community organizer to be able to invite all the groups along a parade route to participate in the parade.</p>
<h3>Our goals</h3>
<ul><li>To make it easy to find groups. <a href="/contact">Not easy? Please contact us to give us your feedback.</a></li>
<li>To keep our service simple. We just list groups by geography &amp; topic. We aim to do that well. We provide an API for everything else.</li>
<li>To be technology agnostic with respect to the technology used by a community group. We aim to list groups from any technology that provides a URL or Email address. These could be Meetup, Facebook pages, or just simply a personal email address for someone who reaches out to communities that are not online.</li>
<li>To make it easy to add data you already have. <a href="/user">Join</a> our community to import <a href="/help/import-csv">CSV</a> data.</li>
<li>To provide structure for describing groups. <a href="/data-standard">See our data standard.</a></li>
<li>To make it easy for community organizers and city employees to keep the information up to date.</li>
<li>To make it easy for community members to add new groups and update out-of-date groups</li>
<li>To make it easy to add helpful information about the groups, like geographic service area (location) and metadata (tags)</li>
<li>To make it easy to get information out of the directory, using a public API (<a href="/groups/all/csv/export">CSV</a> &amp; <a href="/groups/all/export/json">JSON</a>). (Then developers can build new services on top of the group listings, such as a cool map, or an text-message service, or group-to-group notification system.</li>
</ul>',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['datawiki_page_about'] = (object)array(
  'exported_path' => 'about',
  'title' => 'About',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308189591',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'datawiki_page_about',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This is the about page.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This is the about page.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['datawiki_page_data_group'] = (object)array(
  'exported_path' => 'data-standard-community-groups',
  'title' => 'Data Standard: Community Groups',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308189720',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'datawiki_page_data_group',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'CityGroups CSV Data Structure for Groups


All of this appears on this webpage:
http://citygroups.org/data-standard

Updated 6/14/2011

<h3>Column Headers</h3>
name, url, calendar_url, email, contact, type_group, categories, description, notes, source, activity_level, audience_size, ownership, image, location, address, neighborhood, district, city, zipcode, state, region, area_code, latitude, longitude, location_geo

Last updated June 14, 2011

<h4>Name</h4>
name
The name of the online community, ideally from the page or mailing list title.

<h4>URL</h4>
url
Link to the best page to find a description of the group and know how to join the group.

<h4>Calendar URL</h4>
calendar_url
Link to the page that best describes how to get information about events for this group.

<h4>Email</h4>
email
If a mailing list, the email address that someone would use to subscribe. (If subscription is complicated, just list the URL)

<h4>Contact</h4>
contact
Name, email and/or phone number of contact

<h4>Type of Group</h4>
type_group
Type of online community, for example: Yahoo Group, Facebook page, Ning network, Mailing list, etc.

<h4>Categories</h4>
categories
Comma-separated list of tags and keywords that best describe the content of the site.

An important part of CityGroups is having good category listings. We will have a Civic Taxonomy that you can use in addition to freetags. You can also tag groups by your values.

<h4>Description</h4>
description
A general description of the group.

<h4>Notes</h4>
notes
Any additional information about the group.

<h4>Source</h4>
source
Where the original data was from.

<h4>Activity Level</h4>
activity_level

* We will probably have a table here for the values, like GTFS.
General activity level of the group

Values:
Multiple Daily
Daily
Every few days
Weekly
Monthly
Yearly 
Apparently Inactive

<h4>Audience Size</h4>
audience_size
* We will probably have a table here for the values, like GTFS.
General size of audience

Values
1-10
10-100
100-1000
1,000-10,000
10,000-100,000
100,000 - 1,000,000
1,000,000+



<h4>Ownership</h4>
ownership
Possible values: community, commercial, personal, government

<h4>Image</h4>
image
A url pointing to an image for the group.






<h3>About Location Data<h3>
Enter what you know, and we can help you fill in the rest.

Some location data is helpful. 

The goal is to map out the service area that the group actually applies to. City-wide is an option for general discussions, but some groups may just apply to a block, or even just a small plot of land like a garden or a vacant lot.

<h4>Location</h4>
location

Freetext for location, if stored & not geocoded.





<h4>Address</h4>
address
Enter the Street Address. This is optional and we use it to pinpoint your group on the map.

<h4>Neighborhood</h4>
neighborhood
Name of the neighborhood

In cities, the name of a neighborhood is often a complicated issue. Enter as many neighborhood names as can be used to map the service area of the group.

<h4>District</h4>
district
Name of the District

<h4>City</h4>
city
Name of the city.

<h4>State</h4>
state
Name of the State (abbreviated, ex: WA, CA, MN, MA.)

<h4>Zipcode</h4>
zipcode
Zipcode for the area, feel free to include the 4 
digit zipcode extension if you know it.

<h4>Region</h4>
region
If the group extends into the greater metro area, include county names or other useful data. 

<h4>Area Code</h4>
area_code
The three digit area code. Not required, though any location data is useful if you do not know anything else.


<h4>Latitude</h4>
latitude
The latitude. (The tool will be able to geocode this, so if you do not know it, do not worry.)


<h4>Longitude</h4>
longitude
The longitude. (The tool will be able to geocode this, so if you do not know it, do not worry.)




<h4>Location Geo</h4>
* May rename this to geometry, which matches the GeoJSON specification which we use a lot.

location_geo
A Well-known-text shape definition for the service area of the community, or GeoJSON description, or textfield describing the location. If you do not know this, we have a map tool that can help you draw the service area of the group. Import your data, and then go back and update it.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>CityGroups CSV Data Structure for Groups</p>
<p>All of this appears on this webpage:<br /><a href="http://citygroups.org/data-standard">http://citygroups.org/data-standard</a></p>
<p>Updated 6/14/2011</p>
<h3>Column Headers</h3>
<p>name, url, calendar_url, email, contact, type_group, categories, description, notes, source, activity_level, audience_size, ownership, image, location, address, neighborhood, district, city, zipcode, state, region, area_code, latitude, longitude, location_geo</p>
<p>Last updated June 14, 2011</p>
<h4>Name</h4>
<p>name<br />
The name of the online community, ideally from the page or mailing list title.</p>
<h4>URL</h4>
<p>url<br />
Link to the best page to find a description of the group and know how to join the group.</p>
<h4>Calendar URL</h4>
<p>calendar_url<br />
Link to the page that best describes how to get information about events for this group.</p>
<h4>Email</h4>
<p>email<br />
If a mailing list, the email address that someone would use to subscribe. (If subscription is complicated, just list the URL)</p>
<h4>Contact</h4>
<p>contact<br />
Name, email and/or phone number of contact</p>
<h4>Type of Group</h4>
<p>type_group<br />
Type of online community, for example: Yahoo Group, Facebook page, Ning network, Mailing list, etc.</p>
<h4>Categories</h4>
<p>categories<br />
Comma-separated list of tags and keywords that best describe the content of the site.</p>
<p>An important part of CityGroups is having good category listings. We will have a Civic Taxonomy that you can use in addition to freetags. You can also tag groups by your values.</p>
<h4>Description</h4>
<p>description<br />
A general description of the group.</p>
<h4>Notes</h4>
<p>notes<br />
Any additional information about the group.</p>
<h4>Source</h4>
<p>source<br />
Where the original data was from.</p>
<h4>Activity Level</h4>
<p>activity_level</p>
<p>* We will probably have a table here for the values, like GTFS.<br />
General activity level of the group</p>
<p>Values:<br />
Multiple Daily<br />
Daily<br />
Every few days<br />
Weekly<br />
Monthly<br />
Yearly<br />
Apparently Inactive</p>
<h4>Audience Size</h4>
<p>audience_size<br />
* We will probably have a table here for the values, like GTFS.<br />
General size of audience</p>
<p>Values<br />
1-10<br />
10-100<br />
100-1000<br />
1,000-10,000<br />
10,000-100,000<br />
100,000 - 1,000,000<br />
1,000,000+</p>
<h4>Ownership</h4>
<p>ownership<br />
Possible values: community, commercial, personal, government</p>
<h4>Image</h4>
<p>image<br />
A url pointing to an image for the group.</p>
<h3>About Location Data<br /><h3>
Enter what you know, and we can help you fill in the rest.
</h3></h3><p>Some location data is helpful. </p>
<p>The goal is to map out the service area that the group actually applies to. City-wide is an option for general discussions, but some groups may just apply to a block, or even just a small plot of land like a garden or a vacant lot.</p>
<h4>Location</h4>
<p>location</p>
<p>Freetext for location, if stored &amp; not geocoded.</p>
<h4>Address</h4>
<p>address<br />
Enter the Street Address. This is optional and we use it to pinpoint your group on the map.</p>
<h4>Neighborhood</h4>
<p>neighborhood<br />
Name of the neighborhood</p>
<p>In cities, the name of a neighborhood is often a complicated issue. Enter as many neighborhood names as can be used to map the service area of the group.</p>
<h4>District</h4>
<p>district<br />
Name of the District</p>
<h4>City</h4>
<p>city<br />
Name of the city.</p>
<h4>State</h4>
<p>state<br />
Name of the State (abbreviated, ex: WA, CA, MN, MA.)</p>
<h4>Zipcode</h4>
<p>zipcode<br />
Zipcode for the area, feel free to include the 4<br />
digit zipcode extension if you know it.</p>
<h4>Region</h4>
<p>region<br />
If the group extends into the greater metro area, include county names or other useful data. </p>
<h4>Area Code</h4>
<p>area_code<br />
The three digit area code. Not required, though any location data is useful if you do not know anything else.</p>
<h4>Latitude</h4>
<p>latitude<br />
The latitude. (The tool will be able to geocode this, so if you do not know it, do not worry.)</p>
<h4>Longitude</h4>
<p>longitude<br />
The longitude. (The tool will be able to geocode this, so if you do not know it, do not worry.)</p>
<h4>Location Geo</h4>
<p>* May rename this to geometry, which matches the GeoJSON specification which we use a lot.</p>
<p>location_geo<br />
A Well-known-text shape definition for the service area of the community, or GeoJSON description, or textfield describing the location. If you do not know this, we have a map tool that can help you draw the service area of the group. Import your data, and then go back and update it.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$content['datawiki_page_welcome'] = (object)array(
  'exported_path' => 'home',
  'title' => 'Home',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'page',
  'language' => 'und',
  'created' => '1308186396',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'datawiki_page_welcome',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'This is the welcome page.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This is the welcome page.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
return $content;
}