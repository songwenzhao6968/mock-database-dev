cmake_minimum_required(VERSION 3.15)
project(multiparty_database)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -idirafter /usr/include/antlr-runtime")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

include_directories(src)
include_directories(lib/nlohmann_json)

add_executable(mockdb_client
        src/main.cpp
        src/database.cpp
        src/provider.cpp
        src/client.cpp
        )
