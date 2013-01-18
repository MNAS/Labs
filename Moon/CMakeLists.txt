cmake_minimum_required(VERSION 2.8)
project(moon)

add_executable(moon main.cpp Point.cpp Arc.cpp Moon.cpp Romb.cpp)

install(TARGETS moon RUNTIME DESTINATION bin)
