cmake_minimum_required (VERSION 3.0)
project(orranger)

# settings
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(BUILD_GUI ${SOURCE_DIR}/frontends/default)
set(INSTALL_DIR ${CMAKE_BINARY_DIR}/install)

# packages
find_package(Protobuf REQUIRED)
set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR})

add_subdirectory(${BUILD_GUI})
add_subdirectory(${SOURCE_DIR}/backend/)