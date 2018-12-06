#pragma once

#include <string>

#include <GLFW/glfw3.h>

namespace glfw {
    enum class StandardCursorShapes : int {
        ARROW = GLFW_ARROW_CURSOR,
        IBEAM = GLFW_IBEAM_CURSOR,
        CROSSHAIR = GLFW_CROSSHAIR_CURSOR,
        HAND = GLFW_HAND_CURSOR,
        HRESIZE = GLFW_HRESIZE_CURSOR,
        VRESIZE = GLFW_VRESIZE_CURSOR
    };
}

namespace std {
    string to_string(glfw::StandardCursorShapes shape) noexcept;
}

#include "GLFW/private/StandardCursorShapes.inl"
