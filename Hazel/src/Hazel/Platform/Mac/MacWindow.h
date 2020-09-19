//
// Created by Brett Bowman on 9/13/20.
//
#pragma once

#include "Hazel/Core/Window.h"

#include "GLFW/glfw3.h"

namespace Hazel {

    class MacWindow : public Window
    {
    public:
        MacWindow(const WindowProperties& properties);
        virtual ~MacWindow();

        void OnUpdate() override;

        inline unsigned int GetHeight() const override { return m_Data.Height; }
        inline unsigned int GetWidth() const override { return m_Data.Width; }

        virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
        virtual void SetVSync(const bool enabled) override;
        virtual bool IsVSync() const override;

        virtual void* GetNativeWindow() const override { return m_Window; }

        static Window* Create(const WindowProperties& props = WindowProperties());

    private:
        virtual void Init(const WindowProperties& properties);
        virtual void Shutdown();

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };

}
