cmake_minimum_required(VERSION 2.8.8)
project(code)

add_library(src "main.cpp")

add_executable(main "main.cpp")
target_link_libraries(main src)