import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    id: window
    visible: true
    width: 1024
    height: 768
    title: qsTr("Qt CPU info")

    Rectangle {
        color: "black"
        width: window.width; height: window.height
        anchors.bottom: window.bottom
        anchors.horizontalCenter: window.horizontalCenter

        GridView {
            id: grid
            verticalLayoutDirection: GridView.TopToBottom
            cellWidth: 400
            cellHeight: 250
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
                    id: speedometer
                    value: clockFreqMhz;
                    anchors.verticalCenter: parent.verticalCenter
                    maximumValue: 4000
                    width: height
                    height: parent.height

                    style: CpuSpeedGaugeStyle {}
                }

                Rectangle {
                    id: detailsInfoArea
                    color: "transparent"
                    border.color: "blue"
                    width: 50
                    height: 50

                    Text {
                        id: name
                        color: "white"
                        text: {
                            var text = model + "\n" +
                                    "CPU " + processor;
                            return text;
                        }
                    }
                }
            }
        }
    }
}
