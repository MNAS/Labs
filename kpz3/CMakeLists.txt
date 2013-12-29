cmake_minimum_required(VERSION 2.8.8)
project(ships_db)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

set(ships_db.SRCS ship_main.cpp main.cpp ) 
add_executable(ships_db  ${ships_db.SRCS}  )

qt5_use_modules(ships_db Sql Widgets Gui Core Test)
install(TARGETS ships_db RUNTIME DESTINATION bin)