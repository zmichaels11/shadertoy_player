#pragma once

#include <GLFW/glfw3.h>

#include "GLFW/StandardCursorShapes.hpp"

namespace glfw {
    class Cursor {
        GLFWcursor * _cursor;

        Cursor(const Cursor&) = delete;

        Cursor& operator= (const Cursor&) = delete;

    public:
        Cursor() noexcept:
            _cursor(nullptr) {}
            
        Cursor(const GLFWimage * image, int xhot, int yhot) noexcept;

        Cursor(StandardCursorShapes shape) noexcept;

        Cursor(Cursor&& other) noexcept;

        ~Cursor() noexcept;

        Cursor& operator= (Cursor&& other) noexcept;

        GLFWcursor * getHandle() const noexcept;

        operator GLFWcursor*() const noexcept;
    };
}

#include "GLFW/private/Cursor.inl"