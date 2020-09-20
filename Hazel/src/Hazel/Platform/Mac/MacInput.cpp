//
// Created by Brett Bowman on 9/19/20.
//
#include "hzpch.h"
#include "MacInput.h"

#include "Hazel/Application.h"

#include <GLFW/glfw3.h>
namespace Hazel {

    Input* Input::s_Instance = new MacInput();

    bool MacInput::IsKeyPressedImpl(int keycode) const
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);

        return (state == GLFW_PRESS) || (state == GLFW_REPEAT);
    }

    bool MacInput::IsMouseButtonPressedImpl(int button) const
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> MacInput::GetMousePositionImpl() const
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return { static_cast<float>(xpos), static_cast<float>(ypos) };
    }

    float MacInput::GetMouseXImpl() const
    {
        const auto& p = GetMousePositionImpl();
        return std::get<0>(p);
    }

    float MacInput::GetMouseYImpl() const
    {
        const auto& p = GetMousePositionImpl();
        return std::get<1>(p);
    }
}