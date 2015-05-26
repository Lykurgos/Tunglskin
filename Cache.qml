import QtQuick 2.4
import QtPositioning 5.2
import MyModules 1.1

CppCache  {
    id: cppCache1

    property double imageX: parent.width/2- cache.width/2 + Math.cos(toRadians(angle))*geoDistance
    property double imageY: parent.height/2- cache.height/2 - Math.sin(toRadians(angle))*geoDistance


    property double imageDiameter: 20
    property double textX: imageX
    property double textY: flipText()//imageY+imageDiameter


    property variant geoDistance: wordlDistanceToGeoDistance(distance)

    Image {
        id: cache
        x: parent.imageX
        y: parent.imageY
        width: parent.imageDiameter
        height: parent.imageDiameter
        opacity: 1
        sourceSize.height: 500
        sourceSize.width: 500
        fillMode: Image.Stretch
        source: "cache.svg"


        }
    Text{
        x: parent.textX
        y: parent.textY
        text: parent.cacheName
        font.pixelSize: 12
        color: "gray"
    }
    function wordlDistanceToGeoDistance(input){

       if(input <=  1000){
           return Math.sqrt(input)*3.16227766  *(parent.width/100)/2
       }else{
           return Math.sqrt(1100)*3.16227766  *(parent.width/100)/2         //caches out of range, shown on border
       }


    /*
   normalDistance  = sqrt(realDistance) * 3,16227766
   formula makes 1km be at 2* 100 "normal"

   applies:
       Math.sqrt(input)*3.16227766

   100 is not half the screen width, so multiply up
       *(page.geoWidth/100)/2

    */


    }
    function toRadians (angle) {
        return angle * (Math.PI / 180);
    }
    function flipText(){
        if(angle > 180 || angle < 0){
            return imageY + imageDiameter;
        }else{
            return imageY - imageDiameter;
        }
    }
}

