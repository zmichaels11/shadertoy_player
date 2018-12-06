#pragma once

#include <GLFW/glfw3.h>

namespace glfw {
    enum class ClientAPI : int {
        NO_API = GLFW_NO_API,
        OPENGL_API = GLFW_OPENGL_API,
        OPENGLES_API = GLFW_OPENGL_ES_API,
    };

    enum class ContextCreationAPI : int {
        NATIVE_CONTEXT_API = GLFW_NATIVE_CONTEXT_API,
        EGL_CONTEXT_API = GLFW_EGL_CONTEXT_API
    };

    enum class ContextRobustness : int {
        NO_ROBUSTNESS = GLFW_NO_ROBUSTNESS,
        NO_RESET_NOTIFICATION = GLFW_NO_RESET_NOTIFICATION,
        LOSE_CONTEXT_ON_RESET = GLFW_LOSE_CONTEXT_ON_RESET
    };

    enum class ContextReleaseBehavior : int {
        ANY = GLFW_ANY_RELEASE_BEHAVIOR,
        FLUSH = GLFW_RELEASE_BEHAVIOR_FLUSH,
        NONE = GLFW_RELEASE_BEHAVIOR_NONE
    };

    enum class OpenGLProfile : int {
        ANY = GLFW_OPENGL_ANY_PROFILE,
        COMPAT = GLFW_OPENGL_COMPAT_PROFILE,
        CORE = GLFW_OPENGL_CORE_PROFILE
    };

    struct WindowHints {
        bool resizable;
        bool visible;
        bool decorated;
        bool focused;
        bool autoIconify;
        bool floating;
        bool maximized;
        int redBits;
        int greenBits;
        int blueBits;
        int alphaBits;
        int depthBits;
        int stencilBits;
        int accumRedBits;
        int accumGreenBits;
        int accumBlueBits;
        int accumAlphaBits;
        int auxBuffers;
        int samples;
        int refreshRate;
        bool stereo;
        bool srgbCapable;
        bool doubleBuffer;
        ClientAPI clientAPI;
        ContextCreationAPI contextCreationAPI;
        int contextVersionMajor;
        int contextVersionMinor;
        ContextRobustness contextRobustness;
        ContextReleaseBehavior contextReleaseBehavior;
        bool openglForwardCompat;
        bool openGLDebugContext;
        OpenGLProfile openglProfile;

        static WindowHints defaults() noexcept;
    };
}

#include "GLFW/private/WindowHints.inl"
