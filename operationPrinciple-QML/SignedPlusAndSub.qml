import QtQuick 2.7
import QtQuick.Controls 1.4


/*
* 1. 首先是排版的问题要解决好
*     第一个数   +/-   第二个数    结果(灰色行编辑)    按钮

* 2. 将+/-拓展到乘除
*/

Item {
    anchors.fill: parent
    SignedPlusAndSubLabel{
        anchors.centerIn: parent
    }
}
