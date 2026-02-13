cmake_minimum_required(VERSION 3.20)
project(cp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE PROBLEM_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/problems/**/main.cpp")

foreach(src ${PROBLEM_SOURCES})
    get_filename_component(dir ${src} DIRECTORY)
    get_filename_component(problem ${dir} NAME)
    add_executable(${problem} ${src})
endforeach()