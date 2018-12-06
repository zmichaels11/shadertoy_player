#pragma once

#include <cstdint>

#include <string>
#include <vector>

#include <GLFW/glfw3.h>

namespace glfw {
    class Context {
        bool _initialized;

        Context() noexcept;
        Context(const Context&) = delete;
        Context(Context&& other) noexcept;
        
        Context& operator= (const Context&) = delete;
        Context& operator= (Context&& other) noexcept;

    public:
        ~Context() noexcept;

        static Context& getInstance() noexcept;

        bool isInitialized() const noexcept;

        void pollEvents() noexcept;

        void setErrorCallback(GLFWerrorfun cb) noexcept;

        bool extensionSupported(const std::string& ext) const noexcept;

        int getError(const char ** pDescription) const noexcept;

        std::string getKeyName(int key, int scancode) const noexcept;

        int getKeyScancode(int key) const noexcept;

        GLFWglproc getProcAddress(const char * procname) const noexcept;

        void postEmptyEvent() noexcept;

        double getTime() const noexcept;

        std::uint64_t getTimerFrequency() const noexcept;

        std::uint64_t getTimerValue() const noexcept;

        void setTime(double time) noexcept;

        void swapInterval(int interval) noexcept;

        void waitEvents() noexcept;

        void waitEventsTimeout(double timeout) noexcept;

        bool vulkanSupported() const noexcept;

#if defined(VK_VERSION_1_0)
        GLFWvkproc getInstanceProcAddress(VkInstance instance, const char * procName) const noexcept;

        std::vector<std::string> getRequiredInstanceExtensions() const noexcept
#endif

    };
}

#include "GLFW/private/Context.inl"
