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

    /* Función para leer los datos de una batalla desde un archivo */
    int leerBatalla(const std::string& nombreArchivo) {

        std::ifstream archivo(nombreArchivo, std::ios::in);

        if (!archivo.is_open()) { 
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
            return -1;
        }

        char tipo1, tipo2;
        std::string nombre1, nombre2;
        int fuerza1, agilidad1, inteligencia1;
        int fuerza2, agilidad2, inteligencia2;
        char tbatalla;

        std::string buffer = ""; // Lo que vamos a escribir
        // Las lineas se siguen del siguiente formato:
        // Tipo1 Nombre1 Fuerza1 Agilidad1 Inteligencia1 Tipo2 Nombre2 Fuerza2 Agilidad2 Inteligencia2 tipoBatalla
        while (archivo >> tipo1 >> nombre1 >> fuerza1 >> agilidad1 >> inteligencia1
               >> tipo2 >> nombre2 >> fuerza2 >> agilidad2 >> inteligencia2 >> tbatalla) {

            monster::Monstruo* monstruo1 = nullptr;
            monster::Monstruo* monstruo2 = nullptr;

            switch (tipo1)
            {
            case 'O':
                monstruo1 = new monster::Orco(nombre1, fuerza1, agilidad1, inteligencia1);
                break;
            case 'T':
                monstruo1 = new monster::Troll(nombre1, fuerza1, agilidad1, inteligencia1); 
                break;
            case 'V':
                monstruo1 = new monster::Vampiro(nombre1, fuerza1, agilidad1, inteligencia1);
                break;
            case 'D':
                monstruo1 = new monster::Dragon(nombre1, fuerza1, agilidad1, inteligencia1);
                break;
            case 'H':
                monstruo1 = new monster::Hechicero(nombre1, fuerza1, agilidad1, inteligencia1);
                break;
            case 'E':
                monstruo1 = new monster::Esqueleto(nombre1, fuerza1, agilidad1, inteligencia1);
                break;
            default:
                std::cerr << "Tipo de monstruo desconocido: " << tipo1 << std::endl;
                break;
            }

            switch (tipo2)
            {
            case 'O':
                monstruo2 = new monster::Orco(nombre2, fuerza2, agilidad2, inteligencia2);
                break;
            case 'T':
                monstruo2 = new monster::Troll(nombre2, fuerza2, agilidad2, inteligencia2);
                break;
            case 'V':
                monstruo2 = new monster::Vampiro(nombre2, fuerza2, agilidad2, inteligencia2);
                break;
            case 'D':
                monstruo2 = new monster::Dragon(nombre2, fuerza2, agilidad2, inteligencia2);
                break;
            case 'H':
                monstruo2 = new monster::Hechicero(nombre2, fuerza2, agilidad2, inteligencia2);
                break;
            case 'E':
                monstruo2 = new monster::Esqueleto(nombre2, fuerza2, agilidad2, inteligencia2);                                                                                                                                                                                                                                                                                                                                                                                                                                                 
                break;
            default:
                std::cerr << "Tipo de monstruo desconocido: " << tipo2 << std::endl;
                break;
            }

            if (monstruo1 && monstruo2) {
                batalla::Batalla batalla(monstruo1, monstruo2, tbatalla);
                buffer += batalla.simular();
            }

            delete monstruo1;
            delete monstruo2;
        }

        archivo.close();

        // Escribir resultados en el archivo
        std::string resultados = "../src/files/output/resultados.txt";
        io::escribirResultados(resultados, buffer);
        return 0;
    }

    /* Función para leer los datos de un torneo desde un archivo */
    int leerTorneo(const std::string& nombreArchivo) {
        std::ifstream archivo(nombreArchivo, std::ios::in);
        if (!archivo.is_open()) { 
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
            return -1;
        }

        char tipo;
        std::string nombre;
        int fuerza, agilidad, inteligencia;
        std::vector<monster::Monstruo*> monstruos;
        
        // Se sigue del siguiente formato:
        // Tipo Nombre Fuerza Agilidad Inteligencia
        while (archivo >> tipo >> nombre >> fuerza >> agilidad >> inteligencia) {
            monster::Monstruo* monstruo = nullptr;

            switch (tipo)
            {
            case 'O':
                monstruo = new monster::Orco(nombre, fuerza, agilidad, inteligencia);
                break;
            case 'T':
                monstruo = new monster::Troll(nombre, fuerza, agilidad, inteligencia); 
                break;
            case 'V':
                monstruo = new monster::Vampiro(nombre, fuerza, agilidad, inteligencia);
                break;
            case 'D':
                monstruo = new monster::Dragon(nombre, fuerza, agilidad, inteligencia);
                break;
            case 'H':
                monstruo = new monster::Hechicero(nombre, fuerza, agilidad, inteligencia);
                break;
            case 'E':
                monstruo = new monster::Esqueleto(nombre, fuerza, agilidad, inteligencia);
                break;
            default:
                std::cerr << "Tipo de monstruo desconocido: " << tipo << std::endl;
                break;
            }

            if (monstruo) {
                monstruos.push_back(monstruo); // Cada monstruo se añade al vector
            }
        }
        torneo::Torneo torneo(monstruos);
        std::string buffer = torneo.simular(); // Comenzamos el torneo

        archivo.close();

        std::string resultados = "../src/files/output/resultados_torneo.txt";
        io::escribirResultados(resultados, buffer);
        return 0;
    }
};

#endif // LECTURA_H
