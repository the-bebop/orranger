cmake_minimum_required(VERSION 3.5)

set(TARGET processor_dummy)
project(${TARGET} LANGUAGES CXX)

set(SRC_DIR cpp)
set(INC_DIR hpp)

# collect exec files
set(SOURCES
        ${SRC_DIR}/dummy.cpp
)
set(INCLUDES
        ${INC_DIR}/dummy.hpp
)
set(TARGET_FILES ${SOURCES} ${INCLUDES})


add_library(${TARGET} ${TARGET_FILES})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${TARGET} ${PROTOBUF_LIBRARY})

install(TARGETS ${PROJECT_NAME} DESTINATION backend)