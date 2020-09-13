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

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        WindowResizeEvent e(1040, 480);
        HZ_TRACE(e);

        while(true);
    }

}