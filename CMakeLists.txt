cmake_minimum_required(VERSION 3.16)

#set the project name and version
project(RT VERSION 1.0)

#specify the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
file(GLOB_RECURSE libSrc
        ${PROJECT_SOURCE_DIR}/src/*.c
        ${PROJECT_SOURCE_DIR}/src/*.cpp
    )

# Add source header files
file(GLOB_RECURSE libHead
        ${PROJECT_SOURCE_DIR}/src/*.h
        ${PROJECT_SOURCE_DIR}/src/*.hpp
    )

add_executable(RT ${libSrc} ${libHead})