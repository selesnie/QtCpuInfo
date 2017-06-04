import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Work in progress")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        ListView {
            width: 100; height: 100

            model: myModel
            delegate: Rectangle {
                height: 25
                width: 100

                Text {
                    text: {
                        var text = "CPU id: " + processor;
                        text += ", vendor: " + vendor;
                        text += ", model: " + model;
                        text += ", freq: " + clockFreqMhz;
                        return text;
                    }
                }
            }
        }

        Page1 {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }
}
