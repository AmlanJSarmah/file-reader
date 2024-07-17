cmake_minimum_required(VERSION 3.22.1)
project(file-reader)
include_directories(${PROJECT_SOURCE_DIR}/headers)
add_executable(${PROJECT_NAME} main.c)