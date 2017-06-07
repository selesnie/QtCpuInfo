import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt CPU info")

    color: "black"
    DataSource {
        id: dataSource
    }

    Rectangle {
        width: window.width; height: window.height

        color: "black"
        GridView {
            id: grid
            verticalLayoutDirection: GridView.TopToBottom
            cellWidth: 150
            cellHeight: 150
            anchors.leftMargin: 20
            anchors.rightMargin: anchors.leftMargin
            anchors.topMargin: anchors.leftMargin
            anchors.bottomMargin: anchors.leftMargin
            anchors.fill: parent
            model: cpuInfoDataModel
            delegate:
                Rectangle {
                width: grid.cellWidth/1.1
                height: grid.cellHeight/1.1
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

                Text {
                    id: cpuModel
                    anchors.top: parent.bottom
                    color: "white"
                    text: {
                        return model;
                    }
                }

                Text {
                    id: cpuId
                    anchors.top: parent.top
                    color: "white"
                    text: {
                        return "CPU" + processor;
                    }
                }
            }
        }
    }
}
