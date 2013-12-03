project(typing_characteristics)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(typing_characteristics_SRCS typing_characteristics.cpp main.cpp)
qt4_automoc(${typing_characteristics_SRCS})
add_executable(typing_characteristics ${typing_characteristics_SRCS})
target_link_libraries(typing_characteristics ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS typing_characteristics RUNTIME DESTINATION bin)
