/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
import QtQuick 2.0
import QtQuick.Controls 1.2


ApplicationWindow {

    id: page2
    width: 200
    height: 200
    visible: true

    Button {
        id: northBtn
        x: 58
        y: 68
        text: qsTr("Nord")


        onClicked: me.coordinate= me.coordinate.atDistanceAndAzimuth(spinBox1.value, 0)
           }

    Button {
        id: southBtn
        x: 58
        y: 154
        text: qsTr("Sør")
        onClicked: me.coordinate = me.coordinate.atDistanceAndAzimuth(spinBox1.value, 180)
    }

    Button{
        id: westBtn
        x: 0
        y: 111
        text: qsTr("Vest")
        onClicked: me.coordinate = me.coordinate.atDistanceAndAzimuth(spinBox1.value, -90)
        }

    Button {
        id: eastBtn
        x: 115
        y: 111
        text: qsTr("Øst")
        onClicked: me.coordinate= me.coordinate.atDistanceAndAzimuth(spinBox1.value
                                                                     , 90)
    }

    SpinBox {
        id: spinBox1
        x: 30
        y: 17
        width: 93
        height: 35
        maximumValue: 1000
        decimals: 1
        value: 1
    }

    Label {
        id: label1
        x: 129
        y: 17
        text: qsTr("meter")
    }

}

