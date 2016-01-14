find_package(Boost COMPONENTS system REQUIRED)

#add_definitions(-D__DEBUG__)

include_directories(${CMAKE_BINARY_DIR}/include/bitcrypto)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)


file(GLOB SOURCES 
    "src/*.cpp"
    "src/external/*.cpp"
)

file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR}/src
    "src/*.hpp"
    "src/*.ipp"
    "src/external/*.h"
)




add_library(bitcrypto-core STATIC ${SOURCES})


