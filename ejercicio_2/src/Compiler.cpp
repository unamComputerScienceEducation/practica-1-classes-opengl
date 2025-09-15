/**
 * @file Compiler.cpp
 * @brief Implementacion de la clase Compiler
 */

#include "../include/Compiler.h"

namespace opengl {
    GLuint Compiler::compileShader(GLenum type, const std::string& source) {
        // Similar al ejemplo de opengl
        GLuint shader = glCreateShader(type);
        // Pasamos un string a un const char* para poder usar glShaderSource
        const char* src = source.c_str();
        glShaderSource(shader, 1, &src, nullptr);
        glCompileShader(shader);

        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            GLchar infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            return 0;
        }

        return shader;
    }

    GLuint Compiler::linkProgram(GLuint vertexShader, GLuint fragmentShader) {
        // El shader final, similar al ejemplo de opengl
        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        // Verificamos si no hubo algun error al enlazar
        GLint success;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            GLchar infoLog[512];
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
            return -1;
        }
        return shaderProgram;
    }

    void Compiler::cleanUpShader(GLuint shader) {
        // Cada que terminemos de usar un shader, lo limpiamos
        glDeleteShader(shader);
    }
}


