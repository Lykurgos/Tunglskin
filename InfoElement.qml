/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
import QtQuick 2.0

Rectangle {
    width:  200
    height: 100
    id: textArea
    x: 0
    y: 0
    color: "#ffffff"
    radius: 13
    opacity: 1
    border.color: "#0c8166"
    border.width: 5

    property variant title
    property variant value

    Text {
        id: titleText
        x: 15
        y: 8
        text: textArea.title
        font.pixelSize: 24

}
    Text {
        id: valueText
        x: 15
        y: 49
        text: textArea.value
        font.pixelSize: 32
    }
}

