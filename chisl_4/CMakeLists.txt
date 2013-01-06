cmake_minimum_required(VERSION 2.8)
project(chisl_4)

include_directories(/home/namatv/projects/chisl_4)

add_executable(chisl_4 main.c matrix.c vector.c)

target_link_libraries(chisl_4 m )

install(TARGETS chisl_4 RUNTIME DESTINATION bin)
