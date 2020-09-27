//
// Created by Brett Bowman on 9/11/20.
//

#include "Application.h"

#include <glad/glad.h>

#include "Hazel/Core/Input.h"
#include "Hazel/Core/Log.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Renderer/BufferLayout.h"
#include "hzpch.h"

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Application *Application::s_Instance = nullptr;

static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
  switch (type) {
    case Hazel::ShaderDataType::Float:
      return GL_FLOAT;
    case Hazel::ShaderDataType::Float2:
      return GL_FLOAT;
    case Hazel::ShaderDataType::Float3:
      return GL_FLOAT;
    case Hazel::ShaderDataType::Float4:
      return GL_FLOAT;
    case Hazel::ShaderDataType::Mat3:
      return GL_FLOAT;
    case Hazel::ShaderDataType::Mat4:
      return GL_FLOAT;
    case Hazel::ShaderDataType::Int:
      return GL_INT;
    case Hazel::ShaderDataType::Int2:
      return GL_INT;
    case Hazel::ShaderDataType::Int3:
      return GL_INT;
    case Hazel::ShaderDataType::Int4:
      return GL_INT;
    case Hazel::ShaderDataType::Bool:
      return GL_BOOL;
    default:
      HZ_CORE_ASSERT(false, "Unknown ShaderDataType!");
      return GL_NONE;
  }

  HZ_CORE_ASSERT(false, "Unknown ShaderDataType!");
  return 0;
}

Application::Application() {
  HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
  s_Instance = this;

  m_Window = std::unique_ptr<Window>(Window::Create());
  m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

  m_ImGuiLayer = new ImGuiLayer();
  PushOverlay(m_ImGuiLayer);

  glGenVertexArrays(1, &m_VertexArray);
  glBindVertexArray(m_VertexArray);

  float vertices[3 * 7] = {-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
                           0.5f,  -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
                           0.0f,  0.5f,  0.0f, 0.8f, 0.8f, 0.2f, 1.0f};

  m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

  {
    BufferLayout in_layout = {{ShaderDataType::Float3, "a_Position"},
                              {ShaderDataType::Float4, "a_Color"}};

    m_VertexBuffer->SetLayout(in_layout);
  }

  uint32_t index = 0;
  const auto &layout = m_VertexBuffer->GetLayout();
  for (const auto &element : layout) {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, element.GetComponentCount(),
                          ShaderDataTypeToOpenGLBaseType(element.Type),
                          element.Normalized ? GL_TRUE : GL_FALSE,
                          layout.GetStride(),
                          (const void *)static_cast<uint64_t>(element.Offset));
    index++;
  }

  uint32_t indices[3] = {0, 1, 2};
  m_IndexBuffer.reset(
      IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

  const std::string vertexSrc = R"(
      #version 330 core

      layout(location = 0) in vec3 a_Position;

      out vec3 v_Position;

      void main()
      {
          v_Position = a_Position;
          gl_Position = vec4(a_Position, 1.0);
      }
  )";

  const std::string fragmentSrc = R"(
      #version 330 core

      layout(location = 0) out vec4 color;

      in vec3 v_Position;

      void main()
      {
          color = vec4(v_Position * 0.5 + 0.5, 1.0);
      }
  )";

  m_Shader.reset(new Shader(vertexSrc, fragmentSrc));
}

Application::~Application() {}

void Application::Run() {
  while (m_Running) {
    glClearColor(0.1f, 0.1f, 0.1f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    m_Shader->Bind();
    glBindVertexArray(m_VertexArray);
    glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT,
                   nullptr);

    for (Layer *layer : m_LayerStack) layer->OnUpdate();

    m_ImGuiLayer->Begin();
    for (Layer *layer : m_LayerStack) layer->OnImGuiRender();
    m_ImGuiLayer->End();

    m_Window->OnUpdate();
  }
}

void Application::OnEvent(Event &e) {
  EventDispatcher dispatcher(e);
  dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

  // HZ_CORE_TRACE("{0}", e);

  for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
    (*--it)->OnEvent(e);
    if (e.Handled) break;
  }
}

bool Application::OnWindowClose(WindowCloseEvent &e) {
  (void)e;
  m_Running = false;
  return true;
}

void Application::PushLayer(Layer *layer) {
  m_LayerStack.PushLayer(layer);
  layer->OnAttach();
}

void Application::PushOverlay(Layer *overlay) {
  m_LayerStack.PushOverlay(overlay);
  overlay->OnAttach();
}
}  // namespace Hazel
