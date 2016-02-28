
project(ethkey)

set(CMAKE_BUILD_TYPE Release)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")


include(cmake/config.cmake)
include(cmake/secp256k1.cmake)
include(cmake/core.cmake)
include(cmake/lib.cmake)
include(cmake/unit-tests.cmake)
include(cmake/pkg-config.cmake)





