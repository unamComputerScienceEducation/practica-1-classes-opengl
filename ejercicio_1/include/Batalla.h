/**
 * @file Batalla.h
 * @brief Clase para simular una batalla entre dos monstruos
 */

#ifndef BATALLA_H
#define BATALLA_H

#include <string>
#include <vector>
#include "monsters/Monstruo.h"
#include <random>
#include <iostream>

namespace batalla {

    /**
     * @class Batalla
     * @brief Clase para simular una batalla entre dos monstruos
     */
    class Batalla {
    private:
        /* Los monstruos que participan en la batalla */
        monster::Monstruo* monstruo1;
        monster::Monstruo* monstruo2;
        /* Tipo de batalla */
        char tipoBatalla;
        /* Ganador de la batalla */
        monster::Monstruo* ganador; // Nos sirve para los ganadores en los torneos

    public:

        /** 
         * @brief Constructor de la batalla
         * @param m1 Primer monstruo participante
         * @param m2 Segundo monstruo participante
         * @param tipo Tipo de batalla
         */
        Batalla(monster::Monstruo* m1, monster::Monstruo* m2, char tipo)
            : monstruo1(m1), monstruo2(m2), tipoBatalla(tipo) {}

        /** 
         * @brief Getter para el ganador de la batalla
         * @return Monstruo ganador
         */
        monster::Monstruo* getGanador() const { return ganador; }

        /**
         * @brief Simula la batalla entre los dos monstruos y devuelve un string con el resultado
         * @return string con el resultado de la batalla
         */
        std::string simular();
    };
};

#endif // BATALLA_H