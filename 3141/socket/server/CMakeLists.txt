cmake_minimum_required(VERSION 2.8)

project(server)

add_executable(server  sockserver.cpp server.cpp)

install(TARGETS server RUNTIME DESTINATION bin)
