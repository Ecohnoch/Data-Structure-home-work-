import QtQuick 2.7
import QtQuick.Controls 1.4

Item {
    anchors.fill: parent
    HexConverterLabel{id: label2;name: 0; x: 20; y: 20}   //2
    HexConverterLabel{id: label4;name: 1; x: 20; y: 90}   //4
    HexConverterLabel{id: label8;name: 2; x: 20; y: 160}   //8
    HexConverterLabel{id: label16;name: 3; x: 20; y: 230}   //16
    HexConverterLabel{id: label10;name: 4; x: 20; y: 330}   //10

    Text{
        id: signal
        x: 20; y: 375
        text: "成功!"
        opacity: 0
    }

    NumberAnimation {
        id: signalFadeIn; target: signal
        property: "opacity"; duration: 800; to: 1
        easing.type: Easing.InOutQuad; running: false
        onStopped: {signalFadeOut.restart()}
    }
    NumberAnimation {
        id: signalFadeOut; target: signal
        property: "opacity"; duration: 800; to: 0
        easing.type: Easing.InOutQuad; running: false
    }
    function signalShow(){
        signalFadeIn.restart()
    }

    function getLabel(num){
        if(num === 2) return label2
        else if(num === 4) return label4
        else if(num === 8) return label8
        else if(num === 16) return label16
        else if(num === 10) return label10
        else {console.log("***Get wrong label")}
    }
}
