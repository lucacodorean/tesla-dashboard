import QtQuick 2.15

Rectangle {
    id: topBar

    color: "#DCDCDC"
    anchors {
        left:   parent.left
        right:  parent.right
        top:    parent.top
    }

    height: parent.height / 16

    Image {
        id: lockedImage

        anchors {
            top:        parent.top;
            left:       parent.left;
            margins:    12
        }

        visible: true
        width: parent.width / 40
        fillMode: Image.PreserveAspectFit
        source: systemHandler.car_locked  ?  "qrc:/ui/assets/carLocked.png" : "qrc:/ui/assets/carUnlocked.png"
        MouseArea {
            anchors.fill: parent
            onClicked: systemHandler.set_car_locked(!systemHandler.car_locked)
        }
    }

    Text {
        id: time

        anchors {
            top: parent.top;
            left: lockedImage.right;
            topMargin: 15
            leftMargin: 40
            bottom: lockedImage.bottom;
        }

        font.pixelSize: 14
        color: "black"
        text: systemHandler.current_time_display;
    }

    Text {
        id: temperature

        anchors {
            top: parent.top;
            left: time.right;
            topMargin: 15
            leftMargin: 40
            bottom: parent.bottom;
        }

        font.pixelSize: 14
        color: "black"
        text: systemHandler.temperature + "°C";
    }

    Image {
        id: userImage

        anchors {
            top:        parent.top;
            left:       temperature.right;
            margins:    12
            leftMargin: 40
        }

        visible: true
        width: parent.width / 40
        fillMode: Image.PreserveAspectFit
        source: "qrc:/ui/assets/userImage.png"
    }

    Text {
        id: name

        anchors {
            top: parent.top;
            left: userImage.right;
            topMargin: 15
            leftMargin: 15
            bottom: parent.bottom;
        }

        font.pixelSize: 14
        color: "black"
        text: systemHandler.user;
    }
}
