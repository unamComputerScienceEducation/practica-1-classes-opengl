/**
 * @file Orco.h
 * @brief Clase para el monstruo Orco
 */

#ifndef ORCO_H
#define ORCO_H

#include "Monstruo.h"

namespace monster {

    /**
     * @brief Clase para el monstruo Orco, derivada de Monstruo
     */
    class Orco : public Monstruo
    {

    public:

        /**
         * @brief Constructor con parámetros
         * @param nombre Nombre del Orco
         * @param fuerza Fuerza del Orco
         * @param agilidad Agilidad del Orco
         * @param inteligencia Inteligencia del Orco
         */
        Orco(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        /**
         * @brief Método que regresa el tipo de monstruo
         * @return "Orco"
         */
        std::string tipoMonstruo() const override { return "Orco"; }

    };
};
#endif // ORCO_H
