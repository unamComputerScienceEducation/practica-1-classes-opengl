/**
 * @file Torneo.cpp
 * @brief Implementación de la clase Torneo
 */

#include "../include/Torneo.h"

namespace torneo {

    std::string Torneo::simular() {
        if (monstruos.size() % 2 != 0 || monstruos.size() < 16) {
            std::cerr << "Error: El torneo requiere una cantidad par de monstruos y al menos 16." << std::endl;
            return ""; // Debe de haber una cantidad par de monstruos y haber al menos 16 para el torneo
        }

        std::string buffer = "";
        std::string battle = "";
        std::string etapa[] = {"Octavos de Final", "Cuartos de Final", "Semifinal", "Final"}; // Etapas del torneo
        int ronda = 0;
        while (monstruos.size() > 1) {
            // Alteramos el orden de los monstruos para su emparejamiento
            std::shuffle(monstruos.begin(), monstruos.end(), gen);
            // Lista de ganadores por ronda
            std::vector<monster::Monstruo*> ganadores;
            buffer += "--- " + etapa[ronda] + " ---\n";
            ronda++;
            // Simulamos todas las batallas de la ronda
            for (size_t i = 0; i < monstruos.size(); i += 2) {
                char modo = modos[gen() % 3]; // Elegimos un modo de batalla 
                buffer += monstruos[i]->getNombre() + " vs " + monstruos[i + 1]->getNombre() + "->";
                batalla::Batalla batalla(monstruos[i], monstruos[i + 1], modo); // Simulamos la batalla
                battle += batalla.simular();
                buffer += "Gana " + batalla.getGanador()->getNombre() + "\n"; // Vemos quien fue el ganador y lo guardamos
                ganadores.push_back(batalla.getGanador());
            }

            // Liberar memoria de los monstruos que no ganaron
            for (size_t i = 0; i < monstruos.size(); i++) {
                if (std::find(ganadores.begin(), ganadores.end(), monstruos[i]) == ganadores.end()) {
                    delete monstruos[i];
                }
            }
            monstruos = ganadores; // Los ganadores avanzan a la siguiente ronda
        }
        io::escribirResultados("../files/output/resultados.txt", battle); // Anotamos los resultados de las batallas
        return buffer; // Los registros finales del torneo
    }
};