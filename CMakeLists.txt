cmake_minimum_required(VERSION 3.2)
project(call_center)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

find_package(Boost REQUIRED COMPONENTS property_tree)

add_executable(call_center main.cpp ${SOURCES})
add_executable(tests test/testConfig.cpp src/config.cpp)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(call_center ${Boost_LIBRARIES})
    target_link_libraries(tests ${Boost_LIBRARIES})
endif()

if()
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(call_center ${Boost_LIBRARIES})
    target_link_libraries(tests ${Boost_LIBRARIES})
endif()

enable_testing()
find_package(GTest REQUIRED)

target_link_libraries(tests GTest::gtest GTest::gtest_main)
