cmake_minimum_required(VERSION 4.3)
project(oving3)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra)

add_executable(oving3_oppgave2 oppgave2.cpp)
add_executable(oving3_commodity commodity_test.cpp commodity.cpp)
add_executable(oving3_oppgave4 oppgave4.cpp)
