#ifndef HECHICERO_H
#define HECHICERO_H

#include "Monstruo.h"

namespace monster {

    class Hechicero : public Monstruo
    {

    public:
        Hechicero(std::string nombre, int fuerza, int agilidad, int inteligencia) :
            Monstruo{nombre, fuerza, agilidad, inteligencia}
        {
        }

        std::string tipoMonstruo() const override { return "Hechicero"; }

    };

};

#endif // HECHICERO_H
