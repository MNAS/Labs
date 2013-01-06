project(chisl_5)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)

add_executable(chisl_5 main.c chisl_5.c vector.c matrix.c)
target_link_libraries(chisl_5 m )

install(TARGETS chisl_5 RUNTIME DESTINATION bin)
