cmake_minimum_required(VERSION 3.17)
project(Hazel)

set(CMAKE_CXX_STANDARD 14)

add_library(Hazel SHARED src/Hazel/Application.cpp src/Hazel/Application.h src/Hazel.h src/Hazel/EntryPoint.h src/Hazel/Log.cpp src/Hazel/Log.h thirdparty/spdlog/include/spdlog/spdlog.h)
target_include_directories(Hazel PUBLIC thirdparty/spdlog/include)
