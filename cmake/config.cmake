
set (Bit_Crypto_VERSION_MAJOR 1)
set (Bit_Crypto_VERSION_MINOR 0)
set (Bit_Crypto_VERSION_PATCH 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/config.hpp.in"
  "${PROJECT_BINARY_DIR}/include/bitcrypto/config.hpp"
)
