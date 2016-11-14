import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Operation Principle")

    menuBar: MenuBar{
        Menu{
            title: "方法"
            MenuItem{text: "进制转换"; onTriggered: {mainLoader.source = "HexConverter.qml"}}
            MenuItem{text: "有符号数表示"; onTriggered: {mainLoader.source = "SignedNumber.qml"}}
            MenuItem{text: "二进制加减法"; onTriggered: {mainLoader.source = "SignedPlusAndSub.qml"}}
            MenuItem{text: "原码一位乘"; onTriggered: {}}
            MenuItem{text: "原码二位乘"; onTriggered: {}}
            MenuItem{text: "补码一位乘"; onTriggered: {}}
            MenuItem{text: "补码两位乘"; onTriggered: {}}
        }
    }

    Loader{
        id: mainLoader
        source: ""
    }


}
