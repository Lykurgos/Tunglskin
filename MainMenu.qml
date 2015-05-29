/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
import QtQuick 2.0
import MyModules 1.1

Rectangle {
    width: parent.width
    height: parent.height
    signal ghClicked
    color: "light gray"
    Grid{
     columns: 2
     rows: 2
     id:mainGrid
     objectName: "gridObject"
     property double unitSize: getMin(parent.width, parent.height)/columns
spacing: 3

     MainMenuButton{
         color: "white"
         imageSrc: "geoHuntIcon.svg"
         text: "lets Hunt!"
         textRotation: -15
         width: mainGrid.unitSize
         height: mainGrid.unitSize
         objectName: "ghButton"
     }
     MainMenuButton{
         color: "white"
         imageSrc: "avgCoordinateIcon.svg"
         text: "Averager!"
         textRotation: -15
         width: mainGrid.unitSize
         height: mainGrid.unitSize
         objectName: "avgButton"
     }

     MainMenuButton{
         color: "light green"
         text: "N/A"
         width: mainGrid.unitSize
         height: mainGrid.unitSize
     }
     MainMenuButton{
         color: "light blue"
         text: "N/A"
         width: mainGrid.unitSize
         height: mainGrid.unitSize
     }

       function getMin(first, second) {
           if(first < second){
               return first
           }else{
               return second
           }
       }
    }



}

