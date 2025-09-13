#ifndef TROLL_H
#define TROLL_H

#include "Monstruo.h"

namespace monster {

    class Troll : public Monstruo
    {

    public:
        Troll(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        std::string tipoMonstruo() const override { return "Troll"; }

    };
};

#endif // TROLL_H
