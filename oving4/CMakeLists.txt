cmake_minimum_required(VERSION 3.16)
project(oving4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-3.0)

add_executable(oving4_oppgave1 oppgave1.cpp)
add_executable(oving4_oppgave2 oppgave2.cpp)
target_link_libraries(oving4_oppgave2 PRIVATE PkgConfig::GTKMM)