console.log("map");
var cityGroups = {};
cityGroups.map = {};
cityGroups.geoJSON = {};
cityGroups.map.settings = {};
cityGroups.map.rendered;
cityGroups.data = {};
cityGroups.map.form = {};
var datawiki;
// Custom search paths.
cityGroups.paths = {
    "defaultPath": "/data/community-group/map",
    "#defaultPath": "/data/community-group/map",
};
        
$(document).ready(function() {
  cityGroups.map.polygonOptions = Drupal.settings.datawiki.mapColors;
  cityGroups.data.popularLoad();
  cityGroups.loadData(cityGroups.paths['defaultPath']);
  cityGroups.mapPageInteractions();
});


cityGroups.mapPageInteractions = function () {
  cityGroups.map.geocodeAddress();
  $('ul.menu a#popular-search').click(function() {
/*     $('div#popular-terms').css('backgroundColor', '#bb4433'); */
  });
};

cityGroups.data.popularLoad = function () {
  $('div#popular-terms ul li a').click(function(){ 
/*     var path = cityGroups.paths[$(this).attr('href')]; */
    // Dynamically load the path.
    var path = cityGroups.paths.defaultPath + '/' + $(this).attr('href');
    path = path.replace("#", '');
    if( $(this).attr('href') == '#defaultPath') {
     path = cityGroups.paths['defaultPath'];
    }
    cityGroups.loadData(path);
  });
};

cityGroups.loadData = function(path) {
  if (path === undefined) {
    var path = cityGroups.paths.defaultPath;
  }
  var data = "";

  $.ajax({
    url: path,
    dataType: 'json',
    data: data,
    success: cityGroups.loadDataSuccess,
    error: cityGroups.loadDataError
  });

  return false;
};

cityGroups.loadDataError = function(data) {
  console.log("error");
  return false;
};

cityGroups.loadDataSuccess = function(data) {
  console.log("success!");
  $('div.loading').hide();
  cityGroups.data = data;
  cityGroups.map.loadMap();
  cityGroups.geoJSON(cityGroups.data.nodes);
  return false;
};

cityGroups.map.loadMap = function() {
  // initialize the map on the "map" div with a given center and zoom
  cityGroups.map.settings.zoom = 11;
  cityGroups.map.settings.center = new L.LatLng(47.6061889, -122.3308133);
  // cityGroups.map.settings.center = new L.LatLng(cityGroups.map.settings.latitude, cityGroups.map.settings.longitude);
  if(cityGroups.map.rendered === undefined) {
    cityGroups.map.rendered = new L.Map('map', cityGroups.map.settings.center);
  }
  // create a CloudMade tile layer
  cityGroups.map.cloudmadeUrl = 'http://{s}.tile.cloudmade.com/b59bc8b09cd84af58fcef3019d84e662/997/256/{z}/{x}/{y}.png',
  cityGroups.map.cloudmade = new L.TileLayer(cityGroups.map.cloudmadeUrl, {maxZoom: 18});
  cityGroups.map.rendered.setView(cityGroups.map.settings.center, cityGroups.map.settings.zoom).addLayer(cityGroups.map.cloudmade);
};

cityGroups.clearMarkers = function(marker) {
 
};

cityGroups.geoJSON = function(nodes) {
  var mapObject = [];
  var polygonPoints = [];
  var polygonPoint;
  var features = {};

  for (i in nodes) {
    var locationGeoObj = $.parseJSON(nodes[i]["node"]["location_geo"]);
    if(locationGeoObj.type !== undefined) {
      switch(locationGeoObj.type) {
        case "Point":
        console.log("point");
          cityGroups.map.popupPoints(nodes);
        break;
        case "Polygon":
          var polygonPoints = Array();
          for (p in locationGeoObj.coordinates[0]) {
            polygonPoint = p;
            polygonPoint = new L.LatLng(parseFloat(locationGeoObj.coordinates[0][p][1]),  parseFloat(locationGeoObj.coordinates[0][p][0]));
            polygonPoints.push(polygonPoint); 
          }
          cityGroups.map.popupPolygons(polygonPoints, nodes);
          // Draw a marker in the center of the Polygon.
          if(nodes[i]["node"]["latitude"] !== undefined) {
            cityGroups.map.popupPoints(nodes);    
          }
        break;
      }
    }
    else {
      if(nodes[i]["node"]["latitude"] !== undefined) {
      console.log("lat/lon");
        cityGroups.map.popupPoints(nodes);    
      }
    }
  }
};

cityGroups.map.popupPoints = function (nodes){
  var node = nodes[i]["node"];
  var marker = "";

  if(node.latitude !== undefined){
    var markerLocation = new L.LatLng(parseFloat(node.latitude), parseFloat(node.longitude));
    // @TODO escape these.
    var customMarkerStyle = {
      iconUrl: Drupal.settings.datawiki.mapMarkerIconUrl,
      iconSize: new L.Point(Drupal.settings.datawiki.mapMarkerIconPointSize[0], Drupal.settings.datawiki.mapMarkerIconPointSize[1]),
      iconAnchor: new L.Point(Drupal.settings.datawiki.mapMarkerIconAnchor[0], Drupal.settings.datawiki.mapMarkerIconAnchor[1]),
      popupAnchor: new L.Point(Drupal.settings.datawiki.mapMarkerPopupAnchor[0], Drupal.settings.datawiki.mapMarkerPopupAnchor[1])
    };
    var CustomMarker = L.Icon.extend(customMarkerStyle);
    var customIcon = new CustomMarker(),
    marker = new L.Marker(markerLocation, {icon: customIcon});
    cityGroups.map.rendered.addLayer(marker);
    marker.on('click', onMapClick);
    
  	function onMapClick(e) {
  	  $('div#popup-content div.content').html(cityGroups.map.popupTemplate(node));
  	}
  	
  	function offMapClick(e) {
      $('div#popup-content div.content').html('Click map to see where the groups are');
  	}
	}
};

cityGroups.map.popupPolygons = function (polygonPoints, nodes){
  var node = nodes[i]["node"];
  var marker = "";
  var polygon = new L.Polygon(polygonPoints, cityGroups.map.polygonOptions);
	var markerLocation = new L.LatLng(-1*parseFloat(node.latitude), -1*parseFloat(node.longitude));
  var customMarkerStyle = {
      iconUrl: Drupal.settings.datawiki.mapMarkerIconUrl,
      iconSize: new L.Point(Drupal.settings.datawiki.mapMarkerIconPointSize[0], Drupal.settings.datawiki.mapMarkerIconPointSize[1]),
      iconAnchor: new L.Point(Drupal.settings.datawiki.mapMarkerIconAnchor[0], Drupal.settings.datawiki.mapMarkerIconAnchor[1]),
      popupAnchor: new L.Point(Drupal.settings.datawiki.mapMarkerPopupAnchor[0], Drupal.settings.datawiki.mapMarkerPopupAnchor[1])
    };
  var CustomMarker = L.Icon.extend(customMarkerStyle);
  var customIcon = new CustomMarker(),
  marker = new L.Marker(markerLocation, {icon: customIcon});
  /*   cityGroups.map.rendered.removeLayer(marker); */
  cityGroups.map.rendered.addLayer(marker);
  marker.on('click', onMapClick);

	function onMapClick(e) {
	  $('div#popup-content div.content').html(cityGroups.map.popupTemplate(node));
    cityGroups.map.rendered.addLayer(polygon);
    polygon.on('click', offMapClick);
	}
	
	function offMapClick(e) {
    cityGroups.map.rendered.removeLayer(polygon);	
    $('div#popup-content div.content').html('Click map to see where the groups are');
	}
};

cityGroups.map.popupTemplate = function(node) {
  var output = '<div class="popup-item">';
  output += '<a href="' + node.permalink + '" class="title">' + node.title + '</a>';
  if(node.description !== undefined) {
    output += '<div class="description">' + node.description + '</div>';
  }
  if(node.categories !== undefined) {
    output += '<div class="categories">' + node.categories + '</div>';
  }
  
/*   output += "sign in to edit"; */
  output += '<a href="node/' + node.citygroups_nid + '"  >more</a> ';
  output += '<a href="node/' + node.citygroups_nid + '/edit" >edit</a>';
  output += '</div>';
  return output;
};


/**
 * Use Google's Geocode API to return a geocoded address.
 */
cityGroups.map.geocodeAddress = function (){
  //http://maps.googleapis.com/maps/api/geocode/json?address=1600+Amphitheatre+Parkway,+Mountain+View,+CA&sensor=true_or_false
  $('div#search-map input#search-map-submit').click(function() {
    var inputValue = $('input#search-map-input').val();

    inputValue = cityGroups.spaceToPlus(inputValue);
    var googleGeocode = 'http://maps.googleapis.com/maps/api/geocode/json?address=';
    var geocodeRequest = googleGeocode + inputValue;
    cityGroups.map.loadGeocodeSuccess();
    
    $.ajax({
      url: geocodeRequest,
      dataType: 'json',
      data: data,
      success: cityGroups.map.loadGeocodeSuccess,
      error: cityGroups.loadDataError
    });    
    
    // console.log(inputValue);
  });

};

/**
 * Convert spaces in a string to pluses.
 */
cityGroups.spaceToPlus = function(val) {
  // @TODO convert spaces to +
/*   val = val.replace(' ', '+'); */
  console.log(val);
  return val;
};

cityGroups.map.loadGeocodeSuccess = function(/* data */) {
/*   console.log(data); */
  // http://code.google.com/apis/maps/documentation/geocoding/

  var testGeoCodedData =
    {
    "status": "OK",
    "results": [ {
      "types": [ "street_address" ],
      "formatted_address": "1600 Amphitheatre Pkwy, Mountain View, CA 94043, USA",
      "address_components": [ {
        "long_name": "1600",
        "short_name": "1600",
        "types": [ "street_number" ]
      }, {
        "long_name": "Amphitheatre Pkwy",
        "short_name": "Amphitheatre Pkwy",
        "types": [ "route" ]
      }, {
        "long_name": "Mountain View",
        "short_name": "Mountain View",
        "types": [ "locality", "political" ]
      }, {
        "long_name": "California",
        "short_name": "CA",
        "types": [ "administrative_area_level_1", "political" ]
      }, {
        "long_name": "United States",
        "short_name": "US",
        "types": [ "country", "political" ]
      }, {
        "long_name": "94043",
        "short_name": "94043",
        "types": [ "postal_code" ]
      } ],
      "geometry": {
        "location": {
          "lat": 37.4219720,
          "lng": -122.0841430
        },
        "location_type": "ROOFTOP",
        "viewport": {
          "southwest": {
            "lat": 37.4188244,
            "lng": -122.0872906
          },
          "northeast": {
            "lat": 37.4251196,
            "lng": -122.0809954
          }
        }
      }
    } ]
  };
    
/*   cityGroups.map.form.mapGeocodedData(testGeoCodedData); */
};

cityGroups.map.form.mapGeocodedData = function(geocodedData) {
  console.log(geocodedData);
  var formObject = {};
  formObject.field_address = "";
  /*
    for (i in geocodedData.results.address_components) {
      switch(geocodedData.results.address_components[i]["types"][0]) {
        case 'street_number':
          formObject.field_address += geocodedData.results.address_components[i]["long_name"] + " ";
          break;
        case 'route':
          formObject.field_address += geocodedData.results.address_components[i]["long_name"];
          break;
        case 'locality':
          formObject.field_city = geocodedData.results.address_components[i]["long_name"];
          break;  
        case 'administrative_area_level_1':
          formObject.field_state = geocodedData.results.address_components[i]["short_name"];
          break;  
        case 'postal_code':
          formObject.field_zipcode = geocodedData.results.address_components[i]["long_name"];
          break;  
      }
    }
  */
  console.log(formObject);
};

/**
 * Load sample leaflet map.
 */
cityGroups.map.loadTestMap = function () {
	var map = new L.Map('map');
	
	var cloudmadeUrl = 'http://{s}.tile.cloudmade.com/BC9A493B41014CAABB98F0471D759707/997/256/{z}/{x}/{y}.png',
		cloudmadeAttribution = 'Map data &copy; 2011 OpenStreetMap contributors, Imagery &copy; 2011 CloudMade',
		cloudmade = new L.TileLayer(cloudmadeUrl, {maxZoom: 18, attribution: cloudmadeAttribution});
	
	map.setView(new L.LatLng(51.505, -0.09), 13).addLayer(cloudmade);
	
	
	var markerLocation = new L.LatLng(51.5, -0.09),
		marker = new L.Marker(markerLocation);
	
	map.addLayer(marker);
	marker.bindPopup("<b>Hello world!</b><br />I am a popup.").openPopup();
	

	var circleLocation = new L.LatLng(51.508, -0.11),
		circleOptions = {color: '#f03', opacity: 0.7},
		circle = new L.Circle(circleLocation, 500, circleOptions);
	
	circle.bindPopup("I am a circle.");
	map.addLayer(circle);
};