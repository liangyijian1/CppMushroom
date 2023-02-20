cmake_minimum_required(VERSION 3.17)   # 添加自己的项目名   project(1_demo)

project(mushroom)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})

add_subdirectory(src)