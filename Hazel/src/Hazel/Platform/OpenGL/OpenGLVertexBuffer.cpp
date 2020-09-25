//
// Created by Brett Bowman on 9/23/20.
//
#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

#include "hzpch.h"

namespace Hazel {

OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size) {
  glGenBuffers(1, &m_RendererID);
  glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer() { glDeleteBuffers(1, &m_RendererID); }

void OpenGLVertexBuffer::Bind() const {
  glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void OpenGLVertexBuffer::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

}  // namespace Hazel