cmake_minimum_required(VERSION 3.5)

set(TARGET processor_audio_gen)
project(${TARGET} LANGUAGES CXX)

set(SRC_DIR cpp)
set(INC_DIR hpp)

# collect exec files
set(SOURCES
        ${SRC_DIR}/audio_gen.cpp
)
set(INCLUDES
        ${INC_DIR}/audio_gen.hpp
)
set(TARGET_FILES ${SOURCES} ${INCLUDES})

find_package(ALSA REQUIRED)
if(NOT ALSA_FOUND)
        MESSAGE(FATAL_ERROR "ALSA lib is required to build the audio generator but is missing on the system. Please install.")
endif(NOT ALSA_FOUND)

set(ADDITIONAL_INLCUDES
        ${ALSA_INCLUDE_DIRS})
set(ADDITIONAL_LIBRARIES
        ${ALSA_LIBRARIES})

add_library(${TARGET} ${TARGET_FILES})
target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_LIST_DIR} ${ADDITIONAL_INLCUDES})
target_link_libraries(${TARGET} ${PROTOBUF_LIBRARY} ${ADDITIONAL_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION backend)