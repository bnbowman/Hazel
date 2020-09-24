//
// Created by Brett Bowman on 9/22/20.
//
#pragma once

namespace Hazel {

class RenderContext {
 public:
  virtual void Init() = 0;
  virtual void SwapBuffers() = 0;
};

}  // namespace Hazel