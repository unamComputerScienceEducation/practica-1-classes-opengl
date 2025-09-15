#include "../include/Batalla.h"

namespace batalla {

    std::string Batalla::simular() {
        int atributos1;
        int atributos2;
        std::string tipo;
        std::string batalla = "";
        switch (tipoBatalla)
        {
        case 'f':
            // Lógica para batalla fisica
            atributos1 = monstruo1->getFuerza() + monstruo1->getAgilidad();
            atributos2 = monstruo2->getFuerza() + monstruo2->getAgilidad();
            tipo = "Batalla Fisica";
            break;
        case 'i':
            // Lógica para batalla de ingenio
            atributos1 = monstruo1->getInteligencia() + monstruo1->getAgilidad();
            atributos2 = monstruo2->getInteligencia() + monstruo2->getAgilidad();
            tipo = "Batalla de Ingenio";
            break;
        case 'e':
            // Lógica para batalla espiritual
            atributos1 = monstruo1->getFuerza() + monstruo1->getInteligencia();
            atributos2 = monstruo2->getFuerza() + monstruo2->getInteligencia();
            tipo = "Batalla Espiritual";
            break;
        default:
            break;
        }                                                                       
        
        batalla += "--- " + tipo + " ---\n";
        batalla += monstruo1->getNombre() + "(" + monstruo1->tipoMonstruo() + ") vs " + monstruo2->getNombre() + "(" + monstruo2->tipoMonstruo() + ")\n";

        int total = atributos1 + atributos2;
        // Obtenemosn un numero aleatorio entre 1 y el total de los atributos
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, total);
        int victorias1 = 0;
        int victorias2 = 0;

        for (size_t i = 0; i < 3; i++)
        {
            // Generamos un numero aleatorio
            int r = dis(gen);
            // Checamos si el numero aleatorio es menor o igual a los atributos del monstruo 1, esto determina quien gana o pierde
            if (r <= atributos1) {
                batalla += "Encuentro " + std::to_string(i + 1) + ":" + monstruo1->getNombre() + " gana\n";
                victorias1++;
            } else {
                batalla += "Encuentro " + std::to_string(i + 1) + ":" + monstruo2->getNombre() + " gana\n";
                victorias2++;
            }
        }
        // Determinamos el ganador de la batalla
        if (victorias1 > victorias2) {
            this->ganador = monstruo1;
        } else {
            this->ganador = monstruo2;
        }

        batalla += "Ganador de la batalla: " + this->ganador->getNombre() + "\n";
        return batalla;
    }
}