// FramelessWindow/HandleArea.qml
import QtQuick
import QtQuick.Window

Item {
    property var edge
    property Window window
    property int handleSize: 5
    property int size: handleSize
    // 优化：自动确定尺寸
    width: (edge & (Qt.LeftEdge | Qt.RightEdge)) ? size : parent.width
    height: (edge & (Qt.TopEdge | Qt.BottomEdge)) ? size : parent.height
    
    // 优化：自动定位
    anchors {
        left: (edge & Qt.LeftEdge) ? parent.left : undefined
        right: (edge & Qt.RightEdge) ? parent.right : undefined
        top: (edge & Qt.TopEdge) ? parent.top : undefined
        bottom: (edge & Qt.BottomEdge) ? parent.bottom : undefined
    }
    
    // 优化：鼠标区域更高效
    MouseArea {
        id: dragArea
        anchors.fill: parent
        hoverEnabled: true
        
        // 动态光标类型
        cursorShape: {
            if (edge & Qt.LeftEdge && edge & Qt.TopEdge) return Qt.SizeFDiagCursor
            if (edge & Qt.RightEdge && edge & Qt.BottomEdge) return Qt.SizeFDiagCursor
            if (edge & Qt.LeftEdge && edge & Qt.BottomEdge) return Qt.SizeBDiagCursor
            if (edge & Qt.RightEdge && edge & Qt.TopEdge) return Qt.SizeBDiagCursor
            if (edge & Qt.LeftEdge || edge & Qt.RightEdge) return Qt.SizeHorCursor
            if (edge & Qt.TopEdge || edge & Qt.BottomEdge) return Qt.SizeVerCursor
            return Qt.ArrowCursor
        }
        
        onPressed: window.startSystemResize(edge)
    }
}