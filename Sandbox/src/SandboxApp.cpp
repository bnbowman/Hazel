//
// Created by Brett Bowman on 9/11/20.
//

#include "Hazel.h"

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}