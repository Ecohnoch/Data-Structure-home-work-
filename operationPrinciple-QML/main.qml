import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Operation Principle")

    menuBar: MenuBar{
        Menu{
            title: "方法"
            MenuItem{text: "进制转换"; onTriggered: {mainLoader.source = "HexConverter.qml"}}
            MenuItem{text: "有符号数表示"; onTriggered: {mainLoader.source = "SignedNumber.qml"}}
            MenuItem{text: "浮点表示"; onTriggered: {}}
            MenuItem{text: "IEEE754标准"; onTriggered: {}}
            MenuItem{text: "加减法运算"; onTriggered: {}}
            MenuItem{text: "乘除法运算"; onTriggered: {}}
            MenuItem{text: "待添加"; onTriggered: {}}
        }
    }

    Loader{
        id: mainLoader
        source: ""
    }


}
