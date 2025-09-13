#ifndef ORCO_H
#define ORCO_H

#include "Monstruo.h"

namespace monster {

    /* Clase para crear Orcos */
    class Orco : public Monstruo
    {

    public:
        Orco(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        /* Metodo que nos regresa el tipo de monstruo */
        std::string tipoMonstruo() const override { return "Orco"; }

    };
};
#endif // ORCO_H
