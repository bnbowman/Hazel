//
// Created by Brett Bowman on 9/23/20.
//
#pragma once

namespace Hazel {

class IndexBuffer {
 public:
  virtual ~IndexBuffer() {}

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;

  virtual uint32_t GetCount() const = 0;

  static IndexBuffer* Create(uint32_t* indices, uint32_t size);
};

}  // namespace Hazel