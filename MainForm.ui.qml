import QtQuick 2.4

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360
    z: 2147483646

    MouseArea {
        id: mouseArea
        z: -1
        opacity: 0
        anchors.fill: parent
    }

    Text {
        anchors.centerIn: parent
        text: "Hello World"
        anchors.verticalCenterOffset: -29
        anchors.horizontalCenterOffset: -7
    }

    Image {
        id: image1
        x: 77
        y: 134
        width: 193
        height: 157
        z: 2
        fillMode: Image.Tile
        opacity: 0.4
        clip: false
        source: "../../Nedlastinger/sopp.jpeg"

        Text {
            id: text1
            x: 78
            y: 85
            text: qsTr("Textsdfsdfsdf")
            z: 1
            font.pixelSize: 12
        }
    }
}
