/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
import QtQuick 2.0
import MyModules 1.1
Rectangle{
signal clicked;
    property var text
    property var textRotation
    property var imageSrc
Image {
 id: cache
 width: parent.width
 height: parent.height
 opacity: 1
 sourceSize.height: 500
 sourceSize.width: 500
 fillMode: Image.PreserveAspectFit
 source: parent.imageSrc


 Text {
         x: parent.width / 2 - width/2
         y: parent.height *0.75
         text: parent.parent.text
         font.pixelSize: 36
         rotation: parent.parent.textRotation
 }
 MouseArea {
     width: parent.width
     height: parent.height

     onClicked:{
         parent.parent.clicked();

     }

 }

}
}
