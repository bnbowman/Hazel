//
// Created by Brett Bowman on 9/11/20.
//

#include "hzpch.h"
#include "Application.h"

#include "Core/Log.h"
#include "Events/ApplicationEvent.h"

namespace Hazel {

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        while(m_Running) {
            m_Window->OnUpdate();
        }
    }

}