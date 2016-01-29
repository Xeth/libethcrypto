find_package(Boost COMPONENTS system filesystem unit_test_framework random REQUIRED)

file(GLOB TEST_SOURCES 
    "test/*.cpp"
)

find_library(GMP_LIBRARY gmp)

IF(GMP_LIBRARY)
    MESSAGE(STATUS "gmp library - found")
ELSE(GMP_LIBRARY)
    MESSAGE(FATAL_ERROR "gmp library - not found")
ENDIF(GMP_LIBRARY)

#include_directories(${CMAKE_BINARY_DIR}/secp256k1/include ${CMAKE_SOURCE_DIR}/src)

include_directories(${CRYPTOPP_INCLUDE_DIR} ${CMAKE_BINARY_DIR}/include)

add_executable(unit-tests ${TEST_SOURCES})
add_dependencies(unit-tests ethkey)

target_link_libraries(unit-tests ethkey ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_RANDOM_LIBRARY} ${CRYPTOPP_LIBRARY} ${GMP_LIBRARY} -lscrypt)
