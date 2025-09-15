/**
 * @file Window.cpp
 * @brief Implementacion de la clase Window
 */

#include "../include/Window.h"

namespace opengl {
    int Window::init() {
        // Inicializamos GLFW
        if (!glfwInit()) {
            std::cerr << "Error al inicializar GLFW" << std::endl;
            return -1;
        }

        // Establecemos la versión de OpenGL (4.1)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Creamos la ventana a mostrar
        m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
        if (!m_window) {
            std::cerr << "Error al crear la ventana GLFW" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(m_window);

        // Inicializamos GLEW
        if (glewInit() != GLEW_OK) {
            std::cerr << "Error al inicializar GLEW" << std::endl;
            return -1;
        }
        // Si no hubo ningun error, entonces la ventana se inicializo correctamente
        return 0; 
    }
}
