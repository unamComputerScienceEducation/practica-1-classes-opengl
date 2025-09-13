#ifndef ESQUELETO_H
#define ESQUELETO_H

#include "Monstruo.h"

namespace monster {

    class Esqueleto : public Monstruo
    {

    public:
        Esqueleto(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        std::string tipoMonstruo() const override { return "Esqueleto"; }

    };

};

#endif // ESQUELETO_H
