import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: qsTr("Main in QTBUG-91435 Module")

    Label {
        text: "Loaded from module"
        anchors.centerIn: parent
    }
}
