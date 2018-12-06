namespace std {
    inline string to_string(glfw::StandardCursorShapes shape) noexcept {
        switch (shape) {
            case glfw::StandardCursorShapes::ARROW:     return "ARROW";
            case glfw::StandardCursorShapes::IBEAM:     return "IBEAM";
            case glfw::StandardCursorShapes::CROSSHAIR: return "CROSSHAIR";
            case glfw::StandardCursorShapes::HAND:      return "HAND";
            case glfw::StandardCursorShapes::HRESIZE:   return "HRESIZE";
            case glfw::StandardCursorShapes::VRESIZE:   return "VRESIZE";
            default:                                    return "INVALID";
        }
    }
}
