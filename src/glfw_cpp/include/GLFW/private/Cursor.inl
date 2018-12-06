namespace glfw {
    Cursor::Cursor(const GLFWimage * image, int xhot, int yhot) noexcept {
        _cursor = glfwCreateCursor(image, xhot, yhot);
    }

    Cursor::Cursor(StandardCursorShapes shape) noexcept {
        _cursor = glfwCreateStandardCursor(static_cast<int> (shape));
    }

    Cursor::Cursor(Cursor&& other) noexcept {
        _cursor = other._cursor;
        other._cursor = nullptr;
    }

    Cursor::~Cursor() noexcept {
        if (_cursor) {
            glfwDestroyCursor(_cursor);
        }
    }

    Cursor& Cursor::operator= (Cursor&& other) noexcept {
        auto tmp = _cursor;

        _cursor = other._cursor;
        other._cursor = tmp;

        return *this;
    }

    Cursor::operator GLFWcursor *() const noexcept {
        return _cursor;
    }

    GLFWcursor * Cursor::getHandle() const noexcept {
        return _cursor;
    }
}
