// FramelessWindow/ResizeHandles.qml
import QtQuick

Item {
    required property Window window
    
    // 可配置的拖拽区域大小
    property int edgeSize: 10
    property int cornerSize: 20
    
    QTCHandleArea { 
        edge: Qt.TopEdge
        window: parent.window
        height: edgeSize 
    }
    QTCHandleArea { 
        edge: Qt.BottomEdge
        window: parent.window
        height: edgeSize 
    }
    QTCHandleArea { 
        edge: Qt.LeftEdge
        window: parent.window
        width: edgeSize 
    }
    QTCHandleArea { 
        edge: Qt.RightEdge
        window: parent.window
        width: edgeSize 
    }
    QTCHandleArea { 
        edge: Qt.LeftEdge | Qt.TopEdge
        window: parent.window
        size: cornerSize 
    }
    QTCHandleArea { 
        edge: Qt.RightEdge | Qt.TopEdge
        window: parent.window
        size: cornerSize 
    }
    QTCHandleArea { 
        edge: Qt.LeftEdge | Qt.BottomEdge
        window: parent.window
        size: cornerSize 
    }
    QTCHandleArea { 
        edge: Qt.RightEdge | Qt.BottomEdge
        window: parent.window
        size: cornerSize 
    }
}