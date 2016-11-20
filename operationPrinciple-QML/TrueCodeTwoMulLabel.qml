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
        var number = inputFirst.text
        var number2 = inputNext.text
        var len1 = number.length + 2
        var len2 = number.length - 2
        var tag1 = getBu("0" + number.substring(1, number.length))
        var plus = hexMul("0" + number.substring(1, number.length), "0" + number.substring(1, number.length))
        var tag2 = plus.charAt(0) + number.charAt(1) + plus.substring(1, plus.length)
        var tag3 = getBu("1" + number.substring(1, number.length))
        tag.changeTextField(1, tag1)
        tag.changeTextField(2, tag2)
        tag.changeTextField(3, tag3)
        tag1 = "00" + tag1
        tag2 = "00" + tag2
        tag3 = "11" + tag3
        var res = ""
        for(var j = 0; j < len1; ++j){
            if(j === 3) res = res + number.charAt(1)
            else res = res + "0"
        }

        res = res + "00" +number2.substring(2, number2.length)
        var resLen = res.length

        var time = Math.ceil((number2.length - 2) / 2)
        var flag = getFlag(res, "0")
        var i = 0
        var tmp = ""
        console.log("Debug++ ", number, res, flag, time, res.substring(resLen - 2, resLen) + flag)
        for(i = 0; i < time; ++i){
            if(res.substring(resLen - 2, resLen) + flag === "000" || res.substring(resLen - 2, resLen) + flag === "111"){
                flag = getFlag(res, flag)
                res = rightMove(res)
                res = rightMove(res)


                console.log("Debug++ ", res, flag)
            }else if(res.substring(resLen - 2, resLen) + flag === "001" || res.substring(resLen - 2, resLen) + flag === "010"){
                flag = getFlag(res, flag)
                tmp = hexMul(res.substring(0, len1).substring(0, 3)+res.substring(4, len1), tag1.substring(0,3) + tag1.substring(4, tag1.length))

                tmp = tmp.substring(0,3) + res.charAt(3) + tmp.substring(3, tmp.length)
                res = tmp + res.substring(len1, resLen)

                res = rightMove(res)
                res = rightMove(res)

                console.log("Debug++x ", res, flag)
            }else if(res.substring(resLen - 2, resLen) + flag === "011" || res.substring(resLen - 2, resLen) + flag === "100"){
                flag = getFlag(res, flag)
                tmp = hexMul(res.substring(0, len1).substring(0, 3)+res.substring(4, len1), tag2.substring(0, 3) + tag2.substring(4, tag2.length))
                tmp = tmp.substring(0, 3) + res.charAt(3) + tmp.substring(3, tmp.length)
                res = tmp + res.substring(len1, resLen)
                res = rightMove(res)
                res = rightMove(res)

                console.log("Debug++2 ", res, flag)
            }else if(res.substring(resLen - 2, resLen) + flag === "101" || res.substring(resLen - 2, resLen) + flag === "110"){
                flag = getFlag(res, flag)
                tmp = hexMul(res.substring(0, len1).substring(0, 3)+res.substring(4, len1), tag3.substring(0, 3) + tag3.substring(4, tag3.length))
                tmp = tmp.substring(0, 3) + res.charAt(3) + tmp.substring(3, tmp.length)
                res = tmp + res.substring(len1, resLen)
                res = rightMove(res, 1)
                res = rightMove(res, 1)
                console.log("Debug++-x ", res, flag)
            }

            console.log("In loop: ", res)
        }

        console.log("Out loop: ", res.substring(res.length - 2, res.length) + flag)
        if(res.substring(res.length - 2, res.length) + flag === "000" || res.substring(res.length - 2, res.length) + flag === "111"){
            flag = getFlag(res, flag)
            console.log("Debug++ ", res, flag)
        }else if(res.substring(res.length - 2, res.length) + flag === "001" || res.substring(res.length - 2, res.length) + flag === "010"){
            flag = getFlag(res, flag)
            tmp = hexMul(res.substring(0, len1).substring(0, 3)+res.substring(4, len1), tag1.substring(0,3) + tag1.substring(4, tag1.length))
            console.log("Fuck", tmp)
            if(tmp.length === len1) tmp = tmp.substring(1, tmp.length)
            tmp = tmp.substring(0,3) + res.charAt(3) + tmp.substring(3, tmp.length)
            res = tmp + res.substring(len1, res.length)

            console.log("Debug++x ", res, flag)
        }else if(res.substring(res.length- 2, res.length) + flag === "011" || res.substring(res.length - 2, res.length) + flag === "100"){
            flag = getFlag(res, flag)
            tmp = hexMul(res.substring(0, len1).substring(0, 3)+res.substring(4, len1), tag2.substring(0, 3) + tag2.substring(4, tag2.length))
            if(tmp.length === len1) tmp = tmp.substring(1, tmp.length)
            tmp = tmp.substring(0, 3) + res.charAt(3) + tmp.substring(3, tmp.length)
            res = tmp + res.substring(len1, res.length)

            console.log("Debug++2 ", res, flag)
        }else if(res.substring(res.length - 2, res.length) + flag === "101" || res.substring(res.length - 2, res.length) + flag === "110"){
            flag = getFlag(res, flag)
            tmp = hexMul(res.substring(0, len1).substring(0, 3)+res.substring(4, len1), tag3.substring(0, 3) + tag3.substring(4, tag3.length))
            if(tmp.length === len1) tmp = tmp.substring(1, tmp.length)
            tmp = tmp.substring(0, 3) + res.charAt(3) + tmp.substring(3, tmp.length)
            res = tmp + res.substring(len1, resLen)
            console.log("Debug++-x ", res, flag)
        }

        if(number.charAt(0) === number2.charAt(0)){
            res = "0" + number.charAt(1) + res.substring(4, res.length - 2)
        }else{
            res = "1" + number.charAt(1) + res.substring(4, res.length - 2)
        }

        output.text = res


    }

    // aux function
    function getFlag(number, f){
        var flag = "0"
        if(f === "0"){
            if(number.charAt(number.length - 1) === "1" && number.charAt(number.length - 2) === "1"){
                flag = "1"
            }else{
                flag = "0"
            }
        }else{
            if(number.charAt(number.length - 2 === "0")){
                flag = "0"
            }else{
                flag = "1"
            }
        }

        return flag
    }

    function rightMove(number, f){
        var res = ""
        var oper = number.charAt(3)
        number = number.substring(0, 3) + number.substring(4, number.length)
        if(f === 1){
            res = "1" + number.substring(0, number.length - 1)
        }else{
            res = "0" + number.substring(0, number.length - 1)
        }
        res = res.substring(0, 3) + oper + res.substring(3, res.length)
        return res
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

    function charChange(str, i, ch){
        var len = str.length
        var res = ""
        if(i < 0 || i >= len){console.log("*** Char change failed!!"); return}
        for(var j = 0; j < len; j++){
            if(j === i){
                res = res + ch
                continue
            }
            res = res + str.charAt(j)
        }
        return res
    }

}













