//
// Created by Brett Bowman on 9/23/20.
//

#include "Renderer.h"

#include "hzpch.h"

namespace Hazel {

void Renderer::BeginScene() {}

void Renderer::EndScene() {}

void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray) {
  vertexArray->Bind();
  RenderCommand::DrawIndexed(vertexArray);
}

}  // namespace Hazel