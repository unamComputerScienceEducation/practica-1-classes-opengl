#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "Monstruo.h"

namespace monster {

    class Vampiro : public Monstruo
    {

    public:
        Vampiro(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        std::string tipoMonstruo() const override { return "Vampiro"; }

    };
};

#endif // VAMPIRO_H
