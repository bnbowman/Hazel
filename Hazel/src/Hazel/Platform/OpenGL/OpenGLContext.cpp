//
// Created by Brett Bowman on 9/22/20.
//

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "hzpch.h"

namespace Hazel {

OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
    : m_WindowHandle(windowHandle) {
  HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
}

void OpenGLContext::Init() {
  glfwMakeContextCurrent(m_WindowHandle);
  int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

  HZ_CORE_INFO("OpenGL Render Context:");
  HZ_CORE_INFO("\tVendor: {0}", glGetString(GL_VENDOR));
  HZ_CORE_INFO("\tRenderer: {0}", glGetString(GL_RENDERER));
  HZ_CORE_INFO("\tVersion: {0}", glGetString(GL_VERSION));
}

void OpenGLContext::SwapBuffers() { glfwSwapBuffers(m_WindowHandle); }

}  // namespace Hazel
