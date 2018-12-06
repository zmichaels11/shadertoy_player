namespace glfw {
    inline void Gamepad::updateMappings(const std::string& path) noexcept {
        glfwUpdateGamepadMappings(path.c_str());
    }

    inline void Gamepad::updateMappings(const char * path) noexcept {
        glfwUpdateGamepadMappings(path);
    }

    inline std::vector<Gamepad> Gamepad::getPresentGamepads() noexcept {
        auto out = std::vector<Gamepad> ();

        for (int i = GLFW_JOYSTICK_1; i <= GLFW_JOYSTICK_LAST; i++) {
            if (glfwJoystickPresent(i) && glfwJoystickIsGamepad(i)) {
                out.push_back(Gamepad(i));
            }
        }

        return out;
    }

    inline std::string Gamepad::getName() const noexcept {
        return glfwGetGamepadName(_id);
    }

    inline GLFWgamepadstate Gamepad::getState() const noexcept {
        GLFWgamepadstate out;

        glfwGetGamepadState(_id, &out);

        return out;
    }

    inline int Gamepad::getId() const noexcept {
        return _id;
    }

    inline Gamepad::operator int() const noexcept {
        return _id;
    }    
}
