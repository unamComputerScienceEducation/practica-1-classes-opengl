/**
 * @file Draw.h
 * @brief Clase para manejar el dibujo de objetos en OpenGL
 */

#ifndef DRAW_H
#define DRAW_H

#include <GL/glew.h>
#include <vector>

namespace opengl{

    /**
     * @class Draw
     * @brief Clase para manejar el dibujo de objetos en OpenGL
     */
    class Draw {

        private:
            /* La configuracion de los vertices */
            GLuint m_VAO;
            /* El buffer de los vertices */
            GLuint m_VBO;
        public:

            /**
             * @brief Constructor de la clase Draw
             */
            Draw()
             {}

            /**
             * @brief Destructor de la clase Draw
             */
            ~Draw() {
                glDeleteVertexArrays(1, &m_VAO);
                glDeleteBuffers(1, &m_VBO);
            }

            /** 
             * @brief Devuelve el ID del VAO
             * @return ID del VAO
            */
            GLuint getVAO() const { return m_VAO; }

            /**
             * @brief Devuelve el ID del VBO
             * @return ID del VBO
             */
            GLuint getVBO() const { return m_VBO; }

            /**
             * @brief Configura los buffers de vértices
             */
            void initializeVertexArray(const std::vector<float>& vertices, size_t vertexCount);

            /**
             * @brief Configura los buffers de colores (Se requiere que VAO ya este configurado)
             */
            void initializeColorArray(const std::vector<float>& colors, size_t colorCount);

            /**
            * @brief Dibuja un objeto en OpenGL
            * @param count Número de vértices a dibujar
            */
            void drawObject(GLuint shaderProgram, GLsizei count) {
                glUseProgram(shaderProgram);
                glBindVertexArray(m_VAO);
                glDrawArrays(GL_TRIANGLE_STRIP, 0, count);
            }
    };
}

#endif // DRAW_H