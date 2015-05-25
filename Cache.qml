import QtQuick 2.4
import QtPositioning 5.2
import MyModules 1.1

CppCache  {
    id: cppCache1



    property variant geoDistance: wordlDistanceToGeoDistance(distance)

    Image {
    id: cache


    x: parent.parent.width/2- width/2 + Math.cos(toRadians(angle))*parent.geoDistance
    y: parent.parent.height/2- height/2 - Math.sin(toRadians(angle))*parent.geoDistance
    width: 20
    height: 20
    opacity: 1
    sourceSize.height: 500
    sourceSize.width: 500
    fillMode: Image.Stretch
    source: "cache.svg"

    function toRadians (angle) {
        return angle * (Math.PI / 180);
    }
    }
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: cppCache1
                x: 2
                visible: false
            }
        }
    ]


function wordlDistanceToGeoDistance(input){
     return Math.sqrt(input)*3.16227766  *(parent.width/100)/2


    /*
   normalDistance  = sqrt(realDistance) * 3,16227766
   formula makes 1km be at 2* 100 "normal"

   applies:
       Math.sqrt(input)*3.16227766

   100 is not half the screen width, so multiply up
       *(page.geoWidth/100)/2

    */
}
}

