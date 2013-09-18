import QtQuick 2.1
import QocQuick 1.0

Rectangle {
    width: 360
    height: 360

    ChartView {
        anchors.fill: parent
        BarChart {

        }
    }

    function f(a, b) {
      console.log("a is ", a, "b is ", b);
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            f(1, 2)
        }
    }
}

