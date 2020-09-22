cmake_minimum_required(VERSION 3.17)
project(Glad)

set(CMAKE_CXX_STANDARD 14)

add_library(GLAD STATIC include/glad/glad.h include/KHR/khrplatform.h src/glad.c)
target_include_directories(GLAD PUBLIC include)
