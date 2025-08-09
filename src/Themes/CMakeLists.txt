

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
    ThemesConfigParse.h
    ThemesConfigParse.cpp
    ThemeManager.h
    ThemeManager.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
    nlohmann_json::nlohmann_json
)