import QtQuick 2.15

Rectangle {
    height: parent.height / 12

    Image {
        id:  decreaseVolume
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
            onClicked: volumeHandler.set_volume(volumeHandler.volume - 2)
        }
    }

    Image {
        id: volumePlaceholder
        anchors {
            left: decreaseVolume.right
            leftMargin: 6
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * 6
        fillMode: Image.PreserveAspectFit

        source: {
            if(volumeHandler.volume >=  1 && volumeHandler.volume <= 30) return "qrc:/ui/assets/volumeLow.png"
            if(volumeHandler.volume >= 31 && volumeHandler.volume <= 70) return "qrc:/ui/assets/volumeLoud.png"
            if(volumeHandler.volume >= 71)                               return "qrc:/ui/assets/volumeMaximum.png"
            return "qrc:/ui/assets/volumeNone.png"
        }
    }

    Image {
        id:  increaseVolume
        anchors {
            left: volumePlaceholder.right
            leftMargin: 6
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * 6
        fillMode: Image.PreserveAspectFit

        source:  "qrc:/ui/assets/increaseTemperature.png"

        MouseArea {
            anchors.fill: parent
            onClicked: volumeHandler.set_volume(volumeHandler.volume + 2)
        }
    }
}
