/**
 * @file Draw.cpp
 * @brief Implementación de la clase Draw.
 */

#include "../include/Draw.h"

namespace opengl {
    void Draw::initializeVertexArray(const std::vector<float>& vertices, size_t vertexCount) {
        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);

        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        // Usamos vertices.data() para obtener el puntero a los datos del vector 
        glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void Draw::initializeColorArray(const std::vector<float>& colors, size_t colorCount) {
        glBindVertexArray(m_VAO);

        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        // Similar a la funcion anterior
        glBufferData(GL_ARRAY_BUFFER, colorCount * sizeof(float), colors.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
}
