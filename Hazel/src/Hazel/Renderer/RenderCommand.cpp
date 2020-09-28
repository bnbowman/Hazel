//
// Created by Brett Bowman on 9/27/20.
//

#include "RenderCommand.h"

#include "Hazel/Platform/OpenGL/OpenGLRendererAPI.h"
#include "hzpch.h"

namespace Hazel {

RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}