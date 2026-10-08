cmake_minimum_required(VERSION 4.3)
project(oving6)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra)

# For sjakk.cpp (oppgave 1)
add_executable(oving6_sjakk sjakk.cpp)

# For webserver.cpp (oppgave 2) — Boost.Asio
find_package(Boost 1.54 REQUIRED)
find_package(Threads REQUIRED)

add_executable(oving6_webserver webserver.cpp)
target_link_libraries(oving6_webserver PRIVATE Boost::headers Threads::Threads)
