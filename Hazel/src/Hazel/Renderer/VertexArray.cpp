//
// Created by Brett Bowman on 9/27/20.
//
#include "VertexArray.h"

#include "Hazel/Platform/OpenGL/OpenGLVertexArray.h"
#include "Renderer.h"
#include "hzpch.h"

namespace Hazel {

VertexArray* VertexArray::Create() {
  switch (Renderer::GetAPI()) {
    case RendererAPI::None:
      HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
      return nullptr;
    case RendererAPI::OpenGL:
      return new OpenGLVertexArray();
  }

  HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
  return nullptr;
}

}  // namespace Hazel