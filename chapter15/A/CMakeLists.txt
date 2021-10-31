cmake_minimum_required(VERSION 3.5)

project(tv)

add_executable(tv src/tv.cpp)

target_include_directories(tv 
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include)