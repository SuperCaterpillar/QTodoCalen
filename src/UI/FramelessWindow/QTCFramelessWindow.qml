import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQml
import Qt5Compat.GraphicalEffects
import QtQuick.Effects
import QTodoCalen.UI

Window {
    id: root
    visible: true
    color: "transparent"
    flags: Qt.Window | Qt.FramelessWindowHint

    property string windowIcon: ""
    property int cornerRadius: 0
    property bool enableShadow: true
    default property alias content: contentContainer.data

    // 背景图片属性
    property alias backgroundImage: bgImage.source         // 背景图片路径
    property real backgroundOpacity: 1.0       // 背景图片透明度
    property int backgroundBlurRadius: 0       // 背景模糊效果半径
    property color overlayColor: "#12f00e0e"   // 背景覆盖层颜色（默认半透明黑色）
    property bool enableOverlay: true           // 是否启用覆盖层

    Component.onCompleted: {
        if (windowIcon !== "") {
            root.setIcon(Qt.resolvedUrl(windowIcon));
        }
    }

    // 窗口背景
    Rectangle {
        id: background
        anchors.fill: parent
        radius: root.cornerRadius
        color: "transparent" // 背景矩形本身透明
        clip: true

        QTCRoundedMaskedImage {
            id: bgImage
            anchors.fill: parent
            radius: root.cornerRadius
            // source: root.backgroundImage
        }
    }

    QTCTitleBar {
        id: titleBar
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        title: "root.title"
        window: root
    }

    // 内容容器
    Item {
        id: contentContainer
        anchors.fill: parent
        anchors.margins: root.cornerRadius > 0 ? 1 : 0
        clip: true
    }

    QTCResizeHandles {
        anchors.fill: parent
        window: root
        edgeSize: 5
        cornerSize: 5
    }

    function toggleMaximized() {
        if (root.visibility === Window.Maximized) {
            root.showNormal();
        } else {
            root.showMaximized();
        }
    }
}
