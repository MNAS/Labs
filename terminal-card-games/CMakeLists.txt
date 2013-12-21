cmake_minimum_required(VERSION 2.8.8)
project(terminal-card-games)

set(CMAKE_BUILD_TYPE Debug) #Debug|Release|RelWithDebInfo|MinSizeRel
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static")

#set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_definitions(-std=c++11)

find_package(Qt5Widgets REQUIRED)

set(kosynka_SRCS stol.cpp sdacha.cpp dom.cpp koloda.cpp stopka.cpp card.cpp main.cpp)
add_executable(terminal-card-games ${kosynka_SRCS})

#qt5_use_modules(typing_characteristics Widgets Gui Core Test)
install(TARGETS terminal-card-games RUNTIME DESTINATION bin)