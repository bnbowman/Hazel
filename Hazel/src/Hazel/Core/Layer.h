//
// Created by Brett Bowman on 9/14/20.
//
#pragma once

#include "Hazel/Core/Timestep.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

class Layer {
 public:
  Layer(const std::string &name = "Layer");
  virtual ~Layer();

  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUpdate(Hazel::Timestep ts) { (void)ts; }
  virtual void OnImGuiRender() {}
  virtual void OnEvent(Event &event) { (void)event; }

  inline const std::string &GetName() const { return m_DebugName; }

 protected:
  std::string m_DebugName;
};

}  // namespace Hazel
