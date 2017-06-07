import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    id: window
    visible: true
    color: "black"
    width: 1280
    height: 800
    title: qsTr("Qt CPU info")

    Rectangle {
        color: "black"
        width: window.width; height: window.height
        anchors.top: window.top
        anchors.bottom: window.bottom
        anchors.horizontalCenter: window.horizontalCenter
        anchors.fill: parent

        GridView {
            id: grid
            verticalLayoutDirection: GridView.TopToBottom
            cellWidth: (window.width-40)/4
            cellHeight: (window.height-40)/4
            anchors.leftMargin: 20
            anchors.rightMargin: anchors.leftMargin
            anchors.topMargin: anchors.leftMargin
            anchors.bottomMargin: anchors.leftMargin
            anchors.fill: parent
            model: cpuInfoDataModel
            delegate:
                Rectangle {
                width: grid.cellWidth
                height: grid.cellHeight
                color: "black"

                CircularGauge {
                    id: cpuSpeedometer
                    value: clockFreqMhz;
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.fill: parent
                    maximumValue: 4000
                    width: parent.width
                    height: parent.height

                    style: CpuSpeedGaugeStyle {}
                }

                Text {
                    id: name
                    color: "white"
                    anchors.fill: parent
                    text: {
                        var text = model + "\n" +
                                "CPU " + processor;
                        return text;
                    }
                }

//                Rectangle {
//                    anchors.fill: parent
//                    id: debugInfoArea
//                    color: "transparent"
//                    border.color: "blue"
//                    width: 50
//                    height: 50
//                }
            }
        }
    }
}
