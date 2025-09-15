/** 
 * @file Compiler.h 
 * @brief Clase Compiler para manejar la compilación de shaders en OpenGL.
 */

#ifndef COMPILER_H
#define COMPILER_H

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace opengl {
    /**
     * @class Compiler
     * @brief Clase para manejar la compilación de shaders en OpenGL.
     */
    class Compiler {
        public:
            /* Constructor vacio, solo requerimos de sus metodos para compilar shaders */
            Compiler() {}
            /**
             * @brief Compila un shader de OpenGL.
             * @param type Tipo de shader (GL_VERTEX_SHADER o GL_FRAGMENT_SHADER).
             * @param source Código fuente del shader (vertice o el fragmento).
             * @return ID del shader compilado.
             */
            static GLuint compileShader(GLenum type, const std::string& source);

            /**
             * @brief Dado dos shaders, enlaza ambos shaders en un programa de shaders.
             * @param vertexShader ID del shader de vértices.
             * @param fragmentShader ID del shader de fragmentos.
             * @return ID del programa enlazado.
             */
            static GLuint linkProgram(GLuint vertexShader, GLuint fragmentShader);

            /**
             * @brief Carga un shader desde un archivo.
             * @param filename Ruta del archivo.
             * @return Código fuente del shader.
             */
            static std::string loadShader(const std::string& filename) {
                std::ifstream file(filename);
                if (!file.is_open()) {
                    std::cerr << "Error al abrir el archivo: " << filename << std::endl;
                    return "";
                }

                std::stringstream buffer;
                buffer << file.rdbuf();
                return buffer.str();
            }

            /**
             * @brief Limpia los recursos
             * @param shader ID del shader a limpiar.
             */
            static void cleanUpShader(GLuint shader);
    };
}

#endif // COMPILER_H