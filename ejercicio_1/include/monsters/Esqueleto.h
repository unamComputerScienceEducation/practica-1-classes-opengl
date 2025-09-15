/**
 * @file Esqueleto.h
 * @brief Clase para el monstruo Esqueleto
 */

#ifndef ESQUELETO_H
#define ESQUELETO_H

#include "Monstruo.h"

namespace monster {

    /**
     * @brief Clase para el monstruo Esqueleto, derivada de Monstruo
     */
    class Esqueleto : public Monstruo
    {

    public:
        /**
         * @brief Constructor con parámetros
         * @param nombre Nombre del Esqueleto
         * @param fuerza Fuerza del Esqueleto
         * @param agilidad Agilidad del Esqueleto
         * @param inteligencia Inteligencia del Esqueleto
         */
        Esqueleto(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        /**
         * @brief Método que regresa el tipo de monstruo
         * @return "Esqueleto"
         */
        std::string tipoMonstruo() const override { return "Esqueleto"; }

    };

};

#endif // ESQUELETO_H
