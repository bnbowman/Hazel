//
// Created by Brett Bowman on 9/11/20.
//
#pragma once

#include "Hazel/Core/LayerStack.h"
#include "Hazel/Core/Window.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/IndexBuffer.h"
#include "Hazel/Renderer/VertexBuffer.h"

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
  std::unique_ptr<Shader> m_Shader;
  std::unique_ptr<VertexBuffer> m_VertexBuffer;
  std::unique_ptr<IndexBuffer> m_IndexBuffer;

 private:
  static Application *s_Instance;
};

// To be defined by CLIENT
Application *CreateApplication();
}  // namespace Hazel
