cmake_minimum_required(VERSION 2.8)

project(timofeev5)

add_executable(timofeev5 main.cpp dictionary.cpp)

install(TARGETS timofeev5 RUNTIME DESTINATION bin)
