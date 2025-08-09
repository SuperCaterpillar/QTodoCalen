add_subdirectory(UI)
add_subdirectory(App)
add_subdirectory(Utilities)
add_subdirectory(Themes)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
    main.cpp
)

set_target_properties(${TC_APP_NAME} PROPERTIES

    # MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${TC_APP_NAME}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${TC_APP_NAME}
    PRIVATE
    Qt6::Charts
    Qt6::Concurrent
    Qt6::Core
    Qt6::Core5Compat
    Qt6::CorePrivate
    Qt6::Gui
    Qt6::Location
    Qt6::LocationPrivate
    Qt6::Multimedia
    Qt6::MultimediaQuickPrivate
    Qt6::Network
    Qt6::Positioning
    Qt6::PositioningPrivate
    Qt6::Qml
    Qt6::QmlIntegration
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Sensors
    Qt6::Svg
    Qt6::TextToSpeech
    Qt6::Widgets
    Qt6::Xml

    MainWindowModule
)
target_include_directories(${TC_APP_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(${TC_APP_NAME}
    PRIVATE
    QGC_APP_NAME="${QGC_APP_NAME}"

    # QGC_ORG_NAME="${QGC_ORG_NAME}"
    # QGC_ORG_DOMAIN="${QGC_ORG_DOMAIN}"
    # QGC_APP_VERSION_STR="${QGC_APP_VERSION_STR}"
    # QGC_SETTINGS_VERSION=${QGC_SETTINGS_VERSION}
    # $<$<NOT:$<BOOL:${QGC_STABLE_BUILD}>>:QGC_DAILY_BUILD>
    # $<$<BOOL:${QGC_DISABLE_APM_MAVLINK}>:QGC_NO_ARDUPILOT_DIALECT>
)
include(GNUInstallDirs)
install(TARGETS ${TC_APP_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
