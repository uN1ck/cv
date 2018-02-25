cmake_minimum_required(VERSION 3.9)
project(cv)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

add_executable(cv
        main.cpp
        src/BorderHandlers/BorderHandler.hpp
        src/Matrix.hpp
        src/Matrix.cpp
        src/Filters/Filter.hpp
        src/Filters/MatrixFilter.cpp
        src/Filters/MatrixFilter.hpp
        src/BorderHandlers/FillBorderHandler.cpp src/BorderHandlers/FillBorderHandler.hpp)
target_link_libraries(cv ${OpenCV_LIBS})