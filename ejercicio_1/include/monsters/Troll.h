/**
 * @file Troll.h
 * @brief Clase para el monstruo Troll
 */

#ifndef TROLL_H
#define TROLL_H

#include "Monstruo.h"

namespace monster {

    /**
     * @brief Clase para el monstruo Troll, derivada de Monstruo
     */
    class Troll : public Monstruo
    {

    public:

        /**
         * @brief Constructor con parámetros
         * @param nombre Nombre del Troll
         * @param fuerza Fuerza del Troll
         * @param agilidad Agilidad del Troll
         * @param inteligencia Inteligencia del Troll
         */
        Troll(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        /**
         * @brief Método que regresa el tipo de monstruo
         * @return "Troll"
         */
        std::string tipoMonstruo() const override { return "Troll"; }

    };
};

#endif // TROLL_H
