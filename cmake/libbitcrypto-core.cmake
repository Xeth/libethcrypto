find_package(Boost COMPONENTS system REQUIRED)

#add_definitions(-D__DEBUG__)

include_directories(${CMAKE_BINARY_DIR}/include/bitcrypto)


file(GLOB SOURCES 
    "src/*.cpp"
    "src/external/*.cpp"
)



file(GLOB HEADERS RELATIVE ${CMAKE_SOURCE_DIR}/src
    "src/*.hpp"
    "src/*.ipp"
    "src/external/*.h"
)





add_library(bitcrypto-core STATIC ${SOURCES})
add_dependencies(bitcrypto-core libsecp256k1)

add_custom_command(
    TARGET bitcrypto-core
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} ARGS -E make_directory ${CMAKE_BINARY_DIR}/include/bitcrypto/external
)

foreach(HEADER ${HEADERS})
    add_custom_command(
        TARGET bitcrypto-core
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy ${CMAKE_SOURCE_DIR}/src/${HEADER} ${CMAKE_BINARY_DIR}/include/bitcrypto/${HEADER}
)
endforeach(HEADER )


