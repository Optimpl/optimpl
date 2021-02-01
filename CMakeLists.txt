cmake_minimum_required(VERSION 3.5)

project(optimpl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set(source_dir "${PROJECT_SOURCE_DIR}/tests")

file(GLOB source_files "${source_dir}/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(optimpl ${source_files})