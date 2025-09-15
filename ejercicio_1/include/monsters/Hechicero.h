/**
 * @file Hechicero.h
 * @brief Clase para el monstruo Hechicero
 */

#ifndef HECHICERO_H
#define HECHICERO_H

#include "Monstruo.h"

namespace monster {

    /**
     * @brief Clase para el monstruo Hechicero, derivada de Monstruo
     */
    class Hechicero : public Monstruo
    {

    public:
        /**
         * @brief Constructor con parámetros
         * @param nombre Nombre del Hechicero
         * @param fuerza Fuerza del Hechicero
         * @param agilidad Agilidad del Hechicero
         * @param inteligencia Inteligencia del Hechicero
         */
        Hechicero(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        /**
         * @brief Método que regresa el tipo de monstruo
         * @return "Hechicero"
         */
        std::string tipoMonstruo() const override { return "Hechicero"; }

    };

};

#endif // HECHICERO_H
