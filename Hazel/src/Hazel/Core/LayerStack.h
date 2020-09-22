//
// Created by Brett Bowman on 9/14/20.
//
#pragma once

#include "Hazel/Core/Layer.h"

#include <vector>

namespace Hazel {

using LayerIterator = std::vector<Layer *>::iterator;

class LayerStack {
 public:
  LayerStack();
  ~LayerStack();

  void PushLayer(Layer *layer);
  void PushOverlay(Layer *layer);
  void PopLayer(Layer *overlay);
  void PopOverlay(Layer *overlay);

  LayerIterator begin() { return m_Layers.begin(); }
  LayerIterator end() { return m_Layers.end(); }

 protected:
  std::vector<Layer *> m_Layers;
  unsigned int m_LayerInsertIndex = 0;
};

}  // namespace Hazel
