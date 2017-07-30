set(LIBSCRYPT_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/crypto_scrypt-nosse.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/sha256.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/crypto-mcf.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/b64.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/crypto_scrypt-check.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/crypto_scrypt-hash.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/slowequals.c"
)

include(CheckCCompilerFlag)

check_c_compiler_flag(-fstack-protector HAS_FSTACK_PROTECTOR)

if (HAS_FSTACK_PROTECTOR)
    add_definitions(-fstack-protector)
endif()

check_c_compiler_flag(relro HAS_RELRO)

if(HAS_RELRO)
    add_definitions(-Wl,-z,now -Wl,-z,relro -Wl)
endif()


#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/libscrypt.h DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/ethcrypto/)

set(LIBSCRYPT_INCLUDE_DIRS ${PROJECT_SOURCE_DIR})

if(MSVC OR WIN32)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/msvc/include)
else()
    list(APPEND LIBSCRYPT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/libscrypt/crypto-scrypt-saltgen.c")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libscrypt)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/lib.obj")

add_library(scrypt STATIC ${LIBSCRYPT_SOURCES})
