SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(include)

add_executable(server
        src/main.cpp
        src/Server.cpp
        src/Session.cpp)

target_link_libraries(server
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES}
        logger)
