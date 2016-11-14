import QtQuick 2.7
import QtQuick.Controls 1.4

Item {
    TextField{
        id: inputFirst
        width: 100; height: 30
    }
    ComboBox{
        id: comb
        width: 40
        anchors.left: inputFirst.right
        anchors.leftMargin: 5
        anchors.top: inputFirst.top
        anchors.topMargin: 5
        model: ["+", "-"]
    }
    TextField{
        id: inputNext
        width: 100; height: 30
        anchors.left: comb.right
        anchors.leftMargin: 5
        anchors.top: inputFirst.top
    }
    TextField{
        id: output
        width: 100; height: 30
        anchors.left: button.right
        anchors.leftMargin: 15
        anchors.top: inputFirst.top
        enabled: false
    }

    Rectangle{
        id: button
        anchors.left: inputNext.right
        anchors.leftMargin: 15
        anchors.top: inputFirst.top
        anchors.topMargin: -5
        width: 50; height: 40
        radius: 4
        border.width: 3
        border.color: "#888"
        color: "transparent"
        property string text: "="
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
            onClicked:  myClicked()
            cursorShape: Qt.ArrowCursor
        }
    }
    function myClicked(){
        var number1 = inputFirst.text, number2 = inputNext.text
        var operator = comb.currentText
        var len1 = number1.length, len2 = number2.length
        console.log(number1, number2, operator, len1, len2)
        if(len1 <= len2){
            var dist = len2 - len1
            if(number1.charAt(1) === ","){
                var newStr = number1.substring(0, 2)
                for(var time = 0; time < dist; time ++){
                    newStr = newStr + "0"
                }
                newStr = newStr + number1.substring(2, len1)
                number1 = newStr
                len1 = len2
            }
        }else{
            var dist2 = len1 - len2
            if(number2.charAt(1) === ","){
                var newStr2 = number2.substring(0, 2)
                for(var time2 = 0; time2 < dist2; time2 ++){
                    newStr2 = newStr2 + "0"
                }
                newStr2 = newStr2 + number2.substring(2, len2)
                number2 = newStr2
                len2 = len1
            }
        }
        if(operator === "+"){
            var temp = ""
            var lastCon = "" //一个常量,全都是0, 为了方便while循环的展开条件
            var res = ""
            for(var i = 0; i < len1; i++){
                lastCon = lastCon + "0"

                if(number1.charAt(i) === "0" && number2.charAt(i) === "0"){
                    res = res + "0"
                }else if(number1.charAt(i) === "0" && number2.charAt(i) === "1"){
                    res = res + "1"
                }else if(number1.charAt(i) === "1" && number2.charAt(i) === "0"){
                    res = res + "1"
                }else if(number1.charAt(i) === "1" && number2.charAt(i) === "1"){
                    res = res + "1"
                }else if(number1.charAt(i) === "," && number2.charAt(i) === ","){
                    res = res + ""
                }// 二进制的加法, 接下来要做的就是正常的二进制加减逻辑写
            }



        }

        console.log("handled: ", number1, number2)
    }

}
