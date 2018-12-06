#pragma once

#include <string>

#include <GLFW/glfw3.h>

namespace glfw {
    enum class Hat : unsigned char {
        CENTERED = GLFW_HAT_CENTERED,
        UP = GLFW_HAT_UP,
        DOWN = GLFW_HAT_DOWN,
        LEFT = GLFW_HAT_LEFT,
        RIGHT = GLFW_HAT_RIGHT,
        LEFT_UP = GLFW_HAT_LEFT_UP,
        RIGHT_UP = GLFW_HAT_RIGHT_UP,
        LEFT_DOWN = GLFW_HAT_LEFT_DOWN,
        RIGHT_DOWN = GLFW_HAT_RIGHT_DOWN
    };

    Hat operator| (Hat lhs, Hat rhs) noexcept;

    Hat operator& (Hat lhs, Hat rhs) noexcept;

    Hat& operator|= (Hat& lhs, Hat rhs) noexcept;

    Hat& operator&= (Hat& lhs, Hat& rhs) noexcept;
}

namespace std {
    string to_string(glfw::Hat hat) noexcept;
}

#include "GLFW/private/Hat.inl"
