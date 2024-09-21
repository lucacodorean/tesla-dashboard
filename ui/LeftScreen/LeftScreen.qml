import QtQuick 2.15

Rectangle {
    id: leftScreen
    anchors {
        top:    parent.top
        bottom: bottomBar.bottom
        left:  parent.left
    }

    color: "white"
    width: parent.width * 1/3

    Image {
        id: carView
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit

        source: "qrc:/ui/assets/car_view_mic.png"
    }
}
