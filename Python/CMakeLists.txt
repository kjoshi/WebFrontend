cmake_minimum_required(VERSION 3.2)

project(webfrontend)
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

find_package(Boost COMPONENTS python REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(../C++/include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB LIBSOURCES "../C++/src/*.cpp")

add_library(webfrontend MODULE ${SOURCES} ${LIBSOURCES})
target_link_libraries(webfrontend ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
set_target_properties(webfrontend PROPERTIES PREFIX "")
