import QtQuick 2.7
import QtQuick.Controls 1.4

Item {
    anchors.fill: parent
    SignedNumberLabel{id: label0; name: 0; x: 20; y:  20}   //2
    SignedNumberLabel{id: label1; name: 1; x: 20; y:  90; enabled: false}   //4
    SignedNumberLabel{id: label2; name: 2; x: 20; y: 160; enabled: false}   //8
    SignedNumberLabel{id: label3; name: 3; x: 20; y: 230; enabled: false}   //16
    SignedNumberLabel{id: label4; name: 4; x: 20; y: 330; enabled: false}   //10

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
        if(num === 0)      return label0
        else if(num === 1) return label1
        else if(num === 2) return label2
        else if(num === 3) return label3
        else if(num === 4) return label4
        else {console.log("***Get wrong label")}
    }
}
