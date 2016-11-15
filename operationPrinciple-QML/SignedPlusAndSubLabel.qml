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
        if(inputFirst.text.charAt(1) === "," && comb.currentText === "+"){
            intPlus(inputFirst.text, inputNext.text)
        }else if(inputFirst.text.charAt(1) === "," && comb.currentText === "-"){
            intSub(inputFirst.text, inputNext.text)
        }else if(inputFirst.text.charAt(1) === "." && comb.currentText === "+"){
            decPlus(inputFirst.text, inputNext.text)
        }else if(inputFirst.text.charAt(1) === "." && comb.currentText === "-"){
            decSub(inputFirst.text, inputNext.text)
        }
    }

    function intPlus(number1, number2){
        number1 = getBu(number1)
        number2 = getBu(number2)
        console.log("Bu: YES", number1, number2)
        var len = number1.length
        var i = 0
        var tempStr = "0"  //补位的一个临时变量
        if(number1.charAt(0) === "1" && number2.charAt(0) === "1")
            tempStr = "1"
        var endLoop = "" //tempStr结束循环的条件
        var res = ""      //最后除了符号位的结果
        for(i = 0; i < len; i++){ // 补位要多一位
            if(i === 1) {res = res + ","; tempStr = tempStr + ","}
            else {res = res + "0"; tempStr = tempStr + "0"}
        }
        endLoop = tempStr
        for(i = len - 1; i >= 0; i--){
            if(i === 1) {}
            else{
                if(number1.charAt(i) === "0" && number2.charAt(i) === "1"){
                    res = res.substring(0, i) + "1" + res.substring(i + 1, len)
                }else if(number1.charAt(i) === "1" && number2.charAt(i) === "0"){
                    res = res.substring(0, i) + "1" + res.substring(i + 1, len)
                }else if(number1.charAt(i) === "0" && number2.charAt(i) === "0"){
                    res = res.substring(0, i) + "0" + res.substring(i + 1, len)
                }else if(number1.charAt(i) === "1" && number2.charAt(i) === "1"){
                    if(tempStr.charAt(i) !== ",")
                        tempStr = tempStr.substring(0, i) + "1" + tempStr.substring(i + 1, len + 1)
                    else{
                        tempStr = "01," + tempStr.substring(3, len + 1)
                    }
                }
            }
        }
        console.log("res: ", res, "tempStr: ", tempStr)
        while(tempStr !== endLoop){
            var length = res.length
            for(i = length - 1; i >= 2; i--){
                if(res.charAt(i) === "0" && tempStr.charAt(i + 1) === "0"){
                    res = res.substring(0, i) + "0" + res.substring(i + 1, length)
                }else if(res.charAt(i) === "0" && tempStr.charAt(i + 1) === "1"){
                    res = res.substring(0, i) + "1" + res.substring(i + 1, length)
                    tempStr = tempStr.substring(0, i + 1) + "0" + tempStr.substring(i + 2, length + 1)
                }else if(res.charAt(i) === "1" && tempStr.charAt(i + 1) === "0"){
                    res = res.substring(0, i) + "1" + res.substring(i + 1, length)
                }else if(res.charAt(i) === "1" && tempStr.charAt(i + 1) === "1" ){
                    res = res.substring(0, i) + "0" + res.substring(i + 1, length)
                    tempStr = tempStr.substring(0, i + 1) + "0" + tempStr.substring(i + 2, length + 1)
                    if(tempStr.charAt(i) !== ","){
                        tempStr = tempStr.substring(0, i) + "1" + tempStr.substring(i + 1, length + 1)
                        console.log("Debug+ ", i, tempStr, res)
                    }else{
                        tempStr = tempStr.charAt(0) + "1," + tempStr.substring(3, length + 1)
                        console.log("Debug++ ", i, tempStr, res)
                    }
                }
            }
            if(res.charAt(0) === "1" && tempStr.charAt(1) === "1"){  //判断tempStr最高位是否为1
                tempStr = "1" + tempStr.substring(1, tempStr.length)
            }

            var endLoop2 = ""
            for(i = 0; i < length - 2; i++){ //判断是否能够终止大循环while
                endLoop2 = endLoop2 + "0"
            }
            if(tempStr.substring(3, length + 1) === endLoop2){
                if(tempStr.charAt(1) === "0") res = "0," + res.substring(2, length)
                else res = "1," + res.substring(2, length)
                console.log("end: ", res, tempStr)
                break
            }
            console.log("in loops: ", res, tempStr)
        }
        console.log("Final Res: ", res)
        if(tempStr.charAt(0) !== tempStr.charAt(1)){  //判断是否溢出
            output.text = "Over Flow"
            return "Over Flow"
        }

        output.text =  res  //输出结果
        return res
        //机组 P238, 例6.9, 已经完成到求出来了第一轮temp和res
        //     1,1011
        //     1,0111

        //res: 0,1100
        //tmp:10,0110

        //res: 0,1010
        //tmp:10,1000

        //res: 0,0010
        //tmp:11,0000

        //res: 0,0010
        //tmp: 0,0000 //弹出符号位

    }

    function intSub(number1, number2){
        if(number2.charAt(0) === "0") number2 = "1" + number2.substring(1, number2.length)
        else number2 = "0" + number2.substring(1, number2.length)
        output.text = intPlus(number1, number2)
    }
    function decPlus(number1, number2){
        number1 = number1.charAt(0) + "," + number1.substring(2, number1.length)
        number2 = number2.charAt(0) + "," + number2.substring(2, number2.length)
        var res = intPlus(number1, number2)
        res = res.charAt(0) + "." + res.substring(2, res.length)
        output.text = res
    }
    function decSub(number1, number2){
        number1 = number1.charAt(0) + "," + number1.substring(2, number1.length)
        if(number2.charAt(0) === "0")
            number2 = "1," + number2.substring(2, number2.length)
        else
            number2 = "0," + number2.substring(2, number2.length)
        var res = intPlus(number1, number2)
        res = res.charAt(0) + "." + res.substring(2, res.length)
        output.text = res
    }

    //AUX function
    function getBu(yuan){
        var bu
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
        return bu
    }
}
