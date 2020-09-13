//
// Created by Brett Bowman on 9/11/20.
//
#pragma once

#include "Core/Window.h"
#include "Events/ApplicationEvent.h"

namespace Hazel {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined by CLIENT
    Application* CreateApplication();
}

