#include "GLFW/Context.hpp"

namespace glfw {
    inline Monitor Monitor::getPrimary() {
        if (false == Context::getInstance().isInitialized()) {
            throw std::runtime_error("GLFW failed to initialize!");
        }

        return Monitor(glfwGetPrimaryMonitor());
    }

    inline std::vector<Monitor> Monitor::getMonitors() {
        if (false == Context::getInstance().isInitialized()) {
            throw std::runtime_error("GLFW failed to initialize!");
        }

        auto out = std::vector<Monitor> ();
        int count;

        const auto monitors = glfwGetMonitors(&count);

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(Monitor(monitors[i]));
        }

        return out;
    }

    inline void Monitor::setCallback(GLFWmonitorfun cb) {
        if (false == Context::getInstance().isInitialized()) {
            throw std::runtime_error("GLFW failed to initialize!");
        }

        glfwSetMonitorCallback(cb);
    }

    inline Monitor& Monitor::operator= (GLFWmonitor * pMonitor) noexcept {
        _monitor = pMonitor;

        return *this;
    }

    inline Monitor::operator GLFWmonitor*() const noexcept {
        return _monitor;
    }

    inline GLFWmonitor* Monitor::getHandle() const noexcept {
        return _monitor;
    }

    inline void Monitor::getPosition(int& xpos, int& ypos) const noexcept {
        glfwGetMonitorPos(_monitor, &xpos, &ypos);
    }

    inline void Monitor::getPhysicalSize(int& widthMM, int& heightMM) const noexcept {
        glfwGetMonitorPhysicalSize(_monitor, &widthMM, &heightMM);
    }

    inline std::string Monitor::getName() const noexcept {
        return glfwGetMonitorName(_monitor);
    }

    inline GLFWvidmode Monitor::getVideoMode() const noexcept {
        return *glfwGetVideoMode(_monitor);
    }

    inline std::vector<GLFWvidmode> Monitor::getVideoModes() const noexcept {
        auto out = std::vector<GLFWvidmode> ();
        int count;

        auto modes = glfwGetVideoModes(_monitor, &count);

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(modes[i]);
        }

        return out;
    }

    inline void Monitor::setGamma(float gamma) noexcept {
        glfwSetGamma(_monitor, gamma);
    }

    inline GLFWgammaramp Monitor::getGammaRamp() const noexcept {
        return *glfwGetGammaRamp(_monitor);
    }

    inline void Monitor::setGammaRamp(const GLFWgammaramp& ramp) noexcept {
        glfwSetGammaRamp(_monitor, &ramp);
    }

    inline void Monitor::setUserPointer(void * ptr) noexcept {
        glfwSetMonitorUserPointer(_monitor, ptr);
    }

    inline void * Monitor::getUserPointer() const noexcept {
        return glfwGetMonitorUserPointer(_monitor);
    }
}
