import QtQuick 2.0

Rectangle {
    width: parent.width
    height: parent.height

    id: mainMenu


    Grid{
     columns: 2
     rows: 2
     id:mainGrid
     property double unitSize: getMin(parent.width, parent.height)/columns

     Rectangle { color: "red"; width: mainGrid.unitSize; height: mainGrid.unitSize}
     Rectangle { color: "green"; width: mainGrid.unitSize; height: mainGrid.unitSize}
     Rectangle { color: "blue"; width: mainGrid.unitSize; height: mainGrid.unitSize}
     Rectangle { color: "cyan"; width: mainGrid.unitSize; height: mainGrid.unitSize}




       function getMin(height, width) {
           if(height < width){
               return height
           }else{
               return width
           }
       }
    }



}

