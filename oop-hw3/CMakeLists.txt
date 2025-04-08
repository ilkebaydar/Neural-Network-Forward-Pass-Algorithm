cmake_minimum_required(VERSION 3.27)
project(oop_hw3)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_hw3 src/main.cpp
        include/Matrix.h
        include/Activation.h
        src/Matrix.cpp
        src/Matrix.cpp
        src/Matrix.cpp
        src/Activation.cpp
        src/Layer.cpp
        src/Network.cpp)
add_executable(new_target src/Matrix.cpp
        include/Layer.h
        src/Layer.cpp
        include/Network.h)
