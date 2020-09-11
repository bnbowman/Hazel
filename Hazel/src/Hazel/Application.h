//
// Created by Brett Bowman on 9/11/20.
//

#pragma once

namespace Hazel {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined by CLIENT
    Application* CreateApplication();
}

