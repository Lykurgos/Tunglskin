import QtQuick 2.4
import QtQuick.Window 2.2

import QtMultimedia 5.0


Window {
    visible: true
    width: 800
    height: 600


    MainMenu{

    }


    CacheHunt{
        id: cacheHunt
        objectName: "cacheHuntObject"

    }

    MouseArea {
        id: mouseArea1
        objectName: "stateSwitchClicker"
        x: 0
        y: 0
        width: 800
        height: 600
        signal switchState
        onClicked:{

        switchState();

        }

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

