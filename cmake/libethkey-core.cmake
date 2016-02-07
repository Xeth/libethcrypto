find_package(Boost COMPONENTS system REQUIRED)
find_package(JsonCPP REQUIRED)
find_package(CryptoPP REQUIRED)
find_package(LibScrypt REQUIRED)

#add_definitions(-D__DEBUG__)

include_directories(${CRYPTOPP_INCLUDE_DIR} ${JSONCPP_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/include)

file(GLOB SOURCES 
    "src/*.cpp"
    "src/external/*.cpp"
    "src/detail/*.cpp"
    "src/serialization/*.cpp"
    "src/serialization/detail/*.cpp"
    "src/encoding/*.cpp"
    "src/encoding/detail/*.cpp"
    "src/cipher/*.cpp"
    "src/hash/*.cpp"
)

include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/CopyHeaders.cmake)
CopyHeaders()


#file(GLOB HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src
#    "src/*.hpp"
#    "src/*.ipp"
#    "src/external/*.h"
#    "src/detail/*.hpp"
#    "src/detail/*.ipp"
#    "src/serialization/*.hpp"
#    "src/serialization/*.ipp"
#    "src/serialization/detail/*.hpp"
#    "src/serialization/detail/*.ipp"
#    "src/encoding/*.hpp"
#    "src/encoding/*.ipp"
#    "src/encoding/detail/*.hpp"
#    "src/encoding/detail/*.ipp"
#    "src/cipher/*.hpp"
#    "src/cipher/*.ipp"
#    "src/hash/*.hpp"
#    "src/hash/*.ipp"
#)

#message(${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

#add_library(ethkey-dummy STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)



add_library(ethkey-core STATIC ${SOURCES})
add_dependencies(ethkey-core libsecp256k1 )



foreach(HEADER ${HEADERS})
    add_custom_command(
        TARGET ethkey-dummy
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy ${CMAKE_CURRENT_SOURCE_DIR}/src/${HEADER} ${CMAKE_CURRENT_BINARY_DIR}/include/ethkey/${HEADER}
)
endforeach(HEADER )


