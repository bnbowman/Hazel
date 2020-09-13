cmake_minimum_required(VERSION 3.17)
project(Hazel)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(thirdparty/glfw)
add_library(Hazel SHARED src/Hazel/Application.cpp src/Hazel/Application.h src/Hazel.h src/Hazel/EntryPoint.h src/Hazel/Core/Log.cpp src/Hazel/Core/Log.h thirdparty/spdlog/include/spdlog/spdlog.h src/Hazel/Events/Event.h src/Hazel/Core/Core.h src/Hazel/Events/ApplicationEvent.h src/Hazel/Events/KeyEvent.h src/Hazel/Events/MouseEvent.h src/Hazel/Core/KeyCodes.h src/Hazel/Core/MouseCodes.h src/Hazel/Core/Window.h src/Hazel/Platform/MacWindow.cpp src/Hazel/Platform/MacWindow.h)
target_link_libraries(Hazel glfw)
target_include_directories(Hazel PUBLIC thirdparty/spdlog/include thirdparty/glfw/include src)
target_precompile_headers(Hazel PRIVATE src/hzpch.h)
