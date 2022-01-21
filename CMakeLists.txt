cmake_minimum_required(VERSION 3.20)

project(game)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2.5.1 REQUIRED COMPONENTS system window graphics network audio)
find_package(Protobuf 3.19 REQUIRED)

include_directories(logger)

add_library(logger logger/logger.h logger/logger.cpp)


add_subdirectory(server)
