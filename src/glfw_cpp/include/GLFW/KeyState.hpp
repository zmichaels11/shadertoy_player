#pragma once

#include <string>

#include <GLFW/glfw3.h>

namespace glfw {
    enum class KeyState : int {
        PRESS = GLFW_PRESS,
        RELEASE = GLFW_RELEASE,
        REPEAT = GLFW_REPEAT
    };
}

namespace std {
    string to_string(glfw::KeyState keyState) noexcept;
}

#include "GLFW/private/KeyState.inl"
