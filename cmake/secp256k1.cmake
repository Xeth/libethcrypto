if (NOT SECP256K1_USE_CMAKE)
    include(ExternalProject)

    ExternalProject_Add(
      secp256k1
      SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1
      CONFIGURE_COMMAND  ./autogen.sh && ./configure --prefix=${CMAKE_CURRENT_BINARY_DIR}/secp256k1 --disable-shared --includedir=${CMAKE_CURRENT_BINARY_DIR}/include/ethkey/secp256k1 --libdir=${CMAKE_CURRENT_BINARY_DIR}/lib.obj
      BUILD_COMMAND make
      BUILD_IN_SOURCE 1
    )
else (NOT SECP256K1_USE_CMAKE)
    include(CheckTypeSize) 
    check_type_size("void*" SIZEOF_VOID_P BUILTIN_TYPES_ONLY)

    find_package(GMP)

    if(SIZEOF_VOID_P EQUAL 8) 
        message("x86_64 detected")

        if(NOT WIN32 AND NOT MSVC)
            add_definitions(-DUSE_ASM_X86_64)
            add_definitions(-DUSE_FIELD_5X52)
            check_type_size("int128_t" SIZEOF_INT128)
        else()
            check_type_size("__int128" SIZEOF_INT128 BUILTIN_TYPES_ONLY)
        endif()


        if(SIZEOF_INT128)
            add_definitions(-DUSE_SCALAR_4X64)
            add_definitions(-DHAVE___INT128)
            add_definitions(-DUSE_FIELD_5X52)
        else()
            add_definitions(-DUSE_SCALAR_8X32)
            if(WIN32 OR MSVC)
                add_definitions(-DUSE_FIELD_10X26)
            endif()
        endif()

    else()
        add_definitions(-DUSE_SCALAR_8X32)
        add_definitions(-DUSE_FIELD_10X26)
    endif()

    if(GMP_LIBRARY)
        add_definitions(-DHAVE_LIBGMP=1)
        add_definitions(-DUSE_NUM_GMP=1)
        add_definitions(-DUSE_FIELD_INV_NUM=1)
        add_definitions(-DUSE_SCALAR_INV_NUM=1)
    else()
        add_definitions(-DUSE_NUM_NONE=1)
        add_definitions(-DUSE_FIELD_INV_BUILTIN=1)
        add_definitions(-DUSE_SCALAR_INV_BUILTIN=1)
    endif()


    file(GLOB SECP256K1_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1/src/*.c)
    file(GLOB SECP256K1_BENCHMARK_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1/src/bench*.c)
    file(GLOB SECP256K1_TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1/src/test*.c)

    list(REMOVE_ITEM SECP256K1_SOURCES ${SECP256K1_BENCHMARK_SOURCES})
    list(REMOVE_ITEM SECP256K1_SOURCES ${SECP256K1_TEST_SOURCES})


    file(GLOB SECP256K1_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/secp256k1/include/*")

    file(COPY ${SECP256K1_HEADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/ethkey/secp256k1)

if(MSVC OR WIN32)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/msvc/include)
endif()

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/secp256k1)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
    add_library(secp256k1 STATIC ${SECP256K1_SOURCES})

endif (NOT SECP256K1_USE_CMAKE)
