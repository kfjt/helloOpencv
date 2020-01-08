cmake_minimum_required(VERSION 3.0.0)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++0x -O3")

project(helloOpencv VERSION 0.1.0)

file(GLOB my_src ./src/*.cpp)
include_directories(./head)

add_executable(${PROJECT_NAME} ${my_src})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
