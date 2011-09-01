<?php

/**
 * Implements hook_block_info().
 */
function citygroups_city_block_info() {
  $blocks['citygroups_city_welcome'] = array(
    'info' => t('Welcome Message'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_branding_header'] = array(
    'info' => t('Branding Header'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_branding_footer'] = array(
    'info' => t('Branding Footer'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_site_slogan'] = array(
    'info' => t('Site Slogan'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_facebook_like'] = array(
    'info' => t('Facebook Like'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_home_content'] = array(
    'info' => t('Home Content'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
  $blocks['citygroups_city_about'] = array(
    'info' => t('About'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
/*
  $blocks['citygroups_city_map'] = array(
    'info' => t('Map'),
    'cache' => DRUPAL_CACHE_PER_ROLE, // default
  );
*/
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function citygroups_city_block_view($delta = '') {
  switch ($delta) {
    case 'citygroups_city_welcome':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('welcome');
      break;
      
    case 'citygroups_city_branding_header':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('branding_header');
      break;
      
    case 'citygroups_city_branding_footer':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('branding_footer');
      break;     

    case 'citygroups_city_site_slogan':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('site_slogan');
      break;

    case 'citygroups_city_about_citygroups':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('about_citygroups');
      break;         

    case 'citygroups_city_facebook_like':
      $url = ($_SERVER['SERVER_PORT'] == '443') ? 'https' : 'http';
      $url .= '://';
      $url .= ($_SERVER['HTTP_HOST'] == 'localhost') ? 'localhost.com' : $_SERVER['HTTP_HOST'];
      $url .= $_SERVER['REQUEST_URI'];
      $block['subject'] = '';
      $block['content'] = '<script src="http://connect.facebook.net/en_US/all.js#xfbml=1"></script><fb:like href="' . urlencode($url) . '" send="true" width="200" show_faces="false" font=""></fb:like>';
      break;

    case 'citygroups_city_home_content':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('home_content');
      break;

    case 'citygroups_city_about':
      $block['subject'] = '';
      $block['content'] = citygroups_city_contents('about');
      break; 

  }
  return $block;
}

/**
 * Block content for main CityGroups content.
 */
function citygroups_city_contents($type) {
  $output = '';
  
  switch ($type) {
    case 'welcome':
      $output .= '<h3>' . t('Find community groups by location or topic.') . '</h3>';
      $output .= '<p>' . t('Making it easier to find those little local community groups.') .'</p>';
      break;

    case 'site_slogan':
      $output .= '<h3>' . t('A public directory of community groups in the Seattle area.') . '</h3>';
      break;
      
    case 'branding_header':
      $output .= '<div id="branding-header"></div>';
      break;
      
    case 'branding_footer':
      $code_for_america = '';
      $output .= '<div id="branding-footer alpha omega grid_16 alpha omega">' 
      . '<div class="about grid_6 alpha">' 
      . t('This site is the product of a partnership between Community Organizations and City Governments.') . '<br />'
      . t('Created as Open Source by <a href="http://codeforamerica.org">Code for America</a>') 
      . '<div class="tagline">' .  t('"For a more transparent, efficient and participatory future."') . '</div>' . '</div>'
      . '<div class="logo grid_10"><a href="http://codeforamerica.org">' . '<img src="' . base_path() . path_to_theme() . '/images/cfa-full-logo.png" width="150" />' . '</a></div>'
      . '</div>';
      break;

      
/*
      case 'map':
        $output .= citygroups_city_group_map_render();
      break;
*/
      
      case 'home_content':
        $output .= "
          <div class=\"grid_16 sections\">

            <div class=\"grid_6 view-data section alpha\">
              <h3>Search for Groups</h3>
              <p>Since starting the project, we have located about 1,000 community groups in Seattle.</p>" .
              
/*
              "<div id=\"search-map\" class=\"form-input\">
              <input placeholder=\"Enter your address or zipcode here.\" class=\"form-item\" />
              <input type=\"image\" src=\"" . base_path() . path_to_theme() . "/images/search_button.png\" id=\"search-links-submit\" class=\"search_btn\" value=\"Search\" alt=\"Search\">
              </div>
              " .
*/
              views_embed_view('number_groups', 'default') .
              "<div class=\"button\"><a href=\"map\">Map view</a></div>
              <div class=\"button\"><a href=\"list\">List view</a></div>
            </div>

           
            <div class=\"grid_6  push_2  add-new-group section omega\">
              <h3>Know community groups that should be listed?</h3>
              <p>Anyone can suggest a group. Groups should be based in Seattle, and do work to make Seattle better.</p>
              <div class=\"button\"><a href=\"/node/add/community-group\">Add New Group</a></div>
            </div>    

          </div>
          <div class=\"clear\"></div>
          <div class=\"grid_16 sections\">
            <div class=\"grid_6 news section alpha\">
              <h3>News</h3>
              
              <h5>We're mapping Block Watch Captains</h5>
              <p>Our first project to find local community groups is a <a href=\"/blockwatch\">
              Block Watch Captain Directory.</a></p>
              
            </div>    
            <div class=\"grid_6 push_2 promote section omega\">
              <h3>Spread the word</h3>
              <p>If you like this directory and know other people who should <a href=\"/get-involved\">get involved</a>, we want to help you do that.</p>
              <ul>
              <li>/Tweet/</li>
              <li>/Facebook/</li>
              <li>/Email/</li>
              <li>/Print/</li>
              </ul>
            </div>      
          </div>
        ";
      break;  
  
      case 'about':
      
        $groups = '<img src="' . base_path() . path_to_theme() . '/images/groups_icons/group_icons_wide.png" title="Facebook, Yahoo Groups, Google Goups, Meetup Groups, Email, Twitter, Community Blogs, Personal Email" alt="Facebook, Yahoo Groups, Google Goups, Meetup Groups, Email, Twitter, Community Blogs, Personal Email" />';

        $output .= "
        <div class=\"grid_16 postscript-content alpha omega\">
          <div class=\"grid_6 about alpha\">
          <h3>What is CityGroups?</h3>
          
          We make it easy to find and share all kinds of groups in your city
          <div class=\"groups-icons\">" . $groups . "</div>
          <p>Any group that has an e-mail, url or contact person can be listed. The idea is to list those little Facebook pages, twitter groups, mailing lists of people working to make your city better.</p>
          <p>We made this tool because it was really hard to find these kinds of groups doing normal Internet searches. If you know of good resources, tell us and we'll work with those community directories.</p>
          </div>
  
          <div class=\"grid_4 push_1 participate\">
          <h3>Get on the map</h3>
          <p>Anyone can <a href=\"/node/add/community-group\">add</a> & <a href=\"/user\">edit</a> groups. Groups appear on the map - which makes it easy to find groups in your neighborhood.</p>
          </div>
    
          <div class=\"grid_4 push_1 local omega\">
          <h3>Local Community Groups</h3>
          <p>We have all kinds of groups listed. If you don't see the kinds groups that you are looking for, <a href=\"/contact\">let us know</a>.</p>
          <p>We have worked to make it really easy for you too add groups. You can even share them with us <a href=\"/community-data\">using a spreadsheet.</a></p>
          </div>
        </div>        
        ";
      break;      

  }
  return $output;
}