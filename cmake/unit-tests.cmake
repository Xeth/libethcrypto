
file(GLOB TEST_SOURCES 
    "test/*.cpp"
)

include_directories(${Boost_INCLUDE_DIRS} ${CRYPTOPP_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/include)

add_executable(ethcrypto-tests EXCLUDE_FROM_ALL ${TEST_SOURCES})
add_dependencies(ethcrypto-tests ethcrypto)

target_link_libraries(ethcrypto-tests 
    ethcrypto
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ${Boost_RANDOM_LIBRARY}
    ${JSONCPP_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
)

if(GMP_LIBRARIES)
    target_link_libraries(ethcrypto-tests ${GMP_LIBRARIES})
endif()
