
set (Eth_Crypto_VERSION_MAJOR 1)
set (Eth_Crypto_VERSION_MINOR 0)
set (Eth_Crypto_VERSION_PATCH 0)

set(ETHCRYPTO_CONFIG_INCLUDE_DIR ${PROJECT_BINARY_DIR}/include/ethcrypto-config)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/config.hpp.in"
  "${ETHCRYPTO_CONFIG_INCLUDE_DIR}/config.hpp"
)


set(ETHCRYPTO_CONFIG_INCLUDE_DIRS ${ETHCRYPTO_CONFIG_INCLUDE_DIR})
