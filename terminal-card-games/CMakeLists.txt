cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)
#Debug|Release|RelWithDebInfo|MinSizeRel

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static")

project(terminal-card-games)

add_definitions(-std=c++11)

set(berkunsky-kosynka_SRCS stol.cpp sdacha.cpp dom.cpp koloda.cpp stopka.cpp card.cpp main.cpp)

add_executable(terminal-card-games ${berkunsky-kosynka_SRCS})

#target_link_libraries(terminal-card-games ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS terminal-card-games RUNTIME DESTINATION bin)
