import QtQuick 2.1
import QocQuick 1.0

Rectangle {
    width: 360
    height: 360

    ChartView {
        anchors.fill: parent
        BarChart {
            model : DataSeries {
                DataItem {
                    x: 2
                    y: 300
                    color: "blue"
                }

                DataItem {
                    x: 18
                    y: 500
                    color: "blue"
                }

                DataItem {
                    x: 32
                    y: 300
                    color: "blue"
                }

                DataItem {
                    x: 48
                    y: 1000
                    color: "blue"
                }

                DataItem {
                    x: 62
                    y: 300
                    color: "blue"
                }
                DataItem {
                    x: 78
                    y: 500
                    color: "blue"
                }
                DataItem {
                    x: 94
                    y: 300
                    color: "blue"
                }
            }

        }
    }
}

