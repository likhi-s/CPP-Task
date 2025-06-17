import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: qsTr("Repeater Example")

    ColumnLayout
    {
        anchors.centerIn: parent

        Repeater {
            model: 15
            delegate: Text
            {
                text: "Item " + index
            }
        }
    }
}
