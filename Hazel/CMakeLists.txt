cmake_minimum_required(VERSION 3.17)
project(Hazel)

set(CMAKE_CXX_STANDARD 14)

add_library(Hazel STATIC src/Hazel/Application.cpp src/Hazel/Application.h src/Hazel.h src/Hazel/EntryPoint.h src/Hazel/Core/Log.cpp src/Hazel/Core/Log.h src/Hazel/Events/Event.h src/Hazel/Core/Base.h src/Hazel/Events/ApplicationEvent.h src/Hazel/Events/KeyEvent.h src/Hazel/Events/MouseEvent.h src/Hazel/Core/KeyCodes.h src/Hazel/Core/MouseCodes.h src/Hazel/Core/Window.h src/Hazel/Platform/Mac/MacWindow.cpp src/Hazel/Platform/Mac/MacWindow.h src/Hazel/Core/Layer.cpp src/Hazel/Core/Layer.h src/Hazel/Core/LayerStack.cpp src/Hazel/Core/LayerStack.h src/Hazel/ImGui/ImGuiLayer.h src/Hazel/ImGui/ImGuiLayer.cpp src/Hazel/Core/Input.h src/Hazel/Platform/Mac/MacInput.cpp src/Hazel/Platform/Mac/MacInput.h src/Hazel/ImGui/ImGuiBuild.cpp src/Hazel/Renderer/RenderContext.h src/Hazel/Platform/OpenGL/OpenGLContext.cpp src/Hazel/Platform/OpenGL/OpenGLContext.h src/Hazel/Renderer/Shader.cpp src/Hazel/Renderer/Shader.h src/Hazel/Renderer/IndexBuffer.cpp src/Hazel/Renderer/IndexBuffer.h src/Hazel/Renderer/VertexBuffer.cpp src/Hazel/Renderer/VertexBuffer.h src/Hazel/Renderer/Renderer.cpp src/Hazel/Renderer/Renderer.h src/Hazel/Platform/OpenGL/OpenGLVertexBuffer.cpp src/Hazel/Platform/OpenGL/OpenGLVertexBuffer.h src/Hazel/Platform/OpenGL/OpenGLIndexBuffer.cpp src/Hazel/Platform/OpenGL/OpenGLIndexBuffer.h src/Hazel/Renderer/ShaderDataType.h src/Hazel/Renderer/BufferLayout.h src/Hazel/Renderer/VertexArray.h src/Hazel/Renderer/VertexArray.cpp src/Hazel/Platform/OpenGL/OpenGLVertexArray.cpp src/Hazel/Platform/OpenGL/OpenGLVertexArray.h src/Hazel/Renderer/RendererAPI.cpp src/Hazel/Renderer/RendererAPI.h src/Hazel/Renderer/RenderCommand.cpp src/Hazel/Renderer/RenderCommand.h src/Hazel/Platform/OpenGL/OpenGLRendererAPI.cpp src/Hazel/Platform/OpenGL/OpenGLRendererAPI.h)
target_compile_definitions(Hazel PRIVATE GLFW_INCLUDE_NONE=1)
target_compile_definitions(Hazel PUBLIC HZ_DEBUG=1 HZ_PLATFORM_MAC=1)
target_compile_options(Hazel PRIVATE -Wall -Wextra -pedantic -Werror)

add_subdirectory(thirdparty/glad)
target_link_libraries(Hazel GLAD)

add_subdirectory(thirdparty/glfw)
target_link_libraries(Hazel glfw)

add_subdirectory(thirdparty/imgui)
target_link_libraries(Hazel imgui)

target_include_directories(Hazel PUBLIC thirdparty/spdlog/include thirdparty/glfw/include thirdparty/glad/include thirdparty/imgui thirdparty/glm src)
target_precompile_headers(Hazel PRIVATE src/hzpch.h)
