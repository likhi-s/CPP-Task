import QtQuick
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

ApplicationWindow
{
    width: 300
    height: 300
    visible: true

    RowLayout
    {
        anchors.centerIn: parent
        spacing: 20
        layoutDirection: Qt.TopToBottom


        Rectangle
        {
            id: _rect1
            width: 100; height: 30
            color: "orange"
            Layout.alignment: Qt.AlignTop
            Component.onCompleted: {
            console.log("Rect 1 ")
            }
        }

        Rectangle
        {
            id: _rect2
            width: 100; height: 30
            color: "blue"
            Layout.alignment: Qt.AlignBottom
            Component.onCompleted: {
                console.log("Rect 2 ")
            }
        }

        Rectangle
        {
            id: _rect3
            width: 100; height: 30
            color: "pink"
            Layout.alignment: Qt.AlignVCenter
            Component.onCompleted: {
                console.log("Rect 3 ")
            }
        }
    }
}
