//
// Created by Brett Bowman on 9/11/20.
//

#include "Hazel.h"

class ExampleLayer : public Hazel::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {}

    void OnUpdate() override
    {
        //HZ_INFO("ExampleLayer::OnUpdate");
        if (Hazel::Input::IsKeyPressed(Hazel::Key::Tab))
            HZ_TRACE("Tab key is pressed! (poll)");
    }

    void OnEvent(Hazel::Event& event) override
    {
        if (event.GetEventType() == Hazel::EventType::KeyPressed) {
            Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
            if (e.GetKeyCode() == Hazel::Key::Tab)
                HZ_TRACE("Tab key is pressed! (event)");
            HZ_INFO("{0}", static_cast<char>(e.GetKeyCode()));
        }
    }
};

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}