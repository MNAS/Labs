cmake_minimum_required(VERSION 2.8)
project(eom_timofyeyev)

add_executable(eom_timofyeyev main.cpp massive.cpp)

install(TARGETS eom_timofyeyev RUNTIME DESTINATION bin)
