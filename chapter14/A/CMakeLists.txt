cmake_minimum_required(VERSION 3.5)

project(templateClass)

add_executable(templateClass src/stackitem.cpp)

target_include_directories(templateClass 
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include)