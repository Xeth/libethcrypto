

add_library(bitcrypto STATIC ${CMAKE_SOURCE_DIR}/src/main.cpp) 
add_dependencies(bitcrypto libsecp256k1)
add_dependencies(bitcrypto bitcrypto-core)



if (WIN32)
    set_property (TARGET bitcrypto APPEND PROPERTY STATIC_LIBRARY_FLAGS ${CMAKE_BINARY_DIR}/libsecp256k1.a ${CMAKE_BINARY_DIR}/libbitcrypto-core.a)
elseif (APPLE AND ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set_property (TARGET bitcrypto APPEND PROPERTY STATIC_LIBRARY_FLAGS ${CMAKE_BINARY_DIR}/libsecp256k1.a ${CMAKE_BINARY_DIR}/libbitcrypto-core.a)
elseif (UNIX)
    set(LIB_OBJ_DIR ${CMAKE_BINARY_DIR}/lib.obj)
    make_directory (${LIB_OBJ_DIR})

    ADD_CUSTOM_COMMAND(TARGET bitcrypto
          POST_BUILD
          COMMAND echo "packing libbitcrypto.a"
          COMMAND ${CMAKE_AR} x ${CMAKE_BINARY_DIR}/libsecp256k1.a WORKING_DIRECTORY ${LIB_OBJ_DIR}
          COMMAND ${CMAKE_AR} x ${CMAKE_BINARY_DIR}/libbitcrypto-core.a WORKING_DIRECTORY ${LIB_OBJ_DIR}
          COMMAND ${CMAKE_AR} rcs ${CMAKE_BINARY_DIR}/libbitcrypto.a ${LIB_OBJ_DIR}/*.o
          COMMAND rm -fr ${LIB_OBJ_DIR}
    )
endif (WIN32)






file(GLOB SECP256K1_HEADERS 
    "${PROJECT_BINARY_DIR}/secp256k1/include/*"
)


install(FILES ${HEADERS} DESTINATION include/bitcrypto)
install(FILES ${SECP256K1_HEADERS} DESTINATION include/bitcrypto)
install(FILES ${CMAKE_BINARY_DIR}/include/bitcrypto/config.hpp DESTINATION include/bitcrypto)
install (TARGETS bitcrypto ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)

