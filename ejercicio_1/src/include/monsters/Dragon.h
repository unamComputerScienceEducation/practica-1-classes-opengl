#ifndef DRAGON_H
#define DRAGON_H

#include "Monstruo.h"

namespace monster {

    class Dragon : public Monstruo
    {

    public:
        Dragon(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        std::string tipoMonstruo() const override { return "Dragon"; }

    };

};
#endif // DRAGON_H