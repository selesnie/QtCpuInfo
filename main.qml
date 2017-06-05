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
                    id: gauge
                    anchors.fill: parent
                    style: CircularGaugeStyle {
                        needle: Rectangle {
                            y: outerRadius * 0.15
                            implicitWidth: outerRadius * 0.03
                            implicitHeight: outerRadius * 0.9
                            antialiasing: true
                            color: Qt.rgba(0.66, 0.3, 0, 1)
                        }
                        foreground: Item {
                            Rectangle {
                                width: outerRadius * 0.2
                                height: width
                                radius: width / 2
                                color: "#e5e5e5"
                                anchors.centerIn: parent
                            }
                        }
                        tickmark: Rectangle {
                            visible: styleData.value < 80 || styleData.value % 10 == 0
                            implicitWidth: outerRadius * 0.02
                            antialiasing: true
                            implicitHeight: outerRadius * 0.06
                            color: styleData.value >= 80 ? "#e34c22" : "#e5e5e5"
                        }
                    }

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
