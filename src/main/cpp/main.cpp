#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <vector>

#define GLFW_INCLUDE_ES2
#include "GLFW/glfw3.hpp"

namespace {
    std::string readFile(const std::string fileName) noexcept {
        auto input = std::ifstream(fileName);
        
        return std::string(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
    }

    GLuint createShader(GLenum type, const std::string& source) {
        auto shader = glCreateShader(type);
        auto src = source.c_str();
        auto sz = static_cast<GLint> (source.size());

        glShaderSource(shader, 1, &src, &sz);
        glCompileShader(shader);

        GLint status = GL_FALSE;

        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

        if (GL_FALSE == status) {
            GLint infoLogLength = 0;

            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

            auto infoLog = std::make_unique<GLchar[]> (infoLogLength);

            glGetShaderInfoLog(shader, infoLogLength, &infoLogLength, infoLog.get());

            GLint srclen;
            glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &srclen);

            auto src = std::make_unique<GLchar[]> (srclen);

            glGetShaderSource(shader, srclen, &srclen, src.get());

            auto errmsg = std::stringstream();

            errmsg << "Failed to compile shader: " << infoLog.get()
                << "\nSource: " << src.get() << std::endl;

            throw std::runtime_error(errmsg.str());
        }

        return shader;
    }

    GLuint createProgram(const std::vector<GLuint>& shaders) {
        auto program = glCreateProgram();

        for (auto& shader : shaders) {
            glAttachShader(program, shader);
        }

        glLinkProgram(program);

        for (auto& shader : shaders) {
            //glDetachShader(program, shader);
        }

        GLint status = GL_FALSE;

        glGetProgramiv(program, GL_LINK_STATUS, &status);

        if (GL_FALSE == status) {
            GLint infoLogLength = 0;

            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

            auto infoLog = std::make_unique<GLchar[]> (infoLogLength);

            glGetProgramInfoLog(program, infoLogLength, &infoLogLength, infoLog.get());

            auto errmsg = std::stringstream();
            errmsg << "Failed to link program: " << infoLog.get();


            throw std::runtime_error(errmsg.str());
        }

        return program;
    }
}

int main(int argc, char** argv) {
    auto& ctx = glfw::Context::getInstance();

    ctx.setErrorCallback([] (int err, const char * desc) {
        std::cerr << "Error 0x" << std::hex << err << ": " << desc << std::endl;
    });

    {
        auto hints = glfw::WindowHints::defaults();
        hints.clientAPI = glfw::ClientAPI::OPENGLES_API;
        hints.contextCreationAPI = glfw::ContextCreationAPI::EGL_CONTEXT_API;
        hints.contextVersionMajor = 3;
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
            
    GLuint program;

    {
        auto shaders = std::vector<GLuint> ();

        {
            auto vert = readFile("src/main/glsl/fsq.vert");

            shaders.push_back(createShader(GL_VERTEX_SHADER, vert));
        }

        {
            auto frag = std::stringstream();

            frag << readFile("src/main/glsl/inputs.frag") << "\n";
            frag << readFile("src/main/glsl/default.frag");

            shaders.push_back(createShader(GL_FRAGMENT_SHADER, frag.str()));
        }
        
        program = createProgram(shaders);

        for (auto& shader : shaders) {
            glDeleteShader(shader);
        }
    }

    struct Inputs_T {
        GLint iResolution;
        GLint iTime;
        GLint iTimeDelta;
        GLint iFrame;
        GLint iFrameRate;
        GLint iChannelTime[4];
        GLint iChannelResolution[4];
        GLint iMouse;
        GLint iChannel[8];
        GLint iDate;
        GLint iSampleRate;
    } inputs;


    inputs.iResolution = glGetUniformLocation(program, "iResolution");
    inputs.iTime = glGetUniformLocation(program, "iTime");
    inputs.iTimeDelta = glGetUniformLocation(program, "iTimeDelta");
    inputs.iFrame = glGetUniformLocation(program, "iFrame");
    inputs.iFrameRate = glGetUniformLocation(program, "iFrameRate");
    inputs.iMouse = glGetUniformLocation(program, "iMouse");
    inputs.iDate = glGetUniformLocation(program, "iDate");
    inputs.iSampleRate = glGetUniformLocation(program, "iSampleRate");

    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);

    auto lastTime = ctx.getTime();
    int frame = 0;

    while (false == window.shouldClose()) {
        struct FramebufferSize_T {
            int width, height;
        } fbSize;

        auto now = ctx.getTime();
        auto dTime = now - lastTime;
        auto frameRate = 1000.0F / dTime;

        window.getFramebufferSize(fbSize.width, fbSize.height);

        glUseProgram(program);
        glUniform3f(inputs.iResolution, fbSize.width, fbSize.height, 1.0F);
        glUniform1f(inputs.iTime, static_cast<float> (now));
        glUniform1f(inputs.iTimeDelta, static_cast<float> (dTime));
        glUniform1i(inputs.iFrame, frame);
        glUniform1f(inputs.iFrameRate, static_cast<float> (frameRate));

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        ctx.pollEvents();
        window.swapBuffers();
    }

    return 0;
}