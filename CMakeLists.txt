cmake_minimum_required(VERSION 3.16)

list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_SOURCE_DIR}/cmake
)

include(CustomOptions)
include(Toolchain)

project(${TC_APP_NAME} VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)



find_package(Qt6

    # ${QGC_QT_MINIMUM_VERSION}...${QGC_QT_MAXIMUM_VERSION}
    REQUIRED
    COMPONENTS
    Charts
    Concurrent
    Core
    Core5Compat
    Gui
    LinguistTools
    Location
    Multimedia
    Network
    Positioning
    Qml
    QmlIntegration
    Quick
    QuickControls2
    QuickWidgets
    Sensors
    Sql
    Svg
    TextToSpeech
    Widgets
    Xml
    OPTIONAL_COMPONENTS
    Bluetooth
    MultimediaQuickPrivate
    OpenGL
    Quick3D
    SerialPort
    Test
)

qt_standard_project_setup(REQUIRES 6.8)

list(APPEND QTC_RESOURCES
    ${CMAKE_SOURCE_DIR}/resources/qtcresources.qrc
    ${CMAKE_SOURCE_DIR}/themes/themes.qrc

    # ${CMAKE_SOURCE_DIR}/resources/qtcresources.qrc
    # ${CMAKE_SOURCE_DIR}/qgroundcontrol.qrc
)

qt_add_executable(${CMAKE_PROJECT_NAME}
    WIN32
    MACOSX_BUNDLE
    ${QTC_RESOURCES}
)
qt_add_qml_module(${TC_APP_NAME}
    URI ${TC_APP_NAME}
    VERSION 1.0
    RESOURCE_PREFIX /qml
)
add_subdirectory(src)
