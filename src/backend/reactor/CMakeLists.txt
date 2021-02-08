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
        ${SRC_DIR}/moderator.cpp
)
set(INCLUDES
        ${INC_DIR}/reactor.hpp
        ${INC_DIR}/moderator.hpp
)
set(TARGET_FILES ${SOURCES} ${INCLUDES})
set(CMAKE_CXX_STANDARD 17)
set(ADDITIONAL_TARGET_LIST
        processor_dummy
        processor_audio_gen
        )

add_executable(${TARGET} ${TARGET_FILES})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${TARGET} ${ADDITIONAL_TARGET_LIST} Qt${QT_VERSION_MAJOR}::Widgets basic ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${PROJECT_NAME} DESTINATION backend)