import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import AndroidInterface 1.0
ApplicationWindow {
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Hello World")
    AndroidInterface{
        id: android
    }
    Rectangle{
        height:   parent.height * 0.3
        width:    height
        radius:   height/2
        border.color:  "black"
        anchors.centerIn: parent
        Button{
            text: "check"
            anchors.centerIn: parent
            onClicked:{
                console.log("clicked ")
                android.setNotification("Namasthay Joshika")
                console.log("clicked 1")
            }
        }
    }
}
