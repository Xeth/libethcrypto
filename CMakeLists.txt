
project(bitcrypto)

set(CMAKE_BUILD_TYPE Release)
cmake_minimum_required(VERSION 3.2)



include(cmake/config.cmake)
include(cmake/libsecp256k1.cmake)
include(cmake/libbitcrypto-core.cmake)
include(cmake/libbitcrypto.cmake)
include(cmake/unit-tests.cmake)
include(cmake/pkg-config.cmake)





