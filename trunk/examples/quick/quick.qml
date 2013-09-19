import QtQuick 2.1
import QocQuick 1.0

Item {
    width: 500; height: 500
    ChartView {
        anchors.fill: parent
        BarChart {
            backgroundColor: "khaki"
            foregroundColor: "#000000FF"

            model : DataSeries {
                DataItem {
                    x: 1; y: 2
                    color: "crimson"
                }
                DataItem {
                    x: 2; y: 3
                    color: "limegreen"
                }
                DataItem {
                    x: 3; y: 2
                    color: "deepskyblue"
                }
                DataItem {
                    x: 4; y: 6
                    color: "coral"
                }
                DataItem {
                    x: 5; y: 9
                    color: "mediumseagreen"
                }
                DataItem {
                    x: 6; y: 6
                    color: "teal"
                }
                DataItem {
                    x: 7; y: 2
                    color: "red"
                }
                DataItem {
                    x: 8; y: 3
                    color: "lime"
                }
                DataItem {
                    x: 9; y: 2
                    color: "aqua"
                }
            }
        }
    }
}

