import QtQuick
import QtQuick.Window
import "TaskBar"
import "RightScreen"
import "LeftScreen"


Window {
    width: 1280
    height: 720
    visible: true
    color: "white"
    title: qsTr("Luca's personal Tesla Dashboard")

    RightScreen {
        id: rightScreen

        Component.onCompleted: {
            gpsHandler.x1 = gpsHandler.y1 = 0.0;
            gpsHandler.x2 = gpsHandler.y2 = 0.0;
        }
    }

    LeftScreen {
        id: leftScreen
    }

    TaskBar {
        id: bottomBar
    }
}
