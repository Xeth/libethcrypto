set(CRYPTOPP_INCLUDE_DIR ${PROJECT_SOURCE_DIR})
set(CRYPTOPP_LIBRARY cryptopp-static)

include(ExternalProject)

MESSAGE("------------------------------------------------")
MESSAGE("${CMAKE_CURRENT_BINARY_DIR}/lib.obj")
message("make -C ${CMAKE_CURRENT_SOURCE_DIR}/cryptopp")

ExternalProject_Add(
  cryptopp
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cryptopp
  CONFIGURE_COMMAND ""
  INSTALL_COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cryptopp/libcryptopp.a ${CMAKE_CURRENT_BINARY_DIR}/lib.obj
  BUILD_COMMAND make -C ${CMAKE_CURRENT_SOURCE_DIR}/cryptopp
#  BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib.obj
  BUILD_IN_SOURCE 1
  LOG_CONFIGURE 1
  LOG_BUILD 1
)