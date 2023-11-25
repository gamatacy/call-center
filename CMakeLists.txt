cmake_minimum_required(VERSION 3.2)
project(call_center)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS property_tree)
add_executable(call_center main.cpp
        src/config.cpp
        include/config.h
        src/httpServer.cpp
        include/httpServer.h
        include/defs.h
        include/status.h
        src/callCenterService.cpp
        include/callCenterService.h
        src/operatorMock.cpp
        include/operatorMock.h
)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(call_center ${Boost_LIBRARIES})
endif()


