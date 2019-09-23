cmake_minimum_required(VERSION 3.14)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1 main.cpp presentation/MainView.cpp presentation/MainView.h domain/Matrix.cpp domain/Matrix.h presentation/MainPresenter.cpp presentation/MainPresenter.h domain/MatrixOperator.cpp domain/MatrixOperator.h)