namespace std {
    inline string to_string(glfw::KeyState keyState) noexcept {
        switch (keyState) {
            case glfw::KeyState::PRESS:     return "PRESS";
            case glfw::KeyState::RELEASE:   return "RELEASE";
            case glfw::KeyState::REPEAT:    return "REPEAT";
            default:                        return "INVALID";
        }
    }
}
