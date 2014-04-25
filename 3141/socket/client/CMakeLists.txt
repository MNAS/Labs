cmake_minimum_required(VERSION 2.8)

project(client)

add_executable(client sockclient.cpp client.cpp)

install(TARGETS client RUNTIME DESTINATION bin)
