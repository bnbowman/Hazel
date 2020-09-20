//
// Created by Brett Bowman on 9/19/20.
//
#pragma once

#include "Hazel/Core/Input.h"

namespace Hazel {

    class MacInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) const override;
        virtual bool IsMouseButtonPressedImpl(int button) const override;
        virtual std::pair<float, float> GetMousePositionImpl() const override;
        virtual float GetMouseXImpl() const override;
        virtual float GetMouseYImpl() const override;
    };

}