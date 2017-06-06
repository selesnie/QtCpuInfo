import QtQuick 2.4

Item {
    id: dataSource
    property real mhz: 0
    property bool start: true

    SequentialAnimation {
        running: true
        loops: 1

        PauseAnimation {
            duration: 500
        }

        PropertyAction {
            target: dataSource
            property: "start"
            value: false
        }

        SequentialAnimation {
            loops: Animation.Infinite

            ParallelAnimation {
                NumberAnimation {
                    target: dataSource
                    property: "mhz"
                    easing.type: Easing.InOutSine
                    from: 0
                    to: 800
                    duration: 3000
                }
            }
            ParallelAnimation {
                NumberAnimation {
                    target: dataSource
                    property: "mhz"
                    easing.type: Easing.InOutSine
                    from: 800
                    to: 1200
                    duration: 600
                }
            }
            ParallelAnimation {
                NumberAnimation {
                    target: dataSource
                    property: "mhz"
                    easing.type: Easing.InOutSine
                    to: 2400
                    duration: 3000
                }
            }
            ParallelAnimation {
                NumberAnimation {
                    target: dataSource
                    property: "mhz"
                    easing.type: Easing.InOutSine
                    to: 3500
                    duration: 600
                }
            }
            ParallelAnimation {
                NumberAnimation {
                    target: dataSource
                    property: "mhz"
                    easing.type: Easing.InOutSine
                    to: 4000
                    duration: 3000
                }
            }
            ParallelAnimation {
                NumberAnimation {
                    target: dataSource
                    property: "mhz"
                    easing.type: Easing.InOutSine
                    to: 3600
                    duration: 600
                }
            }

            ParallelAnimation {
                NumberAnimation {
                    target: dataSource
                    property: "mhz"
                    easing.type: Easing.InOutSine
                    to: 0
                    duration: 3000
                }
            }

            PauseAnimation {
                duration: 5000
            }
        }
    }
}
