var map = new ol.Map({
    target: 'map',
    layers: [new ol.layer.Tile({source: new ol.source.OSM()})],
    view: new ol.View({
          center: ol.proj.fromLonLat([3.876716,43.61]),
          zoom: 14
    })
});

var mesMarkers = {};
var mesPopups = {};
$('body').on("change", "input[type=checkbox]", function() {
    let  valeur = $(this).attr('name');
    console.log("sélection de la case à cocher "+valeur);
    if ($(this).is(':checked')){
        document.getElementById(mesMarkers[valeur]).style.display='block';
        document.getElementById(mesPopups[valeur]).style.display='block';
    }else{
        document.getElementById(mesMarkers[valeur]).style.display='none';
        document.getElementById(mesPopups[valeur]).style.display='none';
    }
});		


function generateHtml(lien, parent){
    $.getJSON("JSON/"+lien, data => {
        for (let objet of data){
            if(objet.lien){
                $('#points_interet').append("<h3>"+objet.nom+"</h3><div id='"+objet.nom+"'>");
                generateHtml(objet.lien, objet.nom);
            }else{
                $('#'+parent).append("<input type='checkbox' name='"+objet.nom+"'>"+objet.nom+"</input>");

                let image = $("#markerProto").clone();
                image.attr("id", "marker"+objet.nom); // nomPI contient le nom du point d’intérêt
                $("body").append(image);
                mesMarkers[objet.nom] = "marker"+objet.nom;

                let ov = new ol.Overlay({
                    position: ol.proj.fromLonLat([objet.long, objet.lat]),
                    positioning: 'center-center',
                    element: document.getElementById("marker"+objet.nom)
                });
                map.addOverlay(ov);

                let popup = $("#popupProto").clone();
                popup.attr("id", "popup"+objet.nom);
                popup.append("<p>"+objet.nom+"</p>");;
                $("body").append(popup);
                mesPopups[objet.nom] = "popup"+objet.nom;

                let pop = new ol.Overlay({
                    offset: [0, -35],
                    position: ol.proj.fromLonLat([objet.long, objet.lat]),
                    element: document.getElementById("popup"+objet.nom)
                });
                map.addOverlay(pop);

            }
                
        }
    });
}

$().ready(function(){
    $('#points_interet').accordion({collapsible: true, heightStyle: 'content'});
    generateHtml("themes.json");
});

