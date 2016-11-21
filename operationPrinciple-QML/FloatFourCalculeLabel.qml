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
        model: ["+", "-", "×", "÷"]
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
        duijie("00,010", "00,001")
    }

    //对阶
    // 11,011;11.011000
    // 11,100;00.111000

    // 11,011
    // 00,100  //00,100的补码

    // 11,111
    function duijie(number1, number2){
        var n1 = "", n2 = ""   //n1 = "11011"  n2 = "00100"
        n1 = number1.substring(0, 2) + number1.substring(3, number1.length)
        if(number2.charAt(0) === "1"){
            n2 = "00" + number2.substring(3, number2.length)
        }else{
            n2 = getBu("1" + number2.substring(2, number2.length))
            n2 = "11" + n2.substring(2, n2.length)
        }
        var res = ""
        res = hexMul(n1, n2)
        if(res.length > n1.length){
            res = res.substring(1, res.length)
        }
        console.log("res: ", res)
        var sx = getSx(inputFirst.text)
        sx = sx.substring(0, 2) + sx.substring(3, sx.length)
        var sy = getSx(inputNext.text)
        sy = sy.substring(0, 2) + sy.substring(3, sy.length)
        var jx = number1.substring(0,2) + number1.substring(3, number1.length)
        var jy = number2.substring(0,2) + number2.substring(3, number2.length)
        var sres = res.substring(2, res.length)
        var dist = hex2Ten(sres)
        var distHex = ten2Hex(dist, jx.length)

        if(res.charAt(0) === "0"){
            console.log("正", dist)
            for(var jj = 0; jj < dist; ++jj)
                sy = rightMove(sy)
            jy = hexMul(jy, distHex)
            inputNext.text = jy.substring(0, 2) + "," + jy.substring(2, jy.length) + ";" + sy.substring(0, 2) + "." + sy.substring(2, sy.length)
        }else{
            console.log("负", dist)
            for(var ii = 0; ii < dist; ++ii)
                sx = rightMove(sx)
            jx = hexMul(jx, distHex)
            inputFirst.text = jx.substring(0, 2) + "," + jx.substring(2, jx.length) + ";" + sx.substring(0, 2) + "." + sx.substring(2, sx.length)
        }
    }

    //尾数求和
    function sxsyPlus(number1, number2){
        var n1 = "", n2 = ""
        n1 = getSx(number1); n2 = getSx(number2)
        // 这里我直接假设符号位是两位了
        n1 = n1.substring(0, 2) + n1.substring(3, n1.length)
        n2 = n2.substring(0, 2) + n2.substring(3, n2.length)
        var res = hexMul(n1, n2)

    }

    function getSx(number){
        var i = 0, pos = 0
        for(i = 0; i < number.length; ++i){
            if(number.charAt(i) === ";"){
                pos = i
            }
        }
        var res = number.substring(pos + 1, number.length)
        return res
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

    function hex2Ten(number){
        var len = number.length
        var i = 0, res = 0
        for(i = 0; i < len; ++i){
            res += Math.pow(2, len - 1 - i) * parseInt(number.charAt(i))
        }
        console.log(res)
        return res
    }

    function ten2Hex(number, len){
        var res2 = []
        var r2 = ""

        var temp = number
        while(temp !== 0 && temp !== 1){
            var rec = temp % 2
            res2.push(rec)
            temp = Math.floor(temp / 2)
        }
        res2.push(temp)
        while(res2.length){
            r2 += res2.pop()
        }
        var dist = 0
        if(r2.length < len){
            dist = len - r2.length
        }
        var i = 0
        for(i = 0; i < dist; ++i){
            r2 = "0" + r2
        }
        return r2
    }

    function tenTon(num){


        console.log(r2)

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
