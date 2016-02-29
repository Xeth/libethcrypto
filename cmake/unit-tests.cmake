find_package(Boost COMPONENTS system filesystem unit_test_framework random REQUIRED)
find_package(GMP)

file(GLOB TEST_SOURCES 
    "test/*.cpp"
)




include_directories(${Boost_INCLUDE_DIRS} ${CRYPTOPP_INCLUDE_DIR} ${JSONCPP_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/include)

add_executable(ethkey-tests ${TEST_SOURCES})
add_dependencies(ethkey-tests ethkey)

target_link_libraries(ethkey-tests ethkey ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_RANDOM_LIBRARY} ${CRYPTOPP_LIBRARY}  ${JSONCPP_LIBRARY})

if(GMP_LIBRARIES)
    target_link_libraries(ethkey-tests ${GMP_LIBRARIES})
endif()
