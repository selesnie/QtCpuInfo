import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Qt CPU info")

    Rectangle {
        color: "black"
        anchors.fill: parent

        GridView {
            id: grid
            verticalLayoutDirection: GridView.TopToBottom
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            cellWidth: (parent.width - anchors.leftMargin - anchors.rightMargin)/4
            cellHeight: window.height/3
            anchors.fill: parent

            model: cpuInfoDataModel
            delegate:
                Rectangle {
                width: grid.cellWidth
                height: grid.cellHeight
                anchors.leftMargin: 10
                anchors.rightMargin: 20
                anchors.topMargin: 20
                anchors.bottomMargin: 20
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
                    anchors.leftMargin: 10
                    anchors.rightMargin: 20
                    anchors.topMargin: 20
                    anchors.bottomMargin: 20

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
            }
        }
    }
}
