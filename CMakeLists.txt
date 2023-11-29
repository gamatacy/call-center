cmake_minimum_required(VERSION 3.2)
project(call_center)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

find_package(Boost REQUIRED COMPONENTS property_tree)

add_executable(call_center main.cpp ${SOURCES})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(call_center ${Boost_LIBRARIES})
endif()


