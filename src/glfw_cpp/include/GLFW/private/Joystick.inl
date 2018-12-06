namespace glfw {
    inline void Joystick::setCallback(GLFWjoystickfun cb) noexcept {
        glfwSetJoystickCallback(cb);
    }

    inline std::vector<Joystick> Joystick::getJoysticks() noexcept {
        auto out = std::vector<Joystick> ();

        for (int i = GLFW_JOYSTICK_1; i <= GLFW_JOYSTICK_LAST; i++) {
            out.push_back(Joystick(i));
        }

        return out;
    }

    inline std::vector<Joystick> Joystick::getPresentJoysticks() noexcept {
        auto out = std::vector<Joystick> ();

        for (int i = GLFW_JOYSTICK_1; i <= GLFW_JOYSTICK_LAST; i++) {
            if (glfwJoystickPresent(i)) {
                out.push_back(Joystick(i));
            }
        }

        return out;
    }

    inline Joystick::operator int() const noexcept {
        return _id;
    }   
    
    inline int Joystick::getId() const noexcept {
        return _id;
    }

    inline bool Joystick::isPresent() const noexcept {
        return glfwJoystickPresent(_id);
    }

    inline std::vector<ButtonState> Joystick::getButtons() const noexcept {
        auto out = std::vector<ButtonState> ();
        int count;
        auto buttons = glfwGetJoystickButtons(_id, &count);

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(static_cast<ButtonState> (buttons[i]));
        }

        return out;
    }

    inline const ButtonState * Joystick::getButtons(int& count) const noexcept {
        return reinterpret_cast<const ButtonState * > (glfwGetJoystickButtons(_id, &count));
    }

    inline std::vector<float> Joystick::getAxes() const noexcept {
        auto out = std::vector<float> ();
        int count;
        auto axes = glfwGetJoystickAxes(_id, &count);

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(axes[i]);
        }

        return out;
    }

    inline const float * Joystick::getAxes(int& count) const noexcept {
        return glfwGetJoystickAxes(_id, &count);
    }

    inline std::string Joystick::getName() const noexcept {
        return glfwGetJoystickName(_id);
    }

    inline std::string Joystick::getGUID() const noexcept {        
        return glfwGetJoystickGUID(_id);
    }

    inline std::vector<Hat> Joystick::getHats() const noexcept {
        auto out = std::vector<Hat> ();
        int count;
        auto hats = glfwGetJoystickHats(_id, &count);

        out.reserve(count);

        for (int i = 0; i < count; i++) {
            out.push_back(static_cast<Hat> (hats[i]));
        }

        return out;
    }

    inline const Hat * Joystick::getHats(int& count) const noexcept {
        return reinterpret_cast<const Hat * > (glfwGetJoystickHats(_id, &count));
    }

    inline void Joystick::setUserPointer(void * ptr) noexcept {
        glfwSetJoystickUserPointer(_id, ptr);
    }

    inline void * Joystick::getUserPointer() const noexcept {
        return glfwGetJoystickUserPointer(_id);
    }

    inline bool Joystick::isGamepad() const noexcept {
        return glfwJoystickIsGamepad(_id);
    }    
}