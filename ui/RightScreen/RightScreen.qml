import QtQuick 2.15
import QtLocation

Rectangle {
    id: rightScreen
    anchors {
        top:    parent.top
        bottom: bottomBar.bottom
        right:  parent.right
    }

    color: "grey"
    width: parent.width * 2/3

    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name:  "osm.mapping.custom.host";
            value: "https://tile.thunderforest.com/transport/%z/%x/%y.png?apikey=fdfe4637f5c64797a63c012b407bd935"
        }
    }

    MapConfig { id: configuredMap }

    TopBar {
        id: topBar
    }

    SearchBar {
        id: navigationBar

        anchors {
            top:        topBar.bottom
            topMargin: 10
            left:       parent.left
            leftMargin: 15
        }

        width: parent.width * 1/3
        height: parent.height * 1/12
    }
}
