import QtQuick 2.7
import QtQuick.Controls 1.4

Item {
    Text{
        id: text1
        width: 30; height: 30
        text: "[x*]补"
    }
    TextField{
        id: text1Field
        width: 100; height: 30
        anchors.left: text1.right
        anchors.leftMargin: 20
        anchors.top: text1.top
        anchors.topMargin: -5
        text: "请先输入原码"
        enabled: false
    }
    Text{
        id: text2
        anchors.top: text1.bottom
        anchors.topMargin: 10
        width: 30; height: 30
        text: "[2x*]补"
    }
    TextField{
        id: text2Field
        width: 100; height: 30
        anchors.left: text2.right
        anchors.leftMargin: 20
        anchors.top: text2.top
        anchors.topMargin: -5
        text: "请先输入原码"
        enabled: false
    }
    Text{
        id: text3
        anchors.top: text2.bottom
        anchors.topMargin: 10
        width: 30; height: 30
        text: "[-x*]补"
    }

    TextField{
        id: text3Field
        width: 100; height: 30
        anchors.left: text3.right
        anchors.leftMargin: 20
        anchors.top: text3.top
        anchors.topMargin: -5
        text: "请先输入原码"
        enabled: false
    }
    function changeTextField(num, text){
        switch(num){
            case 1: text1Field.text = text; break
            case 2: text2Field.text = text; break
            case 3: text3Field.text = text; break
        }
    }
}
