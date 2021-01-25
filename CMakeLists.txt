cmake_minimum_required(VERSION 3.16)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(ACO-TSP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

set(SOURCES src/main.cpp
            src/ant.cpp
            src/graph.cpp
            src/params.cpp
            src/ant_colony_optimization.cpp)

add_executable(ACO-TSP ${SOURCES})

target_link_libraries(ACO-TSP /usr/local/lib/libutility.a)
