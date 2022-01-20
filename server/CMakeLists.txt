SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(server main.cpp)

target_link_libraries(server
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES})
