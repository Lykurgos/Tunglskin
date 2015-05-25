import QtQuick 2.4
import QtPositioning 5.2
import MyModules 1.1

Rectangle {

    function getMin(height, width) {
        if(height < width){
            return height
        }else{
            return width
        }
    }



 //   MyItem{}
    id: page

    objectName: "pageObject"
    width: parent.width
    height: parent.height
    visible: true


    property variant geoSize: 0.85//screen portion reserved for geo
    property int infoX: width*geoSize

    property int geoHeight: getMin(height,width*geoSize)
    property int geoWidth: geoHeight
    property int geoCentreXY: geoWidth  /2


    Image {

        id: innerCircle
        x: page.geoCentreXY- (width/2)
        y: page.geoCentreXY- (height/2)
        width: Math.sqrt(10) *3.16227766 *(geoWidth/100)
        height: width
        sourceSize.height: 1000
        sourceSize.width: 1000
        fillMode: Image.Stretch

        source: "sirkel.svg"
        Text {
            id: range10Label
            x: parent.width/2 -width/2
            y: parent.height
            text: qsTr("10")
            font.pixelSize: 15
        }
    }
    Image {
        id: middleCircle
        x: page.geoCentreXY- (width/2)
        y: page.geoCentreXY- (height/2)
        width: Math.sqrt(100) *3.16227766 *(geoWidth/100)
        height: width
        sourceSize.height: 1000
        sourceSize.width: 1000
        fillMode: Image.Stretch
        source: "sirkel.svg"

        Text {
            id: range100Label
            x: parent.width/2 -width/2
            y: parent.height
            text: qsTr("100")
            font.pixelSize: 15
        }
    }

    Image {
        id: middle300Circle
        x: page.geoCentreXY- (width/2)
        y: page.geoCentreXY- (height/2)
        width: Math.sqrt(500) *3.16227766 *(geoWidth/100)
        height: width
        opacity: 1
        sourceSize.height: 1000
        sourceSize.width: 1000
        fillMode: Image.Stretch
        source: "sirkel.svg"

        Text {
            id: range300Label
            x: parent.width/2 -width/2
            y: parent.height
            text: qsTr("500")
            font.pixelSize: 15
        }
    }
    Image {
        id: outerCircle
        x: page.geoCentreXY- (width/2)
        y: page.geoCentreXY- (height/2)
        width: Math.sqrt(1000) *3.16227766 *(geoWidth/100)
        height: width
        opacity: 1
        sourceSize.height: 1000
        sourceSize.width: 1000
        fillMode: Image.Stretch
        source: "sirkel.svg"

        Text {
            id: range1000Label
            x: parent.width/2 -width/2
            y: parent.height-height
            text: qsTr("1000")
            font.pixelSize: 15
        }
    }

    Rectangle {
        id: infoRectangle
        x: page.infoX
        y: 0

        width: (1-page.geoSize) * page.width
        height: page.height
        color: "#a3f3e9"


        InfoElement {
            id: latInfo
            y: 0
            width: infoRectangle.width
            title: qsTr("lat")

            value: me.coordinate.latitude
        }
        InfoElement {
            id: longInfo
            y: latInfo.height
            width: infoRectangle.width
            title: qsTr("long")
            value: me.coordinate.longitude
        }
        InfoElement {
            id: cacheLatInfo
            y: latInfo.height
            width: infoRectangle.width
            title: qsTr("Cache lat")
            value: "0"

        }
        InfoElement {
            id: cacheLongInfo
            y: latInfo.height
            width: infoRectangle.width
            title: qsTr("Cache long")
            value: "0"
        }


    }//end infoRectangle

/*
    Cache{
        id: closeCache
       // coordinate: QtPositioning.coordinate(59.64689, 09.63530)
    }
    Cache{
        id: notSoCloseCache
       // coordinate: QtPositioning.coordinate(59.65060, 09.63656)
    }
    Cache{
        id: sECache
     //   coordinate: QtPositioning.coordinate(59.62906, 09.62317) //center: 59.64646, 09.63497
    }
*/

   function fixAngle(angle){
   if(angle < 0){
       return angle+360
   }else if (angle >= 360){
       return angle-360
   }else{
       return angle
   }
   }

   //function wordlDistanceToGeoDistance(input){
     //    return Math.sqrt(input)*3.16227766  *(page.geoWidth/100)/2


        /*
       normalDistance  = sqrt(realDistance) * 3,16227766
       formula makes 1km be at 2* 100 "normal"

       applies:
           Math.sqrt(input)*3.16227766

       100 is not half the screen width, so multiply up
           *(page.geoWidth/100)/2

        */
    //}
    You{
        id: me
        objectName: "meObject"
        x: page.geoCentreXY - width/2
        y: page.geoCentreXY- height/2

    }
    Item{
        x:parent.x
        y:parent.y
        property variant geoCentreXY: page.geoCentreXY


        objectName: "geoArea"
        height:page.geoHeight
        width:page.geoWidth
        opacity: 1

    }




    FakeGps{

    }
 /*   PositionSource {
        id: src
        updateInterval: 1000

       onActiveChanged: {
            var coord = src.position.coordinate;

            console.log("...:", coord.longitude, coord.latitude);

        }
        onPositionChanged: {
            latInfo.value = src.position.coordinate.latitude;
            var coord = src.position.coordinate;
            console.log("Coordinate:", coord.longitude, coord.latitude);


            if (src.supportedPositioningMethods ===
                              src.NoPositioningMethods) {
                          src.nmeaSource = "nmealog.txt";
                          sourceText.text = "(filesource): " + printableMethod(positionSource.supportedPositioningMethods);
                      }
               src.update();
        }
        }*/

/*
distance calculations:
  Math.sqrt(1000) *3.16227766 *(geoWidth/100)

  100 is the distance put into formula below. th

  formula below normalizes the
*/
  //  screen =100, rd=1000

  //  sd  = sqrt(rd) * 3,16227766

  //  rd = (sd/3,16227766)^2

}

