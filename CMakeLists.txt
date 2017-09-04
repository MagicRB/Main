cmake_minimum_required(VERSION 2.8.9)
project(Main)

include_directories(include include-ext)

file(GLOB SOURCES "src/*.cpp" "include/*.h")

add_library(bin/Main SHARED ${SOURCES})
