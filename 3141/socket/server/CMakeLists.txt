cmake_minimum_required(VERSION 2.6)

project(server)

add_executable(server server.cpp sockserver.cpp sockaddr.cpp)

install(TARGETS server RUNTIME DESTINATION bin)
