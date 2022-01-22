add_executable(client
        ${CLIENT_SRCS}
        ${PACKAGING_SRCS}
        ${COMMON_SRCS})

include_directories(include)
include_directories(screens/include)

target_link_libraries(client
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES}
        ${Protobuf_LIBRARIES}
        logger
        proto
        ${Protobuf_LIBRARY})
