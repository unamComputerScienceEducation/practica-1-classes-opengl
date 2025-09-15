/**
 * @file Escritura.cpp
 * @brief Implementación de la función de escritura
 */

#include "../include/io_files/Escritura.h"

namespace io {

    int escribirResultados(const std::string& nombreArchivo, const std::string& resultados) {
        // Abrimos el archivo en modo escritura, siempre se sobreescribe para no acumular resultados
        std::ofstream archivo(nombreArchivo, std::ios::out | std::ios::trunc);
        if (!archivo.is_open()) { 
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
            return -1;
        }

        // Escribimos los resultados en el archivo
        archivo << resultados << std::endl;
        archivo.close();
        return 0;
    }
};