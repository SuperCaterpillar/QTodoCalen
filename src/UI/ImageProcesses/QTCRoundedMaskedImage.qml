// components/RoundedMaskedImage.qml
import QtQuick
import QtQuick.Effects
import Qt5Compat.GraphicalEffects
import QtQuick.Effects
Item {
    id: root
    // 核心属性
    property alias radius: maskLayer.radius
    property alias source: bgImage.source
    property color maskColor: "white"
    property bool enableOverlay: false
    property color overlayColor : "#12121200"

    // 图片加载状态处理
    property bool loaded: false

    // 遮罩层
    Rectangle {
        id: maskLayer
        anchors.fill: parent
        radius: radius
        color: maskColor
        visible: false
    }

    // 图片层
    Image {
        id: bgImage
        anchors.fill: parent
        source: radius
        fillMode: Image.PreserveAspectCrop
        opacity: root.opacity
        visible: false
        onStatusChanged: {
            if (status == Image.Ready) {
                root.loaded = true
            }
        }
    }

    // 遮罩效果
    OpacityMask {
        id: maskEffect
        anchors.fill: parent
        source: bgImage
        maskSource: maskLayer
        invert: false
        smooth: true
        cached: true
    }
    // 半透明覆盖层（增强文本可读性）
    // Rectangle {
    //     id: bgOverlay
    //     anchors.fill: parent
    //     color: overlayColor
    //     visible: enableOverlay && root.source != ""
    //     radius: radius
    // }
     FastBlur {
         anchors.fill: maskEffect
         source: maskEffect
         radius: 10
     }

    // 状态控制
    function setImage(url) {
        bgImage.source = url
        bgImage.statusChanged.disconnect()
        bgImage.statusChanged.connect(function() {
            root.loaded = (bgImage.status === Image.Ready)
        })
    }

    // 调试辅助
    Component.onCompleted: {
        if (maskColor === "transparent") {
            console.warn("建议使用不透明颜色作为遮罩")
        }
    }
}
