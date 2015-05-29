/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
import QtQuick 2.0
import QtPositioning 5.2
import MyModules 1.1
CppCache {

    Rectangle{
        width: 200
        height: 200
        x:300
        y:300


        Text {
            width: parent.width
            height: parent.height
            text: "hello"+ parent.parent.nodeId
            font.pixelSize: 15
        }

    }
}
