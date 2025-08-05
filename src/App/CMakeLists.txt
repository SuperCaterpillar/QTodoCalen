target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
    QTCApplication.h
    QTCApplication.cpp
    QTCMainWindow.h
    QTCMainWindow.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})