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
    }

    LeftScreen {
        id: leftScreen
    }

    TaskBar {
        id: bottomBar
    }
}
