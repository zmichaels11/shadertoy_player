namespace glfw {
    inline WindowHints WindowHints::defaults() noexcept {
        auto out = WindowHints {};
        
        out.resizable = true;
        out.visible = true;
        out.decorated = true;
        out.focused = true;
        out.autoIconify = true;
        out.floating = false;
        out.maximized = false;
        out.redBits = 8;
        out.greenBits = 8;
        out.blueBits = 8;
        out.depthBits = 24;
        out.stencilBits = 8;
        out.accumRedBits = 0;
        out.accumGreenBits = 0;
        out.accumBlueBits = 0;
        out.accumAlphaBits = 0;
        out.auxBuffers = 0;
        out.samples = 0;
        out.refreshRate = GLFW_DONT_CARE;
        out.stereo = false;
        out.srgbCapable = false;
        out.doubleBuffer = true;
        out.clientAPI = ClientAPI::OPENGL_API;
        out.contextCreationAPI = ContextCreationAPI::NATIVE_CONTEXT_API;
        out.contextVersionMajor = 1;
        out.contextVersionMinor = 0;
        out.contextReleaseBehavior = ContextReleaseBehavior::ANY;
        out.openglForwardCompat = false;
        out.openGLDebugContext = false;
        out.openglProfile = OpenGLProfile::ANY;

        return out;
    }
}
