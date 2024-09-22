import QtQuick

Rectangle {

    property MarkerPoint startPoint;

    color: "#f0f0f0"
    radius: 5

    Image {
        id: searchIcon

        anchors {
            left:           parent.left
            leftMargin:     25
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * .45
        fillMode: Image.PreserveAspectFit

        source: "qrc:/ui/assets/searchIcon.png"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if(gpsHandler.end_point !== "" && gpsHandler.start_point !== "") {
                    gpsHandler.end_point = gpsHandler.start_point = null;
                }

                if((gpsHandler.start_point === "" || gpsHandler.start_point === null)) gpsHandler.start_point = navigationText.text;
                else gpsHandler.end_point = navigationText.text;

                navigationText.text = "";
            }
        }
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

            rightMargin: 40
            leftMargin: 15
        }

        verticalAlignment: Text.AlignVCenter
        clip: true

        color: "#373737"
        font.pixelSize: 15
        font.italic: true
    }

    Image {
        id: cancelIcon

        anchors {
            left:           navigationText.right
            leftMargin:     5
            verticalCenter: parent.verticalCenter
        }

        height: parent.height * .45
        fillMode: Image.PreserveAspectFit

        source: "qrc:/ui/assets/cancelButton.png"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                gpsHandler.set_ready(true);
                console.log("Reset clicked.");
                gpsHandler.x1 = gpsHandler.y1 = gpsHandler.y2 = gpsHandler.x2 = 0.0;
            }
        }
    }
}
