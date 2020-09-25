//
// Created by Brett Bowman on 9/23/20.
//

#include "VertexBuffer.h"

#include "Hazel/Platform/OpenGL/OpenGLVertexBuffer.h"
#include "Renderer.h"
#include "hzpch.h"

namespace Hazel {

VertexBuffer *VertexBuffer::Create(float *vertices, uint32_t size) {
  switch (Renderer::GetAPI()) {
    case RendererAPI::None:
      HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
      return nullptr;
    case RendererAPI::OpenGL:
      return new OpenGLVertexBuffer(vertices, size);
  }

  HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
  return nullptr;
}

}  // namespace Hazel