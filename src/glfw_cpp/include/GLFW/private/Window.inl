#include "GLFW/Context.hpp"

namespace glfw {
    inline void Window::setHints(const WindowHints& hints) {
        if (false == Context::getInstance().isInitialized()) {
            throw std::runtime_error("GLFW failed to initialize!");
        }

        glfwWindowHint(GLFW_RESIZABLE, hints.resizable);
        glfwWindowHint(GLFW_VISIBLE, hints.visible);
        glfwWindowHint(GLFW_DECORATED, hints.decorated);
        glfwWindowHint(GLFW_FOCUSED, hints.focused);
        glfwWindowHint(GLFW_AUTO_ICONIFY, hints.autoIconify);
        glfwWindowHint(GLFW_FLOATING, hints.floating);
        glfwWindowHint(GLFW_MAXIMIZED, hints.maximized);
        glfwWindowHint(GLFW_RED_BITS, hints.redBits);
        glfwWindowHint(GLFW_GREEN_BITS, hints.greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, hints.blueBits);
        glfwWindowHint(GLFW_DEPTH_BITS, hints.depthBits);
        glfwWindowHint(GLFW_STENCIL_BITS, hints.stencilBits);
        glfwWindowHint(GLFW_ACCUM_RED_BITS, hints.accumRedBits);
        glfwWindowHint(GLFW_ACCUM_GREEN_BITS, hints.greenBits);
        glfwWindowHint(GLFW_ACCUM_BLUE_BITS, hints.blueBits);
        glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, hints.accumAlphaBits);
        glfwWindowHint(GLFW_AUX_BUFFERS, hints.auxBuffers);
        glfwWindowHint(GLFW_SAMPLES, hints.samples);
        glfwWindowHint(GLFW_REFRESH_RATE, hints.refreshRate);
        glfwWindowHint(GLFW_STEREO, hints.stereo);
        glfwWindowHint(GLFW_SRGB_CAPABLE, hints.srgbCapable);
        glfwWindowHint(GLFW_DOUBLEBUFFER, hints.doubleBuffer);
        glfwWindowHint(GLFW_CLIENT_API, static_cast<int> (hints.clientAPI));
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, static_cast<int> (hints.contextCreationAPI));
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, hints.contextVersionMajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, hints.contextVersionMinor);
        glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, static_cast<int> (hints.contextReleaseBehavior));
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, hints.openglForwardCompat);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, hints.openGLDebugContext);
        glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int> (hints.openglProfile));
    }

    inline Window::Window(int width, int height, const std::string& title, const Monitor * pMonitor, const Window * pShared) {
        _wrapped = true;

        if (false == Context::getInstance().isInitialized()) {
            throw std::runtime_error("GLFW failed to initialize!");
        }

        GLFWmonitor * monitor = nullptr;

        if (pMonitor) {
            monitor = pMonitor->getHandle();
        }

        GLFWwindow * shared = nullptr;

        if (pShared) {
            shared = pShared->_window;
        }

        _window = glfwCreateWindow(width, height, title.c_str(), monitor, shared);

        if (nullptr == _window) {
            throw std::runtime_error("Failed to create GLFWwindow!");
        }
    }

    inline Window::Window(Window&& other) noexcept {
        _window = other._window;
        _wrapped = other._wrapped;
        other._window = nullptr;    
    }

    inline Window::~Window() noexcept {
        if (_window && !_wrapped) {
            glfwDestroyWindow(_window);
        }
    }

    inline Window& Window::operator= (Window&& other) noexcept {
        auto tmp = _window;
        auto tmpWrapped = _wrapped;

        _window = other._window;
        _wrapped = other._wrapped;

        other._window = tmp;
        other._wrapped = tmpWrapped;

        return *this;
    }

    inline Window& Window::operator= (GLFWwindow* pWindow) noexcept {
        _window = pWindow;
        _wrapped = true;

        return *this;
    }

    inline Window::operator GLFWwindow *() const noexcept {
        return _window;
    }

    inline GLFWwindow * Window::getHandle() const noexcept {
        return _window;
    }

    inline void Window::focus() noexcept {
        glfwFocusWindow(_window);
    }

    inline void Window::getFramebufferSize(int& width, int& height) const noexcept {
        glfwGetFramebufferSize(_window, &width, &height);
    }

    inline void Window::getFrameSize(int& left, int& top, int& right, int& bottom) const noexcept {
        glfwGetWindowFrameSize(_window, &left, &top, &right, &bottom);
    }

    inline Monitor Window::getMonitor() const noexcept {
        return Monitor(glfwGetWindowMonitor(_window));
    }

    inline void Window::getPosition(int& xpos, int& ypos) const noexcept {
        glfwGetWindowPos(_window, &xpos, &ypos);
    }

    inline void Window::getSize(int& width, int& height) const noexcept {
        glfwGetWindowSize(_window, &width, &height);
    }
    
    inline void * Window::getUserPointer() const noexcept {
        return glfwGetWindowUserPointer(_window);
    }

    inline void Window::hide() noexcept {
        glfwHideWindow(_window);
    }

    inline void Window::iconify() noexcept {
        glfwIconifyWindow(_window);
    }

    inline void Window::maximize() noexcept {
        glfwMaximizeWindow(_window);
    }

    inline void Window::restore() noexcept {
        glfwRestoreWindow(_window);
    }

    inline void Window::setCursorPositionCallback(GLFWcursorposfun cb) noexcept {
        glfwSetCursorPosCallback(_window, cb);
    }

    inline void Window::setFramebufferSizeCallback(GLFWframebuffersizefun cb) noexcept {
        glfwSetFramebufferSizeCallback(_window, cb);
    }

    inline void Window::setAspectRatio(int num, int denom) noexcept {
        glfwSetWindowAspectRatio(_window, num, denom);
    }

    inline void Window::setCloseCallback(GLFWwindowclosefun cb) noexcept {
        glfwSetWindowCloseCallback(_window, cb);
    }

    inline void Window::setFocusCallback(GLFWwindowfocusfun cb) noexcept {
        glfwSetWindowFocusCallback(_window, cb);
    }

    inline void Window::setIconifyCallback(GLFWwindowiconifyfun cb) noexcept {
        glfwSetWindowIconifyCallback(_window, cb);
    }

    inline void Window::setMonitor(const Monitor& monitor, int xpos, int ypos, int width, int height, int refreshRate) noexcept {
        glfwSetWindowMonitor(_window, monitor, xpos, ypos, width, height, refreshRate);
    }

    inline void Window::setPosition(int xpos, int ypos) noexcept {
        glfwSetWindowPos(_window, xpos, ypos);
    }

    inline void Window::setPositionCallback(GLFWwindowposfun cb) noexcept {
        glfwSetWindowPosCallback(_window, cb);
    }

    inline void Window::setRefreshCallback(GLFWwindowrefreshfun cb) noexcept {
        glfwSetWindowRefreshCallback(_window, cb);
    }

    inline void Window::setShouldClose(bool value) noexcept {
        glfwSetWindowShouldClose(_window, value);
    }

    inline void Window::setSize(int width, int height) noexcept {
        glfwSetWindowSize(_window, width, height);
    }

    inline void Window::setSizeCallback(GLFWwindowsizefun cb) noexcept {
        glfwSetWindowSizeCallback(_window, cb);
    }

    inline void Window::setSizeLimits(int minWidth, int minHeight, int maxWidth, int maxHeight) noexcept {
        glfwSetWindowSizeLimits(_window, minWidth, minHeight, maxWidth, maxHeight);
    }

    inline void Window::setTitle(const std::string& title) noexcept {
        glfwSetWindowTitle(_window, title.c_str());
    }

    inline void Window::setUserPointer(void * ptr) noexcept {
        glfwSetWindowUserPointer(_window, ptr);
    }

    inline void Window::show() noexcept {
        glfwShowWindow(_window);
    }

    inline void Window::swapBuffers() noexcept {
        glfwSwapBuffers(_window);
    }

    inline bool Window::shouldClose() const noexcept {
        return glfwWindowShouldClose(_window);
    }

    inline void Window::makeContextCurrent() noexcept {
        glfwMakeContextCurrent(_window);
    }

    inline std::string Window::getClipboardString() const noexcept {        
        return glfwGetClipboardString(_window);
    }

    inline KeyState Window::getKey(int key) const noexcept {
        return static_cast<KeyState> (glfwGetKey(_window, key));
    }

    inline void Window::setCharCallback(GLFWcharfun cb) noexcept {
        glfwSetCharCallback(_window, cb);
    }

    inline void Window::setCharModsCallback(GLFWcharmodsfun cb) noexcept {
        glfwSetCharModsCallback(_window, cb);
    }

    inline void Window::setClipboardString(const std::string& str) noexcept {
        glfwSetClipboardString(_window, str.c_str());   
    }

    inline void Window::setCursorEnterCallback(GLFWcursorenterfun cb) noexcept {
        glfwSetCursorEnterCallback(_window, cb);
    }

    inline void Window::setCursorPosition(double xpos, double ypos) noexcept {
        glfwSetCursorPos(_window, xpos, ypos);
    }

    inline float Window::getOpacity() const noexcept {
        return glfwGetWindowOpacity(_window);
    }

    inline void Window::requestAttention() noexcept {
        glfwRequestWindowAttention(_window);
    }

    inline void Window::setDropCallback(GLFWdropfun cb) noexcept {
        glfwSetDropCallback(_window, cb);
    }

    inline void Window::setKeyCallback(GLFWkeyfun cb) noexcept {
        glfwSetKeyCallback(_window, cb);
    }

    inline void Window::setMouseButtonCallback(GLFWmousebuttonfun cb) noexcept {
        glfwSetMouseButtonCallback(_window, cb);
    }

    inline void Window::setScrollCallback(GLFWscrollfun cb) noexcept {
        glfwSetScrollCallback(_window, cb);
    }

    inline void Window::setContentScaleCallback(GLFWwindowcontentscalefun cb) noexcept {
        glfwSetWindowContentScaleCallback(_window, cb);
    }

    inline void Window::setMaximizedCallback(GLFWwindowmaximizefun cb) noexcept {
        glfwSetWindowMaximizeCallback(_window, cb);
    }

    inline void Window::setOpacity(float opacity) noexcept {
        glfwSetWindowOpacity(_window, opacity);
    }

    inline void Window::getCursorPosition(double& xpos, double& ypos) const noexcept {
        glfwGetCursorPos(_window, &xpos, &ypos);
    }

    inline ButtonState Window::getMouseButton(int mouseButton) const noexcept {
        return static_cast<ButtonState> (glfwGetMouseButton(_window, mouseButton));
    }

#if defined(VK_VERSION_1_0)
    inline VkSurfaceKHR Window::createSurface(VkInstance instance, const VkAllocationCallbacks * allocator) const noexcept {
        VkSurfaceKHR out = VK_NULL_HANDLE;

        glfwCreateWindowSurface(instance, _window, allocator, &out);

        return out;
    }
#endif

    inline void Window::setIcon(int count, const GLFWimage * images) noexcept {
        glfwSetWindowIcon(_window, count, images);
    }

    inline void Window::setIcon(const std::vector<GLFWimage>& images) noexcept {
        glfwSetWindowIcon(_window, static_cast<int> (images.size()), images.data());
    }

    inline void Window::setCursor(const Cursor& cursor) noexcept {
        glfwSetCursor(_window, cursor);
    }
}
