<?php
  $html_root = drupal_get_path('module', 'datawiki_group_map');
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta charset="utf-8">
  <title>SiteName</title>
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/fluid_grid.css" type="text/css" />
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/boilerplate.css" type="text/css" />
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/js/leaflet/leaflet.css" />
  <link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/style.css" type="text/css" />
<!--[if lte IE 8]><link rel="stylesheet" href="<?php print $html_root; ?>/includes/style/leaflet/leaflet.ie.css" /><![endif]-->
  <script type="text/javascript" src="<?php print $html_root; ?>/includes/js/jquery-1.5.min.js"></script>
  <script type="text/javascript" src="<?php print $html_root; ?>/includes/js/leaflet/leaflet.js"></script>
  <script type="text/javascript" src="<?php print $html_root; ?>/includes/js/map.js"></script>
</head>
<body>
<div id="container" class="section container_12">
    <div id="header">
        <div class="logo grid_6 alpha"><h1><a href="index.html">SiteName</a></h1></div>
        <div class="grid_6 omega">
          <ul class="menu">
            <li><a href="#" >Link</a></li>
            <li><a href="#" >Link</a></li>
          </ul>
        </div>
        <div id="page-title" class="grid_12"><h2>Map</h2></div>
        <div id="popup-content" class="grid_4 alpha">
          <div class="content">Click map to see where the groups are</div>
        
          <div class="popular-terms">
          <ul>
            <li><a href="#block-watch">Block Watch</a></li>
            <li><a href="#online-newspaper">Online Newspaper</a></li>
          </ul>
        </div>
        </div> 
        <div id="content" class="grid_8 omega">
          <div id="map" style="height: 600px"></div> <!-- width equals available horizontal space by default -->
          <div id="data"></div> <!-- width equals available horizontal space by default -->
        </div>
        
        <div id="footer" class="grid_12">
          <ul class="menu">
            <li><a href="link.html">Footer Menu</a></li>
            <li><a href="link.html">Footer Menu</a></li>
          </ul>
        </div>
    </div>
</div>
</html>
