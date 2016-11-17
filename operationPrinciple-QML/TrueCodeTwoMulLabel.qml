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
//        console.log("Do Clicked!")
//        flagChanged(inputFirst.text)
        plus(inputFirst.text, inputNext.text)
    }

    // aux function
    function rightMove(number){
        var bu = getBu(number)

    }

    function flagChanged(number){
        tag.changeTextField(1, getBu(number))
        tag.changeTextField(2, plus(number,number))
        tag.changeTextField(3, (number.charAt(0) === "0")?"1":"0" + number.substring(1, number.length))
    }

    function plus(number1, number2){
        var tmp = "", res = ""
        var i = 0, len = number1.length
        for(i = 0; i <= len; ++i){
            tmp = tmp + "0"
            res = res + "0"
        }

        for(i = len - 1; i >= 0; --i){
            if(number1.charAt(i) === "0" && number2.charAt(i) ==="0"){
                res = charChange(res, i+1, "0")
                tmp = charChange(tmp, i+1, "0")
            }else if(number1.charAt(i) === "0" && number2.charAt(i) === "1"){
                res = charChange(res, i+1, "1")
                tmp = charChange(tmp, i+1, "0")
            }else if(number1.charAt(i) === "1" && number2.charAt(i) === "0"){
                res = charChange(res, i+1, "1")
                tmp = charChange(tmp, i+1, "0")
            }else if(number1.charAt(i) === "1" && number2.charAt(i) === "1"){
                res = charChange(res, i+1, "0")
                tmp = charChange(tmp, i, "1")
            }
        }
        console.log("tmp, res: ", tmp, res)
        var endLoop = ""
        for(i = 0; i <= len; ++i){
            endLoop = endLoop + "0"
        }
        while(tmp !== endLoop){
            for(i = len; i >= 0; --i){
                if(tmp.charAt(i) === "0" && res.charAt(i) === "0"){
                    res = charChange(res, i, "0")
                    tmp = charChange(tmp, i, "0")
                }else if(tmp.charAt(i) === "0" && res.charAt(i) === "1"){
                    res = charChange(res, i, "1")
                    tmp = charChange(tmp, i, "0")
                }else if(tmp.charAt(i) === "1" && res.charAt(i) === "0"){
                    res = charChange(res, i, "1")
                    tmp = charChange(tmp, i, "0")
                }else if(tmp.charAt(i) === "1" && res.charAt(i) === "1"){
                    res = charChange(res, i, "0")
                    if(i !== 0)
                        tmp = charChange(tmp, i-1, "1")
                }
            }
            console.log("in loop:", res, tmp)
            /// 这个地方还出了问题, tmp的哪个地方的1少加了来着
        }


        //      1111111
        //      1111111

        //tmp: 11111110
        //res: 00000000

        //     11111110
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













