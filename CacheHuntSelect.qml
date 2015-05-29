/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
import QtQuick 2.0


ListView {
    width: 180; height: 200


    delegate: Text {
        text: name + ": " + number
    }
}
