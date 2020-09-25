//
// Created by Brett Bowman on 9/23/20.
//

#include "IndexBuffer.h"

#include "Hazel/Platform/OpenGL/OpenGLIndexBuffer.h"
#include "Renderer.h"
#include "hzpch.h"

namespace Hazel {

IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size) {
  switch (Renderer::GetAPI()) {
    case RendererAPI::None:
      HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
      return nullptr;
    case RendererAPI::OpenGL:
      return new OpenGLIndexBuffer(indices, size);
  }

  HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
  return nullptr;
}

}  // namespace Hazel