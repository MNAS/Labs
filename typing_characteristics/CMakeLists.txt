cmake_minimum_required(VERSION 2.8.8)
project(typing_characteristics)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

add_executable(typing_characteristics typing_characteristics.cpp main.cpp)

qt5_use_modules(typing_characteristics Widgets Gui Core Test)
install(TARGETS typing_characteristics RUNTIME DESTINATION bin)