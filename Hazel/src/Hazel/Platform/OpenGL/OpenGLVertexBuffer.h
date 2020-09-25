//
// Created by Brett Bowman on 9/23/20.
//
#pragma once

#include "Hazel/Renderer/VertexBuffer.h"

namespace Hazel {

class OpenGLVertexBuffer : public VertexBuffer {
 public:
  OpenGLVertexBuffer(float* vertices, uint32_t size);
  virtual ~OpenGLVertexBuffer();

  virtual void Bind() const;
  virtual void Unbind() const;

 private:
  uint32_t m_RendererID;
};

}  // namespace Hazel