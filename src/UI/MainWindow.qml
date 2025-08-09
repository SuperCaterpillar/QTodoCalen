import QTodoCalen.UI
import QtQuick.Controls
import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQml

QTCFramelessWindow {
    width: ThemesManager.themeData.mainWindow.width
    height: ThemesManager.themeData.mainWindow.height
    cornerRadius: ThemesManager.themeData.mainWindow.radius ? ThemesManager.themeData.mainWindow.radius : ThemesManager.themeData.mainWindow.radius
    backgroundImage: ThemesManager.themeData.mainWindow.icon.source
    // Button {
    //             width: 30; height: 30
    //             background: Rectangle { color: "transparent" }
    //             contentItem: Text {
    //                 text: "_";
    //                 color: "white";
    //                 font { bold: true; pixelSize: 16 }
    //             }
    //             onClicked: root.showMinimized()
    //         }
}
