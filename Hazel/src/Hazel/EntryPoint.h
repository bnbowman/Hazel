//
// Created by Brett Bowman on 9/11/20.
//

#pragma once

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
    Hazel::Log::Init();
    HZ_CORE_WARN("Initialized log!");
    HZ_INFO("Hello!");

    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}

