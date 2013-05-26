project(graph-path)

add_executable(graph-path main.cpp graph.cpp kaima.cpp rebro.cpp versh.cpp )

install(TARGETS graph-path RUNTIME DESTINATION bin)
