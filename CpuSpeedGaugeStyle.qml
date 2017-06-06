import QtQuick 2.4
import QtQuick.Controls.Styles 1.4

CircularGaugeStyle {
    tickmarkStepSize: 400
    tickmark: Rectangle {
//        visible: styleData.value < 2400 || styleData.value % 10 == 0
        implicitWidth: outerRadius * 0.02
        antialiasing: true
        implicitHeight: outerRadius * 0.06
        color: styleData.value >= 2400 ? "#e34c22" : "#e5e5e5"
    }

    minorTickmark: Rectangle {
//        visible: styleData.value < 2400
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

    function degToRad(degrees) {
        return degrees * (Math.PI / 180);
    }

    function radToDeg(radians) {
        return radians * (180 / Math.PI);
    }

    function paintBackground(ctx) {
        if (halfGauge) {
            ctx.beginPath();
            ctx.rect(0, 0, ctx.canvas.width, ctx.canvas.height / 2);
            ctx.clip();
        }

        ctx.beginPath();
        ctx.fillStyle = "black";
        ctx.ellipse(0, 0, ctx.canvas.width, ctx.canvas.height);
        ctx.fill();

        ctx.beginPath();
        ctx.lineWidth = tickmarkInset;
        ctx.strokeStyle = "black";
        ctx.arc(xCenter, yCenter, outerRadius - ctx.lineWidth / 2, outerRadius - ctx.lineWidth / 2, 0, Math.PI * 2);
        ctx.stroke();

        ctx.beginPath();
        ctx.lineWidth = tickmarkInset / 2;
        ctx.strokeStyle = "#222";
        ctx.arc(xCenter, yCenter, outerRadius - ctx.lineWidth / 2, outerRadius - ctx.lineWidth / 2, 0, Math.PI * 2);
        ctx.stroke();

        ctx.beginPath();
        var gradient = ctx.createRadialGradient(xCenter, yCenter, outerRadius * 0.8, xCenter, yCenter, outerRadius);
        gradient.addColorStop(0, Qt.rgba(1, 1, 1, 0));
        gradient.addColorStop(0.7, Qt.rgba(1, 1, 1, 0.13));
        gradient.addColorStop(1, Qt.rgba(1, 1, 1, 1));
        ctx.fillStyle = gradient;
        ctx.arc(xCenter, yCenter, outerRadius - tickmarkInset, outerRadius - tickmarkInset, 0, Math.PI * 2);
        ctx.fill();
    }

    background: Canvas {
        onPaint: {
//            var ctx = getContext("2d");
//            ctx.reset();
//            paintBackground(ctx);
        }

        Text {
            id: speedText
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
            id: speedLabel
            text: "MHz"
            color: "white"
            font.pixelSize: toPixels(0.09)
            anchors.top: speedText.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: cpuIdText
            font.pixelSize: toPixels(0.1)
            text: "CPU"
            color: "white"
            horizontalAlignment: Text.AlignRight
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: speedLabel.bottom
            anchors.topMargin: toPixels(0.1)
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

            //Draw needle's top side
            ctx.beginPath();
            ctx.moveTo(xCenter, height);
            ctx.lineTo(xCenter - needleBaseWidth / 2, height - needleBaseWidth / 2);
            ctx.lineTo(xCenter - needleTipWidth / 2, 0);
            ctx.lineTo(xCenter, yCenter - needleLength);
            ctx.lineTo(xCenter, 0);
            ctx.closePath();
            ctx.fillStyle = Qt.lighter(Qt.rgba(247, 247, 247, 0.6));
            ctx.fill();

            //Draw needle's bottom side
            ctx.beginPath();
            ctx.moveTo(xCenter, height)
            ctx.lineTo(width, height - needleBaseWidth / 2);
            ctx.lineTo(xCenter + needleTipWidth / 2, 0);
            ctx.lineTo(xCenter, 0);
            ctx.closePath();
            ctx.fillStyle = Qt.lighter(Qt.rgba(229, 229, 229, 0.8));
            ctx.fill();
        }
    }

    foreground: null
}
