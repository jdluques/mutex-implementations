cmake_minimum_required(VERSION 3.27)

project(locks C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_executable(locks
    src/lock.c
    src/dekker.c
    src/peterson.c
    src/dijkstra.c
)

find_package(Threads REQUIRED)
target_link_libraries(locks PRIVATE Threads::Threads)
