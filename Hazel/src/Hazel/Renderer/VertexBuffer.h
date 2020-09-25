//
// Created by Brett Bowman on 9/23/20.
//
#pragma once

namespace Hazel {

class VertexBuffer {
 public:
  virtual ~VertexBuffer() {}

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;

  static VertexBuffer* Create(float* vertices, uint32_t size);
};

}  // namespace Hazel
