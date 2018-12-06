#pragma once

#include <stdexcept>
#include <string>
#include <vector>

#include <GLFW/glfw3.h>

namespace glfw {
    class Monitor {
        GLFWmonitor * _monitor;

    public:
        static Monitor getPrimary();
        static std::vector<Monitor> getMonitors();
        static void setCallback(GLFWmonitorfun cb);

        Monitor(GLFWmonitor * pMonitor = nullptr) noexcept:
            _monitor(pMonitor) {}

        Monitor& operator= (GLFWmonitor * pMonitor) noexcept;
        operator GLFWmonitor*() const noexcept;

        GLFWmonitor * getHandle() const noexcept;

        void getPosition(int& xpos, int& ypos) const noexcept;

        void getPhysicalSize(int& widthMM, int& heightMM) const noexcept;

        std::string getName() const noexcept;

        GLFWvidmode getVideoMode() const noexcept;

        std::vector<GLFWvidmode> getVideoModes() const noexcept;

        void setGamma(float gamma) noexcept;

        void setGammaRamp(const GLFWgammaramp& ramp) noexcept;

        GLFWgammaramp getGammaRamp() const noexcept;

        void setUserPointer(void * ptr) noexcept;

        void * getUserPointer() const noexcept;
    };
}

#include "GLFW/private/Monitor.inl"
