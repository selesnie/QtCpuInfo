import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    id: window
    visible: true
    width: 400
    height: 800
    title: qsTr("Cool stuff")

    DataSource {
        id: dataSource
    }

    Rectangle {
        width: window.width; height: window.height

        GridView {
            id: grid
            verticalLayoutDirection: GridView.TopToBottom
            cellWidth: 200
            cellHeight: 200
            anchors.fill: parent
            model: cpuDataModel
            delegate:
                Rectangle {
                width: grid.cellWidth
                height: grid.cellHeight
                color: "#494d53"

                CircularGauge {
                    id: speedometer
                    value: dataSource.mhz
                    anchors.verticalCenter: parent.verticalCenter
                    maximumValue: 4000
                    width: height
                    height: parent.height

                    style: CpuSpeedGaugeStyle {}

                    Text {
                        color: "white"
                        text: {
                            return "CPU #" + processor + ": " + clockFreqMhz;
                        }
                    }
                }
            }
        }
    }
}
