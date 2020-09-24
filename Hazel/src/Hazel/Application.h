//
// Created by Brett Bowman on 9/11/20.
//
#pragma once

#include "Hazel/Core/LayerStack.h"
#include "Hazel/Core/Window.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Renderer/Shader.h"

namespace Hazel {

class Application {
 public:
  Application();
  virtual ~Application();

  void Run();
  void OnEvent(Event &e);

  void PushLayer(Layer *layer);
  void PushOverlay(Layer *overlay);

  inline static Application &Get() { return *s_Instance; }
  inline Window &GetWindow() { return *m_Window; }

 private:
  bool OnWindowClose(WindowCloseEvent &e);

  std::unique_ptr<Window> m_Window;
  ImGuiLayer *m_ImGuiLayer;
  bool m_Running = true;
  LayerStack m_LayerStack;

  unsigned int m_VertexArray;
  unsigned int m_VertexBuffer;
  unsigned int m_IndexBuffer;
  std::unique_ptr<Shader> m_Shader;

 private:
  static Application *s_Instance;
};

// To be defined by CLIENT
Application *CreateApplication();
}  // namespace Hazel
