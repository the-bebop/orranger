cmake_minimum_required (VERSION 3.0)
project(orranger)


set(DEFAULT_GUI "${CMAKE_CURRENT_LIST_DIR}/src/frontends/default/")
set(INSTALL_DIR "${CMAKE_CURRENT_LIST_DIR}/install/")

set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR})

add_custom_target(clean
   COMMAND ${CMAKE_BUILD_TOOL} clean
   COMMAND ${CMAKE_COMMAND} -P clean_up.cmake
)
add_subdirectory(${DEFAULT_GUI})