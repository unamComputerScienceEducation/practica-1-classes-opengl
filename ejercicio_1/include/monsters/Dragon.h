/**
 * @file Dragon.h
 * @brief Clase para el monstruo Dragon
 */

#ifndef DRAGON_H
#define DRAGON_H

#include "Monstruo.h"

namespace monster {

    /**
     * @brief Clase para el monstruo Dragon, derivada de Monstruo
     */
    class Dragon : public Monstruo
    {

    public:
        /**
         * @brief Constructor con parámetros
         * @param nombre Nombre del Dragon
         * @param fuerza Fuerza del Dragon
         * @param agilidad Agilidad del Dragon
         * @param inteligencia Inteligencia del Dragon
         */
        Dragon(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        /**
         * @brief Método que regresa el tipo de monstruo
         * @return "Dragon"
         */
        std::string tipoMonstruo() const override { return "Dragon"; }

    };

};
#endif // DRAGON_H