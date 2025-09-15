/**
 * @file Lectura.h
 * @brief Funciones para leer los archivos de batalla y/o torneo
 */

#ifndef LECTURA_H
#define LECTURA_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>


// Clases de monstruos
#include "../monsters/Monstruo.h"
#include "../monsters/Orco.h"
#include "../monsters/Troll.h"
#include "../monsters/Vampiro.h"
#include "../monsters/Dragon.h"
#include "../monsters/Hechicero.h"
#include "../monsters/Esqueleto.h"
#include "../Batalla.h"
#include "../Torneo.h"

// Para escribir resultados
#include "Escritura.h"

namespace io {

    /** 
     * @brief Función para leer los datos de una batalla desde un archivo
     * @param nombreArchivo Nombre del archivo a leer
     * @return 0 si se leyó correctamente, -1 en caso de error
     * Una vez leido el archivo, se simula la batalla y se escriben los resultados
     */
    int leerBatalla(const std::string& nombreArchivo);

    /** 
     * @brief Función para leer los datos de un torneo desde un archivo
     * @param nombreArchivo Nombre del archivo a leer
     * @return 0 si se leyó correctamente, -1 en caso de error
     * Una vez leido el archivo, se simula el torneo y se escriben los resultados
     */
    int leerTorneo(const std::string& nombreArchivo);
};

#endif // LECTURA_H
