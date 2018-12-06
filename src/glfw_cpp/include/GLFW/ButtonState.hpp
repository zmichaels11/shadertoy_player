#pragma once

#include <string>

#include <GLFW/glfw3.h>

namespace glfw {
    enum class ButtonState : unsigned char {
        PRESS = GLFW_PRESS,
        RELEASE = GLFW_RELEASE
    };
}

namespace std {
    string to_string(glfw::ButtonState buttonState) noexcept;
}

#include "GLFW/private/ButtonState.inl"
