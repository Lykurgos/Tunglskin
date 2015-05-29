/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
import QtQuick 2.0
import QtPositioning 5.2

Image {

    property variant coordinate:
        QtPositioning.coordinate(59.582222, 9.6775)
    id: you1
    x: page.geoCentreX- (width/2)
    y: page.geoCentreY- (height/2)
    width: 15
    height: 15

    opacity: 1
    sourceSize.height: 500
    sourceSize.width: 500
    fillMode: Image.Stretch
    source: "you.svg"

     signal userCoordinateUpdate( variant coordinate)

    onCoordinateChanged: {
        //console.log("user coordinate changed");
            you1.userCoordinateUpdate(coordinate);
        }

 }

