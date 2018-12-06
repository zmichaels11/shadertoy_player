namespace glfw {
    inline Hat operator| (Hat lhs, Hat rhs) noexcept {
        return static_cast<Hat> (static_cast<unsigned char> (lhs) | static_cast<unsigned char> (rhs));
    }    

    inline Hat operator& (Hat lhs, Hat rhs) noexcept {
        return static_cast<Hat> (static_cast<unsigned char> (lhs) & static_cast<unsigned char> (rhs));
    }

    inline Hat& operator|= (Hat& lhs, Hat rhs) noexcept {
        lhs = lhs | rhs;
        return lhs;
    }

    inline Hat& operator&= (Hat& lhs, Hat rhs) noexcept {
        lhs = lhs & rhs;
        return lhs;
    }
}

namespace std {
    inline string to_string(glfw::Hat hat) noexcept {
        switch (hat) {
            case glfw::Hat::CENTERED:   return "CENTERED";
            case glfw::Hat::DOWN:       return "DOWN";
            case glfw::Hat::UP:         return "UP";
            case glfw::Hat::LEFT:       return "LEFT";
            case glfw::Hat::RIGHT:      return "RIGHT";
            case glfw::Hat::LEFT_DOWN:  return "LEFT_DOWN";
            case glfw::Hat::LEFT_UP:    return "LEFT_UP";
            case glfw::Hat::RIGHT_DOWN: return "RIGHT_DOWN";
            case glfw::Hat::RIGHT_UP:   return "RIGHT_UP";
            default:                    return "INVALID";
        }
    }
}
