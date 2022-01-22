SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(include)

add_executable(server
        ${SERVER_SRCS}
        ${PACKAGING_SRCS})

target_link_libraries(server
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES}
        logger
        proto
        ${Protobuf_LIBRARY})
