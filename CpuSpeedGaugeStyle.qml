import QtQuick 2.4
import QtQuick.Controls.Styles 1.4

CircularGaugeStyle {
    tickmarkStepSize: 400
    tickmark: Rectangle {
        implicitWidth: outerRadius * 0.02
        antialiasing: true
        implicitHeight: outerRadius * 0.06
        color: styleData.value >= 2400 ? "#e34c22" : "#e5e5e5"
    }

    minorTickmark: Rectangle {
        implicitWidth: outerRadius * 0.01
        antialiasing: true
        implicitHeight: outerRadius * 0.03
        color: styleData.value >= 2400 ? "#e34c22" : "#e5e5e5"
    }

    tickmarkLabel:  Text {
        font.pixelSize: Math.max(6, outerRadius * 0.1)
        text: styleData.value
        color: styleData.value >= 2400 ? "#e34c22" : "#e5e5e5"
        antialiasing: true
    }

    tickmarkInset: toPixels(0.04)
    labelStepSize: 400
    labelInset: toPixels(0.23)

    property real xCenter: outerRadius
    property real yCenter: outerRadius
    property real needleLength: outerRadius - tickmarkInset * 1.25
    property real needleTipWidth: toPixels(0.02)
    property real needleBaseWidth: toPixels(0.06)
    property bool halfGauge: false

    function toPixels(percentage) {
        return percentage * outerRadius;
    }

    background: Canvas {
        Text {
            id: cpuSpeedText
            font.pixelSize: toPixels(0.3)
            text: mhzInt
            color: "white"
            horizontalAlignment: Text.AlignRight
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.verticalCenter
            anchors.topMargin: toPixels(0.1)

            readonly property int mhzInt: control.value
        }

        Text {
            id: cpuSpeedLabel
            text: "MHz"
            color: "white"
            font.pixelSize: toPixels(0.15)
            anchors.top: cpuSpeedText.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    needle: Canvas {
        implicitWidth: needleBaseWidth
        implicitHeight: needleLength

        property real xCenter: width / 2
        property real yCenter: height / 2

        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();

            //Draw needle's bottom side
            ctx.beginPath();
            ctx.moveTo(xCenter, height);
            ctx.lineTo(xCenter - needleBaseWidth / 2, height - needleBaseWidth / 2);
            ctx.lineTo(xCenter - needleTipWidth / 2, 0);
            ctx.lineTo(xCenter, yCenter - needleLength);
            ctx.lineTo(xCenter, 0);
            ctx.closePath();
            ctx.fillStyle = Qt.lighter(Qt.rgba(247, 247, 247, 0.6));

            ctx.fill();

            //Draw needle's top side
            ctx.beginPath();
            ctx.moveTo(xCenter, height)
            ctx.lineTo(width, height - needleBaseWidth / 2);
            ctx.lineTo(xCenter + needleTipWidth / 2, 0);
            ctx.lineTo(xCenter, 0);
            ctx.closePath();
            ctx.fillStyle = Qt.lighter(Qt.rgba(255, 255, 255, 1.0));

            ctx.fill();
        }
    }

    foreground: null
}
