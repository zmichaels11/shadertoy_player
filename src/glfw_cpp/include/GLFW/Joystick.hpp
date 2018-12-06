#pragma once

#include <string>
#include <vector>

#include <GLFW/glfw3.h>

#include "GLFW/ButtonState.hpp"
#include "GLFW/Hat.hpp"

namespace glfw {
    class Joystick {
        int _id;

    public:
        static void setCallback(GLFWjoystickfun cb) noexcept;

        static std::vector<Joystick> getJoysticks() noexcept;

        static std::vector<Joystick> getPresentJoysticks() noexcept;
        
        Joystick(int jid) noexcept:
            _id(jid) {}

        operator int() const noexcept;

        int getId() const noexcept;

        bool isPresent() const noexcept;

        bool isGamepad() const noexcept;

        void setUserPointer(void * ptr) noexcept;

        void * getUserPointer() const noexcept;

        std::string getName() const noexcept;

        std::string getGUID() const noexcept;

        std::vector<float> getAxes() const noexcept;

        const float * getAxes(int& count) const noexcept;

        std::vector<ButtonState> getButtons() const noexcept;

        const ButtonState * getButtons(int& count) const noexcept;

        std::vector<Hat> getHats() const noexcept;

        const Hat * getHats(int& count) const noexcept;
    };
}

#include "GLFW/private/Joystick.inl"
