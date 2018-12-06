#pragma once

#include <string>
#include <vector>

#include "GLFW/Joystick.hpp"

namespace glfw {
    class Gamepad {
        int _id;

    public:
        static void updateMappings(const std::string& path) noexcept;

        static void updateMappings(const char * path) noexcept;

        static std::vector<Gamepad> getPresentGamepads() noexcept;

        Gamepad(const Joystick joystick) noexcept: 
            _id(joystick.getId()) {}

        int getId() const noexcept;

        operator int() const noexcept;

        std::string getName() const noexcept;

        GLFWgamepadstate getState() const noexcept;
    };
}

#include "GLFW/private/Gamepad.inl"
