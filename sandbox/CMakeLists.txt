cmake_minimum_required(VERSION 3.26)
project(sandbox)

set(CMAKE_CXX_STANDARD 17)

# Automatisk target for hver .cpp i leksjon1/, leksjon2/, ...
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/${child}/*.cpp")
        foreach(src ${sources})
            get_filename_component(name ${src} NAME_WE)
            add_executable(${child}_${name} ${src})
        endforeach()
    endif()
endforeach()
