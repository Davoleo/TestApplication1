cmake_minimum_required(VERSION 3.12)
project(TestApplication1)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestApplication1  ch1.cpp shapes/Shape.cpp shapes/Shape.h shapes/Circle.cpp shapes/Circle.h)