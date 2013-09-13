import QtQuick 2.0

Item {
    width: 640; height: 480

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
