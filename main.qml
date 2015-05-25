import QtQuick 2.4
import QtQuick.Window 2.2

//hjemme: 59.64660, 09.63527
//nære: 59.64659, 09.63530
// <100m 59.64664, 09.63536
//<1km 59.65060, 09.63656
import QtMultimedia 5.0


Window {
    visible: true
    width: 800
    height: 600

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 800
        height: 600
        color: "#7f79e1"
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
   // onClicked:{cacheHunt.visible = !cacheHunt.visible

}

}//end window

