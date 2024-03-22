cmake_minimum_required(VERSION 3.0)

project(test)

add_executable(test  ./src/test.cpp)

add_subdirectory(./src/business)

target_link_libraries(test PUBLIC business)

target_include_directories(test PUBLIC "./src/business")
