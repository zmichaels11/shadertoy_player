#include <iostream>

#define GLFW_INCLUDE_ES2
#include "GLFW/glfw3.hpp"

int main(int argc, char** argv) {
    auto& ctx = glfw::Context::getInstance();

    ctx.setErrorCallback([] (int err, const char * desc) {
        std::cerr << "Error 0x" << std::hex << err << ": " << desc << std::endl;
    });

    {
        auto hints = glfw::WindowHints::defaults();
        hints.clientAPI = glfw::ClientAPI::OPENGLES_API;
        hints.contextCreationAPI = glfw::ContextCreationAPI::EGL_CONTEXT_API;
        hints.contextVersionMajor = 2;
        hints.contextVersionMinor = 0;

        glfw::Window::setHints(hints);
    }

    auto monitor = glfw::Monitor::getPrimary();
    
    struct WindowSize_T {
        int width;
        int height;
    } windowSize;

    {
        auto videoMode = monitor.getVideoMode();

        windowSize.width = videoMode.width;
        windowSize.height = videoMode.height;
    }

    auto window = glfw::Window(windowSize.width, windowSize.height, "ShaderToy Player", &monitor);

    window.setKeyCallback([] (auto pWindow, auto key, auto scancode, auto action, auto mods) {
        // if any key is pressed
        if (GLFW_RELEASE == action) {
            auto window = glfw::Window(pWindow);

            window.setShouldClose(true);
        }
    });

    window.makeContextCurrent();
    window.show();
    
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) 
            << "\nOpenGL Vendor: " << glGetString(GL_VERSION) 
            << "\nOpenGL Renderer: " << glGetString(GL_RENDERER) 
            << "\nShading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);

    while (false == window.shouldClose()) {
        ctx.pollEvents();
        window.swapBuffers();
    }

    return 0;
}