//
// Created by Brett Bowman on 9/22/20.
//
#pragma once

#include "Hazel/Renderer/RenderContext.h"

struct GLFWwindow;

namespace Hazel {

class OpenGLContext : public RenderContext {
 public:
  OpenGLContext(GLFWwindow *windowHandle);

  virtual void Init() override;
  virtual void SwapBuffers() override;

 private:
  GLFWwindow *m_WindowHandle;
};

}  // namespace Hazel