//
// Created by Brett Bowman on 9/18/20.
//
#pragma once

#include "Hazel/Core/Layer.h"

namespace Hazel {

    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& e) override;
    private:
        float m_Time;
    };

}