import QtQuick 2.7
import QtQuick.Controls 1.4

Item {
    property int name   // 0-zhenzhi   1-yuanma   2-buma    3-fanma    4-yima

    property var chineseName: ["真值", "原码", "补码", "反码", "移码"]

    property string number
    Rectangle{
        id: bitName
        width: 70; height: 40
        color: "transparent"
        border.width: 3
        border.color: "grey"
        Label{
            anchors.centerIn: parent
            text: chineseName[name]
        }
    }

    TextField{
        id: input
        width: 100; height: 30
        anchors.left: bitName.right
        anchors.leftMargin: 30
        anchors.top: bitName.top
        anchors.topMargin: 5
    }
    function changeText(text){
        input.text = text
    }

    Rectangle{
        id: button
        anchors.left: input.right
        anchors.leftMargin: 35
        anchors.top: bitName.top
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
            onClicked:  myClicked(name)
        }
    }
    function zhenZhi(str){
        var yuan = "", bu = "", fan = "", yi = ""
        if(str.charAt(0) === "-" && str.charAt(2) !== "."){
            yuan = "1," + str.substring(1, str.length)
        }else if(str.charAt(0) === "+" && str.charAt(2) !== "."){
            yuan = "0," + str.substring(1, str.length)
        }else if(str.charAt(0) === "-" && str.charAt(2) === "."){
            yuan = "1." + str.substring(3, str.length)
        }else if(str.charAt(0) === "+" && str.charAt(2) === "."){
            yuan = "0." + str.substring(3, str.length)
        }
        console.log("come on,", yuan)
        if(yuan.charAt(0) === "0") bu = yuan
        else{
            bu = yuan.substring(0, 2)
            for(var ii = 2; ii < yuan.length; ii++){
                if(yuan.charAt(ii) === "0") bu = bu + "1"
                else bu = bu + "0"
            }
            var oneLen = 0
            for(var lastBits = bu.length - 1; lastBits > 1; lastBits--){
                if(bu.charAt(lastBits) === "1") oneLen++
                else break
            }
            if(bu.charAt(bu.length - oneLen) === "," || bu.charAt(bu.length - oneLen) === "."){
                var buLen = bu.length
                bu = bu.substring(0, 2)
                bu = bu + "1"
                for(var t = 0; t < buLen; t++){
                    bu = bu + "0"
                }
            }else{
                var changeLast = bu.length - 1
                bu = bu.substring(0, bu.length - oneLen - 1)
                bu = bu + "1"
                for(; changeLast >= bu.length - oneLen; changeLast--){
                    bu = bu + "0"
                }
            }
        }
        console.log("Come On: ", yuan, "bu", bu)
        if(yuan.charAt(0) === "0") fan = yuan
        else{
            fan = yuan.substring(0, 2)
            for(var fanLen = 2; fanLen < yuan.length; fanLen ++ ){
                if(yuan.charAt(fanLen) === "0") fan = fan + "1"
                else fan = fan + "0"
            }
        }
        console.log("Come on2:", yuan, "fan", fan)
        yi = bu.substring(1, bu.length)
        if(bu.charAt(0) === "1") yi = "0" + yi
        else yi = "1" + yi
        console.log("Come on3:", yuan, "yi", yi)
        getLabel(1).changeText(yuan)
        getLabel(2).changeText(bu)
        getLabel(3).changeText(fan)
        getLabel(4).changeText(yi)
        signalShow()
    }

    
    
    function myClicked(name){
        var string = input.text
        switch(name){
            case 0: zhenZhi(string); break;
            case 1: yuanMa(string); break;
            case 2: buMa(string); break;
            case 3: fanMa(string); break;
            case 4: yiMa(string); break;
        }
        signalShow()
    }

}
