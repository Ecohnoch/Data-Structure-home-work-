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
        model: ["×"]
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
        text: "请在前面输入原码"
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
        if(inputFirst.text.charAt(1) === "," && inputNext.text.charAt(1) === ","){
            intMul(inputFirst.text, inputNext.text)
        }else if(inputFirst.text.charAt(1) === "." && inputNext.text.charAt(1) === "."){
            decMul(inputFirst.text, inputNext.text)
        }
    }
    function intMul(number1, number2){
        var operation = ""
        if(number1.charAt(0) === number2.charAt(0)){
            operation = "0"
        }else
            operation = "1"

        var n1 = "0" + number1.substring(2, number1.length)
        var n2 = number2.substring(2, number2.length)
        var len = n2.length    //循环进行的次数
        console.log("n1, n2: ", n1, n2)
        var i = 0     //循环变量
        var partRes = "" //部分积
        for(i = 0; i < n1.length; i ++){
            partRes = partRes + "0"
        }

        var mul = n2     //乘数
        for(i = 0; i < len; i++){

            if(mul.charAt(mul.length - 1) === "1"){
                partRes = hexMul(partRes, n1)
                mul = mul.substring(0, mul.length - 1)
                mul = partRes.charAt(partRes.length - 1) + mul
                partRes = rightMove(partRes)

                console.log("mul: ", mul)
            }else if(mul.charAt(mul.length - 1) === "0"){
                mul = mul.substring(0, mul.length - 1)
                mul = partRes.charAt(partRes.length - 1) + mul
                partRes = rightMove(partRes)
                console.log("mul: ", mul)
            }

        }
        var res = partRes + mul
        res = operation + number1.charAt(1) + res.substring(1, res.length)
        console.log("res: ", res)
        output.text = res
        return res

    }
    function decMul(number1, number2){
        var tempStr = intMul(number1, number2)
        var len = tempStr.length
        tempStr = tempStr.charAt(0) + "." + tempStr.substring(2, len)
        return tempStr
    }

    function rightMove(number){
        var newNumber = ""
        if(number.charAt(1) !== "0" && number.charAt(1) !== "1"){
            newNumber = number.charAt(0) + number.substring(2, number.length)
            newNumber = "0" + newNumber.substring(0, newNumber.length - 1)
            newNumber = newNumber.charAt(0) + number.charAt(1) + newNumber.substring(1,newNumber.length)
        }else{
            newNumber = number
            newNumber = "0" + newNumber.substring(0, newNumber.length - 1)
        }
        return newNumber
    }

    function hexMul(number1, number2){
        var len = number1.length
        var res = ""
        var plus = "0"
        var i = 0
        for(i = len - 1; i >= 0; --i){
            if(number1.charAt(i) === "0" && number2.charAt(i) === "0"){
                if(plus === "0"){
                    res = "0" + res
                }else if(plus === "1"){
                    res = "1" + res
                    plus = "0"
                }
            }else if(number1.charAt(i) === "0" && number2.charAt(i) === "1"){
                if(plus === "0"){
                    res = "1" + res
                }else if(plus === "1"){
                    res = "0" + res
                    plus = "1"
                }
            }else if(number1.charAt(i) === "1" && number2.charAt(i) === "0"){
                if(plus === "0"){
                    res = "1" + res
                }else if(plus === "1"){
                    res = "0" + res
                    plus = "1"
                }
            }else if(number1.charAt(i) === "1" && number2.charAt(i) === "1"){
                if(plus === "0"){
                    res = "0" + res
                    plus = "1"
                }else if(plus === "1"){
                    res = "1" + res
                    plus = "1"
                }
            }
        }
        if(plus === "1"){
            res = "1" + res
        }
        return res
    }
}













