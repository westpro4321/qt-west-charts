import QtQuick 2.1
import QocQuick 1.0

Item {
    width: 500; height: 500
    ChartView {
        id: view
        anchors.fill: parent
        state: "stop"
        BarChart {
            id: chart
            backgroundColor: "khaki"
            foregroundColor: "#000000FF"

            model : DataSeries {
                id: series
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
        states: [
            State {
                name: "stop"
            },
            State {
                name: "start"
            }

        ]

        transitions: [
            Transition {
                from: "stop"; to: "start"
                ParallelAnimation {
                    NumberAnimation { target: chart.bars[0]; properties: "value"; from: (chart.bars[0].value === series.items[0].y ? 0 : chart.bars[0].value); to: series.items[0].y; duration: 2000 }
                    NumberAnimation { target: chart.bars[1]; properties: "value"; from: (chart.bars[1].value === series.items[1].y ? 0 : chart.bars[1].value); to: series.items[1].y; duration: 2000 }
                    NumberAnimation { target: chart.bars[2]; properties: "value"; from: (chart.bars[2].value === series.items[2].y ? 0 : chart.bars[2].value); to: series.items[2].y; duration: 2000 }
                    NumberAnimation { target: chart.bars[3]; properties: "value"; from: (chart.bars[3].value === series.items[3].y ? 0 : chart.bars[3].value); to: series.items[3].y; duration: 2000 }
                    NumberAnimation { target: chart.bars[4]; properties: "value"; from: (chart.bars[4].value === series.items[4].y ? 0 : chart.bars[4].value); to: series.items[4].y; duration: 2000 }
                    NumberAnimation { target: chart.bars[5]; properties: "value"; from: (chart.bars[5].value === series.items[5].y ? 0 : chart.bars[5].value); to: series.items[5].y; duration: 2000 }
                    NumberAnimation { target: chart.bars[6]; properties: "value"; from: (chart.bars[6].value === series.items[6].y ? 0 : chart.bars[6].value); to: series.items[6].y; duration: 2000 }
                    NumberAnimation { target: chart.bars[7]; properties: "value"; from: (chart.bars[7].value === series.items[7].y ? 0 : chart.bars[7].value); to: series.items[7].y; duration: 2000 }
                    NumberAnimation { target: chart.bars[8]; properties: "value"; from: (chart.bars[8].value === series.items[8].y ? 0 : chart.bars[8].value); to: series.items[8].y; duration: 2000 }
                }
            },
            Transition {
                from: "start"; to: "stop"
                ParallelAnimation {
                    NumberAnimation { target: chart.bars[0]; properties: "value"; from: chart.bars[0].value; to: 0; duration: 2000 }
                    NumberAnimation { target: chart.bars[1]; properties: "value"; from: chart.bars[1].value; to: 0; duration: 2000 }
                    NumberAnimation { target: chart.bars[2]; properties: "value"; from: chart.bars[2].value; to: 0; duration: 2000 }
                    NumberAnimation { target: chart.bars[3]; properties: "value"; from: chart.bars[3].value; to: 0; duration: 2000 }
                    NumberAnimation { target: chart.bars[4]; properties: "value"; from: chart.bars[4].value; to: 0; duration: 2000 }
                    NumberAnimation { target: chart.bars[5]; properties: "value"; from: chart.bars[5].value; to: 0; duration: 2000 }
                    NumberAnimation { target: chart.bars[6]; properties: "value"; from: chart.bars[6].value; to: 0; duration: 2000 }
                    NumberAnimation { target: chart.bars[7]; properties: "value"; from: chart.bars[7].value; to: 0; duration: 2000 }
                    NumberAnimation { target: chart.bars[8]; properties: "value"; from: chart.bars[8].value; to: 0; duration: 2000 }
                }
            }

        ]
    }

    MouseArea {
        anchors.fill: parent

        onPressed: {
            view.state == "stop" ? view.state = "start" : view.state = "stop"
            console.log(chart.bars[4].value);

        }
    }
    function f()
    {
        console.log("dupa");
    }
}

