find_package(Boost COMPONENTS system REQUIRED)

#add_definitions(-D__DEBUG__)

include_directories(${CMAKE_BINARY_DIR}/include)


file(GLOB SOURCES 
    "src/*.cpp"
    "src/external/*.cpp"
    "src/detail/*.cpp"
    "src/serialization/*.cpp"
    "src/serialization/detail/*.cpp"
    "src/encoding/*.cpp"
    "src/encoding/detail/*.cpp"
    "src/cipher/*.cpp"
)



file(GLOB HEADERS RELATIVE ${CMAKE_SOURCE_DIR}/src
    "src/*.hpp"
    "src/*.ipp"
    "src/external/*.h"
    "src/detail/*.hpp"
    "src/detail/*.ipp"
    "src/serialization/*.hpp"
    "src/serialization/*.ipp"
    "src/serialization/detail/*.hpp"
    "src/serialization/detail/*.ipp"
    "src/encoding/*.hpp"
    "src/encoding/*.ipp"
    "src/encoding/detail/*.hpp"
    "src/encoding/detail/*.ipp"
    "src/cipher/*.hpp"
    "src/cipher/*.ipp"
)


add_library(ethkey-dummy STATIC ${CMAKE_SOURCE_DIR}/src/main.cpp)



add_library(ethkey-core STATIC ${SOURCES})
add_dependencies(ethkey-core libsecp256k1 ethkey-dummy)



foreach(HEADER ${HEADERS})
    add_custom_command(
        TARGET ethkey-dummy
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy ${CMAKE_SOURCE_DIR}/src/${HEADER} ${CMAKE_BINARY_DIR}/include/ethkey/${HEADER}
)
endforeach(HEADER )


