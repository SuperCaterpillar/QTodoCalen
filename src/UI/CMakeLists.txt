project(MainWindowModule)

qt_add_library(MainWindowModule STATIC)

qt_add_qml_module(MainWindowModule
    URI ${TC_APP_NAME}.UI.MainWindow
    OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${TC_APP_NAME}/UI/MainWindow
    VERSION 1.0
    RESOURCE_PREFIX /qml
    QML_FILES
        MainWindow.qml
    NO_PLUGIN
)
