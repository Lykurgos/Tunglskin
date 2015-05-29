/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
import QtQuick 2.4
import QtQuick.Window 2.2

import QtMultimedia 5.0


Window {
    visible: true
    width: 800
    height: 600


    MainMenu{
        id: mainMenu
        objectName: "mainMenuObject"
    }


    CacheHunt{
        id: cacheHunt
        objectName: "cacheHuntObject"

    }


    MouseArea{
        height: parent.height /10
        width: parent.width/10
        x: parent.width - width
        y: parent.height- height
        id: backButton
        objectName: "backButtonObject"
        signal click
        onClicked:{

        click();

        }
        Rectangle{
         height: parent.height
         width: parent.width
         color: "red"
         z: -1
        }
    }

}//end window

