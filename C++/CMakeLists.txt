cmake_minimum_required(VERSION 3.2)

project(webfrontend)
set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(webfrontend ${SOURCES})

