import QtQuick
import QtQuick 2.15
import QtLocation
import QtPositioning

Item {
    property var geocodePlugin;
    property var tag;
    property string address;
    property var propParent;


    MapQuickItem {
        id: tag
        coordinate: null

        sourceItem: Image { source: "qrc:/ui/assets/locationMarker.png" }

        anchorPoint.x: sourceItem.width / 2
        anchorPoint.y: sourceItem.height
        parent: propParent
        visible: true

        onCoordinateChanged: {
            if(gpsHandler.x1 === 0.0 && gpsHandler.y1 === 0.0) {
                gpsHandler.x1 = coordinate.latitude;
                gpsHandler.y1 = coordinate.longitude;
            } else {
                gpsHandler.x2 = coordinate.latitude;
                gpsHandler.y2 = coordinate.longitude;
                gpsHandler.set_reset(true);
            }

            console.log(gpsHandler.x1 + " " + gpsHandler.y1 + " | " + gpsHandler.x2 + " " + gpsHandler.y2);
        }
    }

    GeocodeModel {
        plugin: geocodePlugin
        query: address
        onLocationsChanged: {
            if(count) tag.coordinate = get(0).coordinate
        }

        Component.onCompleted: update();
        onQueryChanged: update();
    }

    visible: true
    parent: propParent
    width: 1000
    height: 1000

    Component.onCompleted: update();
    onAddressChanged: {
        console.log(address);
        update();
    }
}
