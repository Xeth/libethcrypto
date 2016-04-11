include(ExternalProject)

ExternalProject_Add(
  secp256k1
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/secp256k1
  CONFIGURE_COMMAND  ./autogen.sh && ./configure --prefix=${CMAKE_CURRENT_BINARY_DIR}/secp256k1 --disable-shared --includedir=${CMAKE_CURRENT_BINARY_DIR}/include/ethcrypto/secp256k1 --libdir=${CMAKE_CURRENT_BINARY_DIR}/lib.obj
  BUILD_COMMAND make
  BUILD_IN_SOURCE 1
)
