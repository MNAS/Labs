project(qt4)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(qt4_SRCS main.cpp)
qt4_automoc(${qt4_SRCS})
add_executable(qt4 ${qt4_SRCS})
target_link_libraries(qt4 ${QT_QTCORE_LIBRARY})

install(TARGETS qt4 RUNTIME DESTINATION bin)
