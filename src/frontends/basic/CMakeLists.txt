cmake_minimum_required(VERSION 3.5)

project(basic LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(ASSETS_DIR assets)
FILE(GLOB ASSETS ${ASSETS_DIR}/*)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        run.cpp
        run.hpp
)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
install(TARGETS ${PROJECT_NAME} DESTINATION frontend)
install(FILES ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR}/${ASSETS_DIR})
