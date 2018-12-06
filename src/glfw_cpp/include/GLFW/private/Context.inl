#include <GLFW/glfw3.h>

namespace glfw {
    inline Context& Context::getInstance() noexcept {
        static auto THE_INSTANCE = Context();

        return THE_INSTANCE;
    }
    
    inline Context::Context() noexcept {
        _initialized = glfwInit();
    }

    inline Context::Context(Context&& other) noexcept {
        _initialized = other._initialized;
        other._initialized = false;
    }

    inline Context::~Context() noexcept {
        if (_initialized) {
            glfwTerminate();
        }
    }

    inline Context& Context::operator= (Context&& other) noexcept {
        auto tmp = _initialized;

        _initialized = other._initialized;
        other._initialized = tmp;

        return *this;
    }

    inline bool Context::isInitialized() const noexcept {
        return _initialized;
    }

    inline void Context::pollEvents() noexcept {
        glfwPollEvents();
    }

    inline void Context::setErrorCallback(GLFWerrorfun cb) noexcept {
        glfwSetErrorCallback(cb);
    }

    inline bool Context::extensionSupported(const std::string& ext) const noexcept {
        return glfwExtensionSupported(ext.c_str());
    }

    inline int Context::getError(const char ** pDescription) const noexcept {
        return glfwGetError(pDescription);
    }

    inline std::string Context::getKeyName(int key, int scancode) const noexcept {
        return glfwGetKeyName(key, scancode);
    }

    inline int Context::getKeyScancode(int key) const noexcept {
        return glfwGetKeyScancode(key);
    }

    inline GLFWglproc Context::getProcAddress(const char * procname) const noexcept {
        return glfwGetProcAddress(procname);
    }

    inline void Context::postEmptyEvent() noexcept {
        glfwPostEmptyEvent();
    }

    inline double Context::getTime() const noexcept {
        return glfwGetTime();
    }

    inline std::uint64_t Context::getTimerFrequency() const noexcept {
        return glfwGetTimerFrequency();
    }

    inline std::uint64_t Context::getTimerValue() const noexcept {
        return glfwGetTimerValue();
    }

    inline void Context::setTime(double time) noexcept {
        glfwSetTime(time);
    }

    inline void Context::swapInterval(int interval) noexcept {
        glfwSwapInterval(interval);
    }

    inline void Context::waitEvents() noexcept {
        glfwWaitEvents();
    }

    inline void Context::waitEventsTimeout(double timeout) noexcept {
        glfwWaitEventsTimeout(timeout);
    }

    inline bool Context::vulkanSupported() const noexcept {
        return glfwVulkanSupported();
    }

#if defined(VK_VERSION_1_0)
    inline GLFWvkproc Context::getInstanceProcAddress(VkInstance instance, const char * procName) const noexcept; {
        return glfwGetInstanceProcAddress(instance, procName);
    }

    inline std::vector<std::string> Context::getRequiredInstanceExtensions() const noexcept {
        int count;
        auto extensions = glfwGetRequiredInstanceExtensions(&count);
        auto out = std::vector<std::string> ();

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(extensions[i]);
        }

        return out;
    }
#endif
}
