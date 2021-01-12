cmake_minimum_required(VERSION 3.5)

set(TARGET reactor)
project(${TARGET} LANGUAGES CXX)

set(SRC_DIR cpp)
set(INC_DIR hpp)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

find_package (Threads)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# collect exec files
set(SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/reactor.cpp
)
set(INCLUDES
        ${INC_DIR}/reactor.hpp
)
set(TARGET_FILES ${SOURCES} ${INCLUDES})

add_executable(${TARGET} ${TARGET_FILES})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${TARGET} processor_dummy Qt${QT_VERSION_MAJOR}::Widgets basic ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${PROJECT_NAME} DESTINATION backend)