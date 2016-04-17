
project(ethcrypto)

set(CMAKE_BUILD_TYPE Release)
#cmake_minimum_required(VERSION 3.2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")


include(cmake/modules/OSFlags.cmake)
include(cmake/config.cmake)
include(cmake/lib.cmake)
if(ENABLE_TEST)
    include(cmake/unit-tests.cmake)
endif()

if(NOT SKIP_LIBRARY_INSTALL)
    include(cmake/pkg-config.cmake)
endif()




