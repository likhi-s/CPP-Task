import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow
{
    visible: true
    width: 300
    height: 300
    title: "ColumnLayout Alignment Example"

    ColumnLayout {
        anchors.fill: parent
        spacing: 10
        Rectangle {
            width: 100
            height: 40
            color: "red"
            Layout.alignment: Qt.AlignLeft
            Text {
                text: "ColumnLeft"
                anchors.centerIn: parent
                color: "white"
                font.bold: true
            }
        }

        Rectangle {
            width: 100
            height: 40
            color: "green"
            Layout.alignment: Qt.AlignHCenter
            Text {
                text: "columnCenter"
                anchors.centerIn: parent
                color: "white"
                font.bold: true
            }
        }

        Rectangle {
            width: 100
            height: 40
            color: "blue"
            Layout.alignment: Qt.AlignRight
            Text {
                text: "ColumnRight"
                anchors.centerIn: parent
                color: "white"
                font.bold: true
            }
        }
    }

}
