project(lab_2_1)

add_executable(lab_2_1 main.c  matrix.c sVector.c)
# vector.c

target_link_libraries(lab_2_1 m)
