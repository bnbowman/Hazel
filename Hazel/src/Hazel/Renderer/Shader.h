//
// Created by Brett Bowman on 9/23/20.
//
#pragma once

#include <string>

namespace Hazel {

class Shader {
 public:
  Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
  ~Shader();

  void Bind() const;
  void Unbind() const;

 private:
  uint32_t m_RendererID;
};

}  // namespace Hazel