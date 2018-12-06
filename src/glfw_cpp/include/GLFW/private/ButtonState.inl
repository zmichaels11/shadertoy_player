namespace std {
    inline string to_string(glfw::ButtonState buttonState) noexcept {
        switch (buttonState) {
            case glfw::ButtonState::PRESS:      return "PRESS";
            case glfw::ButtonState::RELEASE:    return "RELEASE";
            default:                            return "INVALID";
        }
    }
}
