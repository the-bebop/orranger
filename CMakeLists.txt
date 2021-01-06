cmake_minimum_required (VERSION 3.0)
project(orranger)


set(BUILD_GUI "${CMAKE_CURRENT_LIST_DIR}/src/frontends/default/")
set(INSTALL_DIR ${CMAKE_BINARY_DIR})

set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR})

add_subdirectory(${BUILD_GUI})