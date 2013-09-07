cmake_minimum_required(VERSION 2.6)

project(printpdf)


if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++11")
endif()

add_executable(printpdf main.cpp)

install(TARGETS printpdf RUNTIME DESTINATION bin)
