cmake_minimum_required(VERSION 3.17)
project(HazelSandbox)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sandbox src/SandboxApp.cpp)
target_link_libraries(Sandbox Hazel)
target_include_directories(Sandbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/thirdparty/spdlog/include ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/src ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/thirdparty ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/thirdparty/glm)
