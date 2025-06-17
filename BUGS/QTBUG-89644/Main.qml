// main.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: "ListView Reuse Example (Qt 5.15)"

    ListView {
        id: listView
        anchors.fill: parent
        model: 100
        reuseItems: true

        delegate: Item {
            width: listView.width
            height: 80

            Rectangle {
                id: rotatingRect
                width: 40
                height: 40
                anchors.centerIn: parent
                color: index % 2 === 0 ? "orange" : "steelblue"
                rotation: 0

                RotationAnimator on rotation {
                    id: rotator
                    running: true
                    loops: Animation.Infinite
                    from: 0
                    to: 360
                    duration: 2000
                }
            }

            Connections {
                target: listView
                onPooled: {
                    if (pooledItem === parent) {
                        console.log("⏸ Pausing animation for index:", index)
                        rotator.running = false
                    }
                }
                onReused: {
                    if (reusedItem === parent) {
                        console.log("▶️ Resuming animation for index:", index)
                        rotator.running = true
                    }
                }
            }

            Component.onCompleted: {
                console.log("✅ Created delegate for index:", index)
            }

            Component.onDestruction: {
                console.log("🗑 Destroyed delegate for index:", index)
            }
        }
    }
}
