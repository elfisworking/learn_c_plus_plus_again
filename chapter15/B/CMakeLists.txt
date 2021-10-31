cmake_minimum_required(VERSION 3.5)

project(tvf)

set(SOURCES 
    src/remote.cpp
    src/main.cpp)


add_executable(tvf ${SOURCES})

target_include_directories(tvf
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include)