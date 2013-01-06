project(moon)

add_executable(moon main.cpp Point.cpp Arc.cpp Moon.cpp)

install(TARGETS moon RUNTIME DESTINATION bin)
