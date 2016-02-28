find_package(Boost COMPONENTS system REQUIRED)
find_package(JsonCPP REQUIRED)
find_package(CryptoPP REQUIRED)

#add_definitions(-D__DEBUG__)

include_directories(${Boost_INCLUDE_DIRS} ${CRYPTOPP_INCLUDE_DIR} ${JSONCPP_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/include)

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


add_library(ethkey-core STATIC ${SOURCES})



foreach(HEADER ${HEADERS})
    add_custom_command(
        TARGET ethkey-dummy
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy ${CMAKE_CURRENT_SOURCE_DIR}/src/${HEADER} ${CMAKE_CURRENT_BINARY_DIR}/include/ethkey/${HEADER}
)
endforeach(HEADER )


