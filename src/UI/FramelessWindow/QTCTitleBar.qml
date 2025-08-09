// TitleBar.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Window

Item {
    id: titleBar
    height: 40
    property string title: ""
    required property Window window
    property alias rightContent: rightContainer.data


    width: parent ? parent.width : 600

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        radius: 8
        // 拖动窗口
        DragHandler {
            onActiveChanged: if (active)
                window.startSystemMove()
        }

        // 窗口标题
        Label {
            text: titleBar.title
            color: "white"
            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 20
            }
        }

        // 标题栏右侧内容（窗口按钮 + 用户自定义）
        Row {
            id: rightContainer
            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
                rightMargin: 10
            }
            spacing: 8

            // 最小化按钮
            Button {
                width: 30
                height: 30
                background: Rectangle { color: "transparent" }
                contentItem: Text {
                    text: "_"
                    color: "white"
                    font.bold: true
                    font.pixelSize: 16
                }
                onClicked: window.showMinimized()
            }

            // 最大化/还原按钮
            Button {
                width: 30
                height: 30
                background: Rectangle { color: "transparent" }
                contentItem: Text {
                    text: window.visibility === Window.Maximized ? "❐" : "☐"
                    color: "white"
                    font.pixelSize: 14
                }
                onClicked: {
                    if (window.visibility === Window.Maximized)
                        window.showNormal()
                    else
                        window.showMaximized()
                }
            }

            // 关闭按钮
            Button {
                width: 30
                height: 30
                background: Rectangle { color: "transparent" }
                contentItem: Text {
                    text: "✕"
                    color: "white"
                    font.bold: true
                }
                onClicked: window.close()
            }
        }
    }
}
