cmake_minimum_required(VERSION 3.20)

project(game)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2.5.1 REQUIRED COMPONENTS system window graphics network audio)
find_package(Protobuf 3.19 REQUIRED)

include(cmake/source_var.cmake)

protobuf_generate_cpp(PROTO_SRC PROTO_HDRS ${CMAKE_SOURCE_DIR}/proto/messages/UserMessage.proto)
add_library(proto ${PROTO_HDRS} ${PROTO_SRC})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(logger)
include_directories(.)
include_directories(messages)
include_directories(${Protobuf_INCLUDE_DIR})
include_directories(${SFML_INCLUDE_DIR})

add_library(logger logger/logger.h logger/logger.cpp messages/packaging.hpp messages/packaging.cpp client/src/main.cpp)


add_subdirectory(server)
add_subdirectory(client)
