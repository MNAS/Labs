project(data_secure_01)

cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(data_secure_01_SRCS main.cpp)

qt4_automoc(${data_secure_01_SRCS})

add_executable(data_secure_01 ${data_secure_01_SRCS})

target_link_libraries(data_secure_01 ${QT_QTCORE_LIBRARY})

install(TARGETS data_secure_01 RUNTIME DESTINATION bin)
