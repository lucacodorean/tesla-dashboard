import QtQuick

Rectangle {

    id: searchBar

    color: "#f0f0f0"
    radius: 5

    Image {
        id: searchIcon

        anchors {
            left:       parent.left
            leftMargin: 25
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * .45
        fillMode: Image.PreserveAspectFit

        source: "qrc:/ui/assets/searchIcon.png"
    }

    Text {
        id: navigationTextPlaceHolder

        anchors {
            verticalCenter: parent.verticalCenter
            left: searchIcon.right
            leftMargin: 18
        }

        color: "#373737"
        font.pixelSize: 15
        font.italic: true
        text: "Navigate"

        visible: navigationText.text === ""
    }


    TextInput {
        id : navigationText


        anchors {
            left:   searchIcon.right
            right:  parent.right
            top:    parent.top
            bottom: parent.bottom

            leftMargin: 18
        }

        verticalAlignment: Text.AlignVCenter
        clip: true

        color: "#373737"
        font.pixelSize: 15
        font.italic: true
    }
}
