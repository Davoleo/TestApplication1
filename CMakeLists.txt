cmake_minimum_required(VERSION 3.12)
project(TestApplication1)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestApplication1  ch1.cpp models/shapes/Shape.cpp models/shapes/Shape.h models/shapes/Circle.cpp models/shapes/Circle.h models/shapes/Rectangle.cpp models/shapes/Rectangle.h)