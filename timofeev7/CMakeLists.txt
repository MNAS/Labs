project(sort)

add_executable(sort main.c sort.c)

install(TARGETS sort RUNTIME DESTINATION bin)
