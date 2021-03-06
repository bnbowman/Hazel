//
// Created by Brett Bowman on 9/23/20.
//
#pragma once

#include "RenderCommand.h"
#include "Shader.h"
#include "OrthographicCamera.h"

namespace Hazel {

class Renderer {
 public:
  static void BeginScene(OrthographicCamera& camera);
  static void EndScene();

  static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

  inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

private:
  struct SceneData
  {
    glm::mat4 ViewProjectionMatrix;
  };

  static SceneData* m_SceneData;
};

}  // namespace Hazel