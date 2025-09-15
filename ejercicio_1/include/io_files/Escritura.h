/**
 * @file Escritura.h
 * @brief Funcion para escribir los resultados en un archivo determinado
 */

#ifndef ESCRITURA_H
#define ESCRITURA_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

namespace io {

    /* Función para escribir resultados en un archivo */
    int escribirResultados(const std::string& nombreArchivo, const std::string& resultados);
};

#endif // ESCRITURA_H