import QtQuick 2.0
//import ChartView 1.0
//import QocQuick 1.0

Item {
    width: 640; height: 480

//    Rectangle{
//        anchors.fill: parent

//        color: "blue"
//    }

    ChartView {
        anchors.fill: parent

        BarChart {
            model: series
        }

        DataSeries{
            id: series
            DataItem {
                x: 1
                y: 1
                color: "blue"
            }
        }
    }
}
