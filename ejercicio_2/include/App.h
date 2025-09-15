/**
 * @file App.h
 * @brief Clase App para manejar la aplicación
 */

#ifndef APP_H
#define APP_H

#include "Window.h"
#include "Draw.h"
#include "Compiler.h"
#include <vector>

namespace opengl {
    /**
     * @class App
     * @brief Clase para manejar la aplicación
     */
    class App {

        private:
            /* La ventana donde dibujaremos */
            Window m_window;
            /* Los objetos para dibujar */
            Draw *m_draw;
            /* Compilador de los shaders */
            Compiler *m_compiler;
            /* Los vertices que describen al objeto */
            std::vector<float> m_vertices; // Utilizamos un vector para poder manejar cualquier cantidad de vertices
            /* Los colores que usaremos para pintar nuestro objeto */
            std::vector<float> m_colors; // Similar a los vertices, un vector para manejar cualquier cantidad de colores


        public:
            /**
             * @brief Constructor de la clase App
             * Inicializamos la ventana similar al ejemplo de OpenGL
             * Para el resto, solo inicializamos los objetos predeterminados
             */
            App() : m_window(800, 600, "OpenGL App"), m_draw(new opengl::Draw()), m_compiler(new opengl::Compiler()) {};

            /**
             * @brief Destructor de la clase App
             */
            ~App();

            /** 
             * @brief Establece los vertices del objeto a dibujar
             * @param vertices Los vertices del objeto
             */
            void setVertices(const std::vector<float>& vertices) { m_vertices = vertices; }

            /**
             * @brief Establece los colores del objeto a dibujar
             * @param colors Los colores del objeto
             */
            void setColors(const std::vector<float>& colors) { m_colors = colors; }
            
            /**
             * @brief Ejecuta la aplicación
             * @return 0 si la aplicación se ejecutó correctamente, -1 en caso contrario
             */
            int run();
    };

}

#endif // APP_H
