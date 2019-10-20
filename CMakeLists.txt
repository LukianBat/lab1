cmake_minimum_required(VERSION 3.14)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1 main.cpp MainView.cpp MainView.h Matrix.cpp Matrix.h SingleMatrix.cpp SingleMatrix.h RectangleMatrix.cpp RectangleMatrix.h)