find_package(Boost COMPONENTS system filesystem unit_test_framework random REQUIRED)
find_package(JsonCPP REQUIRED)

if(ENABLE_GMP)
    find_package(GMP)
endif()

set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)

