project(x11_first)

add_executable(x11_first drect.cpp irect.cpp ipoint.cpp dpoint.cpp windowparams.cpp main.cpp)

find_library(lx11 X11)

target_link_libraries(x11_first ${lx11})

install(TARGETS x11_first RUNTIME DESTINATION bin)
