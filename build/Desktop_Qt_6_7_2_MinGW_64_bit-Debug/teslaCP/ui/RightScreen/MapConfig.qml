import QtLocation
import QtPositioning
import QtQuick
import QtQuick.Window


Map {
    id: map
    plugin: mapPlugin

    anchors.fill: parent
    anchors {
        top: topBar.bottom
    }

    center: QtPositioning.coordinate(47.14, 23.87)
    zoomLevel: 14

    onSupportedMapTypesChanged: {
        map.activeMapType = map.supportedMapTypes[map.supportedMapTypes.length - 1]
    }

    PinchHandler {
        id: pinch
        target: null
        onActiveChanged: if (active) {
                             map.startCentroid = map.toCoordinate(pinch.centroid.position, false)
                         }
        onScaleChanged: (delta) => {
                            map.zoomLevel += Math.log2(delta)
                            map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
                        }
        onRotationChanged: (delta) => {
                               map.bearing -= delta
                               map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
                           }
        grabPermissions: PointerHandler.TakeOverForbidden
    }

    WheelHandler {

        id: wheel
        acceptedDevices: Qt.platform.pluginName === "cocoa" || Qt.platform.pluginName === "wayland"
                         ? PointerDevice.Mouse | PointerDevice.TouchPad
                         : PointerDevice.Mouse
        rotationScale: 1/120
        property: "zoomLevel"
    }

    DragHandler {
        id: drag
        target: null
        onTranslationChanged: (delta) => map.pan(-delta.x, -delta.y)
    }

    Shortcut {
        enabled: map.zoomLevel < map.maximumZoomLevel
        sequence: StandardKey.ZoomIn
        onActivated: map.zoomLevel = Math.round(map.zoomLevel + 1)
    }

    Shortcut {
        enabled: map.zoomLevel > map.minimumZoomLevel
        sequence: StandardKey.ZoomOut
        onActivated: map.zoomLevel = Math.round(map.zoomLevel - 1)
    }

    RouteModel {
        property bool done: gpsHandler.reset || gpsHandler.ready

        id: routeModel
        plugin: map.plugin
        query: RouteQuery { id: routeQuery }

        Component.onCompleted: { update(); }

        onDoneChanged: {
            if(gpsHandler.ready) {
                gpsHandler.x1 = gpsHandler.y1 = gpsHandler.x2 = gpsHandler.y2 = 0.0;
                routeQuery.clearWaypoints();
                routeModel.reset();
                update();
                gpsHandler.set_ready(false);
            } else {
                routeQuery.addWaypoint(QtPositioning.coordinate(gpsHandler.x1, gpsHandler.y1));
                routeQuery.addWaypoint(QtPositioning.coordinate(gpsHandler.x2, gpsHandler.y2));
                update();
            }
        }
    }

    MarkerPoint {
        id: startPointMarker
        geocodePlugin: map.plugin
        address: gpsHandler.start_point
        propParent: map
    }


    MarkerPoint {
        id: endPointMarker
        geocodePlugin: map.plugin
        address: gpsHandler.end_point
        propParent: map
    }

    MapItemView {
        model: routeModel
        delegate: Component {
            MapRoute {
                route: routeData
                line.color: "blue"
                line.width: 5
                smooth: true
                opacity: 0.8
            }
        }
    }
}
