import QtQuick 2.7
import QtQuick.Controls 1.4

Item {
    property int name   // 0-2   1-4   2-8    3-16    4-10

    property var chineseName: ["二进制", "四进制", "八进制", "十六进制", "十进制"]

    property string number
    Rectangle{
        id: hexName
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
        anchors.left: hexName.right
        anchors.leftMargin: 30
        anchors.top: hexName.top
        anchors.topMargin: 5
    }
    function changeText(text){
        input.text = text
    }

    Rectangle{
        id: button
        anchors.left: input.right
        anchors.leftMargin: 35
        anchors.top: hexName.top
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
            cursorShape: Qt.ArrowCursor
        }
    }


    // 2 Main Functions
    function mToTen(num, m){
        var ten = 0, i = num.length - 1

        for(; i >= 0; --i){
            var len = num.length - i - 1
            var ii// = parseInt(num.charAt(i))
            if(m === 16){
                if(num.charAt(i) === 'A' || num.charAt(i) === 'a') ii = 10
                else if(num.charAt(i) === 'B' || num.charAt(i) === 'b') ii = 11
                else if(num.charAt(i) === 'C' || num.charAt(i) === 'c') ii = 12
                else if(num.charAt(i) === 'D' || num.charAt(i) === 'D') ii = 13
                else if(num.charAt(i) === 'E' || num.charAt(i) === 'e') ii = 14
                else if(num.charAt(i) === 'F' || num.charAt(i) === 'f') ii = 15
                else{
                    ii = parseInt(num.charAt(i))
                    if(ii < 0 || ii >= 10) {console.log("***Error when hex 16"); return}
                }
            }else{
                ii = parseInt(num.charAt(i))
                if(m === 2 && (ii < 0 || ii >= 2)){
                    console.log("***Error when hex 2"); return
                }else if(m === 4 && ii < 0 || ii >= 4){
                    console.log("***Error when hex 4"); return
                }else if(m === 8 && ii < 0 || ii >= 8){
                    console.log("***Error when hex 8"); return
                }
            }
            ten += ii * Math.pow(m, len)
        }
        console.log("Res: ", ten)
        return ten
    }


    function tenTon(num){
        var res2 = [], res4 = [], res8 = [], res16 = []
        var r2 = "", r4 = "", r8 = "", r16 = ""

        var temp = num
        while(temp !== 0 && temp !== 1){
            var rec = temp % 2
            res2.push(rec)
            temp = Math.floor(temp / 2)
        }
        res2.push(temp)
        while(res2.length){
            r2 += res2.pop()
        }

        temp = num
        while(temp >= 4){
            var rec2 = temp % 4
            res4.push(rec2)
            temp = Math.floor(temp / 4)
        }
        res4.push(temp)
        while(res4.length){
            r4 += res4.pop()
        }

        temp = num
        while(temp >= 8){
            var rec3 = temp % 8
            res8.push(rec3)
            temp = Math.floor(temp / 8)
        }
        res8.push(temp)
        while(res8.length){
            r8 += res8.pop()
        }

        temp = num
        while(temp >= 16){
            var rec4 = temp % 16
            if(rec4 === 15) rec4 = "F"
            else if(rec4 === 14) rec4 = "E"
            else if(rec4 === 13) rec4 = "D"
            else if(rec4 === 12) rec4 = "C"
            else if(rec4 === 11) rec4 = "D"
            else if(rec4 === 10) rec4 = "E"
            res16.push(rec4)
            temp = Math.floor(temp / 16)
        }
        if(temp < 10) res16.push(temp)
        else if(temp === 10) res16.push("A")
        else if(temp === 11) res16.push("B")
        else if(temp === 12) res16.push("C")
        else if(temp === 13) res16.push("D")
        else if(temp === 14) res16.push("E")
        else if(temp === 15) res16.push("F")
        while(res16.length){
            r16 += res16.pop()
        }

        console.log(r2, r4, r8, r16)
        getLabel(2).changeText(r2)
        getLabel(4).changeText(r4)
        getLabel(8).changeText(r8)
        getLabel(16).changeText(r16)

    }


    // GUI Functions
    function twoToOthers(num){
        var ten = mToTen(num, 2) + ""
        getLabel(10).changeText(ten)
        var tenNum = parseInt(ten)
        tenToOthers(tenNum)
    }
    function fourToOthers(num){
        var ten = mToTen(num, 4) + ""
        getLabel(10).changeText(ten)
        var tenNum = parseInt(ten)
        tenToOthers(tenNum)
    }
    function eightToOthers(num){
        var ten = mToTen(num, 8) + ""
        getLabel(10).changeText(ten)
        var tenNum = parseInt(ten)
        tenToOthers(tenNum)
    }
    function sixteenToOthers(num){
        var ten = mToTen(num, 16) + ""
        getLabel(10).changeText(ten)
        var tenNum = parseInt(ten)
        tenToOthers(tenNum)
    }
    function tenToOthers(num){
        var number = parseInt(num)
        tenTon(number)
    }

    function myClicked(name){
        number = input.text
        switch(name){
            case 0: twoToOthers(number); break;
            case 1: fourToOthers(number); break;
            case 2: eightToOthers(number); break;
            case 3: sixteenToOthers(number); break;
            case 4: tenToOthers(number); break;
        }
        signalShow()
    }
}
