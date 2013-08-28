cmake_minimum_required(VERSION 2.8)

project(berkunsky-kosynka)

#find_package(Qt4 REQUIRED)
#include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
add_definitions(-std=c++11)
set(berkunsky-kosynka_SRCS stol.cpp sdacha.cpp dom.cpp koloda.cpp stopka.cpp card.cpp main.cpp)
#qt4_automoc(${berkunsky-kosynka_SRCS})
add_executable(berkunsky-kosynka ${berkunsky-kosynka_SRCS})
target_link_libraries(berkunsky-kosynka ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS berkunsky-kosynka RUNTIME DESTINATION bin)
