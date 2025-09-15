/**
 * @file Vampiro.h
 * @brief Clase para el monstruo Vampiro
 */

#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "Monstruo.h"

namespace monster {

    /**
     * @brief Clase para el monstruo Vampiro, derivada de Monstruo
     */
    class Vampiro : public Monstruo
    {

    public:

        /**
         * @brief Constructor con parámetros
         * @param nombre Nombre del Vampiro
         * @param fuerza Fuerza del Vampiro
         * @param agilidad Agilidad del Vampiro
         * @param inteligencia Inteligencia del Vampiro
         */
        Vampiro(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        /**
         * @brief Método que regresa el tipo de monstruo
         * @return "Vampiro"
         */
        std::string tipoMonstruo() const override { return "Vampiro"; }

    };
};

#endif // VAMPIRO_H
