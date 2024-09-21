import QtQuick 2.15

Rectangle {
    property var temperatureController;

    height: parent.height / 12

    Image {
        id:  decreaseTemp
        anchors {
            left: parent.left
            leftMargin: 30
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * 6
        fillMode: Image.PreserveAspectFit

        source:  "qrc:/ui/assets/decreaseTemperature.png"

        MouseArea {
            anchors.fill: parent
            onClicked: temperatureController.set_inside_temperature(temperatureController.inside_temperature - 0.2)
        }
    }

    Text {
        id: temperaturePlaceHolder
        anchors {
            left: decreaseTemp.right
            leftMargin: 6
            verticalCenter: parent.verticalCenter
        }


        color: "white"
        font.bold: true
        font.pixelSize: 20
        text: temperatureController.inside_temperature
    }

    Image {
        id:  increaseTemp
        anchors {
            left: temperaturePlaceHolder.right
            leftMargin: 6
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * 6
        fillMode: Image.PreserveAspectFit

        source:  "qrc:/ui/assets/increaseTemperature.png"

        MouseArea {
            anchors.fill: parent
            onClicked: temperatureController.set_inside_temperature(temperatureController.inside_temperature + 0.2)
        }
    }


}
