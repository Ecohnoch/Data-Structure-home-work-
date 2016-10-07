/*

* 基本思路: 使用json去保存文本数据(一看就能看懂吧,
         然后用一个随机数生成器去访问相应结点的数据
* 具体实现: 0. 构建文件读写类...
           1. 创建一个GUI,表示输入和显示文本 (太丑了..有时间优化
           2. 创建一个data对象, 是解析了json数据之后的根对象
           3. 创建parser解析函数, 传入输入的信息和根对象
           4. 根据输入的信息在根对象中检索,返回检索的信息
* 注意事项: 1. 请用Qt打开, main.qml是主工程文件
           2. json文件编写时请按照格式进行编写
           3. 检索规则为包含该子字符串则返回dataJson中1,2,3种任意一个字符串
           4. 具体看一下压缩包里的视频就ok了.

*/

import QtQuick 2.7
import QtQuick.Controls 2.0
import File 1.0

Rectangle {
    color: "lightblue"
    width: 200; height: 100
    clip: false
    Text{
        id: textOutput
        anchors.centerIn: parent
        text: parser("Hello")
        font.family: "Helvetica"
    }
    Rectangle{
        anchors.fill: textInput
        color: "white"
    }
    TextArea{
        id: textInput
        anchors.horizontalCenter: textOutput.horizontalCenter
        anchors.top: textOutput.bottom
        width: 150
        font.pixelSize: 15
        font.family: "Helvetica"
    }
    Button {
        id: sure
        width: 20; height: 20
        anchors.left: textInput.right
        anchors.leftMargin: 5
        anchors.verticalCenter: textInput.verticalCenter
        text: "Do"; font.pixelSize: 5
        onClicked: {
            textOutput.text = parser(textInput.text)
            textInput.clear()
        }
    }

    function parser(msg){
        var jsonData = JSON.parse(File.read(":/data.json"))
        var ss = msg.toLowerCase()
        for (var key in jsonData){
            if(ss.indexOf(key) !== -1){
                return jsonData[key][Math.floor(Math.random()*3)+1]
            }
        }
        return "sorry, I don't remember that!"
    }
}
