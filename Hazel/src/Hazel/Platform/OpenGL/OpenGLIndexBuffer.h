//
// Created by Brett Bowman on 9/23/20.
//
#pragma once

#include "Hazel/Renderer/IndexBuffer.h"

namespace Hazel {

class OpenGLIndexBuffer : public IndexBuffer {
 public:
  OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
  virtual ~OpenGLIndexBuffer();

  virtual void Bind() const;
  virtual void Unbind() const;

  virtual uint32_t GetCount() const { return m_Count; }

 private:
  uint32_t m_RendererID;
  uint32_t m_Count;
};

}  // namespace Hazel