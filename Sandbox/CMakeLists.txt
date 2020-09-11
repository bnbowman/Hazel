cmake_minimum_required(VERSION 3.17)
project(HazelSandbox)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sandbox src/SandboxApp.cpp)
target_include_directories(Sandbox PUBLIC ../Hazel/src)
target_link_libraries(Sandbox ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/libHazel.dylib)
