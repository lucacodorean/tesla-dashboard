import QtQuick 2.15

Rectangle {
    id: taskBar
    color: "black"
    anchors {
        left:   parent.left
        right:  parent.right
        bottom: parent.bottom
    }

    height: parent.height / 12

    Image {
        id: carSettingsIcon
        anchors {
            left: parent.left
            leftMargin: 30
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * .85
        fillMode: Image.PreserveAspectFit

        source:  "qrc:/ui/assets/carSettings.png"
    }

    Acclimatization {
        id: driversAcclimatization
        temperatureController: dTemperatureHandler

        anchors {
            left: carSettingsIcon.right
            leftMargin: 30
            verticalCenter: parent.verticalCenter
        }

    }


    Volume {
        id: volumeIndicator

        anchors {
           right: parent.right
           rightMargin: 135
           verticalCenter: parent.verticalCenter
        }
    }


    Acclimatization {
        id: passengerAcclimatization
        temperatureController: pTemperatureHandler


        anchors {
           right: parent.right
           rightMargin: 260
           verticalCenter: parent.verticalCenter
        }
    }
}
