/**
 * @file Torneo.h
 * @brief Clase para simular un torneo entre monstruos
 */

#ifndef TORNEO_H
#define TORNEO_H

#include <vector>
#include "monsters/Monstruo.h"
#include "Batalla.h"
#include <random>
#include <string>
#include <algorithm>
#include "io_files/Escritura.h"

namespace torneo {

    /**
     * @class Torneo
     * @brief Clase para simular un torneo entre monstruos
     */
    class Torneo {
    private:
        /* La lista de monstruos que participan */
        std::vector<monster::Monstruo*> monstruos;
        /* Generador de números aleatorios */
        std::mt19937 gen;
        /* Modos de batalla */
        char modos[3] = {'f', 'i', 'e'}; // f: fisica, i: ingenio, e: espiritual

    public:
        /** 
         * @brief Constructor del torneo
         * @param monst Los monstruos que participan en el torneo
         * Inicializamos el generador de números aleatorios
        */
        Torneo(const std::vector<monster::Monstruo*>& monst) : monstruos(monst), gen(std::random_device{}()) {}

        /** 
         * @brief Simula el torneo y devuelve un string con los resultados de las etapas del torneo
         * @return string con los resultados del torneo
        */
        std::string simular();
    };
};

#endif // TORNEO_H