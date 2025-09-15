/**
 * @file App.cpp
 * @brief Implementacion de la clase App
 */

#include "../include/App.h"

namespace opengl
{

    App::~App() {
        // Terminada la ejecucion, borramos los objetos creados y terminamos GLFW
        delete m_draw;
        delete m_compiler;
        glfwTerminate();
    }

    int App::run() {

        // Inicializamos la ventana
        if (m_window.init() != 0) {
            return -1;
        }
        // Compilamos los shaders de los vertices
        GLuint vertexShader = m_compiler->compileShader(GL_VERTEX_SHADER, m_compiler->loadShader("../shader/vertex_shader.glsl"));
        if (vertexShader == 0) {
            return -1;
        }

        // Compilamos los shaders de los fragmentos
        GLuint fragmentShader = m_compiler->compileShader(GL_FRAGMENT_SHADER, m_compiler->loadShader("../shader/fragment_shader.glsl"));
        if (fragmentShader == 0) {
            return -1;
        }

        // Los enlazamos
        GLuint shaderProgram = m_compiler->linkProgram(vertexShader, fragmentShader);

        // Una vez enlazados, los shaders ya no son necesarios
        m_compiler->cleanUpShader(vertexShader);
        m_compiler->cleanUpShader(fragmentShader);

        // Inicializamos los buffers de vertices y colores
        m_draw->initializeVertexArray(m_vertices, m_vertices.size());
        m_draw->initializeColorArray(m_colors, m_colors.size());

        // Render loop
        while (!glfwWindowShouldClose(m_window.getWindow())) {
            // Input
            if (glfwGetKey(m_window.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) // Presionando ESC cerramos la ventana
                glfwSetWindowShouldClose(m_window.getWindow(), true);

            // Render
            //glClearColor(0.0f, 0.3f, 0.8f, 1.0f); // Me gusta mas como se ve con el fondo negro xd
            glClear(GL_COLOR_BUFFER_BIT);

            // Draw
            // Se divide porque cada vertice tiene 3 flotantes y no dibujar de mas (util para poder dibujar distintas figuras)
            m_draw->drawObject(shaderProgram, m_vertices.size() / 3);

            // Swap buffers and poll IO events
            glfwSwapBuffers(m_window.getWindow());
            glfwPollEvents();
        }
        // Limpiamos el shader program cuando la ventana se cierre
        m_compiler->cleanUpShader(shaderProgram);

        return 0;
    }
} 


