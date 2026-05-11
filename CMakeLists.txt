cmake_minimum_required(VERSION 3.27)

project(SynchronizationPrimitives C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_executable(synch
    src/main.c
    src/synch.c
    src/dekker.c
    src/peterson.c
    src/dijkstra.c
    src/pthread_lock.c
)

find_package(Threads REQUIRED)
target_link_libraries(synch PRIVATE Threads::Threads)
