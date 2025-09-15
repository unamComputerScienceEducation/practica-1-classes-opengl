/**
 * @file Lectura.cpp
 * @brief Implementación de las funciones para leer los archivos de batalla y/o torneo
 */

#include "../include/io_files/Lectura.h"

namespace io {

    int leerBatalla(const std::string& nombreArchivo) {

        // Abrimos el archivo en modo lectura
        std::ifstream archivo(nombreArchivo, std::ios::in);
        if (!archivo.is_open()) { 
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
            return -1;
        }
        // Formato de cada linea, nos da informacion de dos monstruos y el tipo de batalla
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
            // Creamos dos monstruos, al no saber de que tipo son, usamos punteros a la clase base
            monster::Monstruo* monstruo1 = nullptr;
            monster::Monstruo* monstruo2 = nullptr;

            // Dependiendo del tipo, creamos el primer monstruo correspondiente
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

            // Ahora para el segundo monstruo
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

            // Si ambos monstruos se crearon correctamente, simulamos la batalla
            if (monstruo1 && monstruo2) {
                batalla::Batalla batalla(monstruo1, monstruo2, tbatalla);
                buffer += batalla.simular();
            }

            // Liberamos la memoria de los monstruos
            delete monstruo1;
            delete monstruo2;
        }

        archivo.close();

        // Escribimos los resultados en el archivo
        std::string resultados = "../files/output/resultados.txt";
        io::escribirResultados(resultados, buffer);
        return 0;
    }

    int leerTorneo(const std::string& nombreArchivo) {
        // Abrimos el archivo en modo lectura
        std::ifstream archivo(nombreArchivo, std::ios::in);
        if (!archivo.is_open()) { 
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
            return -1;
        }

        // Formato de cada linea, nos da informacion de un monstruo
        char tipo;
        std::string nombre;
        int fuerza, agilidad, inteligencia;
        std::vector<monster::Monstruo*> monstruos;
        
        // Se sigue del siguiente formato:
        // Tipo Nombre Fuerza Agilidad Inteligencia
        while (archivo >> tipo >> nombre >> fuerza >> agilidad >> inteligencia) {
            // Creamos un monstruo, al no saber de que tipo es, usamos un puntero a la clase base
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
            // Si el monstruo se creo correctamente, lo agregamos al vector
            if (monstruo) {
                monstruos.push_back(monstruo); 
            }
        }

        // A este punto, ya leimos los monstruos del archivo
        archivo.close();

        torneo::Torneo torneo(monstruos); // Enlistamos a los monstruos en el torneo
        std::string buffer = torneo.simular(); // Comenzamos el torneo

        // Escribimos los resultados en el archivo y terminamos
        std::string resultados = "../files/output/resultados_torneo.txt";
        io::escribirResultados(resultados, buffer);
        return 0;
    }
};