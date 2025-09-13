#ifndef ESCRITURA_H
#define ESCRITURA_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

namespace io {

    /* Función para escribir resultados en un archivo */
    int escribirResultados(const std::string& nombreArchivo, const std::string& resultados) {
        std::ofstream archivo(nombreArchivo, std::ios::out | std::ios::trunc);
        if (!archivo.is_open()) { 
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
            return -1;
        }

        archivo << resultados << std::endl;

        archivo.close();
        return 0;
    }
};

#endif // ESCRITURA_H