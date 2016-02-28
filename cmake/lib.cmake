

add_library(ethkey STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp) 
add_dependencies(ethkey libsecp256k1)
add_dependencies(ethkey ethkey-core)



if (WIN32)
    set_property (TARGET ethkey APPEND PROPERTY STATIC_LIBRARY_FLAGS ${CMAKE_CURRENT_BINARY_DIR}/libsecp256k1.a ${CMAKE_CURRENT_BINARY_DIR}/libethkey-core.a)
elseif (APPLE AND ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set_property (TARGET ethkey APPEND PROPERTY STATIC_LIBRARY_FLAGS ${CMAKE_CURRENT_BINARY_DIR}/libsecp256k1.a ${CMAKE_CURRENT_BINARY_DIR}/libethkey-core.a)
elseif (UNIX)
    set(LIB_OBJ_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib.obj)
    make_directory (${LIB_OBJ_DIR})

    ADD_CUSTOM_COMMAND(TARGET ethkey
          POST_BUILD
          COMMAND echo "packing libethkey.a"
          COMMAND ${CMAKE_AR} x ${CMAKE_CURRENT_BINARY_DIR}/libsecp256k1.a WORKING_DIRECTORY ${LIB_OBJ_DIR}
          COMMAND ${CMAKE_AR} x ${CMAKE_CURRENT_BINARY_DIR}/libethkey-core.a WORKING_DIRECTORY ${LIB_OBJ_DIR}
          COMMAND ${CMAKE_AR} rcs ${CMAKE_CURRENT_BINARY_DIR}/libethkey.a ${LIB_OBJ_DIR}/*.o
          COMMAND rm -fr ${LIB_OBJ_DIR}
    )
endif (WIN32)




include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/CopyHeaders.cmake)
CopyHeaders()

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include DESTINATION include)
install (TARGETS ethkey ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)

