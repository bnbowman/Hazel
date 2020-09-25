//
// Created by Brett Bowman on 9/23/20.
//
#pragma once

namespace Hazel {

enum class RendererAPI { None = 0, OpenGL = 1 };

class Renderer {
 public:
  inline static RendererAPI GetAPI() { return s_RendererAPI; }

 private:
  static RendererAPI s_RendererAPI;
};

}  // namespace Hazel