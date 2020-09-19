//
// Created by Brett Bowman on 9/12/20.
//
#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel {

    struct WindowProperties
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProperties(const std::string& title = "Hazel Engine",
                         unsigned int width = 1200,
                         unsigned int height = 720)
         : Title(title), Width(width), Height(height)
        {}
    };

    // Interface class representing a Desktop system style Window
    class Window {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetHeight() const = 0;
        virtual unsigned int GetWidth() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(const bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowProperties& props = WindowProperties());
    };
}