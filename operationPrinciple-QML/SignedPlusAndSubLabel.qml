import QtQuick 2.7
import QtQuick.Controls 1.4

Item {
    TextField{
        id: inputFirst
        width: 100; height: 30
    }
    ComboBox{
        id: comb
        width: 100
        anchors.left: inputFirst.right
        anchors.leftMargin: 5
        anchors.top: inputFirst.top

        model: ["+", "-"]
    }
    TextField{
        id: inputNext
        width: 100; height: 30
        anchors.left: comb.right
        anchors.leftMargin: 5
        anchors.top: comb
    }
    TextField{
        id: output
        width: 100; height: 30
        anchors.left: inputNext.right
        anchors.leftMargin: 15
        anchors.top: comb
    }

    Rectangle{
        id: button
        anchors.left: out.right
        anchors.leftMargin: 30
        anchors.top: comb
        width: 50; height: 40
        radius: 4
        border.width: 3
        border.color: "#888"
        color: "transparent"
        property string text: "确认"
        Rectangle{
            id: background
            anchors.fill: parent
            color: "grey"
            visible: false
        }
        Text{
            anchors.centerIn: parent
            font.pixelSize: 20
            color: "#005AB5"
            text: parent.text
        }
        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {background.visible = true; background.opacity = 0.3}
            onExited: {background.opacity = 0; background.visible = false}
            onClicked:  {}
        }
    }

}
